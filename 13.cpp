//Same Tree
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
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
    if(p==NULL && q==NULL)
        return true;        //case when both are NULL
    
    if(p==NULL || q==NULL)
        return false;       //case when only one tree has NULL
        
    if(p->val!=q->val)
        return false;       //comparing values;
    
    return isSameTree(p->left,q->left) && isSameTree(p->right,q->right); //traverse left and right    
    
    }
    
    
};
