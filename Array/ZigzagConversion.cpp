#include<bits/stdc++.h>
using namespace std;

/*
    LeetCode: 6. ZigZag Conversion
    Ý tưởng:
        - Ta tạo mảng rows với số hàng là numRows.
        - Ta duyệt qua chuỗi s, với mỗi ký tự c ta thêm ký tự c vào hàng hiện tại và cập nhật hàng hiện tại.
        - Nếu hàng hiện tại là hàng cuối cùng hoặc hàng hiện tại là hàng đầu tiên thì ta đảo chiều đi.
        - Cuối cùng ta trả về chuỗi res.
*/

string convert(string s, int numRows){
    if(numRows == 1 || numRows >= s.length()){
        return s;
    }

    int currentRow = 0;
    bool goingDown = false;

    vector<string> rows(numRows);
    for(char c : s){
        rows[currentRow] += c;
        if(currentRow == numRows - 1 || currentRow == 0){
            goingDown = !goingDown;
        }

        currentRow += goingDown ? 1 : -1;
    }

    string res = "";
    for(string row : rows){
        res += row;
    }
    return res;
}

int main(){
    string s; cin >> s;
    int numRows; cin >> numRows;
    string res = convert(s, numRows);
    cout << res;
    return 0;
}