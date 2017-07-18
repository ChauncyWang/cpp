//
// Created by chava on 17-7-18.
//
#include "CPU.h"
#include <iostream>
#include <cstring>
#include "CPU_C.h"
using namespace std;

jstring stoJstring(JNIEnv* env, const char* pat)
{
    jclass strClass = env->FindClass("Ljava/lang/String;");
    jmethodID ctorID = env->GetMethodID(strClass, "<init>", "([BLjava/lang/String;)V");
    jbyteArray bytes = env->NewByteArray(strlen(pat));
    env->SetByteArrayRegion(bytes, 0, strlen(pat), (jbyte*)pat);
    jstring encoding = env->NewStringUTF("utf-8");
    return (jstring)env->NewObject(strClass, ctorID, bytes, encoding);
}
JNIEXPORT jobject JNICALL Java_CPU_get
        (JNIEnv * jniEnv, jclass jclass1) {
    jclass jc = jniEnv->FindClass("LCPU;");
    jobject jobj;
    if(jc){
        jmethodID jmethodID1 = jniEnv->GetMethodID(jc, "<init>", "()V");
        if(jmethodID1){
            jobj = jniEnv->NewObject(jc, jmethodID1);
            if(jobj) {
                jmethodID set1 = jniEnv->GetMethodID(jc,"setVID","(Ljava/lang/String;)V");
                jmethodID set2 = jniEnv->GetMethodID(jc,"setBrand","(Ljava/lang/String;)V");
                CPU cpu_c;

                jniEnv->CallVoidMethod(jobj,set1, stoJstring(jniEnv, cpu_c.getVID().c_str()));
                jniEnv->CallVoidMethod(jobj,set2, stoJstring(jniEnv, cpu_c.getBrand().c_str()));
            } else{
                cout << "生成对象失败!!" << endl;
            }
        } else{
            cout << "获取构造函数失败!" << endl;
        }

    } else{
        cout << "加载Class失败!" << endl;
    }


    return jobj;
}