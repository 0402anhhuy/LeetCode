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
    LeetCode 2558. Take Gifts From the Richest Pile

    Đề bài:
        Cho mảng gifts[] biểu thị số quà trong từng đống và số nguyên k.
        Mỗi giây, ta thực hiện:
            - Chọn đống có nhiều quà nhất
            - Giảm số quà trong đống đó xuống bằng floor(sqrt(số quà ban đầu))
            - Lặp lại quá trình này k lần

    Sau k giây, trả về tổng số quà còn lại trong tất cả các đống

    Ví dụ:
        gifts = [25,64,9,4,100], k = 4
        Các bước: [25,64,9,4,100] → [25,64,9,4,10] → [25,8,9,4,10] → [5,8,9,4,10] → [5,8,9,4,3]
        Tổng còn lại = 29
*/


long long pickGifts(vector<int>& gifts, int k){
    priority_queue<int> tempGift(gifts.begin(), gifts.end());

    while(k--){
        int tmp = tempGift.top();
        tempGift.push((int)sqrt(tmp));
        tempGift.pop();
    }

    long long sum = 0;
    while(!tempGift.empty()){
        sum += tempGift.top();
        tempGift.pop();
    }
    return sum;
}

int main(){
    FAST_IO;

    int n, k; cin >> n;
    vector<int> gifts(n);
    FORI(i, n) cin >> gifts[i];
    cin >> k;

    ll ans = pickGifts(gifts, k);
    cout << ans;
    return 0;
}