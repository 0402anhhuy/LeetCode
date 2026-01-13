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
    LeetCode 1128. Number of Equivalent Domino Pairs

    Đề bài:
    Cho một danh sách các quân domino, trong đó mỗi quân dominoes[i] = [a, b]
    Hai quân domino [a, b] và [c, d] được coi là tương đương (equivalent) nếu:
    → (a == c và b == d) HOẶC (a == d và b == c)

    Ví dụ:
        Input: dominoes = [[1, 2], [2, 1], [3, 4], [5, 6]]
        → Cặp [1, 2] và [2, 1] là tương đương vì khi xoay [2, 1] ta được [1, 2]
        → Các cặp khác không tương đương
        → Output: 1

        Input: dominoes = [[1, 2], [1, 2], [1, 1], [1, 2]]
        → Có 3 quân [1, 2]. Số cặp tương đương từ 3 quân này là 3 (Cặp (0,1), (0,3), (1,3))
        → Output: 3
*/

int numEquivDominoPairs(vector<vector<int>>& dominoes){
    int n = dominoes.size();
    int ans = 0;

    map<vector<int>, int> dominoFreq;
    for(int i = 0; i < n; i++){
        vector<int> tmp = {min(dominoes[i][0], dominoes[i][1]), max(dominoes[i][0], dominoes[i][1])};
        dominoFreq[tmp]++;
    }

    for(auto &[n, f] : dominoFreq){
        ans += (f * (f - 1)) / 2;
    }

    return ans;
}

int main(){
    FAST_IO;

    int n; cin >> n;
    vector<vector<int>> dominoes(n, vector<int>(2));

    FORI(i, n){
        FORI(j, 2){
            cin >> dominoes[i][j];
        }
    }

    int ans = numEquivDominoPairs(dominoes);
    cout << ans;
    return 0;
}