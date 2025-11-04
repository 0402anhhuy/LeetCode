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
    LeetCode 3318. Find X-Sum of All K-Long Subarrays I

    Đề bài:
    Cho một mảng số nguyên nums, độ dài mảng con k, và một số nguyên x (số lượng phần tử thường xuyên nhất cần xét)
    Định nghĩa x-sum của một mảng là:
    1. Đếm tần suất xuất hiện của tất cả các phần tử
    2. Chỉ giữ lại các lần xuất hiện của x phần tử có tần suất cao nhất
    3. Nếu hai phần tử có tần suất bằng nhau, phần tử có giá trị lớn hơn được coi là "thường xuyên hơn" (ưu tiên hơn)
    4. Nếu mảng có ít hơn x phần tử phân biệt, x-sum là tổng của toàn bộ mảng
    5. Tính tổng của mảng kết quả sau khi loại bỏ các phần tử không được giữ lại

    Yêu cầu:
    → Trả về một mảng kết quả (answer) có độ dài n - k + 1
    → Với mỗi chỉ số i, answer[i] là x-sum của mảng con (subarray) độ dài k bắt đầu từ nums[i] (tức là nums[i..i + k - 1])

    Ví dụ:
        Input: nums = [1, 1, 2, 2, 3, 4, 2, 3], k = 6, x = 2
        → Mảng con đầu tiên: [1, 1, 2, 2, 3, 4]
            - Tần suất: {1: 2, 2: 2, 3: 1, 4: 1}
            - Top 2 (Ưu tiên giá trị lớn hơn khi tần suất bằng nhau): {2} (tần suất 2), {1} (tần suất 2)
            - x-sum: 1 + 1 + 2 + 2 = 6
        → Output: [6, 10, 12]
*/

bool compare(pair<int, int> a, pair<int, int> b){
    if(a.second == b.second) return a.first > b.first;
    return a.second > b.second;
}


int XSum(const vector<int>& sub, int x){
    unordered_map<int,int> freq;
    for(int v : sub) freq[v]++;

    vector<pair<int, int>> arr(freq.begin(), freq.end());
    sort(arr.begin(), arr.end(), compare);

    int sum = 0, cnt = 0;
    for(auto &p : arr){
        if (cnt == x) break;
        sum += p.first * p.second;
        cnt++;
    }
    return sum;
}


vector<int> findXSum(vector<int>& nums, int k, int x){
    int n = nums.size();
    vector<int> ans;
    for(int i = 0; i + k <= n; i++){
        vector<int> sub(nums.begin() + i, nums.begin() + i + k);
        ans.push_back(XSum(sub, x));
    }
    return ans;
}


int main(){
    FAST_IO;

    int n, k, x; cin >> n >> k >> x;
    vector<int> nums(n);
    FORI(i, n) cin >> nums[i];

    vector<int> ans = findXSum(nums, k, x);
    FORI(i, ans.size()) cout << ans[i] << " ";
    return 0;
}