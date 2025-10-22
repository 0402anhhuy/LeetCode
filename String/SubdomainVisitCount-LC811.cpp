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
    LeetCode 811. Subdomain Visit Count

    Đề bài:  
    Cho danh sách các chuỗi dạng `"số_lần_truy_cập domain"`, ví dụ `"9001 discuss.leetcode.com"`
    Mỗi lần truy cập một domain thì tất cả các subdomain cha của nó cũng được tính là được truy cập

    Yêu cầu:  
    → Tính tổng số lượt truy cập cho mỗi subdomain (bao gồm cả domain cha và con)
    → Trả về danh sách kết quả dạng `"số_lần_truy_cập domain"` cho tất cả subdomain

    Ví dụ:  
        Input: ["9001 discuss.leetcode.com"]  
        → "discuss.leetcode.com" +9001  
        → "leetcode.com" +9001  
        → "com" +9001  
        → Kết quả: ["9001 discuss.leetcode.com", "9001 leetcode.com", "9001 com"]
*/

vector<string> subdomainVisits(vector<string>& cpdomains){
    unordered_map<string, int> count;
    for(auto cp : cpdomains){
        int index = cp.find(" ");
        int freq = stoi(cp.substr(0, index));
        string s = cp.substr(index + 1);
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '.'){
                count[s.substr(i + 1)] += freq;
            }
        }
        count[s] += freq;
    }

    vector<string> ans;
    for(auto &[s, f] : count){
        ans.push_back(to_string(f) + " " + s);
    }
    return ans;
}

int main(){
    FAST_IO;

    int n; cin >> n; cin.ignore();
    vector<string> cpdomains(n);
    FORI(i, n) getline(cin, cpdomains[i]);

    vector<string> ans = subdomainVisits(cpdomains);
    FORI(i, ans.size()) cout << ans[i] << endl;
    return 0;
}