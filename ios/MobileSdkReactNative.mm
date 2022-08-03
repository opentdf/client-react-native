#import "ReactNativeOpenTDF.h"
#import "react-native-opentdf.h"

@implementation ReactNativeOpenTDF
RCT_EXPORT_MODULE()

// EncryptText - invoke C++ func
RCT_EXPORT_METHOD(encryptText:(nonnull NSString *)inputText
                   withResolver:(RCTPromiseResolveBlock)resolve
                   withReject:(RCTPromiseRejectBlock)reject)
{
    std::string temp = std::string([inputText UTF8String]);
    std::string result = VirtruReactNative::encryptText(temp.c_str());
    NSData* data = [[NSData alloc] initWithBytes:(result).c_str() length:result.size()];
    NSString* encryptedBase64Encoded = [data base64EncodedStringWithOptions:0];
    resolve(encryptedBase64Encoded);
    
}

// DecryptText - invoke C++ func
RCT_EXPORT_METHOD(decryptText:(nonnull NSString *)base64EncryptedString
                   withResolver:(RCTPromiseResolveBlock)resolve
                   withReject:(RCTPromiseRejectBlock)reject)
{
    NSData *decodedData = [[NSData alloc] initWithBase64EncodedString:base64EncryptedString options:0];
    
    std::string encryptedData;
    std::string result;
    encryptedData.append((const char*)[decodedData bytes], [decodedData length]);
    const char * encrypted_c_str = encryptedData.c_str();
    result = VirtruReactNative::decryptText(encryptedData);
    NSString* decryptedString = [NSString stringWithUTF8String:(result).c_str()];
    resolve(decryptedString);
}

// setOIDCEndpoint - invoke C++ func
RCT_EXPORT_METHOD(setOIDCEndpoint:(nonnull NSString *)endpoint
                   withResolver:(RCTPromiseResolveBlock)resolve
                   withReject:(RCTPromiseRejectBlock)reject)
{
    std::string endpointStr = std::string([endpoint UTF8String]);
    //we should probably return some sort of success or fail here
    VirtruReactNative::setOIDCEndpoint(endpointStr.c_str());

}

// setOIDCEndpoint - invoke C++ func
RCT_EXPORT_METHOD(setKASEndpoint:(nonnull NSString *)endpoint
                   withResolver:(RCTPromiseResolveBlock)resolve
                   withReject:(RCTPromiseRejectBlock)reject)
{
    std::string endpointStr = std::string([endpoint UTF8String]);
    //we should probably return some sort of success or fail here
    VirtruReactNative::setKASEndpoint(endpointStr.c_str());
    
}


// setClientId - invoke C++ func
RCT_EXPORT_METHOD(setClientId:(nonnull NSString *)clientId
                   withResolver:(RCTPromiseResolveBlock)resolve
                   withReject:(RCTPromiseRejectBlock)reject)
{
    std::string clientIdStr = std::string([clientId UTF8String]);
    //we should probably return some sort of success or fail here
    VirtruReactNative::setClientId(clientIdStr.c_str());
    
}

// setClientSecret - invoke C++ func
RCT_EXPORT_METHOD(setClientSecret:(nonnull NSString *)secret
                   withResolver:(RCTPromiseResolveBlock)resolve
                   withReject:(RCTPromiseRejectBlock)reject)
{
    std::string secretStr = std::string([secret UTF8String]);
    //we should probably return some sort of success or fail here
    VirtruReactNative::setClientSecret(secretStr.c_str());
}

// setUsername - invoke C++ func
RCT_EXPORT_METHOD(setUsername:(nonnull NSString *)username
                   withResolver:(RCTPromiseResolveBlock)resolve
                   withReject:(RCTPromiseRejectBlock)reject)
{
    std::string usernameStr = std::string([username UTF8String]);
    //we should probably return some sort of success or fail here
    VirtruReactNative::setUsername(usernameStr.c_str());
}

// setOrganizationName - invoke C++ func
RCT_EXPORT_METHOD(setOrganizationName:(nonnull NSString *)organizationName
                   withResolver:(RCTPromiseResolveBlock)resolve
                   withReject:(RCTPromiseRejectBlock)reject)
{
    std::string organizationNameStr = std::string([organizationName UTF8String]);
    //we should probably return some sort of success or fail here
    VirtruReactNative::setOrganizationName(organizationNameStr.c_str());
}



@end
