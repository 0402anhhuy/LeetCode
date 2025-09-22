#include<bits/stdc++.h>
using namespace std;

/*
    Ý tưởng:
        + Duyệt hết nhánh trái: Đưa tất cả các nút con trái vào stack
        + Lấy phần tử trên cùng stack: Đưa giá trị của nó vào kết quả.
        + Duyệt sang nhánh phải: Gán current = current->right và tiếp tục duyệt.
*/

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
};

vector<int> inorderTraversal(TreeNode* root){
    vector<int> res;
    stack<TreeNode*> s;
    TreeNode* current = root;
    while(current != nullptr || !s.empty()){
        while(current != nullptr){
            s.push(current);
            current = current->left;
        }
        current = s.top();
        s.pop();
        res.push_back(current->val);
        current = current->right;
    }
    return res;
}

int main(){
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);
    return 0;
}