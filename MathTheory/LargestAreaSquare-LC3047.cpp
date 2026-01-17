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
    LeetCode 3047. Find the Largest Area of Square Inside Two Rectangles

    Đề bài:
    Cho n hình chữ nhật trên mặt phẳng 2D, có các cạnh song song với trục tọa độ
    Bạn được cung cấp hai mảng tọa độ:
    → bottomLeft[i] = [ai, bi]: Tọa độ góc dưới bên trái của hình chữ nhật thứ i
    → topRight[i] = [ci, di]: Tọa độ góc trên bên phải của hình chữ nhật thứ i

    Yêu cầu:
    → Tìm diện tích lớn nhất của một hình vuông có thể nằm gọn bên trong vùng giao nhau (intersection) của ít nhất hai hình chữ nhật bất kỳ
    → Nếu không có vùng giao nhau nào giữa các cặp hình chữ nhật, trả về 0

    Ví dụ:
        Input: bottomLeft = [[1, 1], [2, 2], [3, 1]], topRight = [[3, 3], [4, 4], [6, 6]]
        → Xét cặp hình chữ nhật 0 và 1: Vùng giao nhau là hình chữ nhật có góc [2, 2] và [3, 3]
          Vùng này là một hình vuông cạnh 1. Diện tích = 1
        → Xét các cặp khác, tìm diện tích hình vuông lớn nhất có thể chứa trong phần giao
        → Output: 1
*/

long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight){
    int n = bottomLeft.size();

    int maxSide = 0;
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            int w = min(topRight[i][0], topRight[j][0]) - max(bottomLeft[i][0], bottomLeft[j][0]);
            int h = min(topRight[i][1], topRight[j][1]) - max(bottomLeft[i][1], bottomLeft[j][1]);

            maxSide = max(maxSide, min(w, h));
        }
    }

    return 1LL * maxSide * maxSide;
}

int main(){
    FAST_IO;

    int n; cin >> n;

    vector<vector<int>> bottomLeft(n, vector<int>(2)), topRight(n, vector<int>(2));
    FORI(i, n){
        cin >> bottomLeft[i][0] >> bottomLeft[i][1];
    }

    FORI(i, n){
        cin >> topRight[i][0] >> topRight[i][1];
    }

    long long ans = largestSquareArea(bottomLeft, topRight);
    cout << ans;
    return 0;
}