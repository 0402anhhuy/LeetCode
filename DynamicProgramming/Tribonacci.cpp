#include<bits/stdc++.h>
using namespace std;

int tribonacci(int n){
    if(n == 0) return 0;
    if(n == 1 || n == 2) return 1;
    
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;

    for(int i = 3; i <= n; i++){
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
    
    return dp[n];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    #ifndef ONLINE_JUDGE
        freopen("D:/AnhHuy/Code/C++/input.inp", "r", stdin);
        freopen("D:/AnhHuy/Code/C++/output.out", "w", stdout);
    #endif
      
    int n; cin >> n;
    int ans = tribonacci(n);
    cout << ans;
    return 0;
}