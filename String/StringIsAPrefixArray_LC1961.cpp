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
    LeetCode 1961. Check If String Is a Prefix of Array

    Đề bài:
    Cho một chuỗi s và một mảng các chuỗi words

    Định nghĩa Chuỗi tiền tố (Prefix String):
    → Chuỗi s được gọi là chuỗi tiền tố của words nếu s có thể được tạo thành bằng cách nối (concatenating) k chuỗi đầu tiên trong mảng words

    Yêu cầu:
    → Xác định xem chuỗi s có phải là một chuỗi tiền tố của words hay không
    → Trả về true nếu phải, và false nếu không

    Ví dụ:
        Input: s = "iloveleetcode", words = ["i", "love", "leetcode", "apples"]
        → Nối 3 chuỗi đầu tiên: "i" + "love" + "leetcode" = "iloveleetcode"
        → Kết quả khớp với s
        → Output: true
*/

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