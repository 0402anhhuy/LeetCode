#include<bits/stdc++.h>
using namespace std;

int diagonalSum(vector<vector<int>>& mat) {
    int n = mat.size(), ans = 0;
    for(int i = 0; i < n; i++){
        ans += (mat[i][i] + mat[i][n - 1 - i]);
    }

    if(n % 2 != 0) ans -= mat[n / 2][n / 2];
    return ans;
}

int main(){
    int n; cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }

    int ans = diagonalSum(grid);
    cout << ans;
    return 0;
}