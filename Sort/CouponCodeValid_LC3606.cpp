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
    LeetCode 3606. Coupon Code Validator

    Đề bài:
    Cho ba mảng có độ dài n, mô tả các thuộc tính của n mã giảm giá:
    1. code[i]: Chuỗi định danh mã giảm giá
    2. businessLine[i]: Chuỗi danh mục kinh doanh
    3. isActive[i]: Boolean cho biết mã giảm giá đang hoạt động hay không

    Định nghĩa Mã Giảm Giá Hợp Lệ (Valid Coupon):
    Mã giảm giá i là hợp lệ nếu thỏa mãn tất cả các điều kiện sau:
    1. code[i] phải không rỗng và chỉ chứa các ký tự chữ-số (a-z, A-Z, 0-9) và gạch dưới (_)
    2. businessLine[i] phải là một trong bốn danh mục: "electronics", "grocery", "pharmacy", "restaurant"
    3. isActive[i] phải là true

    Yêu cầu:
    → Trả về một mảng chứa code của tất cả các mã giảm giá hợp lệ
    → Mảng kết quả phải được sắp xếp theo hai tiêu chí:
        1. Sắp xếp theo businessLine theo thứ tự cố định: "electronics", "grocery", "pharmacy", "restaurant"
        2. Trong cùng một danh mục, sắp xếp theo code theo thứ tự từ điển tăng dần (lexicographical ascending order)

    Ví dụ:
        Input: code = ["SAVE20", "", "PHARMA5", "SAVE@20"], businessLine = ["restaurant", "grocery", "pharmacy", "restaurant"], isActive = [true, true, true, true]
        → Các mã hợp lệ: "SAVE20" (restaurant) và "PHARMA5" (pharmacy)
        → Sắp xếp theo thứ tự businessLine ("pharmacy" trước "restaurant"):
        → Output: ["PHARMA5", "SAVE20"]
*/

vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive){
    int n = code.size();

    map<string, int> order = {
        {"electronics", 0},
        {"grocery", 1},
        {"pharmacy", 2},
        {"restaurant", 3}
    };

    auto validCode = [&](const string& s){
        if(s.empty()) return false;
        for(char c : s){
            if(!(isalnum(c) || c == '_')) return false;
        }
        return true;
    };

    vector<pair<string,string>> temp;

    for(int i = 0; i < n; i++){
        if(!isActive[i]) continue;
        if(order.count(businessLine[i]) == 0) continue;
        if(!validCode(code[i])) continue;

        temp.push_back({businessLine[i], code[i]});
    }

    sort(temp.begin(), temp.end(),
        [&](auto& a, auto& b){
            if(order[a.first] != order[b.first])
                return order[a.first] < order[b.first];
            return a.second < b.second;
        }
    );

    vector<string> res;
    for(auto& p : temp)
        res.push_back(p.second);

    return res;
}


int main(){
    FAST_IO;

    int n; cin >> n;

    vector<string> code(n), businessLine(n);
    vector<bool> isActive(n);

    FORI(i, n) cin >> code[i];
    FORI(i, n) cin >> businessLine[i];
    FORI(i, n){
        int x; cin >> x;
        isActive[i] = x;
    }

    vector<string> ans = validateCoupons(code, businessLine, isActive);
    FORI(i, ans.size()){
        cout << ans[i] << endl;
    }
    return 0;
}