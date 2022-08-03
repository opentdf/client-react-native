import { NativeModules, Platform } from 'react-native';

const LINKING_ERROR =
  `The package 'react-native-opentdf' doesn't seem to be linked. Make sure: \n\n` +
  Platform.select({ ios: "- You have run 'pod install'\n", default: '' }) +
  '- You rebuilt the app after installing the package\n' +
  '- You are not using Expo managed workflow\n';

const ReactNativeOpenTDF = NativeModules.ReactNativeOpenTDF
  ? NativeModules.ReactNativeOpenTDF
  : new Proxy(
      {},
      {
        get() {
          throw new Error(LINKING_ERROR);
        },
      }
    );

export function addDataAttribute(dataAttribute: string): Promise<number> {
  return ReactNativeOpenTDF.addDataAttribute(dataAttribute);
}

export function setUsername(username: string): Promise<number> {
  return ReactNativeOpenTDF.setUsername(username);
}

export function setOrganizationName(username: string): Promise<number> {
  return ReactNativeOpenTDF.setOrganizationName(username);
}

export function setClientId(clientId: string): Promise<number> {
  return ReactNativeOpenTDF.setClientId(clientId);
}

export function setClientSecret(secret: string): Promise<number> {
  return ReactNativeOpenTDF.setClientSecret(secret);
}

export function setKASEndpoint(endpoint: string): Promise<number> {
  return ReactNativeOpenTDF.setKASEndpoint(endpoint);
}

export function setOIDCEndpoint(endpoint: string): Promise<number> {
  return ReactNativeOpenTDF.setOIDCEndpoint(endpoint);
}

export function encryptText(inputText: string): Promise<string> {
  return ReactNativeOpenTDF.encryptText(inputText);
}

export function decryptText(textToDecrypt: string): Promise<string> {
  return ReactNativeOpenTDF.decryptText(textToDecrypt);
}

const client = {
  decryptText,
  encryptText,
  addDataAttribute,
  setKASEndpoint,
  setOIDCEndpoint,
  setClientId,
  setClientSecret,
  setUsername,
  setOrganizationName,
};

export default client;
