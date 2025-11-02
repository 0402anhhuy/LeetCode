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

int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};

int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls){
    vector<vector<int>> grid(m, vector<int>(n, 0));

    for(auto &w : walls) grid[w[0]][w[1]] = 1;

    for(auto &g : guards) grid[g[0]][g[1]] = 2;

    for(auto &g : guards){
        int x = g[0], y = g[1];

        for(int dir = 0; dir < 4; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            while(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] != 1 && grid[nx][ny] != 2){
                if(grid[nx][ny] == 0){
                    grid[nx][ny] = 3;
                }
                nx += dx[dir];
                ny += dy[dir];
            }
        }
    }

    int cnt = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == 0) cnt++;
        }
    }

    return cnt;
}

int main(){
    FAST_IO;

    int m, n, a, b; cin >> m >> n >> a >> b;
    vector<vector<int>> guards, walls;

    FORI(i, a){
        int x, y; cin >> x >> y;
        guards.push_back({x, y});
    }

    FORI(i, b){
        int x, y; cin >> x >> y;
        walls.push_back({x, y});
    }

    int ans = countUnguarded(m, n, guards, walls);
    cout << ans;
    return 0;
}