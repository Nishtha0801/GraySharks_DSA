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

int binarySearch(vector<int> &arr, int data){
    int n = arr.size();
    int si = 0;
    int ei = n-1;

    while(si<=ei){
        int mid = (si + ei)/2;
        if(arr[mid] == data){
            return mid;
        } else if(arr[mid] > data){
            ei = mid-1;
        } else {
            si = mid+1;
        }
    }
    return -1;
}

int firstIndex(vector<int> &arr, int data){
    int si = 0;
    int ei = arr.size()-1;

    while(si <= ei){
        int mid = (si+ei)/2;
        if(arr[mid] == data){
            if(mid-1>=0 && arr[mid-1] == data){
                ei = mid-1;
            } else{
                return mid;
            }
        } else if(arr[mid] > data){
            ei = mid - 1;
        } else {
            si = mid+1;
        }
    }
    return -1;
}

int lastIndex(vector<int> &arr, int data){
    int si = 0, ei = arr.size()-1;
    while(si<=ei){
        int mid = (si+ei)/2;
        if(arr[mid] == data){
            if(mid+1 < arr.size() && arr[mid+1] == data){
                si=mid+1;
            } else {
                return mid;
            }
        } else if(arr[mid] > data){
            ei = mid-1;
        } else {
            si = mid+1;
        }
    }
    return -1;
}



int main(){
   
    vector<int>myArr = {1,2,2,2,2,2,3,4,5,6,7,8,9,9,9,9};
    int data = 9;

    // cout<<linearSearch(myArr, data)<<endl;
    // cout<<binarySearch(myArr, data)<<endl;
    // cout<<firstIndex(myArr, data);
    cout<<lastIndex(myArr, data);
}