#pragma once

#include "VehicleCommunications/SpatMessageData.h"
#include <memory>


namespace OhmioControl
{
	//! Decision tree for applying rules
	//
	//! see https://hmitechnologies.atlassian.net/wiki/spaces/EN/pages/2204106759/Decision+tree+for+traffic+light
	//! This is not a pure C++ implementation. Potential improvements: 
	//! - Derive classes from node for AND vs OR. Then we don't need an IF statement when applying the rules
	//! - Derive Rule from Node. This way only the leaves have rules and we don't need an empty vector at the leaf.
	namespace DecisionTree
	{
		//! The leaf of the tree. A simple rule indicating what the light need to be for a movement 
		class Rule
		{
		public:
			Rule(int g, V2XComms::movementName m, V2XComms::trafficPhaseState p)
				: groupId(g), movement(m), phase(p) {}
			~Rule() {}

			int groupId;						//!< what group ID is this rule for
			V2XComms::movementName movement;	//!< the movement name for this rule
			V2XComms::trafficPhaseState phase;	//!< the phase that is 'green'
		};

		//! How do we combine sub trees (and / or)
		enum class BranchMerging
		{
			Or,		//!< OR between all the branches
			And,	//!< AND between all branches

			Last
		};

		//! A node in the tree
		class Node
		{
		public:
			Node() : rule(-1, V2XComms::movementName::last, V2XComms::trafficPhaseState::last) {};
			~Node() {};

			std::vector<std::shared_ptr<Node>> branches; //!< the sub tree we are responsible for
			Rule rule;	//!< the rule this node implements. Only if this is a leaf
			BranchMerging mergingRule;	//!< do we OR or AND the branches
		};
	}



	//! A Decision tree to decide if we can drive according to traffic light
	//
	//! The leaves are simple rules (go if a particular movement is is the right phase).
	//! Each level can 'OR' or 'AND' all the branches below it.
	class TrafficLightDecisionTree
	{
	public:
		TrafficLightDecisionTree(int regionID = -1, int intersectionID = -1, const std::string& movement = "", int timeToCross = 10000);
		~TrafficLightDecisionTree();

		//! Do we have a valid intersection data?
		bool IsValid() const;

		//!@{
		//! Is this message for the right intersection?
		bool IsRightIntersection(const V2XComms::SpatMessageData& spat) const;
		bool IsRightIntersection(int regionID, int intersectionID, const std::string& movement) const;
		//!@}

		//! Does the message indicate that we should go?
		//
		//! @param[in] spat - the message
		//! @param[in] timeForChange - the time (in 0.1 of second units) before the light will change.
		//! will return 0 if the light is red
		//! @return true if the light is green (or other reasons to go)
		bool IsGreenLight(const V2XComms::SpatMessageData& spat, int& timeForChange) const;

		//! How long (in 0.1 seconds unit) to cross the intersection
		int GetTimeToCross();

		//! Serialise to JSON sting
		void ToJson(std::string& asJson);

		//! Read from JSON string
		bool FromJson(const std::string& asJson);

		//! Get the region ID for diagnostics
		int GetRegionId() const;

		//! Get the Intersection ID for diagnostics
		int GetIntersectionId() const;

		//! Get the movement name for diagnostics
		std::string GetMovementName() const;

		//! Is the movement name meaning no traffic light?
		bool IsIdleMovement(const std::string& movement) const;

		//! Is the event JSON string a stop sign - indicating we should go after we stopped
		bool IsGoSAfterStop(const std::string& eventJson) const;

	private:
		//! Write as JSON
		void WriteToJson(rapidjson::Writer<rapidjson::StringBuffer>& writer);

		//! Export a rule as JSON
		void WriteToJson(rapidjson::Writer<rapidjson::StringBuffer>& writer, const DecisionTree::Rule& rule);

		//! Export a tree as JSON
		void WriteToJson(rapidjson::Writer<rapidjson::StringBuffer>& writer, const DecisionTree::Node& tree);

		//! Export the sub tree to JSON
		void WeiteNodesToJson(rapidjson::Writer<rapidjson::StringBuffer>& writer, const DecisionTree::Node& tree);


		//! Read a decision tree
		bool FromJson(const std::string& asJson, DecisionTree::Node& tree);


		//! Is a spat message "GO" according to specific subtree 
		bool IsGreenLight(const DecisionTree::Node& tree,
			const V2XComms::SpatMessageData& spat, int& timeForChange) const;

		//! Is a spat message "GO" according to specific end leaf
		bool IsGreenLight(const DecisionTree::Rule& rule,
			const V2XComms::SpatMessageData& spat, int& timeForChange) const;

		//! Is a spat message "GO" according to 'AND' subtree
		bool IsGreenAndTree(const std::vector<std::shared_ptr<DecisionTree::Node>>& branches,
			const V2XComms::SpatMessageData& spat, int& timeForChange) const;

		//! Is a spat message "GO" according to 'OR' subtree
		bool IsGreenOrTree(const std::vector<std::shared_ptr<DecisionTree::Node>>& branches,
			const V2XComms::SpatMessageData& spat, int& timeForChange) const;


	private:
		int m_regionId;			//!< the region (in the world) of the intersection
		int m_intersectionId;	//!< which intersection it is
		int m_timeToCross;		//!< time mSec required to cross the intersection (0.1 sec units)
		DecisionTree::Node m_rules; //! the rules
		std::string m_movementName;		//!< optional overriding the rules buy passing a red / green message
	};
}

