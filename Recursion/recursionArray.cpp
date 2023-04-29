// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>

using namespace std;

void display(vector<int>&arr, int idx){
    if(idx == arr.size()){
        return;
    }
    cout<<arr[idx]<<endl;
    display(arr, idx+1);
}

int maximum(vector<int>&arr, int idx){
    if(idx == arr.size() - 1){
        return arr[idx];
    }
    return max(maximum(arr, idx+1), arr[idx]);
}

bool find(vector<int>&arr, int idx, int data){
    if(idx == arr.size()){
        return false;
    }
    if(arr[idx] == data){
        return true;
    }
    return find(arr, idx+1, data);
}

int main() {
    // Write C++ code here
 vector<int>arr = {2,3,4,5,6,7,8};
  display(arr, 0);
  cout<<maximum(arr,0)<<endl;
  cout<<find(arr, 0,4546);
    return 0;
}