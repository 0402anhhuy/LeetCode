#include<bits/stdc++.h>
using namespace std;

/*
    Ý tưởng:
        - Duyệt cây theo DFS
        - Kiểm tra từng nút xem giá trị có bằng nhau hay không
        - Kiểm tra 2 trường hợp
            + Cả 2 cây đều rỗng -> True
            + Có 1 cây rỗng hoặc giá trị của nút khác nhau -> False
*/

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isSameTree(TreeNode* p, TreeNode* q){
    if(!p && !q) return true;
    if(!p || !q || p->val != q->val) return false;
    else return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
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