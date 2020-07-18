//Course Schedule II
class Solution {
public:
    void dfs(vector<vector<int>>&graph,vector<int>&visited,vector<int>&pstack,int point,int *f,vector<int>&result)
    {
        pstack[point]=1;//push point to stack
        for(int i=0;i<graph[point].size();i++)
        {
            if(!visited[graph[point][i]])
            {
                 if(pstack[graph[point][i]]) ////cycle exists
                {
                    *f=1;
                }
                
                
                else
                    dfs(graph,visited,pstack,graph[point][i],f,result);
            }
           
        
        }
        pstack[point]=0; //pop point off the  stack
        visited[point]=1;
        result.push_back(point);
    }
    
    
    
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int> >graph(numCourses);
        for(int i=0;i<prerequisites.size();i++)
        {
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        vector<int>visited(numCourses,0); //storing the visited vertices
        vector<int>pstack(numCourses,0);  //storing the vertices being visited
        vector<int>result;  
        vector<int> nullv;  //null vector returned if cycle present
        int f=0;  //for checking cycles
        int i;
        for(i=0;i<numCourses;i++)
        {
            if(!visited[i])
                dfs(graph,visited,pstack,i,&f,result);
        }
        if(f)
            return nullv;
        else
       {
            vector<int>fin;
            for(i=result.size()-1;i>=0;i--)
            {
                fin.push_back(result[i]);
            }

            return fin;
       }
    }
};
