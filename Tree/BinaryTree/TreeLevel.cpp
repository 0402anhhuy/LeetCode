#include<bits/stdc++.h>
using namespace std;

/*
    Ý tưởng:
        - Duyệt cây theo chiều sâu (DFS)
        - Nếu nút hiện tại là nullptr, trả về 0.
        - Nếu không, tính chiều sâu của cây con trái và phải, sau đó lấy giá trị lớn nhất và cộng thêm 1 (đếm nút gốc)
*/

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
};

int maxDepth(TreeNode* root){
    if(root == nullptr) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    int depth = maxDepth(root);

    cout << "Max Depth: " << depth << endl;

    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;
    return 0;
}
