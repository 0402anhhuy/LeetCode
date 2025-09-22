#include<bits/stdc++.h>
using namespace std;

/*
    LeetCode: 2352. Equal Row and Column Pairs
    Ý tưởng:
        - Ta tạo một map mp để lưu số lần xuất hiện của mỗi hàng.
        - Ta duyệt qua mảng grid, với mỗi hàng grid[i] ta thêm grid[i] vào map mp.
        - Ta tạo một biến res để lưu kết quả.
        - Ta duyệt qua mảng grid, với mỗi cột j ta tạo một mảng tmp để lưu giá trị của cột j.
        - Ta tăng res lên giá trị của mp[tmp].
        - Cuối cùng ta trả về res.
*/

int equalPairs(vector<vector<int>> grid){
    int res = 0;
    map<vector<int>, int> mp;
    for(int i = 0; i < grid.size(); i++){
        mp[grid[i]]++;
    }

    for(int i = 0; i < grid.size(); i++){
        vector<int> tmp;
        for(int j = 0; j < grid.size(); j++){
            tmp.push_back(grid[j][i]);
        }
        res += mp[tmp];
    }
    return res;
}

int main(){
    int n; cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }
    int res = equalPairs(grid);
    cout << res;
    return 0;
}