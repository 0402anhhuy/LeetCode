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
    LeetCode 1925. Count Square Sum Triples

    Đề bài:
    Định nghĩa một Bộ ba số học vuông (square triple) (a, b, c) là một bộ ba các số nguyên thỏa mãn điều kiện:
    → a^2 + b^2 = c^2

    Yêu cầu:
    → Cho một số nguyên n
    → Đếm và trả về tổng số lượng các bộ ba số học vuông (a, b, c)

    Ví dụ:
        Input: n = 5
        → Các bộ ba thỏa mãn a^2 + b^2 = c^2
            1. (3, 4, 5): 3^2 + 4^2 = 9 + 16 = 25 = 5^2
            2. (4, 3, 5): 4^2 + 3^2 = 16 + 9 = 25 = 5^2
        → Output: 2
*/

int countTriples(int n){
    int cnt = 0;
    for(int i = 1; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            int sumSq = i * i + j * j;
            int c = (int)sqrt(sumSq);
            if(c * c == sumSq && c <= n){
                cnt += 2;
            }
        }
    }
    return cnt;
}

int main(){
    FAST_IO;

    int n; cin >> n;
    int ans = countTriples(n);
    cout << ans;
    return 0;
}