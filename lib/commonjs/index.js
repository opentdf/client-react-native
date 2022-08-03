"use strict";

Object.defineProperty(exports, "__esModule", {
  value: true
});
exports.decryptText = decryptText;
exports.encryptText = encryptText;
exports.multiply = multiply;
exports.tdf_test = tdf_test;

var _reactNative = require("react-native");

const LINKING_ERROR = `The package 'react-native-opentdf' doesn't seem to be linked. Make sure: \n\n` + _reactNative.Platform.select({
  ios: "- You have run 'pod install'\n",
  default: ''
}) + '- You rebuilt the app after installing the package\n' + '- You are not using Expo managed workflow\n';
const MobileSdkReactNative = _reactNative.NativeModules.MobileSdkReactNative ? _reactNative.NativeModules.MobileSdkReactNative : new Proxy({}, {
  get() {
    throw new Error(LINKING_ERROR);
  }

});

function multiply(a, b) {
  return MobileSdkReactNative.multiply(a, b);
}

function tdf_test(a, b) {
  return MobileSdkReactNative.tdf_test(a, b);
} // export function encrypt(inputText: string): Promise<string> {
//   return MobileSdkReactNative.encrypt(inputText);
// }


function encryptText(inputText) {
  return MobileSdkReactNative.encryptText(inputText);
}

function decryptText(decryptText) {
  return MobileSdkReactNative.decryptText(decryptText);
}
//# sourceMappingURL=index.js.map