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
    LeetCode 1266. Minimum Time Visiting All Points

    Đề bài:
    Trên một mặt phẳng 2D, cho n điểm có tọa độ nguyên points[i] = [xi, yi]
    Bạn cần xuất phát từ điểm đầu tiên và đi qua tất cả các điểm theo đúng thứ tự đã cho trong mảng

    Quy tắc di chuyển (Trong 1 giây, bạn có thể):
    1. Di chuyển dọc 1 đơn vị
    2. Di chuyển ngang 1 đơn vị
    3. Di chuyển chéo (kết hợp cả ngang và dọc cùng lúc)
       → Tức là từ (x, y) có thể đến (x+1, y+1), (x-1, y+1), v.v.

    Yêu cầu:
    → Tính thời gian tối thiểu (tổng số giây) để đi thăm tất cả các điểm theo đúng thứ tự

    Ví dụ:
        Input: points = [[1, 1], [3, 4], [-1, 0]]
        → Từ [1, 1] đến [3, 4]: 
          Khoảng cách x là 2, khoảng cách y là 3
          Đi chéo 2 bước và đi dọc 1 bước => Mất 3 giây
        → Từ [3, 4] đến [-1, 0]: 
          Khoảng cách x là 4, khoảng cách y là 4
          Đi chéo 4 bước => Mất 4 giây
        → Tổng: 3 + 4 = 7 giây
        → Output: 7
*/

int minTimeToVisitAllPoints(vector<vector<int>>& points){
    int ans = 0;
    int n = points.size();

    for(int i = 1; i < n; i++){
        ans += max(abs(points[i][0] - points[i - 1][0]), abs(points[i][1] - points[i - 1][1]));
    }

    return ans;
}

int main(){
    FAST_IO;

    int n; cin >> n;
    vector<vector<int>> points(n, vector<int>(2));
    FORI(i, n) cin >> points[i][0] >> points[i][1];

    int ans = minTimeToVisitAllPoints(points);
    cout << ans;
    return 0;
}