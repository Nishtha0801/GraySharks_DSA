#include<iostream>
#include<array>
#include<vector>
using namespace std;


int main(){
    
    vector<int>myArr = {1,2,3,4,5};
    myArr.push_back(5);
    myArr.push_back(10);
    myArr.push_back(15);

    for(int i=0; i<myArr.size(); i++){
       cout<<myArr[i]<<" ";
    }

    // int arr[5] = {1,2,3,4,5}; 
    // cout<<sizeof(arr)<<endl;
    // int size = sizeof(arr)/sizeof(arr[0]);
    // cout<<"length of the array: "<<size<<endl;

    // cout<<arr[100]<<endl;

    // array<int, 10> myArray = {1,2,3,4,5};
    // cout<<myArray.size()<<endl;

    // // cout<<arr[0]<<endl;
    // // arr[2] = 15;
    // // cout<<arr[2];

    // for(int i=0; i<100; i++){
    //    cout<<arr[i]<<" ";
    // }

    // for(int i=0; i<myArray.size(); i++){
    //     cout<<myArray[i]<<" ";
    // }

    return 0;

}