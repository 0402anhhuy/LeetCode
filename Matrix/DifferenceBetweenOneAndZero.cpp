#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid){
    int m = grid.size(), n = grid[0].size();
    vector<int> oneRow(m), oneCol(n);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            oneRow[i] += grid[i][j];
            oneCol[j] += grid[i][j];
        }
    }

    vector<vector<int>> diff(m, vector<int>(n));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            diff[i][j] = 2 * (oneRow[i] + oneCol[j]) - m - n;
        }
    }
    return diff;
}

int main(){
    int m, n; cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }
    vector<vector<int>> ans = onesMinusZeros(grid);
    for(vector<int> num : ans){
        for(int n : num){
            cout << n << " ";
        }
        cout << "\n";
    }
    return 0;
}