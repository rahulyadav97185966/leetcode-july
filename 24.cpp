// All Paths From Source to Target
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> tempAns;
    void dfs(vector<vector<int>>& graph, int rootNode) {
        tempAns.push_back(rootNode);
        if(rootNode == graph.size() - 1) {
             ans.push_back(tempAns);
         }
        else {
            for(int i : graph[rootNode])
                dfs(graph, i);
        }
        tempAns.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        dfs(graph, 0);
        return ans;
    }
};
