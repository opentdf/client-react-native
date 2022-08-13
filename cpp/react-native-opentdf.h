#ifndef VIRTRU_REACT_NATIVE_H
#define VIRTRU_REACT_NATIVE_H

#include "stdio.h"
#include <string>
#include "./../lib/include/oidc_credentials.h"
#include "./../lib/include/tdf_client.h"
#include "./../lib/include/nanotdf_client.h"
#include "./../lib/include/tdf_exception.h"

namespace VirtruReactNative
{
  std::string encryptText(const char * inputText);
  std::string decryptText(std::string inputText);
  bool setOIDCEndpoint(const char *endpoint);
  bool setKASEndpoint(const char *endpoint);
  bool setUsername(const char *username);
  bool setOrganizationName(const char *orgName);
  bool setClientId(const char *clientId);
  bool setClientSecret(const char *secret);
  bool addDataAttribute(const char *dataAttribute);
  bool initClient();
  //checks for an existing instance of the client, and creates one if one is not found
  bool checkForInstance();
  std::string readDataAttributes();


}

#endif /* VIRTRU_REACT_NATIVE_H */
