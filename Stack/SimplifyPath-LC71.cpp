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
    LeetCode 71. Simplify Path

    Đề bài:
    Cho một đường dẫn tuyệt đối (absolute path) theo phong cách Unix, luôn bắt đầu bằng dấu gạch chéo '/'

    Quy tắc hệ thống file Unix:
    1. Dấu chấm đơn '.': Đại diện cho thư mục hiện tại (không làm thay đổi đường dẫn)
    2. Dấu chấm đôi '..': Đại diện cho thư mục cha (quay lại một cấp thư mục)
    3. Nhiều dấu gạch chéo liên tiếp (ví dụ '//'): Được coi là một dấu gạch chéo duy nhất '/'
    4. Các chuỗi dấu chấm khác (ví dụ '...'): Được coi là tên thư mục hoặc tệp tin hợp lệ

    Quy chuẩn của đường dẫn rút gọn:
    → Phải bắt đầu bằng một dấu gạch chéo đơn '/'
    → Các thư mục cách nhau bởi đúng một dấu '/'
    → Không kết thúc bằng dấu '/' (trừ khi đó là thư mục gốc)
    → Không chứa các ký hiệu '.' hoặc '..' dùng để chuyển hướng

    Ví dụ:
        Input: path = "/home//foo/"
        → Rút gọn: "/home/foo"

        Input: path = "/home/user/Documents/../Pictures"
        → '..' khiến ta quay lại từ Documents về user
        → Rút gọn: "/home/user/Pictures"

        Input: path = "/../"
        → Từ gốc '/' quay lại cha vẫn là gốc '/'
        → Rút gọn: "/"
*/

string simplifyPath(string path){
    vector<string> stack;
    string token;
    stringstream ss(path);

    while(getline(ss, token, '/')){
        if(token == "" || token == "."){
            continue;
        } 
        else if(token == ".."){
            if(!stack.empty()){
                stack.pop_back();
            }
        } 
        else{
            stack.push_back(token);
        }
    }

    string result = "/";
    for(int i = 0; i < stack.size(); i++){
        result += stack[i];
        if(i != stack.size() - 1)
            result += "/";
    }

    return result;
}

int main(){
    FAST_IO;

    string path; cin >> path;

    string ans = simplifyPath(path);
    cout << ans;
    return 0;
}