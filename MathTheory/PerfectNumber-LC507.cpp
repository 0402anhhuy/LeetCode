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
    LeetCode 507. Perfect Number

    Đề bài:
    Một số hoàn hảo là một số nguyên dương mà tổng các ước số dương của nó bằng chính số đó
    → Ước số của x là số nguyên có thể chia hết x một cách trọn vẹn

    Yêu cầu:
    → Cho một số nguyên num
    → Trả về true nếu nó là số hoàn hảo, ngược lại trả về false

    Ví dụ:
        Input: num = 28
        → Các ước của 28 (không tính 28): 1, 2, 4, 7, 14
        → Tổng: 1 + 2 + 4 + 7 + 14 = 28
        → Output: true

        Input: num = 7
        → Các ước của 7 (không tính 7): 1
        → Tổng: 1 (khác 7)
        → Output: false

    Công thức số hoàn hảo:
        2ⁱ⁻¹(2ⁱ-1)
        → (2ⁱ-1) là số nguyên tố
        → i là số nguyên tố
*/

bool isPrime(long long x){
    if(x < 2) return false;
    for(long long i = 2; i * i <= x; i++){
        if(x % i == 0) return false;
    }
    return true;
}

bool checkPerfectNumber(int num){
    for(int p = 2; p <= 31; p++){
        if(isPrime(p)){
            long long tmp1 = (1LL << p) - 1;
            if(isPrime(tmp1)){
                long long tmp2 = (1LL << (p - 1)) * tmp1;
                if(tmp2 == num) return true;
            }
        }
    }
    return false;
}

int main(){
    FAST_IO;

    int num; cin >> num;
    cout << boolalpha << checkPerfectNumber(num);
    return 0;
}