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
    LeetCode 992. Subarrays with K Different Integers

    Đề bài:
    Cho một mảng số nguyên nums và một số nguyên k
    Một mảng được gọi là tốt (good) nếu số lượng các số nguyên khác nhau trong mảng đó đúng bằng k

    Yêu cầu:
    → Đếm và trả về số lượng các mảng con (subarray) liên tục của nums thỏa mãn điều kiện là mảng tốt

    Ví dụ:
        Input: nums = [1, 2, 1, 2, 3], k = 2
        → Các mảng con có đúng 2 số khác nhau:
          [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]
        → Output: 7

    Công thức
        exactly(K) = atMost(K) - atMost(K - 1)
*/

int atMostKDistinct(vector<int>& nums, int k){
    if(k == 0) return 0;

    unordered_map<int, int> freq;
    int left = 0, ans = 0;
    
    for(int right = 0; right < nums.size(); right++){
        freq[nums[right]]++;
        
        while(freq.size() > k){
            freq[nums[left]]--;
            if(freq[nums[left]] == 0) freq.erase(nums[left]);
            left++;
        }
        
        ans += right - left + 1;
    }
    return ans;
}

int subarraysWithKDistinct(vector<int>& nums, int k){
    return atMostKDistinct(nums, k) - atMostKDistinct(nums, k - 1);
}

int main(){
    FAST_IO;

    int n, k; cin >> n >> k;
    vector<int> nums(n);
    for(int i = 0 ; i < n; i++){
        cin >> nums[i];
    }

    int ans = subarraysWithKDistinct(nums, k);
    cout << ans;
    return 0;
}