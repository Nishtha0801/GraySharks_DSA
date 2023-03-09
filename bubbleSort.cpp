#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void bubbleSort(vector<int> &arr){
    int n = arr.size();
    for(int i=0; i<n-1;i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    return;
}

int main(){
    vector<int>myArr = {7,6,5,4,3,2,1};
    bubbleSort(myArr);
    for(int i=0;i<myArr.size(); i++){
        cout<<myArr[i]<<" ";
    }

}