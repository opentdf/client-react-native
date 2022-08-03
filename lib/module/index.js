import { NativeModules, Platform } from 'react-native';
const LINKING_ERROR = `The package 'mobile-sdk-react-native' doesn't seem to be linked. Make sure: \n\n` + Platform.select({
  ios: "- You have run 'pod install'\n",
  default: ''
}) + '- You rebuilt the app after installing the package\n' + '- You are not using Expo managed workflow\n';
const MobileSdkReactNative = NativeModules.MobileSdkReactNative ? NativeModules.MobileSdkReactNative : new Proxy({}, {
  get() {
    throw new Error(LINKING_ERROR);
  }

});
export function multiply(a, b) {
  return MobileSdkReactNative.multiply(a, b);
}
export function tdf_test(a, b) {
  return MobileSdkReactNative.tdf_test(a, b);
} // export function encrypt(inputText: string): Promise<string> {
//   return MobileSdkReactNative.encrypt(inputText);
// }

export function encryptText(inputText) {
  return MobileSdkReactNative.encryptText(inputText);
}
export function decryptText(decryptText) {
  return MobileSdkReactNative.decryptText(decryptText);
}
//# sourceMappingURL=index.js.map