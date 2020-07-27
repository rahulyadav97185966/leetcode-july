//Construct binary tree from inorder and postorder

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
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    unordered_map<int,int> hash;
    int idx = 0;
    for(const auto& e : inorder)
      hash[e] = idx++;
     
    function<TreeNode*(int,int,int,int)> doRecur = [&](int istart, int ifin, int pstart, int pfin) -> TreeNode* {
      if(istart > ifin) return nullptr;
      
      TreeNode* root = new TreeNode(postorder[pfin]);
      
      int iroot = hash[postorder[pfin]];
      root->left = doRecur(istart, iroot-1, pstart, pstart + iroot - istart - 1);
      root->right = doRecur(iroot+1, ifin, pstart + iroot - istart, pfin-1);
      
      return root;
    };

    return doRecur(0, inorder.size()-1, 0, postorder.size()-1);
  }
};
