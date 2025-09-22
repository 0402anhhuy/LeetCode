#include<bits/stdc++.h>
using namespace std;

/*
    LeetCode - 191. Number of 1 Bits
    Ý tưởng:
        - Lặp đến khi n = 0
        - Dùng (n & 1) để lấy bit cuối
        - Dịch bit sang phải 1 (n = n >> 1)
*/

int hammingWeight(int n) {
    int cnt = 0;
    while(n != 0){
        if(n & 1) cnt++;
        n >>= 1;
    }
    return cnt;
}

int main(){
    int n; cin >> n;
    int res = hammingWeight(n);
    cout << res;
    return 0;
}