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
    LeetCode 54. Spiral Matrix

    Đề bài:
    Cho một ma trận kích thước m x n. Hãy duyệt qua tất cả các phần tử của ma trận theo thứ tự xoắn ốc (spiral order)

    Quy tắc duyệt xoắn ốc:
    1. Bắt đầu từ góc trên cùng bên trái
    2. Đi từ trái sang phải dọc theo hàng trên cùng
    3. Đi từ trên xuống dưới dọc theo cột ngoài cùng bên phải
    4. Đi từ phải sang trái dọc theo hàng dưới cùng
    5. Đi từ dưới lên trên dọc theo cột ngoài cùng bên trái
    6. Lặp lại quá trình này cho các lớp bên trong cho đến khi đi qua tất cả phần tử

    Yêu cầu:
    → Trả về một danh sách chứa tất cả phần tử của ma trận theo thứ tự đã duyệt

    Ví dụ:
        Input: matrix = [
          [1, 2, 3],
          [4, 5, 6],
          [7, 8, 9]
        ]
        → Thứ tự: 1 -> 2 -> 3 -> 6 -> 9 -> 8 -> 7 -> 4 -> 5
        → Output: [1, 2, 3, 6, 9, 8, 7, 4, 5]
*/

vector<int> spiralOrder(vector<vector<int>>& matrix){
    int m = matrix.size();
    int n = matrix[0].size();

    int top = 0, bottom = m - 1;
    int left = 0, right = n - 1;

    vector<int> ans;
    while(top <= bottom && left <= right){
        for(int j = left; j <= right; j++){
            ans.push_back(matrix[top][j]);
        }

        top++;

        for(int i = top; i <= bottom; i++){
            ans.push_back(matrix[i][right]);
        }

        right--;

        if(top <= bottom){
            for(int j = right; j >= left; j--){
                ans.push_back(matrix[bottom][j]);
            }
            bottom--;
        }

        if(left <= right){
            for(int i = bottom; i >= top; i--){
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }

    return ans;
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

    vector<int> ans = spiralOrder(matrix);
    FORI(i, ans.size()) cout << ans[i] << " ";
    return 0;
}