#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

//o(n)
int linearSearch(vector<int> &myArr, int data){
    int n = myArr.size();
    for(int i=0;i<n;i++){
        if(myArr[i] == data){
            return i;
        }
    }
    return -1;
}

int main(){
   
    vector<int>myArr = {1,2,3,4,5,6,7};
    int data = 16;

    cout<<linearSearch(myArr, data)<<endl;
}