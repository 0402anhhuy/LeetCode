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
    LeetCode 2521. Distinct Prime Factors of Product of Array

    Đề bài:
    Cho một mảng các số nguyên dương nums
    Xét một số nguyên là tích (product) của tất cả các phần tử trong mảng nums

    Ví dụ:
        Input: nums = [2, 4, 3, 7, 10, 6]
        → Output: 4
*/

set<int> result;

void primeFactor(int a){
    for(int i = 2; i * i <= a; i++){
        while(a % i == 0){
            result.insert(i);
            a /= i;
        }
    }
    if(a > 1) result.insert(a);
}

int distinctPrimeFactors(vector<int>& nums){
    for(int num : nums){
        primeFactor(num);
    }

    return result.size();
}

int main(){
    FAST_IO;

    int n; cin >> n;
    vector<int> nums(n);
    FORI(i, n) cin >> nums[i];

    int ans = distinctPrimeFactors(nums);
    cout << ans;
    return 0;
}