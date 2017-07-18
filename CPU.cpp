//
// Created by 13969 on 2017/7/18.
//

#include <cstring>
#include "CPU.h"

void CPU::execCpuId(int id) {
    __asm__ __volatile__("movl %4,%%eax;"
            "cpuid;"
            "movl %%eax,%0;"
            "movl %%ebx,%1;"
            "movl %%ecx,%2;"
            "movl %%edx,%3;":"=&a"(m_eax),"=&b"(m_ebx),"=&c"(m_ecx),"=&d"(m_edx):"r"(id):"memory");
}

string CPU::getVID() {
    char cVID[13];
    memset(cVID, 0, 13);
    execCpuId(0);
    memcpy(cVID, &m_ebx, 4);
    memcpy(cVID + 4, &m_edx, 4);
    memcpy(cVID + 8, &m_ecx, 4);

    return string(cVID);
}

string CPU::getBrand() {
    int brandId = 0x80000002;
    char cBrand[49];
    memset(cBrand, 0, 49);
    for( int i = 0;i < 3;++i) {
        execCpuId(brandId + i);
        memcpy(cBrand + i * 16, &m_eax,16);
    }

    return string(cBrand);
}