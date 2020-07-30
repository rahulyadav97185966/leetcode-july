//word break II
class Solution {
public:
    vector<string> dfs(string s, set<string> &dict_set, int idx, map<int, vector<string>> &memo) {
        if(memo.count(idx)) return memo[idx];
        vector<string> res;
        for(int i =idx; i < s.length(); i++) {
            string cur = s.substr(idx, i - idx + 1);
            if(dict_set.count(cur)) {
                if(i == s.size() - 1) res.push_back(cur);
                vector<string> tmp = dfs(s, dict_set, i + 1, memo);
                for(string e :tmp) res.push_back(cur + " " + e);
            }
        }
        return memo[idx]=res;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        set<string> dict_set(wordDict.begin(), wordDict.end());
        map<int, vector<string>> memo;
        return dfs(s, dict_set, 0, memo);
    }
    
};
