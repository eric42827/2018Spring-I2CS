#ifndef __SIMULATOR__
#define __SIMULATOR__
#define _GLIBCXX_USE_CXX11_ABI 0
#include <string>
#include <iomanip>
using namespace std;

class Simulator{
public:
    bool loadMemory(string);
    bool storeMemory(string);
    bool simulate();
private:
    char ch[256];
    char reg[16];
    //int check = 1;
    //int16_t op = 0;//第一碼
    //int16_t ret = 0;//第二碼
};

#endif
