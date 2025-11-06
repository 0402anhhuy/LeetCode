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
    LeetCode 2149. Rearrange Array Elements by Sign

    Đề bài:
    Cho một mảng số nguyên **nums** có độ dài chẵn, bao gồm số lượng **số nguyên dương** và **số nguyên âm** bằng nhau.

    Yêu cầu:
    Sắp xếp lại mảng **nums** để thỏa mãn các điều kiện sau:
    1. **Từng cặp số nguyên liền kề** phải có dấu đối lập (một dương, một âm).
    2. **Thứ tự tương đối** của các số cùng dấu (ví dụ: tất cả các số dương) phải được **giữ nguyên** như trong mảng đầu vào.
    3. Phần tử **đầu tiên** của mảng được sắp xếp lại phải là **số nguyên dương**.
    → Trả về mảng đã được sắp xếp lại.

    Ví dụ:
        Input: nums = [3, 1, -2, -5, 2, -4]
        → Số dương (giữ thứ tự): [3, 1, 2]
        → Số âm (giữ thứ tự): [-2, -5, -4]
        → Kết quả: [Số dương 1, Số âm 1, Số dương 2, Số âm 2, ...]
        → Output: [3, -2, 1, -5, 2, -4]
*/

vector<int> rearrangeArray(vector<int>& nums){
    int posIndex = 0, negIndex = 1, n = nums.size();
    vector<int> ans(n, 0);

    for(int num : nums){
        if(num > 0){
            ans[posIndex] = num;
            posIndex += 2;
        }
        else{
            ans[negIndex] = num;
            negIndex += 2;
        }
    }
    return ans;
}

int main(){
    FAST_IO;

    int n; cin >> n;
    vector<int> nums(n);
    FORI(i, n) cin >> nums[i];

    vector<int> ans = rearrangeArray(nums);
    FORI(i, n) cout << ans[i] << " ";
    return 0;
}