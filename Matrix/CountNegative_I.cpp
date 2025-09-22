#include<bits/stdc++.h>
using namespace std;

/*
    Time complexity: O(m * n)
*/

int countNegatives(vector<vector<int>>& grid){
    int m = grid.size(), n = grid[0].size(), ans = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] < 0){
                ans += n - j;
                break;
            }
        }
    }
    return ans;
}

int main(){
    int m, n; cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }
    int ans = countNegatives(grid);
    cout << ans;
    return 0;
}