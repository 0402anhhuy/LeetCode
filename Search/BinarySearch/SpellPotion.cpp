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

int bs(vector<int> &potions, ll spell, ll success){
    int low = 0, high = potions.size() - 1, idx = -1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(1LL * potions[mid] * spell >= success){
            idx = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return idx;
}

vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success){
    sort(potions.begin(), potions.end());
    int n = spells.size(), m = potions.size();

    vector<int> ans(n, 0);
    for(int i = 0; i < n; i++){
        int index = bs(potions, spells[i], success);
        if(index != -1){
            ans[i] = m - index;
        }
    }
    return ans;
}

int main(){
    FAST_IO;

    int n, m; cin >> n >> m;

    vector<int> spells(n), potions(m);
    ll success; cin >> success;
    FORI(i, n) cin >> spells[i];
    FORI(i, m) cin >> potions[i];

    vector<int> ans = successfulPairs(spells, potions, success);
    for(int i : ans) cout << i << " ";
    return 0;
}