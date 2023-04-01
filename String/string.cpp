#include<iostream>
#include<vector>
using namespace std;

void reverseString(string &str){
    int n = str.length();
    int si = 0;
    int ei = n-1;
    while(si<ei){
        char temp = str[si];
        str[si] = str[ei];
        str[ei] = temp;
        si++;
        ei--;
    }
}

//leetcode 2108

    bool isPalindrome(string str){
        int si = 0, ei = str.length()-1;

        while(si<ei){
            if(str[si++] != str[ei--]){
                return false;
            }
        }
        return true;
    }

    string firstPalindrome(vector<string> &words) {
        int n = words.size();

        for(int i=0;i<n;i++){
            if(isPalindrome(words[i])){
                return words[i];
            }
        }

        return "";
    }

int main(){
    string str = "Nishtha Goyal";
    reverseString(str);
    cout<<str<<endl;
    // cout<<str[2]<<endl;

    // char arr[5] = {'a', 'e', 'i', 'o', 'u'};

    // string fullName;
    // getline(cin, fullName);

    // // reverse a string

    // cout<<fullName<<endl;







}