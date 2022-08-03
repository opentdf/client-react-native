#include <jni.h>
#include "mobile-sdk-react-native.h"

extern "C"
JNIEXPORT jint JNICALL
Java_com_mobilesdkreactnative_MobileSdkReactNativeModule_nativeMultiply(JNIEnv *env, jclass type, jint a, jint b) {
    return example::multiply(a, b);
}
