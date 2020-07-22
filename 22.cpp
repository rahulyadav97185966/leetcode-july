// Binary Tree Zigzag Level Order Traversal

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
int depth(TreeNode *root) 
{
    if(!root) return 0;
    return max(depth(root->left),depth(root->right))+1;
}

void post(TreeNode* root,int level,vector<vector<int>> &ans)
{
    if(!root) return;
	
    post(root->left,level+1,ans);
    post(root->right,level+1,ans);
	
    ans[level].push_back(root->val);
}

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int n=depth(root);
        vector<vector<int>> ans(n);
		
        post(root,0,ans);
        for(int i=0;i<n;i++)
	{
            if(i & 1)
                reverse(ans[i].begin(),ans[i].end());
	}
		
        return ans;
    }
};
