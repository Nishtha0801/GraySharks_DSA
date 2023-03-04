#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int findElement(vector<int> myArr, int num){
    for(int i=0;i<myArr.size();i++){
        if(myArr[i] == num){
            return i; // returning index here
        }
    }
    return -1; // element is not present in the array
}

int minimumElement(vector<int> myArr){
    int minEle = (int)1e9;
    for(int i=0;i<myArr.size();i++){
        minEle = min(myArr[i], minEle);
    }
    return minEle;
}

int main(){
    //Q1 Find an element in the array(arr, num)
    //q2 Find the minimum element in the array.
    //q3 Find the maximum element in the array.

    vector<int>myArr(5);
    for(int i=0; i<myArr.size();i++){
        cin>>myArr[i]; 
    }

    // for(int i=0;i<myArr.size(); i++){
    //     cout<<myArr[i]<<" ";
    // }
    cout<<endl;
    // cout<<findElement(myArr, 5);
    cout<<minimumElement(myArr);

    
}
