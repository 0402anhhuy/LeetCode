#include<bits/stdc++.h>
using namespace std;

/*
    Ý tưởng:
        - Sử dụng hai stack (s1 và s2) để giả lập quá trình duyệt cây:
            + s1: Được sử dụng để duyệt cây theo thứ tự đặc biệt (root → right → left)
            + s2: Được sử dụng để lưu thứ tự đúng của hậu tố (postorder)
*/

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
};

vector<int> postorderTraversal(TreeNode* root){
    vector<int> res;
    if(!root) return res;
    stack<TreeNode*> s1, s2;
    s1.push(root);
    while(!s1.empty()){
        TreeNode* node = s1.top();
        s1.pop();
        s2.push(node);

        if(node->left) s1.push(node->left);
        if(node->right) s1.push(node->right);
    }
    while(!s2.empty()){
        res.push_back(s2.top()->val); s2.pop();
    }
    return res;
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

    vector<int> nums = postorderTraversal(root);
    for(int num : nums){
        cout << num << " ";
    }
    return 0;
}