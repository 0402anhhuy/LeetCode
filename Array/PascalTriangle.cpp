#include<bits/stdc++.h>
using namespace std;

/*
    LeetCode: 118. Pascal's Triangle
    Ý tưởng:
        - Ta tạo mảng 2 chiều res với số hàng là numRows.
        - Duyệt qua mảng res, với mỗi hàng i ta tạo mảng con với i + 1 phần tử và gán giá trị của mảng con đó bằng 1.
        - Duyệt qua mảng con, với mỗi phần tử j từ 1 đến i - 1 ta gán giá trị của phần tử đó bằng tổng của phần tử ở hàng trên và cùng cột với phần tử đó và phần tử ở hàng trên và cột trước phần tử đó.
        - Cuối cùng ta trả về mảng res.
*/

vector<vector<int>> generate(int numRows){
    vector<vector<int>> res(numRows);
    for(int i = 0; i < numRows; i++){
        res[i].resize(i + 1, 1);
        for(int j = 1; j < i; j++){
            res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
        }
    }
    return res;
}

void printPascalTriangle(vector<vector<int>> nums){
    for(int i = 0; i < nums.size(); i++){
        for(int num : nums[i]){
            cout << num << " ";
        }
        cout << endl;
    }
}

int main(){
    int numRows; cin >> numRows;
    vector<vector<int>> res = generate(numRows);
    printPascalTriangle(res);
    return 0;
}