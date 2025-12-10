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
    LeetCode 3760. Maximum Substrings With Distinct Start

    Đề bài:
    Cho một chuỗi s chỉ bao gồm các chữ cái tiếng Anh viết thường

    Yêu cầu:
    → Cần chia (split) chuỗi s thành một số lượng các chuỗi con (substrings)
    → Điều kiện: Mỗi chuỗi con phải bắt đầu bằng một ký tự bắt đầu khác nhau (distinct start character)
    → Tức là, không có hai chuỗi con nào được bắt đầu bằng cùng một ký tự
    → Trả về số nguyên thể hiện số lượng chuỗi con tối đa mà chuỗi s có thể được chia thành (thỏa mãn điều kiện trên)

    Ví dụ:
        Input: s = "abab"
        → Cách chia: "a" và "bab"
        → Ký tự bắt đầu: 'a' và 'b'. (Khác nhau)
        → Số lượng chuỗi con tối đa: 2
        → Output: 2
*/

int maxDistinct(string s){
    set<char> ans(s.begin(), s.end());
    return ans.size();
}

int main(){
    FAST_IO;

    string s; cin >> s;

    int ans = maxDistinct(s);
    cout << ans;
    return 0;
}