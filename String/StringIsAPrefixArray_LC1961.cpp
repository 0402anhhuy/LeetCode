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

bool isPrefixString(string s, vector<string>& words){
    string tmp = "";
    for(int i = 0; i < words.size(); i++){
        tmp += words[i];
        if(tmp == s){
            return true;
        }
    }
    return false;
}

int main(){
    FAST_IO;

    int n; cin >> n;
    vector<string> words;
    for(int i = 0; i < n; i++){
        string x; cin >> x;
        words.push_back(x);
    }

    string s; cin >> s;
    cout << boolalpha << isPrefixString(s, words);
    return 0;
}