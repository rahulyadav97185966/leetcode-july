//Subsets
class Solution {
public:
    vector<vector<int>>res;
    void dfs(vector<int>& nums,vector<int>& prefix,int idx)
    {
        if(idx>nums.size()) return;
        res.push_back(prefix);
        for(int i=idx ; i<nums.size() ; i++)
        {
            prefix.push_back(nums[i]);
            dfs(nums,prefix,i+1);
            prefix.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>prefix;
        dfs(nums,prefix,0);
        return res;
    }
};

