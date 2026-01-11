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
    LeetCode 692. Top K Frequent Words

    Đề bài:
    Cho một mảng các chuỗi words và một số nguyên k

    Yêu cầu:
    → Tìm và trả về k từ xuất hiện thường xuyên nhất
    → Kết quả trả về phải được sắp xếp theo các quy tắc sau:
        1. Ưu tiên từ có tần suất xuất hiện cao hơn đứng trước
        2. Nếu hai từ có cùng tần suất, từ nào có thứ tự từ điển (lexicographical order) nhỏ hơn sẽ đứng trước (ví dụ: "apple" đứng trước "banana")

    Ví dụ:
        Input: words = ["i", "love", "leetcode", "i", "love", "coding"], k = 2
        → "i": xuất hiện 2 lần
        → "love": xuất hiện 2 lần
        → "leetcode": xuất hiện 1 lần
        → "coding": xuất hiện 1 lần
        → "i" và "love" cùng tần suất 2, nhưng "i" đứng trước "love" trong bảng chữ cái
        → Output: ["i", "love"]
*/

vector<string> topKFrequent(vector<string>& words, int k){
    unordered_map<string, int> wordFreq;
    for(string word : words){
        wordFreq[word]++;
    }

    int n = words.size();
    vector<vector<string>> bucket(n + 1);

    for(auto &[s, f] : wordFreq){
        bucket[f].push_back(s);
    }

    for(auto &v : bucket){
        sort(v.begin(), v.end());
    }

    vector<string> res;
    for(int i = n; i >= 0; i--){
        for(string x : bucket[i]){
            res.push_back(x);
            if(res.size() == k) return res;
        }
    }
    return res;
}

int main(){
    FAST_IO;

    int n, k; cin >> n >> k;
    vector<string> words(n);
    FORI(i, n) cin >> words[i];

    vector<string> ans = topKFrequent(words, k);
    FORI(i, ans.size()) cout << ans[i] << " ";
    return 0;
}