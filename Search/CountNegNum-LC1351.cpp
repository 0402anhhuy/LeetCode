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
    LeetCode 1351. Count Negative Numbers in a Sorted Matrix

    Đề bài:
    Cho một ma trận grid kích thước m x n được sắp xếp theo thứ tự giảm dần (non-increasing) ở cả hàng và cột

    Yêu cầu:
    → Đếm tổng số lượng các số âm có trong ma trận này 

    Đặc điểm ma trận:
    → Vì các hàng và cột đều giảm dần, các số âm thường tập trung ở phía góc dưới bên phải của ma trận

    Ví dụ:
        Input: grid = [
          [ 4,  3,  2, -1],
          [ 3,  2,  1, -1],
          [ 1,  1, -1, -2],
          [-1, -1, -2, -3]
        ]
        → Các số âm: -1, -1, -1, -2, -1, -1, -2, -3 (Tổng cộng 8 số)
        → Output: 8
*/

int countNegatives(vector<vector<int>>& grid){
    int m = grid.size(), n = grid[0].size(), ans = 0;

    int i = m - 1, j = 0;
    while(i >= 0 && j < n){
        if(grid[i][j] < 0){
            ans += n - j;
            i--;
        }
        else{
            j++;
        }
    }

    return ans;
}

int main(){
    FAST_IO;

    int m, n; cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));

    FORI(i, m){
        FORI(j, n){
            cin >> grid[i][j];
        }
    }

    int ans = countNegatives(grid);
    cout << ans;
    return 0;
}