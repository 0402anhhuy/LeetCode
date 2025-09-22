#include<bits/stdc++.h>
using namespace std;

int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
    int n = grid.size();

    vector<int> rowMax, colMax;
    for(int i = 0; i < n; i++){
        int row = 0, col = 0;
        for(int j = 0; j < n; j++){
            row = max(row, grid[i][j]);
        }

        for(int k = 0; k < n; k++){
            col = max(col, grid[k][i]);
        }
            
        rowMax.push_back(row);
        colMax.push_back(col);
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int temp = min(rowMax[i], colMax[j]);
            ans += (temp - grid[i][j]);
        }
    }
    return ans;
}

int main(){
    int n; cin >> n;
    vector<vector<int>> grid (n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }

    int ans = maxIncreaseKeepingSkyline(grid);
    cout << ans;
    return 0;
}