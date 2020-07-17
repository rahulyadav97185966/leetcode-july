//Top K Frequent Elements

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>m; multimap<int,int>mp;
        for(auto x:nums) m[x]++;
        for(auto x:m) mp.insert({x.second,x.first});
        auto it=mp.rbegin();
        vector<int>res;
        while(k--) {res.push_back(it->second);it++;}
        return res;
    }
};
