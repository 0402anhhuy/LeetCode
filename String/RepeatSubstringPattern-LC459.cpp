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
    LeetCode 459. Repeated Substring Pattern

    Đề bài:
    Cho một chuỗi s

    Yêu cầu:
    → Kiểm tra xem chuỗi s có thể được tạo ra bằng cách lấy một chuỗi con (substring) của nó và lặp lại liên tiếp nhiều lần hay không
    → Trả về true nếu có thể, ngược lại trả về false

    Ví dụ:
        Input: s = "abab"
        → Giải thích: Chuỗi "ab" được lặp lại 2 lần
        → Output: true

        Input: s = "aba"
        → Giải thích: Không có chuỗi con nào lặp lại tạo thành "aba"
        → Output: false

        Input: s = "abcabcabcabc"
        → Giải thích: Chuỗi "abc" lặp lại 4 lần hoặc "abcabc" lặp lại 2 lần
        → Output: true
*/

bool repeatedSubstringPattern(string s){
    int n = s.length();

    for(int len = 1; len <= n / 2; len++){
        if(n % len != 0) continue;

        string pattern = s.substr(0, len);
        bool ok = true;

        for(int i = len; i < n; i += len){
            if(s.substr(i, len) != pattern){
                ok = false;
                break;
            }
        }

        if(ok) return true;
    }
    return false;
}


int main(){
    FAST_IO;

    string s; cin >> s;
    cout << boolalpha << repeatedSubstringPattern(s);
    return 0;
}