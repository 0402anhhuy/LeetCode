#include<bits/stdc++.h>
using namespace std;

/*
    Time complexity: O(m + n)
*/

int countNegatives(vector<vector<int>>& grid){
    int m = grid.size(), n = grid[0].size(), ans = 0;

    int i = m - 1, j = 0;
    while(i >= 0 && j < n){
        if(grid[i][j] < 0){
            ans += n - j;
            i--;
        }
        else{
            j++;
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