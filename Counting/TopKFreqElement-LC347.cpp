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
    LeetCode 347. Top K Frequent Elements

    Đề bài:
    Cho một mảng số nguyên nums và một số nguyên k

    Yêu cầu:
    → Tìm và trả về k phần tử xuất hiện thường xuyên nhất (có tần suất xuất hiện cao nhất) trong mảng
    → Bạn có thể trả về kết quả theo bất kỳ thứ tự nào

    Thử thách:
    → Thuật toán của bạn nên có độ phức tạp thời gian tốt hơn O(n log n), trong đó n là kích thước của mảng

    Ví dụ:
        Input: nums = [1, 1, 1, 2, 2, 3], k = 2
        → Số 1 xuất hiện: 3 lần.
        → Số 2 xuất hiện: 2 lần.
        → Số 3 xuất hiện: 1 lần.
        → Hai phần tử xuất hiện nhiều nhất là 1 và 2
        → Output: [1, 2]

        Input: nums = [1], k = 1
        → Output: [1]
*/

vector<int> topKFrequent(vector<int>& nums, int k){
    unordered_map<int, int> numFreq;
    for(int num : nums){
        numFreq[num]++;
    }

    int n = nums.size();
    vector<vector<int>> bucket(n + 1);

    for(auto &[n, f] : numFreq){
        bucket[f].push_back(n);
    }

    vector<int> res;
    for(int i = n; i >= 0; i--){
        for(int x : bucket[i]){
            res.push_back(x);
            if(res.size() == k) return res;
        }
    }

    return res;
}

int main(){
    FAST_IO;

    int n, k; cin >> n >> k;
    vector<int> nums(n);
    FORI(i, n) cin >> nums[i];

    vector<int> ans = topKFrequent(nums, k);
    FORI(i, ans.size()) cout << ans[i] << " ";
    return 0;
}