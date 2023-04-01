// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <algorithm>

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
int maximum(vector<vector<int>> &res)
{
    int maxEle = -(int)1e9;
    for (vector<int> vec : res)
    {
        for (int ele : vec)
        {
            maxEle = max(maxEle, ele);
        }
    }
    return maxEle;
}

// minimum ele
int minimum(vector<vector<int>> &res)
{
    int minEle = (int)1e9;
    for (vector<int> vec : res)
    {
        for (int ele : vec)
        {
            minEle = min(minEle, ele);
        }
    }
    return minEle;
}

// find data
bool find(vector<vector<int>> &res, int target)
{
    for (vector<int> vec : res)
    {
        for (int ele : vec)
        {
            if (ele == target)
            {
                return true;
            }
        }
    }
    return false;
}

void waveTraversalLeftRight(vector<vector<int>> &res)
{
    int m = res.size();
    int n = res[0].size();
    for (int i = 0; i < m; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < n; j++)
            {
                cout << res[i][j] << " ";
            }
        }
        else
        {
            for (int j = n - 1; j >= 0; j--)
            {
                cout << res[i][j] << " ";
            }
        }
    }
}

// leetcode 867
vector<vector<int>> transpose(vector<vector<int>> &arr)
{
    vector<vector<int>> ans(arr[0].size(), vector<int>(arr.size(), 0));
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            ans[j][i] = arr[i][j];
        }
    }
    return ans;
}

// leetcode 498
vector<int> findDiagonalOrder(vector<vector<int>> &arr)
{

    int n = arr.size();
    int m = arr[0].size();
    vector<int> ans(n * m, 0);
    int row = 0;
    int col = 0;
    int dir = 1;
    for (int i = 0; i < ans.size(); i++)
    {
        ans[i] = arr[row][col];
        if (dir == 1)
        { // diagonal
            if (col == m - 1)
            {
                row++;
                dir = -1;
            }
            else if (row == 0)
            {
                col++;
                dir = -1;
            }
            else
            {
                row--;
                col++;
            }
        }
        else
        { // anti-diagonal
            if (row == n - 1)
            {
                col++;
                dir = 1;
            }
            else if (col == 0)
            {
                row++;
                dir = 1;
            }
            else
            {
                row++;
                col--;
            }
        }
    }
    return ans;
}

//leetcode 54
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int left = 0;
        int right = m-1;
        int top = 0;
        int bottom = n-1;
        
        vector<int> ans;
        int dir = 1;
        while(left<=right && top<=bottom){
            if(dir == 1){
                for(int i=left; i<=right;i++){
                    ans.push_back(matrix[top][i]);
                }
                dir = 2;
                top++;
            }
            else if(dir == 2){
                for(int i=top; i<=bottom; i++){
                    ans.push_back(matrix[i][right]);
                }
                dir = 3;
                right--;
            } 
            else if(dir == 3){
                for(int i=right; i>=left; i--){
                    ans.push_back(matrix[bottom][i]);
                }
                dir = 4;
                bottom--;
            }
            else if(dir == 4){
                for(int i=bottom; i>=top;i--){
                    ans.push_back(matrix[i][left]);
                }
                dir = 1;
                left++;
            }
        }
        return ans;
    }

int main()
{

    int m = 2;
    int n = 3;
    // vector<vector<int>> res(m, vector<int>(n, 0));
    // input(res,m,n);
    vector<vector<int>> res = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };
    display(res);
    cout << maximum(res) << endl;
    waveTraversalLeftRight(res);
    return 0;
}