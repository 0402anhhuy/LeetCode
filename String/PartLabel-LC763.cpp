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
    LeetCode 763. Partition Labels

    Đề bài: Cho chuỗi s 
    Yêu cầu:
    - Chia chuỗi thành nhiều phần nhất có thể sao cho:
    + Mỗi ký tự chỉ xuất hiện trong một phần duy nhất
    - Sau khi ghép tất cả các phần theo thứ tự, ta thu được lại chuỗi ban đầu
    - Trả về danh sách độ dài của từng phần

    Ví dụ:
        s = "ababcbacadefegdehijhklij"
        → Chia thành: "ababcbaca", "defegde", "hijhklij"
        → Kết quả: [9, 7, 8]
*/

vector<int> partitionLabels(string s){
    vector<int> lastIndex(26, 0);
    for(int i = 0; i < s.length(); i++){
        lastIndex[s[i] - 'a'] = i;
    }

    vector<int> ans;
    int index = 0;
    string temp = "";
    for(int i = 0; i < s.length(); i++){
        index = max(index, lastIndex[s[i] - 'a']);
        temp += s[i];
        if(i == index){
            ans.push_back(temp.length());
            index = 0;
            temp = "";
        }
    }
    return ans;
}

int main(){
    FAST_IO;

    string s; cin >> s;
    vector<int> nums = partitionLabels(s);
    for(int num : nums){
        cout << num << " ";
    }
    return 0;
}