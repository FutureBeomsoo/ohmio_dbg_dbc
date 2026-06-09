#pragma once
#include "version.h"

#include <string>
#include <array>
#include <openssl/conf.h>

namespace LicenceUtils
{
	//! Encrypt and decrypt files
	//
	//! this class is based on the code in https://github.com/kulkarniamit/openssl-evp-demo 
	//! with the minimal cahnges needed to make it into a helpful class
	class Encryption
	{
	public:
	
		//! Constructor
		//
		//! @param[in] key - the password for encryption. Could be one of 3 options:
		//! - empty string - use this computer hardware ID as key. Use this option 
		//! for decrypting a licence file on the local computer.
		//! - 64 BYTE string - this is the key as hex code, each 2 chareters are a single BYTE in the key.
		//! The key is supplied by calling GetKey(). Use this option for encrypting a 
		//! licence file for a castomer computer.
		//! - Any other string - the string is the password. The caller is responsible for
		//! creating a secure password and keeping it safe
		//! @param[in] useFullHarwareId - Set to false for using limited hardware 
		Encryption(std::string key = "", bool useFullHarwareId = true);
		~Encryption();

		//! Encrypt a file
		//
		//! @param[in] inFile - source (plain) file name to encrypt
		//! @param[in] outFile - destination (encrypted) file name to write results to
		//! @return true if success 
		bool EnryptFile(std::string inFile, std::string outFile);

		//! Decrypt a file
		//
		//! @param[in] inFile - source (encrypted) file name to decrypt
		//! @param[in] outFile - destination (palin) file name to write results to
		//! @return true if success 
		bool DecryptFile(std::string inFile, std::string outFile);


		//! Encrypt a string
		//
		//! @param[in] source - source (plain) file name to encrypt
		//! @return the encrypted string
		std::string EnryptString(std::string source);

		//! Decrypt a string
		//
		//! @param[in] source - source (plain) file name to encrypt
		//! @return the Decrypted string
		std::string DecryptString(std::string source);


		//! Decrypt a string
		//
		//! @param[in] sourceFilerName - source file to decrypt
		//! @param[out] decrypted - the decrypted string
		//! @return true if success 
		bool DecryptFileToString(const std::string& sourceFilerName, std::string& decrypted);

		//! Get the encryption key as a string
		//
		//! Use this to display the hashed hardware ID 
		std::string GetKey();


	private:
		static const int AES_256_KEY_SIZE = 32;
		static const int AES_BLOCK_SIZE = AES_256_KEY_SIZE / 2;

		//! parametrers for encryption / decryption
		class cipherParams
		{
		public:
			std::array<unsigned char, AES_256_KEY_SIZE>  key;	//!< Key to use for encrpytion and decryption
			std::array<unsigned char, AES_BLOCK_SIZE> iv;		//!< Initialization Vector
			const EVP_CIPHER *cipher_type;			//!< type of code we use
		};

		//! Create the encyption parameters from the key string
		//
		//! @param[in] password - the password to use. If empty use hardware ID
		//! @param[in] useFullHarwareId - if using hardware ID do we use full (true)
		//! or just the mimimum that is stable in running the tests on unspecified hardware (false)
		void CreateParams(std::string password, bool useFullHarwareId);

		//! Encrypt or decrypt a stream (file or string)
		//
		//! @param[in] inStream - source stream 
		//! @param[in] outStream - destination stream
		//! @param[in] encryptOrDecrypt - indicating if we want to encrypt (1) or decreapt (0)
		//! @return true if success 
		bool EncryptDecrypt(std::istream& inStream, std::ostream& outStream, int encryptOrDecrypt);

		//! Encrypt or decrypt a file
		//
		//! @param[in] inName - source file name 
		//! @param[in] outName - destination file name
		//! @param[in] encryptOrDecrypt - indicating if we want to encrypt (1) or decreapt (0)
		//! @return true if success 
		bool EncryptDecryptFile(const std::string& inName, const std::string& outName, int encryptOrDecrypt);
		
		//! Hide the key so that it is not displayed 
		//
		//! Symmetric steganography. Call once to 'hide' the key value. Call second time to get the originnal key back
		//! @param[in] keyIn - the original key
		//! @param[in] keyOut - the hidden value
		void Steganography(const std::array<unsigned char, AES_256_KEY_SIZE>& keyIn, std::array<unsigned char, AES_256_KEY_SIZE>& keyOut);

	private:
		cipherParams m_params;	//!< encryption / decryption parameters. 
	};

}

