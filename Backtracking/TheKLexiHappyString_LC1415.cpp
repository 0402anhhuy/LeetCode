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
    LeetCode 1415. The k-th Lexicographical String of All Happy Strings of Length n

    Đề bài:
    Định nghĩa Chuỗi Hạnh Phúc (Happy String) là chuỗi thỏa mãn:
    1. Chỉ bao gồm các chữ cái trong tập ['a', 'b', 'c']
    2. Hai ký tự liền kề trong chuỗi phải khác nhau

    Yêu cầu:
    → Cho hai số nguyên n (độ dài chuỗi) và k (thứ tự)
    → Xét danh sách tất cả các Chuỗi Hạnh Phúc có độ dài n, được sắp xếp theo thứ tự từ điển (lexicographical order)
    → Trả về chuỗi thứ k trong danh sách đó
    → Nếu tổng số Chuỗi Hạnh Phúc có độ dài n nhỏ hơn k, trả về chuỗi rỗng ("")

    Ví dụ:
        Input: n = 1, k = 3
        → Các chuỗi hạnh phúc độ dài 1: ["a", "b", "c"]
        → Chuỗi thứ 3 là "c"
        → Output: "c"
*/

vector<string> ans;

void backtrack(int n, string &temp){
    if(temp.length() == n){
        ans.push_back(temp);
        return;
    }

    for(int i = 0; i < 3; i++){
        char c = 'a' + i;

        if(!temp.empty() && temp.back() == c) continue;

        temp.push_back(c);
        backtrack(n, temp);
        temp.pop_back();
    }
}

string getHappyString(int n, int k){
    string temp = "";
    backtrack(n, temp);

    if(ans.size() < k) return "";
    return ans[k - 1];
}

int main(){
    FAST_IO;

    int n, k; cin >> n >> k;

    string ans = getHappyString(n, k);
    cout << ans;
    return 0;
}