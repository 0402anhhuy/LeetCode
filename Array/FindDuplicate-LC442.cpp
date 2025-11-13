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
    LeetCode 442. Find All Duplicates in an Array

    Đề bài:
    Cho một mảng số nguyên nums có độ dài n
    → Các số nguyên trong mảng nằm trong phạm vi [1, n]
    → Mỗi số nguyên xuất hiện tối đa hai lần

    Yêu cầu:
    → Trả về một mảng chứa tất cả các số nguyên xuất hiện hai lần trong mảng nums
    → Ràng buộc hiệu suất: Thuật toán phải chạy trong thời gian O(n) và chỉ được sử dụng không gian phụ trợ hằng số O(1) (không tính không gian dùng để lưu trữ kết quả đầu ra)
*/

vector<int> findDuplicates(vector<int>& nums){
    vector<int> ans;

    for(int x : nums){
        int idx = abs(x) - 1;
        if(nums[idx] < 0){
            ans.push_back(idx + 1);
        }
        else{
            nums[idx] = -nums[idx];
        }
    }
    return ans;
}

int main(){
    FAST_IO;

    int n; cin >> n;
    vector<int> nums(n);
    FORI(i, n) cin >> nums[i];

    vector<int> ans = findDuplicates(nums);
    FORI(i, ans.size()) cout << ans[i] << " "; 
    return 0;
}