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
    LeetCode 1161. Maximum Level Sum of a Binary Tree

    Đề bài:
    Cho root của một cây nhị phân (binary tree)
    → Tầng (level) của root là 1, tầng của các con của nó là 2, và cứ tiếp tục như vậy

    Yêu cầu:
    → Tính tổng giá trị của tất cả các node ở mỗi tầng
    → Tìm tầng có tổng giá trị lớn nhất
    → Nếu có nhiều tầng có cùng tổng giá trị lớn nhất, hãy trả về số thứ tự của tầng nhỏ nhất (tầng gần root nhất)

    Ví dụ:
        Input: root = [1, 7, 0, 7, -8, null, null]
        → Tầng 1: Tổng = 1
        → Tầng 2: Tổng = 7 + 0 = 7
        → Tầng 3: Tổng = 7 + (-8) = -1
        → Tổng lớn nhất là 7, tương ứng với tầng 2
        → Output: 2
*/

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int maxLevelSum(TreeNode* root){
    if(!root) return 0;
    
    queue<TreeNode*> q;
    q.push(root);

    int level = 0, bestLevel = 1;
    long long maxSum = INT_MIN;

    while(!q.empty()){
        int n = q.size();
        level++;

        long long sum = 0;
        for(int i = 0; i < n; i++){
            TreeNode* cur = q.front();
            q.pop();

            sum += cur->val;

            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }

        if(sum > maxSum){
            maxSum = sum;
            bestLevel = level;
        }
    }

    return bestLevel;
}   

int main(){
    FAST_IO;

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(7);
    root->right = new TreeNode(0);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(-8);

    int ans = maxLevelSum(root);
    cout << ans;
    return 0;
}