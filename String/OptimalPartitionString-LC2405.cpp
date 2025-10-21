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
    LeetCode 2405. Optimal Partition of String

    Đề bài:  
    Cho chuỗi `s`, hãy chia nó thành nhiều nhất có thể các đoạn con sao cho:  
    - Trong mỗi đoạn con, các ký tự là duy nhất (không bị lặp)
    - Mỗi ký tự trong `s` chỉ thuộc về một đoạn con duy nhất

    Yêu cầu:  
    → Trả về số lượng nhỏ nhất các đoạn con cần để thỏa mãn điều kiện

    Ví dụ:  
        s = "abacaba"  
        → Các đoạn: "a", "ba", "cab", "a"  
        → Kết quả: 4
*/

int partitionString(string s){
    set<char> charSet;
    int cnt = 1;

    for(char c : s){
        if(charSet.count(c)){
            cnt++;
            charSet.clear();
        }
        charSet.insert(c);
    }
    return cnt;
}


int main(){
    FAST_IO;

    string s; cin >> s;

    int ans = partitionString(s);
    cout << ans;
    return 0;
}