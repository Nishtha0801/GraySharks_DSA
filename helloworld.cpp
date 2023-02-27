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

}