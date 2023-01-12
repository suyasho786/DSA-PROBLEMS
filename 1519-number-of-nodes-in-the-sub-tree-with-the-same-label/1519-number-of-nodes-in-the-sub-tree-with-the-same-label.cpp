class Solution {
public:
    void dfs(int n,int node,int parent,vector<int>adj[],string &s,vector<int>&vis,vector<int>&ans,map<int,map<char,int>>&m){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(n,it,node,adj,s,vis,ans,m);
            }
        }
        m[node][s[node]]++;
        for(auto it:m[node]){
          if(parent!=-1)  m[parent][it.first]+=it.second;
        }
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string s) {
        vector<int>adj[n],vis(n,0),ans(n,0);
        map<int,map<char,int>>m;
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        dfs(n,0,-1,adj,s,vis,ans,m);
        for(int i=0;i<n;i++){
           ans[i]=m[i][s[i]] ;
        }
        return ans;
    }
};