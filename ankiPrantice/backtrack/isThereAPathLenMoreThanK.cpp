#include <bits/stdc++.h>

using namespace std;

class Graph{
    public:
    int V;
    vector<vector<pair<int,int>>> adj;
    Graph(int V){
        this->V = V;
        this->adj.resize(this->V);
    }
    void addEdge(int u, int v, int w){
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    bool pathUtil(vector<vector<pair<int,int>>>& adj, vector<bool>& vis, int src, int k){
        if (k < 0) return true;

        //vector<pair<int,int>>::iterator i;
        //for(i = adj[src].begin(); i != adj[src].end(); ++i){
        for(auto &listEdge : adj[src]){
            int v = listEdge.first;

            int w = listEdge.second;

            if (vis[v] == true) continue;
            if (w >= k) return true;
            vis[v] = true;
            if (pathUtil(adj,vis,v,k-w)) {
                return true;
            }
            vis[v] = false;
        }
        return false;
    }
    bool pathMoreThanK(int src, int k){
        vector<bool> vis(this->V,false);

        vis[src] = true;
        return pathUtil(this->adj,vis,src,k);

    }

};

int main(){
    int V = 9;
    Graph g(V);
    g.addEdge(0,1,4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    int src = 0;
    int k = 60;
    g.pathMoreThanK(src,k) ? cout<<"yes\n" : cout<<"no\n";
    return 0;
}
