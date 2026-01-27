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
    LeetCode 744. Find Smallest Letter Greater Than Target

    Đề bài:
    Cho một mảng các ký tự letters đã được sắp xếp theo thứ tự không giảm và một ký tự target
    Mảng chứa ít nhất hai ký tự khác nhau

    Yêu cầu:
    → Tìm ký tự nhỏ nhất trong mảng letters mà lớn hơn target về mặt từ điển (lexicographically greater)
    → Trường hợp đặc biệt: Nếu không tìm thấy ký tự nào lớn hơn target, hãy trả về ký tự đầu tiên của mảng letters

    Ví dụ:
        Input: letters = ["c", "f", "j"], target = "a"
        → Ký tự nhỏ nhất lớn hơn 'a' là 'c'
        → Output: "c"

        Input: letters = ["c", "f", "j"], target = "j"
        → Không có ký tự nào trong mảng lớn hơn 'j'. Trả về ký tự đầu tiên
        → Output: "c"

        Input: letters = ["x", "x", "y", "y"], target = "z"
        → Không có ký tự nào lớn hơn 'z'. Trả về ký tự đầu tiên
        → Output: "x"
*/

char nextGreatestLetter(vector<char>& letters, char target){
    int l = 0, r = letters.size();

    while(l < r){
        int m = (l + r) / 2;
        if(letters[m] <= target){
            l = m + 1;
        }
        else{
            r = m;
        }
    }

    if(l == letters.size()) return letters[0];

    return letters[l];
}

int main(){
    FAST_IO;

    int n; cin >> n;
    char target; cin >> target;

    vector<char> letters(n);
    FORI(i, n) cin >> letters[i];

    char ans = nextGreatestLetter(letters, target);
    cout << ans;
    return 0;
}