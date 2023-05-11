#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>&arr, int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;
    int temp;
    
    while(i<j){
        while(i<=high && arr[i]<=pivot){
            i++;
        }
         while(j>=low && arr[j]>pivot){
            j--;
        }
        
        if(i<j){
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    
    arr[low] = arr[j];
    arr[j] = pivot;
    
    return j;
}

void quickSort(vector<int>&arr, int low, int high){
    if(low<high){
        int p = partition(arr, low, high);
        quickSort(arr, low, p-1);
        quickSort(arr, p+1, high);
    }
}

int main() {
    // Write C++ code here
   vector<int>arr = {9,8,2,3,6,5,4,7};
   quickSort(arr,0, arr.size()-1);
   
   for(int i=0;i<arr.size();i++){
       cout<<arr[i]<<endl;
   }

    return 0;
}