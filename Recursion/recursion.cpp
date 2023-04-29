// Online C++ compiler to run C++ program online
#include <iostream>

using namespace std;

void printDec(int n){
    if(n==0){
        return;
    }
    cout<<n<<endl;
    printDec(n-1);
}

void printInc(int n){
    if(n==0){
        return;
    }
    printInc(n-1);
    cout<<n<<endl;
}

void printDecInc(int n){
    if(n==0){
        return;
    }
        
   cout<<n<<endl;
   printDecInc(n-1);
   cout<<n<<endl;
}

int factorial(int n){
    if(n == 1){
        return 1;
    }
    int fnm1 = factorial(n-1);
    int fn = n*fnm1;
    
    return fn;
}

void printOddEven(int a, int b){
    if(a == b+1){
        return;
    }
    if(a%2 == 0){
        cout<<a<<endl;
    }
    
    printOddEven(a+1,b);
    
    if(a%2 != 0){
       cout<<a<<endl;
    }
}

int power(int x, int n){
    if(n==0){
        return 1;
    }
    int pnm1 = power(x, n-1);
    int pn = pnm1*x;
    
    return pn;
}

int main() {
    // Write C++ code here
 
    // printDecInc(5);
    printOddEven(1,10);
//   cout<<factorial(5);
cout<<power(2,5);
    return 0;
}