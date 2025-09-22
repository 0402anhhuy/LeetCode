#include<bits/stdc++.h>
using namespace std;

/*
    LeetCode - 190. Reverse Bits
    Ý tưởng:
        - Duyệt qua 32 bit
        - Dịch trái bit của res và cộng cho bit cuối của n
*/

uint32_t reverseBits(uint32_t n){
    uint32_t res = 0;
    for(int i = 0; i < 32; i++){
        res = (res << 1) | (n & 1);
        n >>= 1;
    }
    return res;
}

int main(){
    uint32_t n; cin >> n;
    cout << reverseBits(n);
    return 0;
}