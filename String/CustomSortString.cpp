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

string customSortString(string order, string s){
    vector<int> freq(26, 0);
    for(char c : s){
        freq[c - 'a']++;
    }

    string ans = "";
    for(char c : order){
        while(freq[c - 'a']-- > 0){
            ans += c;
        }
    }

    for(int i = 0; i < 26; i++){
        while(freq[i]-- > 0){
            ans += i + 'a';
        }
    }
    return ans;
}

int main(){
    FAST_IO;

    string order, s; cin >> order >> s;
    string ans = customSortString(order, s);
    cout << ans;
    return 0;
}