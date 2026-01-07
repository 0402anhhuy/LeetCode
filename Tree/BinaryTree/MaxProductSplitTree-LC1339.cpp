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
    LeetCode 1339. Maximum Product of Splitted Binary Tree

    Đề bài:  
    Cho root của một cây nhị phân. Bạn cần chia cây này thành hai cây con bằng cách loại bỏ đúng một cạnh bất kỳ

    Yêu cầu:  
    → Tính tổng các node trong mỗi cây con sau khi chia
    → Tìm cách xóa cạnh sao cho tích của hai tổng này đạt giá trị lớn nhất
    → Trả về giá trị tích lớn nhất đó dưới dạng modulo 10^9 + 7
    → Lưu ý: Bạn phải tìm giá trị tích cực đại trước khi thực hiện phép chia lấy dư (modulo)

    Ví dụ:  
        Input: root = [1, 2, 3, 4, 5, 6]
        → Tổng toàn bộ cây là 21.
        → Giả sử xóa cạnh nối node 1 và node 3:
            - Cây con 1: {3, 6}, tổng = 9
            - Cây con 2: {1, 2, 4, 5}, tổng = 12
            - Tích = 9 * 12 = 108
        → Giả sử xóa cạnh nối node 1 và node 2 (như ví dụ đề bài):
            - Cây con 1: {2, 4, 5}, tổng = 11
            - Cây con 2: {1, 3, 6}, tổng = 10
            - Tích = 11 * 10 = 110 (Cực đại)
        → Output: 110
*/

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

long long total = 0;
long long bestSum = 0;

long long sumTree(TreeNode* root){
    if(!root) return 0;

    long long leftSum  = sumTree(root->left);
    long long rightSum = sumTree(root->right);

    return root->val + leftSum + rightSum;
}

long long dfs(TreeNode* root){
    if(!root) return 0;

    long long left = dfs(root->left);
    long long right = dfs(root->right);

    long long sub = root->val + left + right;

    bestSum = max(bestSum, sub * (total - sub));

    return sub;
}

int maxProduct(TreeNode* root){
    total = sumTree(root);
    dfs(root);
    return bestSum % MOD;
}

int main(){
    FAST_IO;

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    int ans = maxProduct(root);
    cout << ans;
    return 0;
}