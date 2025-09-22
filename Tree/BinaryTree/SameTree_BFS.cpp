#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
};

bool isSameTree(TreeNode* p, TreeNode* q){
    queue<TreeNode*> queue;
    queue.push(p);
    queue.push(q);

    while(!queue.empty()){
        TreeNode* node1 = queue.front(); queue.pop();
        TreeNode* node2 = queue.front(); queue.pop();
        if(!node1 && !node2) continue;
        if(!node1 || !node2 || node1->val != node2->val) return false;

        queue.push(node1->left);
        queue.push(node2->left);
        queue.push(node1->right);
        queue.push(node2->right);
    }
    return true;
}

int main(){
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);

    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);

    cout << (isSameTree(root1, root2) ? "Same Tree" : "Not Same Tree") << endl;
    return 0;
}