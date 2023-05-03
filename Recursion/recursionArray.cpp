// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>

using namespace std;

void display(vector<int> &arr, int idx)
{
    if (idx == arr.size())
    {
        return;
    }
    cout << arr[idx] << endl;
    display(arr, idx + 1);
}

int maximum(vector<int> &arr, int idx)
{
    if (idx == arr.size() - 1)
    {
        return arr[idx];
    }
    return max(maximum(arr, idx + 1), arr[idx]);
}

bool find(vector<int> &arr, int idx, int data)
{
    if (idx == arr.size())
    {
        return false;
    }
    if (arr[idx] == data)
    {
        return true;
    }
    return find(arr, idx + 1, data);
}

int lastIdx(vector<int> &arr, int idx, int data)
{

    if (idx == arr.size())
    {
        return -1;
    }

    int ans = lastIdx(arr, idx + 1, data);
    if (ans != -1)
    {
        return ans;
    }

    return arr[idx] == data ? idx : -1;
}

int mazePath(int sr, int sc, int er, int ec, string ans)
{

    if (sr == er && sc == ec)
    {
        cout << ans << endl;
        return 1;
    }
    int count = 0;
    if (sc + 1 <= ec)
    {
        count += mazePath(sr, sc + 1, er, ec, ans + "H");
    }
    if (sr + 1 <= er)
    {
        count += mazePath(sr + 1, sc, er, ec, ans + "V");
    }
    if (sr + 1 <= er && sc + 1 <= ec)
    {
        count += mazePath(sr + 1, sc + 1, er, ec, ans + "D");
    }
    return count;
}

int mazePathWithJumps(int sr, int sc, int er, int ec, string ans)
{
    if (sr == er && sc == ec)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;
    for (int jump = 1; sc + jump <= ec; jump++)
    {
        count += mazePathWithJumps(sr, sc + jump, er, ec, ans + "H" + to_string(jump));
    }

    for (int jump = 1; sr + jump <= er; jump++)
    {
        count += mazePathWithJumps(sr + jump, sc, er, ec, ans + "V" + to_string(jump));
    }

    for (int jump = 1; sr + jump <= er && sc + jump <= ec; jump++)
    {
        count += mazePathWithJumps(sr + jump, sc + jump, er, ec, ans + "D" + to_string(jump));
    }

    return count;
}

void floodfill(vector<vector<int>> maze, int sr, int sc, string asf,
               vector<vector<bool>> vis)
{
    if (sr == maze.size() - 1 && sc == maze[0].size() - 1)
    {
        cout << asf << endl;
        return;
    }

    if (sr < 0 || sc < 0 || sr >= maze.size() || sc >= maze[0].size() || vis[sr][sc] == true)
    {
        return;
    }

    vis[sr][sc] = true;
    floodfill(maze, sr - 1, sc, asf + "t", vis);
    floodfill(maze, sr, sc - 1, asf + "l", vis);
    floodfill(maze, sr + 1, sc, asf + "d", vis);
    floodfill(maze, sr, sc + 1, asf + "r", vis);
    vis[sr][sc] = false;
}

int coinChangePermutationR(vector<int> coins, int tar, string ans)
{
    if (tar == 0)
    {
        cout << ans << endl;
        return 1;
    }
    int count = 0;
    for (int i = 0; i < coins.size(); i++)
    {
        if (tar - coins[i] >= 0)
        {
            count += coinChangePermutationR(coins, tar - coins[i], ans + to_string(coins[i]));
        }
    }
    return count;
}

int coinChangeCombinationR(vector<int> coins, int idx, int tar, string ans)
{
    if (tar == 0)
    {
        cout << ans << endl;
        return 1;
    }
    int count = 0;
    for (int i = idx; i < coins.size(); i++)
    {
        if (tar - coins[i] >= 0)
        {
            count += coinChangeCombinationR(coins, i, tar - coins[i], ans + to_string(coins[i]));
        }
    }
    return count;
}

int coinChangeCombinationWR(vector<int> coins, int idx, int tar, string ans)
{
    if (tar == 0)
    {
        cout << ans << endl;
        return 1;
    }
    int count = 0;
    for (int i = idx; i < coins.size(); i++)
    {
        if (tar - coins[i] >= 0)
        {
            count += coinChangeCombinationWR(coins, i + 1, tar - coins[i], ans + to_string(coins[i]));
        }
    }
    return count;
}

    int coinChangePermutationWR(vector<int>coins, int tar, vector<bool>vis, string ans){
     if(tar == 0){
         cout<<ans<<endl;
         return 1;
     }
     int count = 0;
      for(int i=0;i<coins.size();i++){
          if(tar-coins[i] >= 0 && !vis[i]){
              vis[i] = true;
              count+=coinChangePermutationWR(coins, tar-coins[i],vis, ans+to_string(coins[i]));
              vis[i] = false;
          }
      }
      return count;
  }

int main()
{
    // Write C++ code here
    vector<int> arr = {2, 3, 4, 5, 6, 7, 8};
    display(arr, 0);
    cout << maximum(arr, 0) << endl;
    cout << find(arr, 0, 4546);
    cout << mazePath(0, 0, 2, 2, "");
    cout << mazePathWithJumps(0, 0, 2, 2, "");
    int n = 4;
    int m = 4;

    vector<vector<int>> maze(n, vector<int>(m));
    vector<vector<bool>> visited(n, vector<bool>(m));

    floodfill(maze, 0, 0, "", visited);
    return 0;
}