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

// leetcode 695

class Solution {
public:

        int maxAreaOfIslandDFS(vector<vector<int>>& grid, int r, int c, vector<vector<int>>&dir){
        grid[r][c] = 0;
        int count = 0;
        for(int d=0; d<dir.size(); d++){
            int x = r + dir[d][0];
            int y = c + dir[d][1];

            if(x>=0 && y>=0 && x<grid.size() && y<grid[0].size() && grid[x][y] == 1){
                count+=maxAreaOfIslandDFS(grid, x, y, dir); 
            }
        }
        return count+1;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<int>>dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        int maxArea = 0;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 1){
                    maxArea = max(maxArea, maxAreaOfIslandDFS(grid, i, j, dir));
                    
                }
            }
        }
        return maxArea;
    }
};

// leetcode 785
    bool isBipartite(vector<vector<int>>& graph, vector<int>&markedColor, int src) {
        queue<int>que;
        que.push(src);

        int color = 0;
        while(que.size() != 0){
            int size = que.size();

            while(size-- > 0){
                int vtx = que.front();
                que.pop();

                if(markedColor[vtx] != -1){
                    if(markedColor[vtx] != color){
                        return false;
                    }
                    continue;
                }

                markedColor[vtx] = color;
                for(int e: graph[vtx]){
                    if(markedColor[e] == -1){
                        que.push(e);
                    }
                }
            }
            color = (color+1)%2;
        }

        return true;

    }


    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>markedColor(n, -1);

        bool ans = true;
        for(int i=0;i<n;i++){
            if(markedColor[i] == -1){
                ans = isBipartite(graph, markedColor,i);

                if(!ans){
                    return false;
                }
            }
        }
        return true;
    }

    //leetcode 1091

        int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0){
            return -1;
        }

        int n = grid.size();
        int m = grid[0].size();

        if(grid[0][0] == 1 || grid[n-1][m-1]){
            return -1;
        }

        queue<int>que;
        // idx = r*m+c
        que.push(0*m + 0);

        grid[0][0] = 1;

        vector<vector<int>>dir = {{1,0}, {-1,0}, {0,1}, {0,-1}, {1,1}, {-1, -1}, {-1,1}, {1,-1}};

        int level = 1;
        while(que.size() != 0){
            int size = que.size();
            while(size-- > 0){
                int idx = que.front();
                que.pop();

                int r = idx/m;
                int c = idx%m;

                if(r == n-1 && c == m-1){
                    return level;
                }

                for(int d=0;d<8;d++){
                    int x = r + dir[d][0];
                    int y = c + dir[d][1];

                    if(x>=0 && y>=0 && x<n && y<m && grid[x][y] == 0){
                        grid[x][y] = 1;
                        que.push(x*m+y);
                    }
                }
            }
            level++;
        }

        return -1;
    }

    // leetcode 994
       int orangesRotting(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0){
            return 0;
        }

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};

        queue<int>que;
        int frOranges = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    que.push(i*m+j);
                }
                if(grid[i][j] == 1){
                    frOranges++;
                }
            }
        }

        if(frOranges == 0){
            return 0;
        }

        int time = 0;
        while(que.size() != 0){
            int size = que.size();
            while(size-- > 0){
                int idx = que.front();
                que.pop();
                int r = idx/m;
                int c = idx%m;

                for(int d = 0; d<4;d++){
                    int x = r + dir[d][0];
                    int y = c + dir[d][1];

                    if(x>=0 && y>=0 && x<n && y<m && grid[x][y] == 1){
                        grid[x][y] = 2;
                        frOranges--;
                        que.push(x*m+y);

                        if(frOranges == 0){
                            return time+1;
                        }
                    }
                }
            }
            time++;
        }
        return -1;

    }

    // leetcode 207
    class Solution {
public:
    bool canFinish(int N, vector<vector<int>>& arr) {
        // kahn's algo!
        vector<vector<int>>graph(N, vector<int>());

        vector<int>indegree(N, 0);

        for(vector<int> a: arr){
            indegree[a[1]]++;
            graph[a[0]].push_back(a[1]);
        }

        queue<int>que;
        for(int i=0;i<N;i++){
            if(indegree[i] == 0){
                que.push(i);
            }
        }

        int count = 0;
        while(que.size() != 0){
            int vtx = que.front();
            que.pop();
            count++;

            for(int e : graph[vtx]){
                if(--indegree[e] == 0){
                    que.push(e);
                }
            }
        }

        return count == N;

    }
};

// leetcode 210
class Solution {
public:
    vector<int> findOrder(int N, vector<vector<int>>& arr) {
        vector<vector<int>>graph(N, vector<int>());

        vector<int>indegree(N, 0);
        for(vector<int>a : arr){
            indegree[a[1]]++;
            graph[a[0]].push_back(a[1]);
        }

        queue<int>que;
        for(int i=0;i<N;i++){
            if(indegree[i] == 0){
                que.push(i);
            }
        }

        vector<int>ans(N, 0);
        int idx = N-1;
        while(que.size() != 0){
            int vtx = que.front();
            que.pop();

            ans[idx--] = vtx;
            for(int e: graph[vtx]){
                if(--indegree[e] == 0){
                    que.push(e);
                }
            }
        }
        
        if(idx == -1){
            return ans;
        }

        return {};
    }
};