#include <jni.h>
#include <string>
#include <opencv2/opencv.hpp>
#include <bits/stdc++.h>
#include <android/log.h>

#define  LOG_TAG    "JNI_PART"
#define LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG, __VA_ARGS__)
#define LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG, __VA_ARGS__)
#define LOGW(...)  __android_log_print(ANDROID_LOG_WARN,LOG_TAG, __VA_ARGS__)
#define LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG, __VA_ARGS__)
#define LOGF(...)  __android_log_print(ANDROID_LOG_FATAL,LOG_TAG, __VA_ARGS__)

using namespace cv;
using namespace std;

extern "C"
JNIEXPORT jstring JNICALL
Java_orbslam_iceberg_club_android_1orbslam_MainActivity_stringFromJNI(JNIEnv* env, jobject /* this */) {

Mat test ;
Mat test2 ;

std::string hello = "Hello from C++";
return env->NewStringUTF(hello.c_str());
}
