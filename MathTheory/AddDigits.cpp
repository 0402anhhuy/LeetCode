#include<bits/stdc++.h>
using namespace std;

/*
    LeetCode - 258. Add Digits
    Ý tưởng:
        - Tổng các chữ số của N có cùng giá trị dư khi chia 9 như N ban đầu
*/

int addDigits(int num){
    if(num == 0) return 0;
    else if(num % 9 == 0) return 9;
    return num % 9;
}

int main(){
    int n; cin >> n;
    int res = addDigits(n);
    cout << res;
    return 0;
}