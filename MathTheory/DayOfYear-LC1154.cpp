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
    LeetCode 1154. Day of the Year

    Đề bài:
    Cho một chuỗi date biểu diễn ngày tháng theo lịch Gregorian với định dạng YYYY-MM-DD (Năm-Tháng-Ngày)

    Yêu cầu:
    → Tính và trả về số thứ tự của ngày đó trong năm (từ 1 đến 366)

    Ví dụ:
        Input: date = "2019-01-09"
        → Đây là ngày 9 tháng 1 năm 2019
        → Output: 9

        Input: date = "2019-02-10"
        → Tháng 1 có 31 ngày + 10 ngày của tháng 2 = 41
        → Output: 41

    Lưu ý đặc biệt:
    → Cần kiểm tra xem năm đó có phải là năm nhuận hay không để xác định tháng 2 có 28 hay 29 ngày
*/

int dayOfYear(string date){
    vector<int> months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int year = stoi(date.substr(0, 4));
    if(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) months[1] = 29;

    int month = stoi(date.substr(5,2));
    int day = stoi(date.substr(8,2));

    int ans = 0;
    for(int i = 0; i < month-1; i++){
        ans += months[i];
    }

    return ans + day;
}

int main(){
    FAST_IO;

    string date; cin >> date;
    int ans = dayOfYear(date);

    cout << ans;
    return 0;
}