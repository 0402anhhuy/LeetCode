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
    LeetCode 1123. Lowest Common Ancestor of Deepest Leaves

    Đề bài:
    Cho root của một cây nhị phân. Trả về Tổ tiên chung thấp nhất (Lowest Common Ancestor - LCA) của tất cả các lá sâu nhất trong cây.

    Định nghĩa:
    1. Lá (Leaf): Là node không có node con
    2. Độ sâu (Depth): Gốc (root) có độ sâu là 0. Node con có độ sâu bằng độ sâu của cha cộng 1
    3. Tổ tiên chung thấp nhất (LCA): Của một tập hợp các node S là node A có độ sâu lớn nhất sao cho mọi node trong S đều thuộc cây con có gốc là A

    Yêu cầu:
    → Xác định tất cả các lá có độ sâu lớn nhất trong cây
    → Tìm node là "cha chung" gần nhất của toàn bộ các lá này

    Ví dụ:
        Input: root = [3, 5, 1, 6, 2, 0, 8, null, null, 7, 4]
        → Các lá sâu nhất là 7 và 4
        → Tổ tiên chung thấp nhất của 7 và 4 là node 2
        → Output: [2, 7, 4]
*/

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int maxDepth(TreeNode* root){
    if(!root) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

TreeNode* dfs(TreeNode* root, int depth, int maxDepth){
    if(!root) return nullptr;
    if(depth == maxDepth){
        return root;
    }
    
    TreeNode* L = dfs(root->left, depth + 1, maxDepth);
    TreeNode* R = dfs(root->right, depth + 1, maxDepth);

    if(L && R) return root;
    return L ? L : R;
}

TreeNode* lcaDeepestLeaves(TreeNode* root){
    int maxD = maxDepth(root);
    return dfs(root, 1, maxD);
}

void printTree(TreeNode* root){
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        int sz = q.size();
        for(int i = 0; i < sz; i++){
            TreeNode* cur = q.front(); q.pop();
            cout << cur->val << " ";

            if(cur->left)  q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }
    }
}

int main(){
    FAST_IO;

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->right->right->left = new TreeNode(4);
    root->right->right->right = new TreeNode(10);

    TreeNode* result = lcaDeepestLeaves(root);
    return 0;
}