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
    LeetCode 1009. Complement of Base 10 Integer

    Đề bài:
    Số bù (complement) của một số nguyên là số nhận được khi bạn đảo ngược tất cả các bit trong biểu diễn nhị phân của nó (đổi 0 thành 1 và 1 thành 0)

    Ví dụ:
    Số nguyên 5 trong hệ nhị phân là "101"
    Khi đảo ngược các bit, ta được "010", tương ứng với số 2 trong hệ thập phân

    Ví dụ:
        Input: n = 5
        - 5 = (101) nhị phân
        - Đảo bit thành (010)
        - (010) nhị phân = 2 thập phân
        - Output: 2
*/

int bitwiseComplement(int n){
    if(n == 0) return 0;
    int mask = 0, temp = n;
    while(temp != 0){
        mask = (mask << 1) | 1;
        temp >>= 1;
    }
    
    return n ^ mask;
}

int main(){
    FAST_IO;

    int n; cin >> n;

    int ans = bitwiseComplement(n);
    cout << ans;
    return 0;
}