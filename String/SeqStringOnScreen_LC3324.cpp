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
    LeetCode 3324. Find the Sequence of Strings Appeared on the Screen

    Đề bài:
    Cho một chuỗi mục tiêu target
    Alice gõ chuỗi target bằng một bàn phím đặc biệt chỉ có hai phím:
    1. Phím 1: Thêm ký tự "a" vào cuối chuỗi hiện tại trên màn hình
    2. Phím 2: Thay đổi ký tự cuối cùng của chuỗi hiện tại sang ký tự tiếp theo trong bảng chữ cái (ví dụ: 'c' → 'd', 'z' → 'a')

    Lưu ý: Ban đầu, chuỗi trên màn hình là rỗng (""), do đó thao tác đầu tiên bắt buộc là Phím 1

    Yêu cầu:
    → Alice phải tạo ra chuỗi target bằng số lần nhấn phím tối thiểu
    → Trả về một danh sách tất cả các chuỗi xuất hiện trên màn hình, theo đúng thứ tự chúng xuất hiện, từ lúc bắt đầu cho đến khi tạo ra được target

    Ví dụ:
        Input: target = "abc"
        → Output: ["a", "aa", "ab", "aba", "abb", "abc"]
*/

vector<string> stringSequence(string target){
    vector<string> ans;
    string screen = "";

    int n = target.length();
    for(int i = 0; i < n; i++){
        screen.push_back('a');
        ans.push_back(screen);

        while(screen.back() != target[i]){
            if(screen.back() == 'z'){
                screen.back() = 'a';
            }
            else{
                screen.back()++;
            }
            ans.push_back(screen);
        }
    }

    return ans;
}

int main(){
    FAST_IO;

    string target; cin >> target;

    vector<string> ans = stringSequence(target);
    FORI(i, ans.size()) cout << ans[i] << " ";
    return 0;
}