// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Edge
{
public:
    int v = 0;
    int w = 0;

    Edge(int v, int w)
    {
        this->v = v;
        this->w = w;
    }
};

int N = 7;
vector<vector<Edge>> graph(N, vector<Edge>());

void addEdge(int u, int v, int w)
{
    graph[u].push_back(Edge(v, w));
    graph[v].push_back(Edge(u, w));
}

// display ============

void display()
{
    for (int i = 0; i < N; i++)
    {
        cout << (to_string(i) + "->");
        for (Edge e : graph[i])
        {
            cout << "(" + to_string(e.v) + "," + to_string(e.w) + ")";
        }
        cout << endl;
    }
}

int searchVtx(int u, int v){
    for(int i=0;i<graph[u].size(); i++){
        Edge e = graph[u][i];
        if(e.v == v){
            return i;
        }
    }
    return -1;
}

void removeEdge(int u, int v){
    int l1 = searchVtx(u,v);
    graph[u].erase(graph[u].begin() + l1);
    
    int l2 = searchVtx(v,u);
     graph[v].erase(graph[v].begin() + l2);
}

void removeVtx(int u){
    for(int i= graph[u].size()-1; i>=0;i--){
        Edge e = graph[u][i];
        removeEdge(u, e.v);
    }
}

bool hasPath(int src, int dest, vector<bool>&vis){
    // try krengeee
    if(src == dest){
        return true;
    }
    
    vis[src] = true;
    bool res = false;
    // to traverse over the neighbours
    for(Edge e : graph[src]){
        if(!vis[e.v]){
            res = res || hasPath(e.v, dest, vis);
        }
    }
    return res;
}

//psf -> path so far
int allPaths(int src, int dest, vector<bool>&vis, string psf, int wsf){
    // try krengeeee
    if(src == dest){
        cout<<psf + to_string(src) + "@ " + to_string(wsf) <<endl;
        return 1;
    }
    
    int count = 0;
    vis[src] = true;
    for(Edge e: graph[src]){
        if(!vis[e.v]){
            count+=allPaths(e.v, dest, vis, psf+to_string(src)+" ", wsf+e.w);
        }
    }
    vis[src] = false;
    return count;
}


//minimumWeight and maximumWeight vale path btane h?

pair<string, int> maxWeightPath(int src, int dest, vector<bool>&vis){
    if(src == dest){
        return {to_string(src)+ " ", 0};
    }
    
    vis[src] = true;
    
    pair<string, int>myAns = {"", -1};
    
    for(Edge e: graph[src]){
        if(!vis[e.v]){
            pair<string, int>recAns = maxWeightPath(e.v, dest, vis);
            
            if(recAns.second != -1 && recAns.second + e.w > myAns.second){
                myAns.second = recAns.second + e.w;
                myAns.first = to_string(src) + " " + recAns.first;
            }
        }
    }
    vis[src] = false;
    return myAns;
}

int hamintonianPath(int src, int osrc, vector<bool>&vis, int edgeCount, string psf){
    
    if(edgeCount == N-1){
        psf+=to_string(src);
        int idx = searchVtx(src, osrc);
        if(idx!=-1){
            cout<<"Cycle:"<<psf<<endl;
 
        } else {
            cout<<"Path: "<<psf<<endl;
        }
        
        return 1;
    }
    
    vis[src] = true;
    int count = 0;
    for(Edge e : graph[src]){
        if(!vis[e.v]){
            count+=hamintonianPath(e.v, osrc, vis,edgeCount+1, psf+to_string(src) + " ");
        }
    }
    vis[src] = false;
    return count;
}


void constructGraph()
{
    addEdge(0, 1, 10);
    addEdge(0, 3, 10);
    addEdge(1, 2, 10);
    addEdge(2, 3, 40);
    addEdge(3, 4, 2);
    addEdge(4, 5, 2);
    addEdge(4, 6, 8);
    addEdge(5, 6, 3);

    display();
}

//BFS ====================================
void BFS_01(int src, vector<bool>&vis){
    queue<int>que;
    
    que.push(src);
    
    bool cycle = false;
    while(que.size()!=0){
        int vtx = que.front();
        que.pop();
        
        cout<<vtx<<" "<<endl;
        
        if(vis[vtx]){
            cycle = true;
            continue;
        }
        
        vis[vtx] = true;
        for(Edge e : graph[vtx]){
            if(!vis[e.v]){
                que.push(e.v);
            }
        }
    }
}

// Delimiter method
void BFS_02(int src, int dest, vector<bool>&vis){
    queue<int>que;
    que.push(src);
    que.push(-1);
    
    bool cycle = false;
    int level = 0;
    
    while(que.size() != 1){
        int vtx = que.front();
        que.pop();
        
        if(vis[vtx]){
            cycle = true;
            continue;
        }
        
        if(vtx == dest){
            cout<<level;
        }
        
        vis[vtx] = true;
        for(Edge e: graph[vtx]){
            if(!vis[e.v]){
                que.push(e.v);
            }
        }
        
        if(que.front() == -1){
            level++;
            que.pop();
            que.push(-1);
        }
    }
}


//automatically cycle handle ho jaegi
void BFS_03(int src, vector<bool>&vis, vector<int>&dis){ //size wala method
   queue<int>que;
   que.push(src);
   
   vis[src] = true;
   
   int level = 0;

   
   while(que.size() != 0){
       int size = que.size();
       while(size-- > 0){
           int vtx = que.front();
           que.pop();
           dis[vtx] = level;
           
           for(Edge e: graph[vtx]){
               if(!vis[e.v]){
                   vis[e.v] = true;
                   que.push(e.v);
               }
           }
       }
       level++;
   }
}

int main()
{
    constructGraph();
    vector<bool>vis(N,false);
     vector<int>dis(N,0);
    // cout<<hasPath(0,6,vis)<<endl;
   // cout<<allPaths(0,6,vis,"",0);
    // removeEdge(3,4);
    // cout<<endl;
    // display();
    // removeVtx(3);
    // cout<<endl;
    // display();
    
    // pair<string, int> ans = maxWeightPath(0, 6, vis);
    
    // cout<<ans.first<<"@"<<ans.second<<endl;
    
    // cout<<hamintonianPath(0, 0, vis, 0, "")<<endl;
    
    // BFS_01(0, vis);
    // BFS_02(0, 6, vis);
    
    BFS_03(0, vis, dis);
    
    for(int ele : dis){
        cout<<ele<<" ";
    }
    
    
    
    return 0;
}