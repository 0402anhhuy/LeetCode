#include<bits/stdc++.h>
using namespace std;

/*
    LeetCode - 1318. Minimum Flips to Make a OR b Equal to c
    Ý tưởng:
        + Nếu c có bit 0, cần tắt bit ở a và b nếu có
        + Nếu c có bit 1, ít nhất một trong a hoặc b phải có 1, nếu không thì bật 1 trong 2 bit
*/

int minFlips(int a, int b, int c){
    int cnt = 0;
    for(int i = 0; i < 32; i++){
        int bitA = (a >> i) & 1;
        int bitB = (b >> i) & 1;
        int bitC = (c >> i) & 1;

        if(bitC == 0) cnt += (bitA + bitB);
        else{
            cnt += (bitA | bitB) ? 0 : 1;
        }
    }
    return cnt;
}

int main(){
    int a, b, c; cin >> a >> b >> c;
    int res = minFlips(a, b, c);
    cout << res;
    return 0;
}