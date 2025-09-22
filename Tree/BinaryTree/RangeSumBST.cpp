#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
};

int rangeSumBST(TreeNode* root, int low, int high){
    if(!root) return 0;

    if(root->val < low){
        return rangeSumBST(root->right, low, high);
    }

    if(root->val > high){
        return rangeSumBST(root->left, low, high);
    }

    return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(6);
    root->left->right->right = new TreeNode(7);
    root->right->right->left = new TreeNode(9);

    int low, high; cin >> low >> high;

    int ans = rangeSumBST(root, low, high);
    cout << ans;
    return 0;
}