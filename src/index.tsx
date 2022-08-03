import { NativeModules, Platform } from 'react-native';

const LINKING_ERROR =
  `The package 'mobile-sdk-react-native' doesn't seem to be linked. Make sure: \n\n` +
  Platform.select({ ios: "- You have run 'pod install'\n", default: '' }) +
  '- You rebuilt the app after installing the package\n' +
  '- You are not using Expo managed workflow\n';

const MobileSdkReactNative = NativeModules.MobileSdkReactNative ? NativeModules.MobileSdkReactNative : new Proxy(
  {},
  {
    get() {
      throw new Error(LINKING_ERROR);
    },
  }
);

export function setUsername(username: string): Promise<number> {
  return MobileSdkReactNative.setUsername(username);
}

export function setOrganizationName(username: string): Promise<number> {
  return MobileSdkReactNative.setOrganizationName(username);
}

export function setClientId(clientId: string): Promise<number> {
  return MobileSdkReactNative.setClientId(clientId);
}

export function setClientSecret(secret: string): Promise<number> {
  return MobileSdkReactNative.setClientSecret(secret);
}

export function setKASEndpoint(endpoint: string): Promise<number> {
  return MobileSdkReactNative.setKASEndpoint(endpoint);
}

export function setOIDCEndpoint(endpoint: string): Promise<number> {
  return MobileSdkReactNative.setOIDCEndpoint(endpoint);
}


export function encryptText(inputText: string): Promise<string> {
  return MobileSdkReactNative.encryptText(inputText);
}

export function decryptText(decryptText: string): Promise<string> {
  return MobileSdkReactNative.decryptText(decryptText);
}

export function initClient(clientId: string, clientSecret: string, oidcEndpoint: string, kasEndpoint: string): void {
  // return MobileSdkReactNative.decryptText(decryptText);
  // return Promise.resolve<string>()
}

const client = {
  decryptText,
  encryptText,
  setKASEndpoint,
  setOIDCEndpoint,
  setClientId,
  setClientSecret,
  setUsername,
  setOrganizationName,
}

export default client;
