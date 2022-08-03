#include <iostream>
#include <unordered_map>
#include "react-native-opentdf.h"
#include "./../lib/include/oidc_credentials.h"
#include "./../lib/include/tdf_client.h"
#include "./../lib/include/nanotdf_client.h"
#include "./../lib/include/tdf_exception.h"

namespace VirtruReactNative
{
	static std::string encryptResult;
	static std::string decryptResult;
	static virtru::OIDCCredentials clientCreds;
	static bool instanceCreated = false;
	static std::string OIDC_ENDPOINT = "http://192.168.86.39:3000";
	static std::string KAS_ENDPOINT = "http://192.168.86.39:3000/api/kas";
	static std::string CLIENT_ID = "tdf-client";
	static std::string CLIENT_SECRET = "123-456";
	static std::string ORGANIZATION_NAME = "tdf";
	static std::string username = "avery.pfeiffer@virtru.com";
	static std::unique_ptr<virtru::TDFClient> tdfClient;

	bool setUsername(const char *username)
	{
		try
		{
			VirtruReactNative::username = std::string(username);
			return true;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
			return false;
		}
	}

	bool setOrganizationName(const char *orgName)
	{
		try
		{
			VirtruReactNative::ORGANIZATION_NAME = std::string(orgName);
			return true;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
			return false;
		}
	}

	bool setClientId(const char *clientId)
	{
		try
		{
			VirtruReactNative::CLIENT_ID = std::string(clientId);
			return true;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
			return false;
		}
	}

	bool setClientSecret(const char *secret)
	{
		try
		{
			VirtruReactNative::CLIENT_SECRET = std::string(secret);
			return true;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
			return false;
		}
	}

	bool setOIDCEndpoint(const char *endpoint)
	{
		try
		{
			VirtruReactNative::OIDC_ENDPOINT = std::string(endpoint);
			return true;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
			return false;
		}
	}

	bool setKASEndpoint(const char *endpoint)
	{
		try
		{
			VirtruReactNative::KAS_ENDPOINT = std::string(endpoint);
			return true;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
			return false;
		}
	}

	std::string encryptText(const char *inputText)
	{
		using namespace virtru;
		// These are the credentials of OpenTDF backend when run locally
		// NOTE: Port 3000 is pointing at a proxy right now, since the openTDF backend won't work unless it receives requests from "localhost"
		if (VirtruReactNative::instanceCreated == false)
		{
			VirtruReactNative::clientCreds.setClientCredentialsClientSecret(CLIENT_ID, CLIENT_SECRET, ORGANIZATION_NAME, OIDC_ENDPOINT);
			VirtruReactNative::tdfClient = std::make_unique<virtru::TDFClient>(VirtruReactNative::clientCreds, VirtruReactNative::KAS_ENDPOINT);
			VirtruReactNative::instanceCreated = true;
		}

		try
		{

			std::string cipherText = VirtruReactNative::tdfClient->encryptString(inputText);
			// auto plainText = nanoTDFClient->decryptString(cipherText);
			VirtruReactNative::encryptResult = cipherText;
			//            VirtruReactNative::encryptResult = cipherText.c_str();
			return VirtruReactNative::encryptResult;
		}
		catch (const Exception &exception)
		{
			std ::cerr << "virtru exception " << exception.what() << std::endl;
			std::string errString = exception.what();
			VirtruReactNative::encryptResult = errString.c_str();
			return VirtruReactNative::encryptResult;
		}
		catch (const std::exception &exception)
		{
			std ::cerr << exception.what() << std::endl;
			std::string errString = exception.what();
			VirtruReactNative::encryptResult = errString.c_str();
			return VirtruReactNative::encryptResult;
		}
		catch (...)
		{
			std ::cerr << "Unknown..." << std::endl;
			std::string errString = "Unknown error occurred";
			VirtruReactNative::encryptResult = errString.c_str();
			return VirtruReactNative::encryptResult;
		}

		return "EXIT_SUCCESS";
	}

	std::string decryptText(std::string cyperText)
	{
		using namespace virtru;
		// create a new instance if we don't have one
		if (VirtruReactNative::instanceCreated == false)
		{
			// These are the credentials of OpenTDF backend when run locally
			// NOTE: Port 3000 is pointing at a proxy right now, since the openTDF backend won't work unless it receives requests from "localhost"
			VirtruReactNative::clientCreds.setClientCredentialsClientSecret(CLIENT_ID, CLIENT_SECRET, ORGANIZATION_NAME, OIDC_ENDPOINT);
			VirtruReactNative::tdfClient = std::make_unique<virtru::TDFClient>(VirtruReactNative::clientCreds, VirtruReactNative::KAS_ENDPOINT);
			VirtruReactNative::instanceCreated = true;
		}

		try
		{

			std::string plainText = VirtruReactNative::tdfClient->decryptString(cyperText);

			VirtruReactNative::decryptResult = plainText;
			return VirtruReactNative::decryptResult;
		}
		catch (const Exception &exception)
		{
			std ::cerr << "virtru exception " << exception.what() << std::endl;
			std::string errString = exception.what();
			VirtruReactNative::decryptResult = errString;
			return VirtruReactNative::decryptResult;
		}
		catch (const std::exception &exception)
		{
			std ::cerr << exception.what() << std::endl;
			std::string errString = exception.what();
			VirtruReactNative::decryptResult = errString;
			return VirtruReactNative::decryptResult;
		}
		catch (...)
		{
			std ::cerr << "Unknown..." << std::endl;
			std::string errString = "Unknown Error Occurred";
			VirtruReactNative::decryptResult = errString;
			return VirtruReactNative::decryptResult;
		}

		return "EXIT_SUCCESS";
	}

}
