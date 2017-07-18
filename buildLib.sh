#!/usr/bin/env bash

echo "正在编译..."
`g++ $1 -fPIC -shared -o libJava.so`
if [ $? -eq 0 ]; then
    echo "编译成功!"
    `mv -f libJava.so /home/chava/lib`
    if [ $? -eq 0 ]; then
        echo "移动成功!!"
    else
        echo "移动失败!"
    fi
else
    echo "编译失败!"
fi