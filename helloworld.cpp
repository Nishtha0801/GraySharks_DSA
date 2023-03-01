#include<iostream>
using namespace std;

int main(){

    // cout<<"Hello world"<<endl;
    // cout<<"Hello everyone, Let's start doing DSA";

    // int number;
    // cout<<"Type a number:";
    // cin>>number;

    // if else 

    // int number;
    // cout<<"Type a number:";
    // cin>>number;

    // if(number>=5){
    //     cout<<"The number is greater than 5"<<endl;
    // } else {
    //     cout<<"The number is lesser than 5"<<endl;
    // }

    // if(number>0){
    //     cout<<"Number is +ve"<<endl;
    // } else if (number<0){
    //     cout<<"Number is negative"<<endl;
    // } else {
    //     cout<<"Number is neither negative nor positive"<<endl;
    // }

    // if(number != 0){
    //     if(number > 0){
    //         cout<<"Number is +ve"<<endl;
    //     } else {
    //         cout<<"Number is -ve"<<endl;
    //     }
    // } else {
    //    cout<<"Number is neither negative nor positive"<<endl;
    // }

    // if(number%2 == 0){
    //     cout<<"The number is even"<<endl;
    // } else {
    //     cout<<"The number is odd"<<endl;
    // }

    // char ch;
    // cout<<"Enter the character";
    // cin>>ch;

    // if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
    //     cout<<"vowel";
    // } else {
    //     cout<<"consonant";
    // }

    // for loop
        for(int i=1; i<=5; i++){
        cout<<i<<endl;
        }

        for(int i=1; i<=5; i++){
        cout<<"Nishtha"<<endl; 
        }

    // sum of first n natural numbers
        int n;
        cout<<"Enter n: ";
        cin>>n;
        
        int sum = 0;
        for(int i=1;i<=n;i++){
            sum+=i;
        }
        // 1+2+3+4+5
        cout<<sum<<endl;

        // factorial 
        int n;
        long fact = 1;
        cout<<"Enter n:";
        cin>>n;
        
        for(int i=1;i<=n; i++){
            fact*=i;
        }
        cout<<fact;

        // while loop

        // int i=1;
        // while(i<=5){
        //     cout<<i<<endl;
        //     i++;
        // }

        // break
         for(int i=1; i<=5; i++){
            if(i==3){
                break;
            }
            cout<<i<<endl;
        }

        // Reverse a number
        int dividend;
        int divisor;
        
        cout<<"Please enter your dividend: ";
        cin>>dividend;
        cout<<"Please enyer your divisor: ";
        cin>>divisor;
        
        int quotient = dividend/divisor;
        int remainder = dividend % divisor;
        
        cout<<"My Quotient is: "<< quotient<<endl;
        cout<<"My Remainder is: "<< remainder<<endl;


        // Reverse a number
        int n;
        cout<<"enter number: ";
        cin>>n;
        
        int ans = 0;
        while(n!=0){
            int rem = n%10;
            ans = ans*10 + rem;
            n/=10;
        }
        
        cout<<"The answer is: " <<ans<<endl;

        // Palindrome

        int n;
        cout<<"enter number: ";
        cin>>n;
        
        int originalNumber = n;
        int reversedNumber = 0;
        
        while(n!=0){
            int rem = n%10;
            reversedNumber = reversedNumber*10 + rem;
            n/=10;
        }
        
        cout<<"The reversedNumber is: " <<reversedNumber<<endl;
        
        //12321 -> palindrome number or not
        
        if(originalNumber == reversedNumber){
            cout<<"The given number is palindrome.";
        } else {
            cout<<"The given number is not a palindrome.";
        }
  
        // prime  number
            int n;
            cout<<"enter number: ";
            cin>>n;
            bool isPrime = true;
            
            if(n==0 || n==1){
                isPrime = false;
            }
            
            for(int i=2;i<n;i++){ // i<=n/2
                if(n%i == 0){
                    isPrime = false;
                    break;
                }
            }
            
            if(isPrime == true){
                cout<<"The number is prime";
            } else {
                cout<<"The number is not prime";
            }

            // count digits
            int n;
            cout<<"Enter number: ";
            cin>>n;
            
            int count = 0;
            while(n != 0){
                n = n/10;
                count++;
            }
            cout<<count<<endl;

            // print all primes till N
              int n;
                cout<<"Enter number: ";
                cin>>n;
                
                for(int i=2; i<=n; i++){
                    bool isPrime = true;
                    for(int j=2;j<=i/2;j++){ 
                            if(i%j == 0){
                                isPrime = false;
                                break;
                            }
                    }
                    if(isPrime){
                        cout<<i<<" "<<endl;
                    }
                }


                // Pattern 1=======

                int n;
                cout<<"Enter number: ";
                cin>>n;

                for(int rows = 1; rows <= n; rows++) {
                    for(int cst = 1; cst <= rows; cst++) {
                        cout << "* ";
                    }
                    cout << endl;
                }


                // Pattern 2=========
                    int n;
                    cout<<"Enter number: ";
                    cin>>n;

                    for(int rows = n; rows >= 0; rows--) {
                        for(int cst = 1; cst <= rows; cst++) {
                            cout << "* ";
                        }
                        cout << endl;
                    }

    return 0;
}