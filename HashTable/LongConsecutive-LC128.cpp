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
    LeetCode 128. Longest Consecutive Sequence

    Đề bài:
    Cho một mảng số nguyên nums chưa được sắp xếp. Bạn cần tìm độ dài của dãy con gồm các số nguyên liên tiếp dài nhất

    Định nghĩa:
    → Một dãy liên tiếp là dãy các số có dạng x, x+1, x+2, ... (ví dụ: [1, 2, 3, 4])
    → Các con số này không nhất thiết phải nằm cạnh nhau trong mảng ban đầu.

    Yêu cầu:
    → Trả về độ dài của dãy liên tiếp dài nhất đó.
    → Ràng buộc hiệu năng: Thuật toán phải chạy trong độ phức tạp thời gian O(n)

    Ví dụ:
        Input: nums = [100, 4, 200, 1, 3, 2]
        → Các dãy liên tiếp có thể tìm thấy:
          - [100] (độ dài 1)
          - [200] (độ dài 1)
          - [1, 2, 3, 4] (độ dài 4)
        → Dãy dài nhất có độ dài là 4
        → Output: 4

        Input: nums = [0, 3, 7, 2, 5, 8, 4, 6, 0, 1]
        → Dãy liên tiếp: [0, 1, 2, 3, 4, 5, 6, 7, 8]
        → Output: 9
*/

int longestConsecutive(vector<int>& nums){
    unordered_set<int> s(nums.begin(), nums.end());

    int ans = 0;
    for(int x : s){
        if(!s.count(x - 1)){
            int cur = x;
            int len = 1;

            while(s.count(cur + 1)){
                cur++;
                len++;
            }

            ans = max(ans, len);
        }
    }

    return ans;
}


int main(){
    FAST_IO;

    int n; cin >> n;
    vector<int> nums(n);
    FORI(i, n) cin >> nums[i];

    int ans = longestConsecutive(nums);
    cout << ans;
    return 0;
}