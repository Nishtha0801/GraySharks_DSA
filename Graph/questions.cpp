// leetcode 200

class Solution {
public:

    void numIslandsDFS(vector<vector<char>>& grid, int r, int c, vector<vector<int>>&dir){
        grid[r][c] = '0';

        for(int d=0; d<dir.size(); d++){
            int x = r + dir[d][0];
            int y = c + dir[d][1];

            if(x>=0 && y>=0 && x<grid.size() && y<grid[0].size() && grid[x][y] == '1'){
                numIslandsDFS(grid, x, y, dir); 
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>>dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};

        int count = 0;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == '1'){
                    numIslandsDFS(grid, i, j, dir);
                    count++;
                }
            }
        }
        return count;
    }
};