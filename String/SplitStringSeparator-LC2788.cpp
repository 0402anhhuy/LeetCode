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
    LeetCode 2788. Split Strings by Separator

    Đề bài:  
    Cho một mảng các chuỗi words và một ký tự phân tách separator

    Yêu cầu:  
    → Chia (split) mỗi chuỗi trong mảng words dựa trên ký tự separator
    → Kết quả trả về là một mảng chứa các chuỗi mới được tạo thành sau khi chia

    Ví dụ:  
        Input: words = ["one.two.three", "four.five", "six"], separator = "."
        → Chuỗi 1: "one", "two", "three"
        → Chuỗi 2: "four", "five"
        → Chuỗi 3: "six"
        → Output: ["one", "two", "three", "four", "five", "six"]
*/

vector<string> splitWordsBySeparator(vector<string>& words, char separator){
    vector<string> ans;

    string temp = "";
    for(string word : words){
        for(int i = 0; i < word.length(); i++){
            if(word[i] == separator){
                if(temp != ""){
                    ans.push_back(temp);
                }
                temp = "";
            }
            else{
                temp += word[i];
            }
        }
        if(temp != ""){
            ans.push_back(temp);
        }
        temp = "";
    }

    return ans;
}

int main(){
    FAST_IO;

    int n; cin >> n;
    vector<string> words(n);
    FORI(i, n) cin >> words[i];
    
    char separator; cin >> separator;

    vector<string> ans = splitWordsBySeparator(words, separator);
    FORI(i, ans.size()) cout << ans[i] << " ";
    return 0;
}