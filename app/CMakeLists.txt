# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

set(CMAKE_VERBOSE_MAKEFILE on)
set(libs "${CMAKE_SOURCE_DIR}/src/main/jniLibs")   # 設定 jniLibs 路徑
include_directories(${CMAKE_SOURCE_DIR}/src/main/cpp/include) # 設定 include 路徑

# 加入 native 資源的 格式如下 (加入使用到的 jniLibs 檔案)
add_library(libopencv_java SHARED IMPORTED )
set_target_properties(libopencv_java PROPERTIES
    IMPORTED_LOCATION "${libs}/${ANDROID_ABI}/libopencv_java.so")

add_library(libopencv_androidcamera SHARED IMPORTED )
set_target_properties(libopencv_androidcamera PROPERTIES
    IMPORTED_LOCATION "${libs}/${ANDROID_ABI}/libopencv_androidcamera.a")

add_library(libopencv_calib3d SHARED IMPORTED )
set_target_properties(libopencv_calib3d PROPERTIES
    IMPORTED_LOCATION "${libs}/${ANDROID_ABI}/libopencv_calib3d.a")

add_library(libopencv_contrib SHARED IMPORTED )
set_target_properties(libopencv_contrib PROPERTIES
    IMPORTED_LOCATION "${libs}/${ANDROID_ABI}/libopencv_contrib.a")

add_library(libopencv_core SHARED IMPORTED )
set_target_properties(libopencv_core PROPERTIES
    IMPORTED_LOCATION "${libs}/${ANDROID_ABI}/libopencv_core.a")

add_library(libopencv_features2d SHARED IMPORTED )
set_target_properties(libopencv_features2d PROPERTIES
    IMPORTED_LOCATION "${libs}/${ANDROID_ABI}/libopencv_features2d.a")

add_library(libopencv_flann SHARED IMPORTED )
set_target_properties(libopencv_flann PROPERTIES
    IMPORTED_LOCATION "${libs}/${ANDROID_ABI}/libopencv_flann.a")

add_library(libopencv_highgui SHARED IMPORTED )
set_target_properties(libopencv_highgui PROPERTIES
    IMPORTED_LOCATION "${libs}/${ANDROID_ABI}/libopencv_highgui.a")

add_library(libopencv_imgproc SHARED IMPORTED )
set_target_properties(libopencv_imgproc PROPERTIES
    IMPORTED_LOCATION "${libs}/${ANDROID_ABI}/libopencv_imgproc.a")

add_library(libopencv_info SHARED IMPORTED )
set_target_properties(libopencv_info PROPERTIES
    IMPORTED_LOCATION "${libs}/${ANDROID_ABI}/libopencv_info.so")

add_library(libopencv_legacy SHARED IMPORTED )
set_target_properties(libopencv_legacy PROPERTIES
    IMPORTED_LOCATION "${libs}/${ANDROID_ABI}/libopencv_legacy.a")

add_library(libopencv_ml SHARED IMPORTED )
set_target_properties(libopencv_ml PROPERTIES
    IMPORTED_LOCATION "${libs}/${ANDROID_ABI}/libopencv_ml.a")

add_library(libopencv_objdetect SHARED IMPORTED )
set_target_properties(libopencv_objdetect PROPERTIES
    IMPORTED_LOCATION "${libs}/${ANDROID_ABI}/libopencv_objdetect.a")

add_library(libopencv_ocl SHARED IMPORTED )
set_target_properties(libopencv_ocl PROPERTIES
    IMPORTED_LOCATION "${libs}/${ANDROID_ABI}/libopencv_ocl.a")

add_library(libopencv_photo SHARED IMPORTED )
set_target_properties(libopencv_photo PROPERTIES
    IMPORTED_LOCATION "${libs}/${ANDROID_ABI}/libopencv_photo.a")

add_library(libopencv_stitching SHARED IMPORTED )
set_target_properties(libopencv_stitching PROPERTIES
    IMPORTED_LOCATION "${libs}/${ANDROID_ABI}/libopencv_stitching.a")

add_library(libopencv_superres SHARED IMPORTED )
set_target_properties(libopencv_superres PROPERTIES
    IMPORTED_LOCATION "${libs}/${ANDROID_ABI}/libopencv_superres.a")

add_library(libopencv_ts SHARED IMPORTED )
set_target_properties(libopencv_ts PROPERTIES
    IMPORTED_LOCATION "${libs}/${ANDROID_ABI}/libopencv_ts.a")

add_library(libopencv_video SHARED IMPORTED )
set_target_properties(libopencv_video PROPERTIES
    IMPORTED_LOCATION "${libs}/${ANDROID_ABI}/libopencv_video.a")

add_library(libopencv_videostab SHARED IMPORTED )
set_target_properties(libopencv_videostab PROPERTIES
    IMPORTED_LOCATION "${libs}/${ANDROID_ABI}/libopencv_videostab.a")

#最後加上 這段
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11 -fexceptions -frtti")

add_library( # Sets the name of the library.
             native-lib

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             src/main/cpp/native-lib.cpp )

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
              log-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
                       native-lib android log

                       # OpenCV library (加入使用到的 jniLibs 檔案)
                       libopencv_java libopencv_androidcamera libopencv_calib3d libopencv_contrib libopencv_core
                       libopencv_features2d libopencv_flann libopencv_highgui libopencv_imgproc libopencv_info
                       libopencv_legacy libopencv_ml libopencv_objdetect libopencv_ocl libopencv_photo
                       libopencv_stitching libopencv_superres libopencv_ts libopencv_video libopencv_videostab

                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib} )