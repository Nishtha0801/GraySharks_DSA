// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>

using namespace std;

int subseq(string ques, string ans){
    
    if(ques.length() == 0){
        cout<<ans<<endl;
        return 1;
    }
    
    int count = 0;
    count+=subseq(ques.substr(1), ans+ques[0]); // include
    count+=subseq(ques.substr(1), ans); // exclude
    
    return count;
}

vector<string>codes = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};

vector<string> keyPadCombinations(string str){ //678
    if(str.length() == 0){
        vector<string>base;
        base.push_back("");
        return base;
    }
    char ch = str[0]; // '6' 
    string rstr = str.substr(1); //78
    
    string word = codes[ch - '0']; //'6' - '0' = 6
    
    
    vector<string>smallAns = keyPadCombinations(rstr);
    vector<string>myAns;
    
    for(string s : smallAns){
        for(int i=0;i<word.length();i++){
            myAns.push_back(word[i] + s);
        }
    }
    return myAns;
}

int permutation(string str, string ans){
    if(str.length() == 0){
        cout<<ans<<endl;
        return 1;
    }
    
    int count = 0;
    for(int i=0;i<str.length();i++){
        char ch = str[i];
        string ros = str.substr(0,i) + str.substr(i+1);
        count+=permutation (ros, ans+ch);
    }
    return count;
}

int permuWithoutDuplicates(string str, string ans){
    if(str.length() == 0){
        cout<<ans<<endl;
        return 1;
    }
    
    int count = 0;
    vector<bool>vis(26,0);
    
    for(int i=0;i<str.length();i++){
        char ch = str[i];
        if(!vis[ch-'a']){
            vis[ch-'a'] = true;
             string ros = str.substr(0,i) + str.substr(i+1);
             count+=permuWithoutDuplicates(ros, ans+ch);
        }
     
    }
    return count;
}

int main() {
  vector<int>arr = {2,3,3,4,5,2,2,2};
//   cout<<lastIdx(arr,0,2)<<endl;
//   cout<<subseq("abc", "")<<endl;
//   cout<<permutation("abc", "")<<endl;
cout<<permuWithoutDuplicates("aba", "")<<endl;
    return 0;
}