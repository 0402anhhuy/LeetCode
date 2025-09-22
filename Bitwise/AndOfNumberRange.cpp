#include<bits/stdc++.h>
using namespace std;

/*
    LeetCode - 201. Bitwise AND of Numbers Range
    Ý tưởng:
        - Tìm chung tiền tố (common prefix) của left và right
        - Vì chỉ những bit chung mới giữ nguyên
*/

int rangeBitwiseAnd(int left, int right){
    int cnt = 0;
    while(left < right){
        left >>= 1;
        right >>= 1;
        cnt++;
    }
    return left << cnt;
}

int main(){
    int left, right; cin >> left >> right;
    int res = rangeBitwiseAnd(left, right);
    cout << res;
    return 0;
}