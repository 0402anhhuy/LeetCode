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
    LeetCode 2943. Maximize Area of Square Hole in Grid

    Đề bài:
    Bạn có một lưới được tạo bởi n + 2 thanh ngang và m + 2 thanh dọc
    Các thanh được đánh số từ 1.
    → hBars: Danh sách các thanh ngang bạn có thể loại bỏ
    → vBars: Danh sách các thanh dọc bạn có thể loại bỏ

    Quy tắc:
    Khi loại bỏ các thanh liên tiếp, khoảng cách giữa các thanh còn lại sẽ tăng lên, tạo thành một "lỗ hổng" lớn hơn

    Yêu cầu:
    → Tìm diện tích lớn nhất của một lỗ hổng có hình vuông (square-shaped) sau khi đã loại bỏ một số thanh (hoặc không loại bỏ thanh nào).

    Ví dụ:
        Input: n = 2, m = 1, hBars = [2, 3], vBars = [2]
        → hBars có thanh 2 và 3 liên tiếp. Nếu bỏ cả 2, khoảng trống chiều dọc tối đa là 3 đơn vị (tạo bởi thanh 1 và thanh 4 còn lại). 
        → vBars có thanh 2. Nếu bỏ thanh 2, khoảng trống chiều ngang tối đa là 2 đơn vị (tạo bởi thanh 1 và thanh 3 còn lại).
        → Để tạo hình vuông, cạnh lớn nhất có thể là min(3, 2) = 2
        → Diện tích: 2 * 2 = 4
        → Output: 4
*/

int maxGap(vector<int>& bars){
    if(bars.empty()) return 1;

    sort(bars.begin(), bars.end());

    int maxLen = 1;
    int curr = 1;

    for(int i = 1; i < bars.size(); i++){
        if(bars[i] == bars[i - 1] + 1){
            curr++;
        } 
        else{
            curr = 1;
        }
        maxLen = max(maxLen, curr);
    }

    return maxLen + 1;
}

int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars){
    int side = min(maxGap(hBars), maxGap(vBars));
    int area = side * side;

    return area;
}

int main(){
    FAST_IO;

    int n, m, hBarSize, vBarSize; cin >> n >> m >> hBarSize >> vBarSize;

    vector<int> hBars(hBarSize), vBars(vBarSize);
    FORI(i, hBarSize) cin >> hBars[i];
    FORI(i, vBarSize) cin >> vBars[i];

    int ans = maximizeSquareHoleArea(n, m, hBars, vBars);
    cout << ans;
    return 0;
}