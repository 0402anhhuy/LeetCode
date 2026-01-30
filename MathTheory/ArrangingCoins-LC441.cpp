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
    LeetCode 441. Arranging Coins

    Đề bài:
    Bạn có n đồng xu và muốn xếp chúng thành hình một chiếc cầu thang
    Cấu trúc cầu thang:
    → Hàng thứ 1 có đúng 1 đồng xu.
    → Hàng thứ 2 có đúng 2 đồng xu.
    → Hàng thứ i có đúng i đồng xu.
    Hàng cuối cùng của cầu thang có thể không đầy đủ (có ít hơn số lượng cần thiết)

    Yêu cầu:
    → Cho số nguyên n, hãy tìm và trả về số lượng hàng hoàn chỉnh mà bạn có thể xây dựng được

    Ví dụ:
        Input: n = 5
        → Hàng 1: 1 đồng xu (còn dư 4)
        → Hàng 2: 2 đồng xu (còn dư 2)
        → Hàng 3: Cần 3 đồng xu nhưng chỉ còn 2 -> Hàng này không hoàn chỉnh
        → Số hàng hoàn chỉnh là 2
        → Output: 2

        Input: n = 8
        → Hàng 1: 1
        → Hàng 2: 2
        → Hàng 3: 3 (tổng đã dùng 6, còn dư 2)
        → Hàng 4: Cần 4 nhưng chỉ còn 2 -> Không hoàn chỉnh
        → Số hàng hoàn chỉnh là 3
        → Output: 3
*/

int arrangeCoins(int n){
    int l = 0, r = n, ans = 0;
    
    while(l <= r){
        long long m = l + (r - l) / 2;
        long long sum = (m * (m + 1)) / 2;
        if(sum <= n){
            ans = m;
            l = m + 1;
        }
        else{
            r = m - 1;
        }
    }

    return ans;
}

int main(){
    FAST_IO;

    int n; cin >> n;

    int ans = arrangeCoins(n);
    cout << ans;
    return 0;
}