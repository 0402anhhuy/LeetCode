#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("D:/AnhHuy/Code/C++/input.inp", "r", stdin);
        freopen("D:/AnhHuy/Code/C++/output.out", "w", stdout);
    #endif

    int n, m;
    cin >> n >> m;
    vector<int> gold(n);
    for(int i = 0; i < n; i++) cin >> gold[i];

    int maxValue = *max_element(gold.begin(), gold.end());

    vector<int> dp(m + maxValue, false);
    dp[0] = true;

    for(int x : gold){
        for(int j = m + maxValue - 1; j >= x; j--){
            if(dp[j - x]){
                dp[j] = true;
            }
        }
    }

    for(int j = m + maxValue - 1; j >= 0; j--){
        if(dp[j]){
            cout << j;
            break;
        }
    }
    return 0;
}
