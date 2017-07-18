//
// Created by 13969 on 2017/7/18.
//

#ifndef CPP_CPU_H
#define CPP_CPU_H

#include <string>
using namespace std;

class CPU {
public:
    string getVID();
    string getBrand();

private:
    void execCpuId(int id);
    int m_eax;
    int m_ebx;
    int m_ecx;
    int m_edx;
};


#endif //CPP_CPU_H
