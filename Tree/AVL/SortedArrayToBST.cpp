#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* helper(vector<int>& nums, int left, int right){
    if(left > right) return nullptr;
    
    int mid = left + (right - left) / 2;
    TreeNode* root = new TreeNode(nums[mid]);

    root->left = helper(nums, left, mid - 1);
    root->right = helper(nums, mid + 1, right);
    return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums){
    if(nums.empty()) return nullptr;
    return helper(nums, 0, nums.size() - 1);
}

void printTree_LNR(TreeNode* root){
	if(root != NULL){
		printTree_LNR(root->left);
		cout << root->val << " ";
		printTree_LNR(root->right);
	}
}

int main(){
    int n; cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    TreeNode* root = sortedArrayToBST(nums);
    printTree_LNR(root);
    return 0;
}