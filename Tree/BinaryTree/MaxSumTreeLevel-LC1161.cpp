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