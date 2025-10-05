#include<bits/stdc++.h>
using namespace std;

int climbStairs(int n){
    if(n == 1) return 1;

    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    dp[2] = 2;
    
    /*
        dp[i] = số cách để leo lên bậc i
        - Base case:
            dp[1] = 1 (Có 1 cách leo lên bậc 1)
            dp[2] = 2 (Có 2 cách leo lên bậc 2)

        - dp[i] = dp[i - 1] + dp[i - 2]
                  (1 bước)    (2 bước)
    */
    for(int i = 3; i <= n; i++){
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
    int ans = climbStairs(n);
    cout << ans;
    return 0;
}