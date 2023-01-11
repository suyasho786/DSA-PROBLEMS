class Solution {
public:
    void dfs(vector<vector<int>>&adj,long long &ans,int node,int parent,vector<bool>&vis,vector<bool>&has){
        vis[node]=1;
        bool flag=0;
      if  (has[node])cout<<node<<" "<<ans<<endl;
        for(auto it:adj[node]){
            if(vis[it]==0){
                dfs(adj,ans,it,node,vis,has);
                if(has[it]==1){
                    flag=1;
                    ans+=2;
                }
            }
        }
        if(parent!=-1&&flag&&!has[node]){has[node]=1;}
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& has) {
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        long long ans=0;vector<bool>vis(n,0);
        
        dfs(adj,ans,0,-1,vis,has);
        return ans;
    }
};