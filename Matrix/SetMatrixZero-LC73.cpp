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
    LeetCode 73. Set Matrix Zeroes

    Đề bài:
    Cho một ma trận số nguyên matrix kích thước m x n
    Nếu một phần tử có giá trị bằng 0, hãy đặt toàn bộ hàng và cột chứa phần tử đó về giá trị 0

    Ví dụ:
        Input: matrix = [
          [1, 1, 1],
          [1, 0, 1],
          [1, 1, 1]
        ]
        → Phần tử matrix[1][1] là 0
        → Đưa toàn bộ hàng 1 và cột 1 về 0
        Output: [
          [1, 0, 1],
          [0, 0, 0],
          [1, 0, 1]
        ]
*/

void setZeroes(vector<vector<int>>& matrix){
    int m = matrix.size();
    int n = matrix[0].size();

    bool col0 = false;

    // Đánh dấu những hàng hoặc cột có giá trị 0
    for(int i = 0; i < m; i++){
        if(matrix[i][0] == 0){
            col0 = true;
        }
        
        for(int j = 1; j < n; j++){
            if(matrix[i][j] == 0){
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // Dựa theo dấu đã đánh để thực hiện đánh giá trị 0 cho các giá trị bên trong (tương ứng theo hàng hoặc cột)
    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            if(matrix[i][0] == 0 || matrix[0][j] == 0){
                matrix[i][j] = 0;
            }
        }
    }

    // Kiểm tra hàng 0 và cột 0
    if(matrix[0][0] == 0){
        for(int j = 0; j < n; j++){
            matrix[0][j] = 0;
        }
    }

    if(col0){
        for(int i = 0; i < m; i++){
            matrix[i][0] = 0;
        }
    }
}

int main(){
    FAST_IO;

    int m, n; cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n));

    FORI(i, m){
        FORI(j, n){
            cin >> matrix[i][j];
        }
    }

    setZeroes(matrix);

    FORI(i, m){
        FORI(j, n){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}