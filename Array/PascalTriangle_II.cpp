#include<bits/stdc++.h>
using namespace std;

/*
    LeetCode: 119. Pascal's Triangle II
    Ý tưởng:
        - Ta tạo mảng 2 chiều res với số hàng là rowIndex + 1.
        - Duyệt qua mảng res, với mỗi hàng i ta tạo mảng con với i + 1 phần tử và gán giá trị của mảng con đó bằng 1.
        - Duyệt qua mảng con, với mỗi phần tử j từ 1 đến i - 1 ta gán giá trị của phần tử đó bằng tổng của phần tử ở hàng trên và cùng cột với phần tử đó và phần tử ở hàng trên và cột trước phần tử đó.
        - Cuối cùng ta trả về hàng rowIndex của mảng res.
*/

vector<int> generate(int rowIndex){
    vector<vector<int>> res(rowIndex + 1);
    for(int i = 0; i < rowIndex + 1; i++){
        res[i].resize(i + 1, 1);
        for(int j = 1; j < i; j++){
            res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
        }
    }
    return res[rowIndex];
}

void printPascalTriangle(vector<int> nums){
    for(int num : nums){
        cout << num << " ";
    }
}

int main(){
    int numRows; cin >> numRows;
    vector<int> res = generate(numRows);
    printPascalTriangle(res);
    return 0;
}