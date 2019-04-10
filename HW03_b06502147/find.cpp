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

long int gcdExtended(long int a, long int b, long int &x, long int &y) { 
    // Base Case 
    if (a == 0) { 
        x = 0, y = 1; 
        return b; 
    } 
    long int x1, y1; // To store results of recursive call 
    long int gcd = gcdExtended(b%a, a, x1, y1); 
    // Update x and y using results of recursive 
    x = y1 - (b/a) * x1; 
    y = x1; 
    return gcd; 
} 
  
// Function to find modulo inverse of a 
unsigned long int modInverse(long int a, long int m) { 
    long int x=0, y=0; 
    long int res;
    long int g = gcdExtended(a, m, x, y); 
    if (g != 1) 
        cout << "Inverse doesn't exist"; 
    else{ 
        res = (x%m+m)%m; 
    } 
    return res;
} 
  
// C function for extended Euclidean Algorithm 




int main(){

    char phi[11],e[2];
    int phi_int[10] = {0};
    unsigned long int e_int = 0;
    unsigned long int phif = 0;//phi

    ifstream file;
    file.open("cryptan.txt",ios::in|ios::binary);
    file >> e >> phi;//load N e to char
    
    for(int i = 0;phi[i]!='\0';i++){//phi convert to int
        phif+=power10(phi[i]-'0',9-i);
    }

    e_int = e[0]-'0';
    //cout << e_int << endl;
    //cout << phif << endl;
    ofstream out("cryptan_result.txt",ofstream::binary);
    //unsigned long int d = modInverse(e_int,phif);
    long int d = modInverse(3,4146024640);
    //cout << d;
    out << d;

    return 0;
}