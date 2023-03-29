// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>

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

int main()
{
    
    int m = 2;
    int n = 3;
    vector<vector<int>> res(m, vector<int>(n, 0));
    input(res,m,n);
    display(res);
    return 0;
}