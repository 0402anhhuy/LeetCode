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
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
};

void LNR(vector<int> &a, TreeNode* root){
    if(!root) return;
    LNR(a, root->left);
    a.push_back(root->val);
    LNR(a, root->right);
}

vector<int> getAllElements(TreeNode* root1, TreeNode* root2){
    vector<int> a, b, ans;

    LNR(a, root1);
    LNR(b, root2);

    int i = 0, j = 0;
    while(i < a.size() && j < b.size()){
        if(a[i] < b[j]){
            ans.push_back(a[i]);
            i++;
        }
        else{
            ans.push_back(b[j]);
            j++;
        }
    }

    while(i < a.size()){
        ans.push_back(a[i]);
        i++;
    }

    while(j < b.size()){
        ans.push_back(b[j]);
        j++;
    }

    return ans;
}

int main(){
    FAST_IO;

    TreeNode* root1 = new TreeNode(5);
    root1->left = new TreeNode(3);
    root1->right = new TreeNode(7);
    root1->left->left = new TreeNode(1);
    root1->left->right = new TreeNode(4);
    root1->right->left = new TreeNode(6);
    root1->right->right = new TreeNode(8);

    
    TreeNode* root2 = new TreeNode(5);
    root2->left = new TreeNode(3);
    root2->right = new TreeNode(7);
    root2->left->left = new TreeNode(1);
    root2->left->right = new TreeNode(4);
    root2->right->left = new TreeNode(6);
    root2->right->right = new TreeNode(8);

    vector<int> nums = getAllElements(root1, root2);
    for(int num : nums){
        cout << num << " ";
    }
    return 0;
}