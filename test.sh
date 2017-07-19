#!/bin/bash

JAVAC=`whereis javac|sed 's/.*\s\(.*lib\/jvm.*\)\s.*/\1/g'`
home="${JAVAC:0:-9}"
CPLUS_INCLUDE_PATH="${home}include":"${home}include/linux":$CPLUS_INCLUDE_PATH
export CPLUS_INCLUDE_PATH

echo "正在编译本地代码..."
g++ $@ -fPIC -shared -o libJava.so
if [ $? -eq 0 ]; then
    echo "编译本地代码成功!"
else
    echo "编译本地代码失败!"
fi

echo "正在生成java字节码..."
`javac java/*.java`
if [ $? -eq 0 ]; then
    echo "java字节码生成成功!"
fi
echo "正在打包Jar..."
jar cvfm A.jar ./mymanifest -C java/ .
echo "打包Jar成功!"
echo "运行Jar："
java -cp . -jar A.jar
