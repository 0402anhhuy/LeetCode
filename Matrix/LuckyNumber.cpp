#include<bits/stdc++.h>
using namespace std;

vector<int> luckyNumbers(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();

    vector<int> rowMin, colMax, ans;
    for(int i = 0; i < m; i++){
        int row = INT_MAX;
        for(int j = 0; j < n; j++){
            row = min(row, matrix[i][j]);
        }
        rowMin.push_back(row);
    }

    for(int i = 0; i < n; i++){
        int col = INT_MIN;
        for(int j = 0; j < m; j++){
            col = max(col, matrix[j][i]);
        }
        colMax.push_back(col);
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(matrix[i][j] == rowMin[i] && matrix[i][j] == colMax[j]){
                ans.push_back(matrix[i][j]);
            }
        }
    }
    return ans;
}

int main(){
    int m, n; cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> matrix[i][j];
        }
    }
    vector<int> ans = luckyNumbers(matrix);
    for(int num : ans){
        cout << num << " ";
    }
    return 0;
}