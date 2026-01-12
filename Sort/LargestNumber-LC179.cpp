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
    LeetCode 179. Largest Number

    Đề bài:
    Cho một danh sách các số nguyên không âm nums

    Yêu cầu:
    → Sắp xếp và ghép các số này lại với nhau sao cho chúng tạo thành số lớn nhất có thể
    → Vì kết quả có thể rất lớn, hãy trả về kết quả dưới dạng một chuỗi (string) thay vì số nguyên

    Ví dụ:
        Input: nums = [10, 2]
        → Ghép "10" + "2" = "102"
        → Ghép "2" + "10" = "210"
        → Số lớn nhất là 210.
        → Output: "210"

        Input: nums = [3, 30, 34, 5, 9]
        → Ghép lại tối ưu nhất: "9" + "5" + "34" + "3" + "30"
        → Output: "9534330"
*/

bool compare(string a, string b){
    return a + b > b + a;
}

string largestNumber(vector<int>& nums){
    vector<string> numStrings;
    for(int num : nums){
        numStrings.push_back(to_string(num));
    }

    sort(numStrings.begin(), numStrings.end(), compare);

    if(numStrings[0] == "0") return "0";

    string ans = "";
    for(string numString : numStrings){
        ans += numString;
    }

    return ans;
}

int main(){
    FAST_IO;

    int n; cin >> n;
    vector<int> nums(n);
    FORI(i, n) cin >> nums[i];

    string ans = largestNumber(nums);
    cout << ans;
    return 0;
}