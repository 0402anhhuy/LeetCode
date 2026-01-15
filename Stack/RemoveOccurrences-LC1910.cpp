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
    LeetCode 1910. Remove All Occurrences of a Substring

    Đề bài:
    Cho hai chuỗi s và part. Bạn cần thực hiện thao tác sau trên s cho đến khi tất cả các lần xuất hiện của chuỗi con part bị xóa sạch:
    1. Tìm vị trí xuất hiện ngoài cùng bên trái của chuỗi con part
    2. Xóa nó khỏi chuỗi s

    Yêu cầu:
    → Trả về chuỗi s cuối cùng sau khi đã xóa hết mọi sự hiện diện của part

    Ví dụ:
        Input: s = "daabcbaabcbc", part = "abc"
        → Tìm "abc" đầu tiên tại index 2: "da[abc]baabcbc" -> s = "dabaabcbc"
        → Tìm "abc" tiếp theo tại index 4: "daba[abc]bc" -> s = "dababc"
        → Tìm "abc" cuối cùng tại index 3: "dab[abc]" -> s = "dab"
        → Output: "dab"
*/

string removeOccurrences(string s, string part){
    string ans = "";

    for(int i = 0; i < s.length(); i++){
        ans += s[i];
        if(ans.length() >= part.length() && ans.back() == part.back()){
            string temp = ans.substr(ans.length() - part.length(), part.length());
            if(temp == part){
                ans.erase(ans.length() - part.length(), part.length());
            }
        }
    }

    return ans;
}

int main(){
    FAST_IO;

    string s, part; cin >> s >> part;

    string ans = removeOccurrences(s, part);
    cout << ans;
    return 0;
}