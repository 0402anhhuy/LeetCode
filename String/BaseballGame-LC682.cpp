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
    LeetCode 682. Baseball Game

    Đề bài:
    Bạn đang ghi chép điểm cho một trận bóng chày với các quy tắc đặc biệt. 
    Ban đầu, danh sách điểm số của bạn trống. Bạn được cho một mảng các chuỗi operations

    Các thao tác (operations[i]):
    1. Số nguyên x: Ghi một điểm mới là x
    2. '+': Ghi một điểm mới bằng tổng của hai điểm gần nhất trước đó
    3. 'D': Ghi một điểm mới bằng gấp đôi điểm gần nhất trước đó
    4. 'C': Hủy bỏ điểm gần nhất trước đó (xóa nó khỏi danh sách)

    Yêu cầu:
    → Trả về tổng của tất cả các điểm số có trong danh sách sau khi đã thực hiện mọi thao tác
    → Đề bài đảm bảo mọi thao tác đều hợp lệ (ví dụ: khi có '+', chắc chắn trước đó đã có ít nhất 2 điểm)

    Ví dụ:
        Input: ops = ["5", "2", "C", "D", "+"]
        → "5": Danh sách [5]
        → "2": Danh sách [5, 2]
        → "C": Xóa 2, danh sách [5]
        → "D": 2 * 5 = 10, danh sách [5, 10]
        → "+": 5 + 10 = 15, danh sách [5, 10, 15]
        → Tổng: 5 + 10 + 15 = 30
        → Output: 30
*/

int calPoints(vector<string>& operations){
    vector<int> ans;
    for(string operation : operations){
        int n = ans.size();
        if(operation != "D" && operation != "C" && operation != "+"){
            int num = stoi(operation);
            ans.push_back(num);
        }
        else if(operation == "D"){
            ans.push_back(ans.back() * 2);
        }
        else if(operation == "+"){
            ans.push_back(ans[n - 2] + ans[n - 1]);
        }
        else{
            ans.pop_back();
        }
    }

    return accumulate(ans.begin(), ans.end(), 0);
}

int main(){
    FAST_IO;
      
    int n; cin >> n;
    vector<string>  operations(n);
    for(int i = 0; i < n; i++){
        cin >> operations[i];
    }

    int ans = calPoints(operations);
    cout << ans;

    return 0;
}