#include<iostream>
#include "CPU.h"

using namespace std;
int main() {
    CPU cpu;
    cout << cpu.getVID() << endl;
    cout << cpu.getBrand() << endl;
    return 0;
}