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
    LeetCode 1578. Minimum Time to Make Rope Colorful

    Đề bài:
    Cho một chuỗi colors (màu sắc của các quả bóng) và một mảng neededTime (thời gian cần để loại bỏ quả bóng tương ứng)
    Alice muốn sợi dây "đầy màu sắc" (colorful), nghĩa là không có hai quả bóng liền kề nào cùng màu

    Yêu cầu:
    → Bob cần loại bỏ một số quả bóng để thỏa mãn điều kiện trên
    → Trả về tổng thời gian tối thiểu Bob cần để loại bỏ các quả bóng, sao cho không còn hai quả bóng liền kề nào cùng màu
    → Quy tắc xóa: Trong một nhóm các quả bóng liền kề cùng màu, chỉ giữ lại quả bóng có thời gian xóa lớn nhất (tốn thời gian nhất), và xóa bỏ tất cả các quả bóng còn lại trong nhóm đó

    Ví dụ:
        Input: colors = "abaac", neededTime = [1, 2, 3, 4, 5]
        → Nhóm cùng màu liền kề là "aa" (ở chỉ số 3 và 4)
        → neededTime: [4, 5]. Max là 5 (giữ lại quả bóng ở chỉ số 4)
        → Cần xóa quả bóng ở chỉ số 3 với thời gian 4
        → Output: 4 (thời gian tối thiểu)
*/

int minCost(string colors, vector<int>& neededTime){
    int n = neededTime.size();
    vector<int> dp(n);

    dp[0] = 0;
    for(int i = 1; i < n; i++){
        if(colors[i] == colors[i - 1]){
            dp[i] = dp[i - 1] + min(neededTime[i], neededTime[i - 1]);
            neededTime[i] = max(neededTime[i], neededTime[i - 1]);
        }
        else{
            dp[i] = dp[i - 1];
        }
    }
    return dp[n - 1];
}

int main(){
    FAST_IO;

    string colors; cin >> colors;
    int n; cin >> n;

    vector<int> times(n);
    FORI(i, n) cin >> times[i];

    int ans = minCost(colors, times);
    cout << ans;
    return 0;
}