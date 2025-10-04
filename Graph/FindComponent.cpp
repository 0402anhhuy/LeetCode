#include<bits/stdc++.h>
using namespace std;

void bfs(int start, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& component){
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while(!q.empty()){
        int u = q.front();
        q.pop();
        component.push_back(u);

        for(int v : adj[u]){
            if(!visited[v]){
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main(){
    int n = 7;
    vector<vector<int>> adj(n);

    auto addEdge = [&](int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    };

    addEdge(0, 1);
    addEdge(1, 2);
    addEdge(3, 4);
    addEdge(5, 6);

    vector<bool> visited(n, false);
    vector<vector<int>> components;

    for(int i = 0; i < n; i++){
        if(!visited[i]){
            vector<int> component;
            bfs(i, adj, visited, component);
            components.push_back(component);
        }
    }

    cout << "So thanh phan lien thong: " << components.size() << "\n";
    for(int i = 0; i < components.size(); i++){
        cout << "Thanh phan " << i + 1 << ": ";
        for(int v : components[i]) cout << v << " ";
        cout << "\n";
    }
}
