// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

void input(vector<vector<int>> &res, int m, int n)
{
    // input
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> res[i][j];
        }
    }
}

void display(vector<vector<int>> &res)
{
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[0].size(); j++)
        {
            cout << res[i][j];
        }
        cout << endl;
    }
}

// maximum ele 
int maximum(vector<vector<int>> &res){
    int maxEle = -(int)1e9;
    for(vector<int>vec : res){
        for(int ele: vec){
            maxEle = max(maxEle,ele);
        }
    }
    return maxEle;
}

// minimum ele
int minimum(vector<vector<int>> &res){
    int minEle = (int)1e9;
    for(vector<int>vec : res){
        for(int ele: vec){
            minEle = min(minEle,ele);
        }
    }
    return minEle;
}

// find data
bool find(vector<vector<int>> &res, int target){
    for(vector<int>vec : res){
        for(int ele: vec){
            if(ele == target){
                return true;
            }
        }
    }
    return false;
}

void waveTraversalLeftRight(vector<vector<int>> &res){
    int m = res.size();
    int n = res[0].size();
    for(int i=0;i<m;i++){
        if(i%2 == 0){
            for(int j=0;j<n;j++){
                cout<<res[i][j]<<" ";
            }
        } else {
            for(int j=n-1;j>=0;j--){
                cout<<res[i][j]<<" ";
            }
        }
    }

}


int main()
{
    
    int m = 2;
    int n = 3;
    // vector<vector<int>> res(m, vector<int>(n, 0));
    // input(res,m,n);
    vector<vector<int>>res = {
      {1,2,3},
      {4,5,6},
      {7,8,9},  
    };
    display(res);
    cout<<maximum(res)<<endl;
    waveTraversalLeftRight(res);
    return 0;
}