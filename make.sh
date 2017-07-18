#!/bin/bash

`g++ $1 -fPIC -shared -o libJava.so`
`rm /home/chava/lib/libJava.so`
`mv libJava.so /home/chava/lib`
