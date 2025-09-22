#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
};

bool isSymmetric(TreeNode* root){
    if(root == nullptr) return true;

    queue<TreeNode*> q;
    q.push(root->left);
    q.push(root->right);
    
    while(!q.empty()){
        TreeNode* node1 = q.front(); q.pop();
        TreeNode* node2 = q.front(); q.pop();

        if(!node1 && !node2) continue;
        if(!node1 || !node2 || node1->val != node2->val) return false;

        q.push(node1->left);
        q.push(node2->right);
        q.push(node1->right);
        q.push(node2->left);
    }
    return true;
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    cout << (isSymmetric(root) ? "Cây đối xứng" : "Cây không đối xứng") << endl;
    return 0;
} 
