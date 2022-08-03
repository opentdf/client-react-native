import { NativeModules, Platform } from 'react-native';
const LINKING_ERROR = `The package 'react-native-opentdf' doesn't seem to be linked. Make sure: \n\n` + Platform.select({
  ios: "- You have run 'pod install'\n",
  default: ''
}) + '- You rebuilt the app after installing the package\n' + '- You are not using Expo managed workflow\n';
const ReactNativeOpenTDF = NativeModules.ReactNativeOpenTDF ? NativeModules.ReactNativeOpenTDF : new Proxy({}, {
  get() {
    throw new Error(LINKING_ERROR);
  }

});
export function multiply(a, b) {
  return ReactNativeOpenTDF.multiply(a, b);
}
export function tdf_test(a, b) {
  return ReactNativeOpenTDF.tdf_test(a, b);
} // export function encrypt(inputText: string): Promise<string> {
//   return ReactNativeOpenTDF.encrypt(inputText);
// }

export function encryptText(inputText) {
  return ReactNativeOpenTDF.encryptText(inputText);
}
export function decryptText(decryptText) {
  return ReactNativeOpenTDF.decryptText(decryptText);
}
//# sourceMappingURL=index.js.map