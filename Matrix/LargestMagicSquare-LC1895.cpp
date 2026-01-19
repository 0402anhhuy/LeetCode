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
    LeetCode 1895. Largest Magic Square

    Đề bài:
    Một hình vuông ma thuật (magic square) kích thước $k \times k$ là một lưới các số nguyên sao cho:
    → Tổng của mọi hàng, mọi cột và hai đường chéo chính đều bằng nhau
    → Các số nguyên trong hình vuông này không nhất thiết phải khác nhau
    → Mọi lưới 1x1 mặc định là một hình vuông ma thuật

    Yêu cầu:
    → Cho một ma trận số nguyên grid kích thước m x n
    → Tìm và trả về độ dài cạnh k lớn nhất của một hình vuông ma thuật nằm trong ma trận này

    Ví dụ:
        Input: grid = [
          [7, 1, 4, 5, 6],
          [2, 5, 1, 6, 4],
          [1, 5, 4, 3, 2],
          [1, 2, 7, 3, 4]
        ]
        → Tồn tại hình vuông ma thuật 3x3 (bắt đầu từ hàng 0, cột 1)
        → Các hàng, cột, đường chéo của nó đều có tổng bằng 12
        → Output: 3
*/

vector<vector<int>> hertical(vector<vector<int>> grid){
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> herticalPrefix(m, vector<int>(n, 0));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            herticalPrefix[i][j] = grid[i][j];
            if(j > 0){
                herticalPrefix[i][j] += herticalPrefix[i][j - 1];
            }
        }
    }

    return herticalPrefix;
}

vector<vector<int>> vertical(vector<vector<int>> grid){
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> verticalPrefix(m, vector<int>(n, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            verticalPrefix[j][i] = grid[j][i];
            if(j > 0){
                verticalPrefix[j][i] += verticalPrefix[j - 1][i];
            }
        }
    }

    return verticalPrefix;
}

vector<vector<int>> diagonalRight(vector<vector<int>> grid){
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> diagonalRightPrefix(m, vector<int>(n, 0));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            diagonalRightPrefix[i][j] = grid[i][j];
            if(i > 0 && j > 0){
                diagonalRightPrefix[i][j] += diagonalRightPrefix[i - 1][j - 1];
            }
        }
    }

    return diagonalRightPrefix;
}

vector<vector<int>> diagonalLeft(vector<vector<int>> grid){
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> diagonalLeftPrefix(m, vector<int>(n, 0));

    for(int i = 0; i < m; i++){
        for(int j = n - 1; j >= 0; j--){
            diagonalLeftPrefix[i][j] = grid[i][j];
            if(i > 0 && j + 1 < n){
                diagonalLeftPrefix[i][j] += diagonalLeftPrefix[i - 1][j + 1];
            }
        }
    }

    return diagonalLeftPrefix;
}

bool isMagic(int i, int j, int k, vector<vector<int>>& h, vector<vector<int>>& v, vector<vector<int>>& d1, vector<vector<int>>& d2){
    int target = h[i][j + k - 1] - (j > 0 ? h[i][j - 1] : 0);

    // Rows
    for(int r = i; r < i + k; r++){
        int sum = h[r][j + k - 1] - (j > 0 ? h[r][j - 1] : 0);
        if(sum != target) return false;
    }

    // Cols
    for(int c = j; c < j + k; c++){
        int sum = v[i + k - 1][c] - (i > 0 ? v[i - 1][c] : 0);
        if(sum != target) return false;
    }

    // dRight
    int diag1 = d1[i + k - 1][j + k - 1] - (i > 0 && j > 0 ? d1[i - 1][j - 1] : 0);

    // dLeft
    int diag2 = d2[i + k - 1][j] - (i > 0 && j + k < d2[0].size() ? d2[i - 1][j + k] : 0);

    return diag1 == target && diag2 == target;
}


int largestMagicSquare(vector<vector<int>>& grid){
    vector<vector<int>> h = hertical(grid);
    vector<vector<int>> v = vertical(grid);
    vector<vector<int>> d1 = diagonalRight(grid);
    vector<vector<int>> d2 = diagonalLeft(grid);

    int m = grid.size();
    int n = grid[0].size();

    for(int k = min(m, n); k >= 2; k--){
        for(int i = 0; i + k - 1 < m; i++){
            for(int j = 0; j + k - 1 < n; j++){
                if(isMagic(i, j, k, h, v, d1, d2)){
                    return k;
                }
            }
        }
    }

    return 1;
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

    int ans = largestMagicSquare(grid);
    cout << ans;
    return 0;
}