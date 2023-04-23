#include <iostream>
#include<vector>
#include<stack>
#include<unordered_map>>

using namespace std;

vector<int>ngor(vector<int> &arr){
    stack<int>st;
    st.push(-1);
    
    int n = arr.size();
    vector<int>ans(n,-1);
    
    for(int i=0;i<n;i++){
        while(st.top() != -1 && arr[st.top()] < arr[i]){
            ans[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    return ans;
}

vector<int>ngol(vector<int> &arr){
    stack<int>st;
    st.push(-1);
    
    int n = arr.size();
    vector<int>ans(n,-1);
    
    for(int i=n-1;i>=0;i--){
        while(st.top() != -1 && arr[st.top()] < arr[i]){
            ans[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    return ans;
}

vector<int>nsor(vector<int> &arr){
    stack<int>st;
    st.push(-1);
    
    int n = arr.size();
    vector<int>ans(n,n);
    
    for(int i=0;i<n;i++){
        while(st.top() != -1 && arr[st.top()] > arr[i]){
            ans[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    return ans;
}


vector<int>nsol(vector<int> &arr){
    stack<int>st;
    st.push(-1);
    
    int n = arr.size();
    vector<int>ans(n,-1);
    
    for(int i=n-1;i>=0;i--){
        while(st.top() != -1 && arr[st.top()] > arr[i]){
            ans[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    return ans;
}

bool isDuplicate(string &str){
    stack<char>st;
    for(int i=0;i<str.length();i++){
        char ch = str[i];
        if(ch == ')'){
            if(st.top() == '('){
                return true;
            } else {
                while(st.top() != '('){
                    st.pop();
                }
                st.pop();
            }
        } else {
            st.push(ch);
        }
    }
    return false;
}

bool isValid(string s) {
        stack<int>st;
        int n = s.length();
        for(int i=0;i<n;i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                st.push(i);
            }
            else {
                if(st.size() == 0){ // more no. of closing brackets
                    return false;
                } else if(s[i] == ')' && s[st.top()] != '('){
                    return false;
                } else if(s[i] == ']' && s[st.top()] != '['){
                    return false;
                } else if(s[i] == '}' && s[st.top()] != '{'){
                    return false;
                } else {
                    st.pop();
                }
            }
        }
        return st.size() == 0; // more no of opening brackets
}


    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        vector<int>ngorAns = ngor(nums2);

        unordered_map<int,int>map;

        for(int i=0;i<nums2.size();i++){
            map[nums2[i]] = ngorAns[i];
        }

        vector<int>ans(nums1.size(), -1);

        for(int i=0;i<nums1.size();i++){
            if(map.find(nums1[i]) != map.end()){
                ans[i] = map[nums1[i]];
            }
        }
        return ans;

    }

    // leetcode 503
     vector<int> nextGreaterElements(vector<int>& arr) {
        stack<int>st;
        st.push(-1);

        int n= arr.size();
        vector<int>ans(n, -1);
        for(int i=0;i<2*n;i++){
            while(st.top() != -1 && arr[st.top()] < arr[i%n]){
                ans[st.top()] = arr[i%n];
                st.pop();
            }
            if(i<n){
                st.push(i);
            }
        }
        return ans;
    }

    // leetcode 921
      int minAddToMakeValid(string s) {
        stack<int>st;
        int n = s.length();
        for(int i=0;i<n;i++){
            if(st.size() != 0 && s[st.top()] == '(' && s[i] == ')'){
                st.pop();
            } else{
                st.push(i);
            }
        }
        return st.size();
    }
    //leetcode 32
    
   int longestValidParentheses(string s) {
        stack<int>st;
        st.push(-1);

        int n = s.length();
        int len = 0;

        for(int i=0;i<n;i++){
            if(st.top() != -1 && s[st.top()] == '(' && s[i] == ')'){
                st.pop();

                len = max(len, i-st.top());
            }
            else{
                st.push(i);
            }
        }
        return len;
    }

    // leetcode 1249
      string minRemoveToMakeValid(string s) {
        stack<int>st;
        int n = s.length();

        for(int i=0;i<n;i++){
            if(s[i] == ')'){
                if(st.size() != 0){
                    st.pop();
                } else {
                    s[i] = '#';
                }
            } else if (s[i] == '('){
                st.push(i);
            }
        }
        while(st.size() != 0){
            s[st.top()] = '#';
            st.pop();
        } 

        string ans = "";
        for(int i=0;i<n;i++){
            if(s[i] != '#'){
                ans+=s[i];
            }
        }
        return ans;
    }



int main() {
    vector<int>arr = {13,7,6,12};
    vector<int>ans = ngor(arr);
    vector<int>ansArr = ngol(arr);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<ansArr.size();i++){
        cout<<ansArr[i]<<" ";
    }

    return 0;
}

