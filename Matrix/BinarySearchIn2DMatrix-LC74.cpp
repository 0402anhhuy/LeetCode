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
    LeetCode 74. Search a 2D Matrix

    Đề bài:
    Cho một ma trận số nguyên matrix kích thước m x n có hai tính chất đặc biệt:
    1. Mỗi hàng được sắp xếp theo thứ tự không giảm
    2. Số nguyên đầu tiên của mỗi hàng lớn hơn số cuối cùng của hàng trước đó

    Điều này có nghĩa là nếu ta trải phẳng ma trận ra thành một mảng một chiều, mảng đó sẽ hoàn toàn được sắp xếp theo thứ tự tăng dần

    Yêu cầu:
    → Cho một số nguyên target, kiểm tra xem nó có xuất hiện trong ma trận hay không
    → Trả về true nếu có, ngược lại trả về false
    → Ràng buộc hiệu năng: Thuật toán phải có độ phức tạp thời gian là O(log(m * n))

    Ví dụ:
        Input: matrix = [
          [1,  3,  5,  7],
          [10, 11, 16, 20],
          [23, 30, 34, 60]
        ], target = 3
        → Giá trị 3 nằm ở hàng 0, cột 1
        → Output: true
*/

bool searchMatrix(vector<vector<int>>& matrix, int target){
    int m = matrix.size();
    int n = matrix[0].size();

    vector<int> first;
    for(int i = 0; i < m; i++){
        first.push_back(matrix[i][0]);
    }

    int row = lower_bound(first.begin(), first.end(), target) - first.begin();

    if(row == m || first[row] > target){
        row--;
    }

    if(row < 0) return false;

    return binary_search(matrix[row].begin(), matrix[row].end(), target);
}


int main(){
    FAST_IO;

    int m, n, target; cin >> m >> n >> target;
    vector<vector<int>> matrix(m, vector<int>(n));

    FORI(i, m){
        FORI(j, n){
            cin >> matrix[i][j];
        }
    }

    cout << boolalpha << searchMatrix(matrix, target);
    return 0;
}