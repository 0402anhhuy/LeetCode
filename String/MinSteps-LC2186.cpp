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

int minSteps(string s, string t){
    vector<int> s26(26, 0), t26(26, 0);
    for(char c : s){
        s26[c - 'a']++;
    }

    for(char c : t){
        t26[c - 'a']++;
    }

    int ans = 0;
    for(int i = 0; i < 26; i++){
        ans += abs(s26[i] - t26[i]);
    }
    return ans;
}

int main(){
    FAST_IO;

    string s, t; cin >> s >> t;
    int ans = minSteps(s, t);
    cout << ans;
    return 0;
}