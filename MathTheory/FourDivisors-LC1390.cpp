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
    LeetCode 1390. Four Divisors

    Đề bài: Cho một mảng số nguyên nums

    Yêu cầu:
    → Với mỗi số nguyên trong mảng, hãy tìm các ước số (divisors) của nó
    → Chỉ xét những số có đúng 4 ước số
    → Tính tổng của tất cả các ước số của những số thỏa mãn điều kiện trên
    → Trả về tổng cuối cùng. Nếu không có số nào có đúng 4 ước số, trả về 0

    Ví dụ:
        Input: nums = [21, 4, 7]
        → Số 21: Có 4 ước là {1, 3, 7, 21}. Tổng = 1 + 3 + 7 + 21 = 32
        → Số 4: Có 3 ước là {1, 2, 4}
        → Số 7: Có 2 ước là {1, 7}
        → Kết quả: 32
*/

int sumIfFourDivisors(int x){
    int cnt = 0, sum = 0;

    for(int i = 1; i * i <= x; i++){
        if(x % i == 0){
            if(i == (x / i)){
                cnt++;
                sum += i;
            }
            else{
                cnt += 2;
                sum += (i + (x / i));
            }
        }
    }

    if(cnt == 4) return sum;
    return 0;
}


int sumFourDivisors(vector<int>& nums){
    int ans = 0;

    map<int, int> numFreq;
    for(int num : nums){
        numFreq[num]++;
    }

    for(auto &[n, f] : numFreq){
        ans += sumIfFourDivisors(n) * f;
    }

    return ans;
}

int main(){
    FAST_IO;

    int n; cin >> n;
    vector<int> nums(n);
    FORI(i, n) cin >> nums[i];

    int ans = sumFourDivisors(nums);
    cout << ans;
    return 0;
}