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

/*
    LeetCode 1400. Construct K Palindrome Strings

    Đề bài:
    Cho chuỗi s và số nguyên k.
    Hãy kiểm tra xem có thể dùng toàn bộ ký tự trong s để tạo ra k chuỗi palindrome (đối xứng), mỗi chuỗi không rỗng, hay không

    Trả về true nếu có thể, ngược lại false

    Ví dụ:
        s = "annabelle", k = 2
        Có thể tạo 2 chuỗi palindrome như "anna" + "elble" ⇒ true
*/


bool canConstruct(string s, int k){
    if(s.length() < k) return false;

    map<char, int> charFreq;
    for(char c : s){
        charFreq[c]++;
    }

    int cntOdd = 0;
    for(auto &[c, f] : charFreq){
        if(f % 2 != 0){
            cntOdd++;
        }
    }

    if(cntOdd > k) return false;
    return true;
}

int main(){
    FAST_IO;

    string s; cin >> s;
    int k; cin >> k;

    cout << boolalpha << canConstruct(s, k);
    return 0;
}