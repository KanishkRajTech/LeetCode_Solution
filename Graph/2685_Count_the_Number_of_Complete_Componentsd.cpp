class Solution {
    void dfs(int curr,int& nodes,int& edges,vector<vector<int>>& adj,vector<bool>& visited){
        nodes++;
        visited[curr] = true;
        for(int& nbr: adj[curr]){
            edges++;
            if(!visited[nbr])
                dfs(nbr,nodes,edges,adj,visited);
        }
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto& edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int complete_components = 0;
        vector<bool> visited(n,false);
        for(int i=0;i<n;++i){
            if(!visited[i]){
                //Count nodes and edges for each component
                int edges = 0;
                int nodes = 0;
                dfs(i,nodes,edges,adj,visited);
                
                if(edges==(nodes*(nodes-1)))
                    complete_components++;
            }
        }
        return complete_components;
    }
};