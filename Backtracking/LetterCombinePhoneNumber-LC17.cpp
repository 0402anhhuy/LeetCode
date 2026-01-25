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
    LeetCode 17. Letter Combinations of a Phone Number

    Đề bài:
    Cho một chuỗi gồm các chữ số từ 2-9. Bạn cần trả về tất cả các tổ hợp chữ cái có thể có mà dãy số đó đại diện

    Quy tắc ánh xạ (Giống bàn phím điện thoại cổ điển):
    - '2': "abc", '3': "def", '4': "ghi", '5': "jkl", 
    - '6': "mno", '7': "pqrs", '8': "tuv", '9': "wxyz"
    - Lưu ý: Chữ số '1' không tương ứng với bất kỳ chữ cái nào

    Yêu cầu:
    → Trả về danh sách các chuỗi kết quả theo bất kỳ thứ tự nào.
    → Độ dài của mỗi chuỗi kết quả bằng độ dài của chuỗi chữ số đầu vào

    Ví dụ:
        Input: digits = "23"
        → '2' có thể là {a, b, c}
        → '3' có thể là {d, e, f}
        → Các tổ hợp: "ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"
        → Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

        Input: digits = ""
        → Output: []
*/

vector<string> res;
vector<string> mp = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void backtrack(int index, string &digit, string cur){
    if(index == digit.length()){
        res.push_back(cur);
        return;
    }

    int d = digit[index] - '0';
    for(char c : mp[d]){
        cur.push_back(c);
        backtrack(index + 1, digit, cur);
        cur.pop_back();
    }
}

vector<string> letterCombinations(string digits){
    if(digits.length() == 0) return {};

    string cur = "";
    backtrack(0, digits, cur);
    return res;
}

int main(){
    FAST_IO;

    string digits; cin >> digits;

    vector<string> ans = letterCombinations(digits);
    FORI(i, ans.size()) cout << ans[i] << " ";
    return 0;
}