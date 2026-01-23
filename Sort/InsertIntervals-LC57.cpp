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
    LeetCode 57. Insert Interval

    Đề bài:
    Cho một danh sách các khoảng intervals đã được sắp xếp theo thứ tự tăng dần của điểm bắt đầu
    Các khoảng này hiện tại không hề chồng lấn (overlap) lên nhau
    Bạn được cho thêm một khoảng mới newInterval

    Yêu cầu:
    → Chèn newInterval vào danh sách sao cho:
        1. Danh sách vẫn giữ được thứ tự sắp xếp theo điểm bắt đầu
        2. Hợp nhất (merge) tất cả các khoảng bị chồng lấn sau khi chèn để đảm bảo không có khoảng nào giao nhau trong kết quả cuối cùng

    Ví dụ:
        Input: intervals = [[1, 3], [6, 9]], newInterval = [2, 5]
        → Khoảng [2, 5] chồng lấn với [1, 3] vì 2 < 3
        → Hợp nhất thành: [min(1, 2), max(3, 5)] = [1, 5]
        → Khoảng [6, 9] không bị chồng lấn
        → Output: [[1, 5], [6, 9]]
*/

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval){
    vector<vector<int>> ans;
    int i = 0, n = intervals.size();

    while(i < n && intervals[i][1] < newInterval[0]){
        ans.push_back(intervals[i]);
        i++;
    }

    while(i < n && intervals[i][0] <= newInterval[1]){
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }
    ans.push_back(newInterval);

    while(i < n){
        ans.push_back(intervals[i]);
        i++;
    }

    return ans;
}

int main(){
    FAST_IO;

    int n; cin >> n;
    vector<vector<int>> intervals(n, vector<int>(2));
    vector<int> newInterval(2);

    FORI(i, n){
        cin >> intervals[i][0] >> intervals[i][1];
    }

    cin >> newInterval[0] >> newInterval[1];

    vector<vector<int>> ans = insert(intervals, newInterval);
    FORI(i, ans.size()){
        cout << ans[i][0] << " " << ans[i][1] << endl;
    }
    return 0;
}