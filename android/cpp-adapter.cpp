#include <jni.h>
#include "react-native-opentdf.h"

extern "C"
JNIEXPORT jint JNICALL
Java_com_reactnativeopentdf_ReactNativeOpenTDFModule_nativeMultiply(JNIEnv *env, jclass type, jint a, jint b) {
    return example::multiply(a, b);
}
