#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int findElement(vector<int> &myArr, int num){
    for(int i=0;i<myArr.size();i++){
        if(myArr[i] == num){
            return i; // returning index here
        }
    }
    return -1; // element is not present in the array
}

int minimumElement(vector<int> &myArr){
    int minEle = (int)1e9;
    for(int i=0;i<myArr.size();i++){
        minEle = min(myArr[i], minEle);
    }
    return minEle;
}

int maximumElement(vector<int> &myArr){
    int maxEle = -(int)1e9;
    for(int i=0;i<myArr.size(); i++){
        maxEle = max(myArr[i], maxEle);
    }
    return maxEle;
}

void swap(vector<int> &arr, int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    return;
}
void reverse(vector<int> &arr, int si, int ei){
    while(si < ei){
        swap(arr,si,ei);
        si++;
        ei--;
    }

}

void addArrays(vector<int> &a, vector<int> &b){
    int n = a.size();
    int m = b.size();

    vector<int>res(max(n,m)+1, 0);

    int i = n-1;
    int j = m-1;
    int k = res.size() - 1;

    int carry = 0;
    while(k >= 0){
        int sum = carry;
        if(i >= 0){
            sum+=a[i];
            i--;
        }
        if(j >= 0){
            sum+=b[j];
            j--;
        }

        res[k] = sum%10;
        k--;
        carry = sum/10;
    }

    for(int i=0;i<res.size(); i++){
        cout<<res[i]<<" ";
    }

    return;
}

void subTwoArrays(vector<int> &a, vector<int> &b){
    int n = a.size();
    int m = b.size();
    int i = n-1;
    int j = m-1;
    vector<int>ans(max(n,m), 0);
    int k = ans.size() - 1;

    int borrow = 0;
    while(k>=0){
        int diff = borrow;
        if(i>=0){
            diff+=a[i];
            i--;
        } 
        if(j>=0){
            diff-=b[j];
            j--;
        }
        if(diff<0){
            diff+=10;
            borrow = -1;
        } else {
            borrow = 0;
        }
        ans[k] = diff;
        k--;
    }

    for(int i=0;i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }


}

void subArray(vector<int> &a){
    for(int i=0;i<a.size();i++){
        for(int j=i;j<a.size();j++){
            for(int k=i;k<=j;k++){
                cout<<a[k]<< " ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
}


int main(){
    //Q1 Find an element in the array(arr, num)
    //q2 Find the minimum element in the array.
    //q3 Find the maximum element in the array.

    vector<int>myArr = {1,2,3,4};
    vector<int>arr = {9,9};
    // for(int i=0; i<myArr.size();i++){
    //     cin>>myArr[i]; 
    // }

    // for(int i=0;i<myArr.size(); i++){
    //     cout<<myArr[i]<<" ";
    // }
    // cout<<endl;
    // cout<<findElement(myArr, 5);
    // cout<<minimumElement(myArr);
    // cout<<maximumElement(myArr);
    // swap(myArr, 0, myArr.size()-1);
    // reverse(myArr, 0, myArr.size()-1);
    //  for(int i=0;i<myArr.size(); i++){
    //     cout<<myArr[i]<<" ";
    // }
    // addArrays(myArr, arr);
    // subTwoArrays(myArr, arr);
    subArray(myArr);


    
}
