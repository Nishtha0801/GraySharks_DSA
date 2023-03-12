#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> mergeTwoSortedArrays(vector<int> &a, vector<int> &b){
    int n = a.size();
    int m = b.size();

    vector<int>ans(m+n);
    int i=0; // for first array
    int j=0; // for second array
    int k=0; // for the resultant array

    while(i<n && j<m){
        if(a[i] <= b[j]){
            ans[k] = a[i];
            i++;
            k++;
        } else {
            ans[k] = b[j];
            j++;
            k++;
        }
    }

    while(i < n){
        ans[k] = a[i];
        i++;
        k++;
    }

     while(j < m){
        ans[k] = b[j];
        j++;
        k++;
    }

    return ans;

}

int main(){
    vector<int>a = {1,3,4,5};
    vector<int>b = {2,4,6,8};
    vector<int> ans = mergeTwoSortedArrays(a,b);
    for(int ele : ans){
        cout<< ele << " ";
    }

    return 0;
}