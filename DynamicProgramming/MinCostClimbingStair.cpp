#include<bits/stdc++.h>
using namespace std;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr)

using ll  = long long;
using ull = unsigned long long;
using ld  = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi  = vector<int>;
using vll = vector<ll>;
using vii = vector<pii>;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define pb push_back
#define eb emplace_back
#define F first
#define S second

#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
#define FORI(i, n) for (int i = 0; i < (n); ++i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPD(i, n) for (int i = (n)-1; i >= 0; --i)

const int INF = 1e9 + 7;
const ll  LINF = 4e18;
const ld  EPS = 1e-9;
const int MOD = 1e9 + 7;

int minCostClimbingStairs(vector<int>& cost){
    int n = cost.size();
    if(n == 1) return cost[0];
    if(n == 2) return min(cost[0], cost[1]);
    
    vector<int> dp(n);
    dp[0] = cost[0];
    dp[1] = cost[1];
    for(int i = 2; i < n; i++){
        dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
    }
    return min(dp[n - 2], dp[n - 1]);
}

int main(){
    FAST_IO;

    int n; cin >> n;
    vector<int> cost(n);
    FORI(i, n) cin >> cost[i];

    int ans = minCostClimbingStairs(cost);
    cout << ans;
    return 0;
}