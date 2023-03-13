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
void rotate(vector<int> &arr, int k){
    k = k % arr.size();

    int i = 0;
    int j = arr.size()-1;

    reverse(arr, i, j);
    reverse(arr, 0, k-1);
    reverse(arr, k, j);

    return;
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
void segregateZeroesAndOnes(vector<int> &arr){
    if(arr.size() == 0){
        return;
    }

    int p = -1;
    int idx = 0;
    int n = arr.size();

    while(idx < n){
        if(arr[idx] == 0){
            p++;
            swap(arr, p, idx);
        }
        idx++;
    }
    return;
}

void segregatePositiveAndNegative(vector<int> &arr){
    if(arr.size() == 0){
        return;
    }

    int p = -1;
    int idx = 0;
    int n = arr.size();

    while(idx < n){
        if(arr[idx] >= 0){
            p++;
            swap(arr, p, idx);
        }
        idx++;
    }
    return;
}

    void sortColors(vector<int>& arr) {
        if(arr.size() == 0){
            return;
        }
        int n = arr.size() ;
        int p1 = -1;
        int idx = 0;
        int p2 = n-1;

        while(idx <= p2){
            if(arr[idx] == 0){
                p1++;
                swap(arr, idx, p1);
                idx++;
            } else if(arr[idx] == 2){
                swap(arr, idx, p2);
                p2--;
            } else {
                idx++;
            }
        }
    }

    // 1480
     vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            ans[i] = sum;
        }
        return ans;
    }

    //1929
      vector<int> getConcatenation(vector<int>& nums) {
        vector<int>ans;
        int n = nums.size();
        for(int i=0;i<2*n;i++){
            ans.push_back(nums[i%n]);
        }
        return ans;
    }

    //1365
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            int count = 0;
            for(int j=0;j<n;j++){
                if(nums[j] < nums[i]){
                    count++;
                }
            }
            ans.push_back(count);
        }
        return ans;
    }

    //leetcode 215
    int findKthLargest(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end(), greater<int>());
        return arr[k-1];
    }

    // leetcode 34
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
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans(2);
        ans[0] = firstIndex(nums, target);
        ans[1] = lastIndex(nums, target);

        return ans;

    }



int main(){
    //Q1 Find an element in the array(arr, num)
    //q2 Find the minimum element in the array.
    //q3 Find the maximum element in the array.

    vector<int>myArr = {1,2,3,4,5,6,7};
    // vector<int>arr = {0,0,1,1,0,0,1,1,0,0,0};
    vector<int>arr = {4, -3, 6, 7, 2, -8, -9, 10, 11, 12, -19};
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
    // subArray(myArr);
    // rotate(myArr,8);
    // segregateZeroesAndOnes(arr);
    segregatePositiveAndNegative(arr);
    for(int i=0;i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    
}
