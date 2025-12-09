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

bool isValid(int a, int b){
    return (a % 2 == 0 && b % 2 != 0) || (a % 2 != 0 && b % 2 == 0);
}

int main(){
    FAST_IO;

    int n, t; cin >> t;
    while(t--){
        cin >> n;
        vector<int> arr(n);

        for(int &x : arr) cin >> x;
        
        vector<int> dp(n, 0);
        dp[0] = arr[0];

        for(int i = 1; i < n; i++){
            if(isValid(arr[i - 1], arr[i])){
                dp[i] = max(dp[i - 1] + arr[i], arr[i]);
            }
            else dp[i] = arr[i];
        }
        cout << *max_element(dp.begin(), dp.end()) << endl;
    }
    return 0;
}