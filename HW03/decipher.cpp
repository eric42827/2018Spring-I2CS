#define _GLIBCXX_USE_CXX11_ABI 0
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <bitset>
using namespace std;

unsigned long int power(int x,int y){
    unsigned  long int sum=1;
    for(int i=0;i<y;i++){
        sum*=x;
    }

    return sum;
}
unsigned long int power10(int x,int y){
    unsigned  long int sum=(unsigned long int)x;
    for(int i=0;i<y;i++){
        sum*=10 ;
    }

    return sum;
}
unsigned long int exponentiation(unsigned long int base,unsigned long int exp,unsigned long int N) 
{ 
    if (exp == 0)return 1; 

    if (exp == 1)return base % N; 
  
    unsigned long int t = exponentiation(base, exp / 2, N); 
    t = (t * t) % N; 
  
    // if exponent is even value 
    if (exp % 2 == 0) 
        return t; 
  
    // if exponent is odd value 
    else
        return ((base % N) * t) % N; 
} 


int main(){

    char save[10][11];
    char N[11],d[11];
    int N_int[10] = {0},d_int[10] = {0};
    unsigned long int Nf = 0;
    unsigned long int df = 0;
    unsigned long int sf[10] = {0};
    ifstream file1;
    file1.open("secret.txt",ios::in|ios::binary);
    
    ifstream file2;
    file2.open("private_key.txt",ios::in|ios::binary);
    file2 >> N >> d;

    unsigned int i = 0;
    while(file1.getline(save[i],11,'\n')){//load secret to char

        for(int j =0;save[i][j]!='\0';j++){//s convert to int
            if(save[i][9]!='\0')
                sf[i]+=power10(save[i][j]-'0',9-j);
            else 
                sf[i]+=power10(save[i][j]-'0',8-j);
        }
        //cout << "sf:" << sf[i]<<endl;
        i++;
        
    }

    for(int i =0;N[i]!='\0';i++){//N convert to int
        Nf+=power10(N[i]-'0',9-i);
    }
    //cout << "Nf:" << Nf <<endl;

    for(int i =0;d[i]!='\0';i++){//d convert to int
        df+=power10(d[i]-'0',9-i);
    }
    //cout << "df:" << df <<endl;
    ofstream out("message.txt",ofstream::binary);

    for(int i = 0;i<10;i++){

        unsigned long int buffer = 0; 
        char reg1,reg2;
        buffer = exponentiation(sf[i],df,Nf);//s^d modN
        //cout << "buffer2 = " << buffer <<'\n';
        reg1 = buffer >> 8;
        reg2 = buffer & 0xff;
        out << reg1 << reg2;

    }

    //cout << N << endl;
    //cout << d << endl;
    
    return 0;
}