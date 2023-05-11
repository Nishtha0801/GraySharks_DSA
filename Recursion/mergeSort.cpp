#include <iostream>
#include<vector>

using namespace std;

int merge(vector<int>&arr, int si, int ei){
    int mid = (si+ei)/2;
    int count = 0;
    int i = si;
    int j = mid + 1;
    
    vector<int>temp(ei-si+1, 0);
    int k = 0;
    while(i<=mid && j<=ei){
        if(arr[i] <= arr[j]){
            temp[k] = arr[i];
            k++;
            i++;
        } else {
            temp[k] = arr[j];
            count+=(mid - i + 1);
            k++;
            j++;
        }
    }
    
    while(i<=mid){
        temp[k] = arr[i];
        k++;
        i++;
    }
    
     while(j<=ei){
        temp[k] = arr[j];
        k++;
        j++;
    }
    
    for(int idx=si;idx<=ei;idx++){
        arr[idx] = temp[idx-si];
    }
    return count;
}


int mergeSort(vector<int>&arr, int si, int ei){
    int count = 0;
    if(si < ei){
        int mid = (si+ei)/2;
       count+=mergeSort(arr, si, mid);
       count+=mergeSort(arr, mid+1, ei);
        
       count+=merge(arr, si, ei);
    }
    return count;
}

int main() {
   vector<int>arr = {2,3,4,5,6};
   cout<<mergeSort(arr, 0, arr.size()-1)<<endl;
   for(int i=0;i<arr.size();i++){
       cout<<arr[i]<<endl;
   }

    return 0;
}