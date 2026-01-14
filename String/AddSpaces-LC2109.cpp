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
    LeetCode 2109. Adding Spaces to a String

    Đề bài:
    Cho một chuỗi s (đánh chỉ số từ 0) và một mảng số nguyên spaces mô tả các vị trí (index) trong chuỗi gốc mà bạn cần chèn thêm dấu cách
    
    Quy tắc chèn:
    → Mỗi dấu cách sẽ được chèn vào trước ký tự tại chỉ số tương ứng trong mảng spaces
    → Các chỉ số trong mảng spaces luôn được sắp xếp theo thứ tự tăng dần

    Yêu cầu:
    → Trả về chuỗi mới sau khi đã được chèn đầy đủ các dấu cách

    Ví dụ:
        Input: s = "LeetcodeHelpsMeLearn", spaces = [8, 13, 15]
        → Chèn dấu cách trước index 8 ('H'), index 13 ('M'), và index 15 ('L')
        → "Leetcode" + " " + "Helps" + " " + "Me" + " " + "Learn"
        → Output: "Leetcode Helps Me Learn"

        Input: s = "spacing", spaces = [0, 1, 2, 3, 4, 5, 6]
        → Output: " s p a c i n g"
*/

string addSpaces(string s, vector<int>& spaces){
    int index = 0;
    string ans = "";
    for(int i = 0; i < s.length(); i++){
        if(index < spaces.size() && i == spaces[index]){
            ans += ' ';
            index++;
        }
        ans += s[i];
    }
    return ans;
}

int main(){
    FAST_IO;

    string s; cin >> s;
    int n; cin >> n;
    vector<int> spaces(n);
    FORI(i, n) cin >> spaces[i];

    string ans = addSpaces(s, spaces);
    cout << ans;
    return 0;
}