#ifndef CANBUS_H
#define CANBUS_H

#include "ICanBus.h"
#include "controlcan.h"

namespace Ohmio
{
	class Canbus : public ICanBus 
	{
	public:
		explicit Canbus();
		~Canbus();

		virtual bool initCanbus() override;
		virtual void quitCanbus() override;
		virtual bool GetPortStatus() override;
		virtual bool ReadCanbus(std::vector<CAN_MSG>& msg, CanBuses CANInd) override;
		virtual bool WriteCanbus(const CAN_MSG& msg) override;
		virtual bool WriteCanbusMulti(std::vector<CAN_MSG>& messages, CanBuses CANInd) override;
		bool IsMock() override;
		bool IsConnected() override;

		// clear the CAN bus buffer. Not sure if we do need it.
		// If we do we need to move the declaration to the base class so that it can be called
		bool Clear(int CANInd = 0);



	private:
		//! Set the appropriate flags so that the data can be sent on CAN bus
		void SetVciCanFlags(VCI_CAN_OBJ &can, CanBuses CANInd);

		// convert a message to VCI_CAN_OBJ so that we can send it over the bus
		VCI_CAN_OBJ ConvertToVci(const  CAN_MSG& msg, CanBuses CANInd);

		// convert a VCI_CAN_OBJ to message after reading from the bus
		CAN_MSG ConvertFromVci(const VCI_CAN_OBJ& vciMsg, CanBuses CANInd);

	private:
		bool m_portIninialized;

	};
}

#endif // CANBUS_H
