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
    LeetCode 48. Rotate Image

    Đề bài:
    Cho một ma trận 2D vuông kích thước n x n (matrix) đại diện cho một hình ảnh

    Yêu cầu:
    → Xoay (rotate) hình ảnh này đi 90 độ theo chiều kim đồng hồ (clockwise)
    → Việc xoay phải được thực hiện trực tiếp tại chỗ (in-place): nghĩa là phải chỉnh sửa ma trận đầu vào matrix mà KHÔNG được cấp phát thêm một ma trận 2D mới nào khác

    Ví dụ (Minh họa logic xoay):
        Input:
            [ [1, 2, 3],
              [4, 5, 6],
              [7, 8, 9] ]

        Xoay 90 độ (clockwise)

        Output:
            [ [7, 4, 1],
              [8, 5, 2],
              [9, 6, 3] ]
*/

void rotate(vector<vector<int>>& matrix){
    vector<vector<int>> temp = matrix;
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix.size(); j++){
            matrix[i][j] = temp[matrix.size() - j - 1][i];
        }
    }
}

int main(){
    FAST_IO;

    int n; cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    FORI(i, n){
        FORI(j, n){
            cin >> matrix[i][j];
        }
    }

    rotate(matrix);
    for(auto v : matrix){
        FORI(i, v.size()){
            cout << v[i] << " ";
        }
        cout << endl;
    }
    return 0;
}