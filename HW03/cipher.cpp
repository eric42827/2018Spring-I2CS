#define _GLIBCXX_USE_CXX11_ABI 0
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;

unsigned  long int power(int x,int y){
    unsigned  long int sum=1;
    for(int i=0;i<y;i++){
        sum*=x;

    }
    //cout << "sum:" <<sum<<endl;
    //cout << "x="<<x<<" y="<<y<<endl;

    return sum;
}
unsigned  long int power10(int x,int y){
    unsigned  long int sum=(unsigned long int)x;
    for(int i=0;i<y;i++){
        sum*=10 ;

    }
    //cout << "sum:" <<sum<<endl;
    //cout << "x="<<x<<" y="<<y<<endl;

    return sum;
}

int main(){

    char s[10000];
    char N[100],e[2];
    int N_int[10] = {0},e_int = 0;
    unsigned long int Nf = 0;//N
    ifstream file1;
    file1.open("plain.txt",ios::in|ios::binary);
    
    ifstream file2;
    file2.open("public_key.txt",ios::in|ios::binary);
    
    file1.getline(s,10000,'\n');//load plain message
    file2 >> N >> e;//load N e to char
    
    for(int i =0;N[i]!='\0';i++){//N convert to int
        //cout << N[i] <<" ";
        Nf+=power10(N[i]-'0',9-i);
        //cout <<"tNf:"<< Nf <<endl;
    }

    //cout << endl;
    //cout << Nf << endl;
    e_int = e[0]-'0';
    //cout << e_int <<endl;

    ofstream out("secret.txt",ofstream::binary);
    //ofstream message("message_int.txt",ofstream::binary);//test


    for(int i = 0;s[i]!='\0';i+=2){

        unsigned long int buffer = 0;
        //cout << s[i] << s[i+1] << endl; 
        buffer = (u_int16_t)s[i]*256 + (u_int16_t)s[i+1];//encoding(m)
        //cout << "buffer = " << buffer <<'\n';
        //message << buffer << '\n';//save messages        
        buffer = power(buffer,e_int);//m^e
        //cout << "buffer2 = " << buffer <<'\n';
        buffer%=Nf;//mod N
        //cout << "buffer3 = " << buffer <<'\n';
        out << buffer << '\n';

    }

    //cout << N << endl;//ch
    //cout << e << endl;//ch
    
    return 0;
}