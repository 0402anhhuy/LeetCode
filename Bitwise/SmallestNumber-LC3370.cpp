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
    LeetCode 3370. Smallest Number With All Set Bits

    Đề bài:  
    Cho một số nguyên dương `n`

    Yêu cầu:  
    → Tìm số nhỏ nhất x ≥ n sao cho biểu diễn nhị phân của x chỉ chứa toàn bit 1  
    (ví dụ: 1 → 1, 3 → 11, 7 → 111, 15 → 1111, ...)

    Ví dụ:  
        Input: n = 5  
        → Các số có toàn bit 1: 1, 3, 7, 15...  
        → 7 ≥ 5 → Output: 7
*/

int smallestNumber(int n){
    int num = 2;
    while(num <= n){
        num *= 2;
    }
    return num - 1;
}

int main(){
    FAST_IO;

    int n; cin >> n;
    int ans = smallestNumber(n);
    cout << ans;
    return 0;
}