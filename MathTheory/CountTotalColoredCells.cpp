#include<bits/stdc++.h>
using namespace std;

/*
    LeetCode - 2579. Count Total Colored Cells in a Grid
    Ý tưởng:
        - Số ô màu sau n phút là:
        = 1 + 4 + 8 + 12 + ... + 4 * (n - 1) 
        = 1 + 4 * (1 + 2 + ... + (n - 1)) 
        = 1 + 4 * (n - 1) * n / 2
    Code:
        return 1LL + 4LL * (n - 1) * n / 2;
*/

long long coloredCells(int n){
    long long res = 1, fill = 4;
    for(int i = 0; i < n; i++){
        res += fill * i;
    }
    return res;
}

int main(){
    int n; cin >> n;
    long long res = coloredCells(n);
    cout << res;
    return 0;
}