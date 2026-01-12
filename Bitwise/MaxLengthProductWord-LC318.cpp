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
    LeetCode 318. Maximum Product of Word Lengths

    Đề bài:
    Cho một mảng các chuỗi words

    Yêu cầu:
    → Tìm giá trị lớn nhất của tích: length(words[i]) * length(words[j])
    → Điều kiện: Hai từ words[i] và words[j] phải không có bất kỳ chữ cái chung nào
    → Nếu không tìm được cặp từ nào thỏa mãn điều kiện, trả về 0

    Ví dụ:
        Input: words = ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
        → Cặp "abcw" (dài 4) và "xtfn" (dài 4) không có chữ cái chung. Tích = 16
        → Cặp "abcdef" (dài 6) và các từ khác đều có ít nhất một chữ cái chung
        → Output: 16

        Input: words = ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
        → Cặp "ab" và "cd" không chung chữ cái. Tích = 2 * 2 = 4.
        → Cặp "a" và "bcd" không chung chữ cái. Tích = 1 * 3 = 3
        → Output: 4
*/

bool isDifferent(string s, string t){
    int mask1 = 0, mask2 = 0;
    for(char c : s){
        mask1 |= (1 << (c - 'a'));
    }

    for(char c : t){
        mask2 |= (1 << (c - 'a'));
    }

    return (mask1 & mask2) == 0;
}


int maxProduct(vector<string>& words){
    int n = words.size();

    int ans = 0;
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(isDifferent(words[i], words[j])){
                int maxLength = words[i].length() * words[j].length();
                ans = max(ans, maxLength);
            }
        }
    }

    return ans;
}

int main(){
    FAST_IO;

    int n; cin >> n;
    vector<string> words(n);
    FORI(i, n) cin >> words[i];

    int ans = maxProduct(words);
    cout << ans;
    return 0;
}