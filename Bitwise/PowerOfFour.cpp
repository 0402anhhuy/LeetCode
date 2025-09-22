#include<bits/stdc++.h>
using namespace std;

/*
    LeetCode - 342. Power Of Four
    Ý tưởng:
        - Tính 4^n bằng phép dịch trái (Vì 4^n = 2^(2n))
        - Duyệt qua 32 bit -> cho i += 2 (Vì 2n)
        - Dùng (1 << 2n) <=> 4^n
*/

bool isPowerOfFour(int n){
    if(n < 0) return false;
    for(int i = 0; i < 32; i += 2){
        if((1 << i) == n){
            return true;
        }
    }
    return false;
}

int main(){
    int n; cin >> n;
    bool res = isPowerOfFour(n);
    cout << boolalpha << res;
    return 0;
}