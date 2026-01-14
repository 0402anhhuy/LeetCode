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
    LeetCode 890. Find and Replace Pattern

    Đề bài:
    Cho một danh sách các chuỗi words và một chuỗi pattern (mẫu)

    Định nghĩa Khớp (Match):
    → Một từ (word) được coi là khớp với mẫu (pattern) nếu tồn tại một hoán vị chữ cái p (permutation) sao cho, khi thay thế mỗi chữ cái x trong pattern bằng p(x), ta nhận được từ đó
    → Hoán vị (Permutation) là một song ánh (bijection) giữa các chữ cái:
        1. Mỗi chữ cái trong pattern phải ánh xạ tới một chữ cái trong word
        2. Không có hai chữ cái khác nhau trong pattern được ánh xạ tới cùng một chữ cái trong word

    Yêu cầu:
    → Trả về một danh sách (list) chứa tất cả các chuỗi words[i] thỏa mãn điều kiện khớp với pattern
    → Thứ tự trả về của các từ không quan trọng

    Ví dụ:
        Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
        → "mee" khớp với "abb":
            - Ánh xạ: a -> m, b -> e. (Là song ánh)
        → "ccc" KHÔNG khớp với "abb":
            - Ánh xạ: a -> c, b -> c. (Không là song ánh vì a và b cùng ánh xạ đến c)
        → Output: ["mee", "aqq"]
*/

bool matchPattern(string pattern, string word){
    unordered_map<char, char> patternToWord;
    unordered_map<char, char> wordToPattern;

    int n = pattern.length();

    for(int i = 0; i < n; i++){
        patternToWord[pattern[i]] = word[i];
        wordToPattern[word[i]] = pattern[i];
    }

    string mappedPattern = pattern;
    string mappedWord = word;

    for(int i = 0; i < n; i++){
        mappedPattern[i] = patternToWord[pattern[i]];
        mappedWord[i] = wordToPattern[word[i]];
    }

    return (mappedPattern == word) && (mappedWord == pattern);
}


vector<string> findAndReplacePattern(vector<string>& words, string pattern){
    vector<string> ans;

    for(string word : words){
        if(matchPattern(pattern, word)){
            ans.push_back(word);
        }
    }

    return ans;
}

int main(){
    FAST_IO;

    int n; cin >> n;
    string pattern; cin >> pattern;

    vector<string> words(n);
    FORI(i, n) cin >> words[i];

    vector<string> ans = findAndReplacePattern(words, pattern);
    FORI(i, ans.size()) cout << ans[i] << " ";
    return 0;
}