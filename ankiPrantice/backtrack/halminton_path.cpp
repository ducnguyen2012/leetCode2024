#include <bits/stdc++.h>
const int V = 5;
using namespace std;

bool isSafe(vector<vector<bool>>& graph, int v, vector<int>& path, int pos){
    if (graph[path[pos-1]][v] == 0) return false; // neu khong co duong di truc tiep tu
    // dinh hien tai trong path toi v, thi khong the backtrack duoc dinh nay

    for(int i = 0; i < pos; ++i){
        if (path[i] == v) { // neu truoc do da tung tham dinh v -> khong duoc backtrack dinh nay nua
            return false;
        }

    }


    return true;
}



bool backtrack(vector<vector<bool>>& graph, int s, int pos, vector<int>& path){
    if (pos == V){
            if (graph[path[pos-1]][path[0]] == 1){
            return true;
    } else {
    return false;}
    }


    for(int v = 0; v < V; ++v){
        if (isSafe(graph,v,path,pos)){
            path[pos] = v;
            if (backtrack(graph,v,pos+1,path) == true) return true;
            path[pos] = -1;
        }
    }
    return false;
}
void printSolution(vector<vector<bool>>& graph, vector<int>& path){
    for(int i = 0; i < V; ++i){
        cout<<path[i]<<" ";
    }
    cout<<"\n";
}
void hamCycle(vector<vector<bool>>& graph, int s){

    vector<int> path(V,-1);

    path[0] = s;
    if (backtrack(graph,s,1,path) == false) {
        cout<<"no solution!"<<"\n";

    } else {
        printSolution(graph,path);
        cout<<path[0]<<"\n" // this cout is for complete path
    }



}






int main(){
    vector<vector<bool>> graph1 = {{0, 1, 0, 1, 0},
                        {1, 0, 1, 1, 1},
                        {0, 1, 0, 0, 1},
                        {1, 1, 0, 0, 1},
                        {0, 1, 1, 1, 0}};

    // Print the solution
    hamCycle(graph1,0);

    /* Let us create the following graph
        (0)--(1)--(2)
        |     / \   |
        |    /      \  |
        | /      \ |
        (3)       (4) */
    vector<vector<bool>> graph2 = {{0, 1, 0, 1, 0},
                         {1, 0, 1, 1, 1},
                         {0, 1, 0, 0, 1},
                         {1, 1, 0, 0, 0},
                         {0, 1, 1, 0, 0}};

    // Print the solution
    hamCycle(graph2,0);
    return 0;
}
