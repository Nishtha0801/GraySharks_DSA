#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void insertionSort(vector<int> &arr){
    int n = arr.size();
    for(int i=1; i<n;i++){
        int temp = arr[i];
        int j = i-1;

        while(j>=0 && arr[j] > temp){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

int main(){
    vector<int>myArr = {7,6,5,4,3,2,1};
    insertionSort(myArr);
    for(int i=0;i<myArr.size(); i++){
        cout<<myArr[i]<<" ";
    }

}