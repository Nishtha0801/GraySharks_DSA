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

int N = 14;
vector<vector<Edge>> graph(N, vector<Edge>());

void addEdge(int u, int v, int w)
{
    graph[u].push_back(Edge(v, w));
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

void topoDFS(int src, vector<bool>&vis, vector<int>&ans){
    vis[src] = true;
    for(Edge e : grapg[src]){
        if(!vis[e.v]){
            topoDFS(e.v, vis, ans);
        }
    }
    ans.push_back(src);
}

void topoDFS(){
    vector<int>ans;
    vector<bool>vis(N,0);
    for(int i=0;i<N;i++){
        if(!vis[i]){
            topoDFS(i,vis,ans);
        }
    }
    
    //reverse
    //print
}

//BFS

void TopoBFS(){
    vector<int>ans;
    vector<int>indegree(N,0);
    
    for(int i=0; i<N;i++){
        for(Edge e : graph[i]){
            indegree[e.v]++;
        }
    }
    
    queue<int>que;
    for(int i=0;i<N;i++){
        if(indegree[i] == 0){
            que.push(i);
        }
    }
    
    while(que.size() != 0){
        int vtx = que.front();
        que.pop();
        
        ans.push_back(vtx);
        for(Edge e : graph[vtx]){
            if(--indegree[e.v] == 0){
                que.push(e.v);
            }
        }
    }
    
    if(ans.size() != N){
        cout<<"There is a cycle"<<endl;
    } else {
        cout<<"No cycle"<<endl;
    }
    
    return;
}



int main()
{
  
    
    
    return 0;
}