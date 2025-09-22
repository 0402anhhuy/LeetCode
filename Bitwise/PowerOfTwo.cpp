#include<bits/stdc++.h>
using namespace std;

/*
    LeetCode - 231. Power Of Two
    Ý tưởng:
        - Tính số mũ 2^n bằng phép dịch trái
        - Dùng (1 << n) <=> 2^n
*/

bool isPowerOfTwo(int n){
    if(n < 0) return false;
    for(int i = 0; i < 32; i++){
        if((1 << i) == n){
            return true;
        }
    }   
    return false;
}

int main(){
    int n; cin >> n;
    bool res = isPowerOfTwo(n);
    cout << boolalpha << res;
    return 0;
}