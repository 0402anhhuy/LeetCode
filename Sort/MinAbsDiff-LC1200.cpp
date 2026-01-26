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
    LeetCode 1200. Minimum Absolute Difference

    Đề bài:
    Cho một mảng các số nguyên khác nhau từng đôi một (distinct) có tên là arr

    Yêu cầu:
    1. Tìm giá trị hiệu số tuyệt đối nhỏ nhất (minimum absolute difference) giữa hai phần tử bất kỳ trong mảng
    2. Tìm tất cả các cặp phần tử [a, b] thỏa mãn:
       → a, b thuộc mảng arr
       → a < b
       → Hiệu số b - a đúng bằng giá trị nhỏ nhất vừa tìm được
    3. Trả về danh sách các cặp này theo thứ tự tăng dần của các cặp

    Ví dụ:
        Input: arr = [4, 2, 1, 3]
        → Hiệu nhỏ nhất giữa các cặp là 1 (ví dụ: 2-1=1, 3-2=1, 4-3=1)
        → Các cặp thỏa mãn: [1, 2], [2, 3], [3, 4]
        → Output: [[1, 2], [2, 3], [3, 4]]

        Input: arr = [3, 8, -10, 23, 19, -4, -14, 27]
        → Hiệu nhỏ nhất là 4
        → Các cặp: [[-14, -10], [19, 23], [23, 27]]
        → Output: [[-14, -10], [19, 23], [23, 27]]
*/

vector<vector<int>> minimumAbsDifference(vector<int>& arr){
    sort(arr.begin(), arr.end());

    int minAbs = INT_MAX;
    for(int i = 1; i < arr.size(); i++){
        minAbs = min(minAbs, arr[i] - arr[i - 1]);
    }

    vector<vector<int>> ans;
    for(int i = 1; i < arr.size(); i++){
        if(arr[i] - arr[i - 1] == minAbs){
            ans.push_back({arr[i - 1], arr[i]});
        }
    }

    return ans;
}

int main(){
    FAST_IO;

    int n; cin >> n;
    vector<int> arr(n);
    FORI(i, n) cin >> arr[i];

    vector<vector<int>> ans = minimumAbsDifference(arr);
    FORI(i, ans.size()){
        FORI(j, ans[0].size()){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}