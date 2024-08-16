// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "base/android/jni_android.h"
#include "base/android/library_loader/library_loader_hooks.h"

#include "base/android/base_jni_onload.h"
#include "base/android/jni_utils.h"
#include "base/logging.h"
#include "jni_headers/apk_demo/libdemo__jni_registration_generated.h"


namespace {

bool NativeInit(base::android::LibraryProcessType library_process_type) {
  LOG(INFO) << "hanszhli NativeInit";
  return true;
}

}  // namespace


JNI_EXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
  base::android::InitVM(vm);
  base::android::SetNativeInitializationHook(&NativeInit);
  JNIEnv *env = base::android::AttachCurrentThread();

  LOG(INFO) << "hanszhli JNI_OnLoad start register jni";

  if (!RegisterNatives(env)) {
    LOG(INFO) << "hanszhli JNI_OnLoad RegisterNatives failed";
    return -1;
  }

  LOG(INFO) << "hanszhli JNI_OnLoad end";
  return JNI_VERSION_1_4;
}
