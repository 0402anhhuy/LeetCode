#include<bits/stdc++.h>
using namespace std;

int fib(int n){
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2; i <= n; i++){
        dp[i] = dp[i - 1] + dp[i - 2];
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
    int ans = fib(n);
    cout << ans;
    return 0;
}