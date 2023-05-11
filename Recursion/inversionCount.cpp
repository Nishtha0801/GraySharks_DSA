#include <iostream>
#include<vector>

using namespace std;

long long int merge(long long arr[], long long int si, long long int ei){
        long long int mid = (si+ei)/2;
        long long int count = 0;
         long long int i = si;
         long long int j = mid + 1;
        
        vector<long long>temp(ei-si+1, 0);
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


long long int mergeSort(long long arr[], long long int si, long long int ei){
    long long int count = 0;
    
    if(si < ei){
        long long int mid = (si+ei)/2;
       count+=mergeSort(arr, si, mid);
       count+=mergeSort(arr, mid+1, ei);
        
       count+=merge(arr, si, ei);
    }
    return count;
}
    long long int inversionCount(long long arr[], long long N)
    {
        return mergeSort(arr, 0, N-1);
    }