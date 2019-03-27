#define _GLIBCXX_USE_CXX11_ABI 0
#include "Simulator.h"
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

bool Simulator::loadMemory(string path) {
    //TODO
    ifstream file;
    file.open(path.c_str(),ios::in|ios::binary);
    file.read(ch,256);//寫入
    for(int i = 0;i < 16;i++){//輸出資料確認
        for(int j = 0;j < 16;j++){
            //cout << setw(2) << hex << (uint16_t)(ch[16*i+j]&0x00FF) <<" ";
        }
        //cout<<'\n';
    }
    //cout << '\n';
    return true;

}
bool Simulator::storeMemory(string path) {
    //TODO
    ofstream file;
    file.open(path.c_str(), ios::out | ios::binary);
    file.write(ch,256);
    for(int i = 0;i < 16;i++){//輸出資料確認
        for(int j = 0;j < 16;j++){
            //cout << setw(2) << hex << (int16_t)(ch[16*i+j]&0x00FF) <<" ";
        }
        //cout<<'\n';
    }
    file.close();
    //cout << '\n';
    return true;

}
bool Simulator::simulate() {
    //TODO
    for(int i=0;i<16;i++)reg[i]={'\0'};//初始化register的值
    for(int i=0;i<256;i+=2){
        uint16_t op = ((uint16_t)ch[i] >> 4) & 0xf;//第一碼
        uint16_t ret = ((uint16_t)ch[i]) & 0xf;//第二碼
        uint16_t content = ((uint16_t)ch[i+1]) & 0xff;//三四碼
        uint16_t content3 = (content >> 4) & 0xf;
        uint16_t content4 = content & 0xf;
        //cout << op << ret << " " << content << " ";
        if(op == 0xc & content==0x00){//遇到C0時跳出
            //cout << "good";
            //cout << content;
            //cout << " "<<content3<<content4;
            break;
        }

        switch (op)
        {
            case 1:
                reg[ret] = ch[content];
                break;
            case 2:
                reg[ret] = content;
                break;
            case 3:
                ch[content] = reg[ret];
                break;
            case 4:
                reg[content4] = reg[content3];
                break;
            case 5:
                reg[ret] = reg[content3] + reg[content4];
                break;
            case 6://浮點數未完成
                break;
            case 7:
                reg[ret] = reg[content3] | reg[content4];
                break;
            case 8:
                reg[ret] = reg[content3] & reg[content4];
                break;
            case 9:
                reg[ret] = reg[content3] ^ reg[content4];
                break;
            case 10:{//旋轉
                uint16_t rotate = (reg[ret] << (8-content4));
                reg[ret] = (reg[ret] >> content4) | rotate;
                break;
            }

            case 11://jump
                if(reg[ret]==reg[0]){
                    i = content-2;//跳到該位置
                    
                    //if(content==0x6&&check==1)i=256;
                    //check=1;
                    //if(ret)cout<<ch[i];
                    //cout <<"c:"<<content<<" ";
                }
                break;
        }
    }

}
