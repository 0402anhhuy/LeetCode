#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
};

vector<int> preorderTraversal(TreeNode* root){
    vector<int> res;
    stack<TreeNode*> st;
    TreeNode* current = root;
    while(current != nullptr || !st.empty()){
        while(current != nullptr){
            res.push_back(current->val);
            st.push(current);
            current = current->left;
        }
        current = st.top(); st.pop();
        current = current->right;
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

    vector<int> res = preorderTraversal(root);
    for(int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }
    return 0;
}