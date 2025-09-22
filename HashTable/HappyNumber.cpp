#include<bits/stdc++.h>
using namespace std;

/*
    LeetCode: 202. Happy Number
    Ý tưởng:
        - Ta tạo một hàm sumOfSquares để tính tổng bình phương của các chữ số của n.
        - Ta tạo một unordered_set res để lưu các giá trị đã xuất hiện.
        - Ta duyệt qua n, nếu n != 1 thì ta kiểm tra n đã xuất hiện trong res chưa, nếu có thì trả về false.
        - Nếu không thì ta thêm n vào res và cập nhật n = sumOfSquares(n).
        - Cuối cùng ta trả về true.
*/

int sumOfSquares(int n){
    int sum = 0;
    while(n != 0){
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }
    return sum;
}
bool isHappy(int n) {
    unordered_set<int> res;
    while(n != 1){
        if(res.count(n)){
            return false;
        }
        res.insert(n);
        n = sumOfSquares(n);
    }
    return true;
}

int main(){
    int n; cin >> n;
    bool res = isHappy(n);
    cout << boolalpha << res;
    return 0;
}