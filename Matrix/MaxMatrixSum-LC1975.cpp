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
    LeetCode 1975. Maximum Matrix Sum

    Đề bài:
    Cho một ma trận vuông matrix kích thước n x n. Bạn có thể thực hiện thao tác sau với số lần bất kỳ:
    → Chọn hai phần tử bất kỳ cạnh nhau (chung cạnh) và nhân cả hai phần tử đó với -1

    Yêu cầu:
    → Tìm cách thực hiện thao tác trên để tổng của tất cả các phần tử trong ma trận đạt giá trị lớn nhất
    → Trả về giá trị tổng lớn nhất đó

    Ví dụ:
        Input: matrix = [[1, -1], [-1, 1]]
        → Có 2 số âm (số chẵn).
        → Nhân hai số ở hàng đầu với -1: [[-1, 1], [-1, 1]]
        → Nhân hai số ở cột đầu với -1: [[1, 1], [1, 1]]
        → Tổng: 1 + 1 + 1 + 1 = 4
        → Output: 4
*/

long long maxMatrixSum(vector<vector<int>>& matrix){
    int minValue = INT_MAX, negCount = 0;
    long long sum = 0;

    for(auto row : matrix){
        for(int x : row){
            sum += abs(x);
            if(x < 0){
                negCount++;
            }

            minValue = min(minValue, abs(x));
        }
    }

    if(negCount % 2 != 0){
        sum -= 2 * minValue;
    }

    return sum;
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

    long long ans = maxMatrixSum(matrix);
    cout << ans;
    return 0;
}