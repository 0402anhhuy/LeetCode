#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &h, vector<vector<bool>> &visited, int r, int c){
    int m = h.size(), n = h[0].size();
    visited[r][c] = true;

    vector<pair<int, int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    for(auto [dr, dc] : dirs){
        int nr = r + dr, nc = c + dc;
        if(nr < 0 || nr >= m || nc < 0 || nc >= n){
            continue;
        }

        if(visited[nr][nc]) continue;
        if(h[nr][nc] < h[r][c]){
            continue;
        }
        dfs(h, visited, nr, nc);
    }
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights){
    int m = heights.size(), n = heights[0].size();
    vector<vector<bool>> pacific(m, vector<bool>(n, 0));
    vector<vector<bool>> atlantic(m, vector<bool>(n, 0));

    for(int i = 0; i < m; i++){
        dfs(heights, pacific, i, 0);
        dfs(heights, atlantic, i, n - 1);
    }

    for(int j = 0; j < n; j++){
        dfs(heights, pacific, 0, j);
        dfs(heights, atlantic, m - 1, j);
    }

    vector<vector<int>> res;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(pacific[i][j] && atlantic[i][j]){
                res.push_back({i, j});
            } 
        }
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    #ifndef ONLINE_JUDGE
        freopen("D:/AnhHuy/Code/C++/input.inp", "r", stdin);
        freopen("D:/AnhHuy/Code/C++/output.out", "w", stdout);
    #endif
      
    int m, n; cin >> m >> n;
    vector<vector<int>> heights(m, vector<int>(n));

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> heights[i][j];
        }
    }

    vector<vector<int>> ans = pacificAtlantic(heights);
    for(auto n : ans){
        cout << n[0] << " " << n[1] << endl;
    }
    return 0;
}