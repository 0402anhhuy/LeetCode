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
    LeetCode 961. N-Repeated Element in Size 2N Array

        Đề bài:
        Cho một mảng số nguyên nums có các tính chất sau:
        1. Độ dài của mảng là 2n (luôn là số chẵn)
        2. Mảng chứa n + 1 phần tử độc nhất (unique elements)
        3. Có duy nhất một phần tử trong mảng được lặp lại đúng n lần

        Yêu cầu:
        → Tìm và trả về phần tử xuất hiện n lần đó

        Ví dụ:
            Input: nums = [1, 2, 3, 3]
            → Độ dài mảng là 4 (n = 2)
            → Số lượng phần tử độc nhất: {1, 2, 3} (3 phần tử, tức là n + 1)
            → Phần tử 3 xuất hiện 2 lần (đúng n lần)
            → Output: 3
*/

int repeatedNTimes(vector<int>& nums){
    map<int, int> numFreq;
    for(int num : nums){
        numFreq[num]++;
        if(numFreq[num] > 1) return num;
    }
    return -1;
}

int main(){
    FAST_IO;

    int n; cin >> n;
    vector<int> nums(n);
    FORI(i, n) cin >> nums[i];

    int ans = repeatedNTimes(nums);
    cout << ans;
    return 0;
}