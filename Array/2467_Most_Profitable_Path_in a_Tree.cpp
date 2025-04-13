class Solution {
    bool findBobPath(vector<vector<int>>& adj,int bob,int parent,vector<int>& curr_path,vector<int>& bob_path){
        if(bob==0){
            bob_path = curr_path;
            return true;
        }
        //Traverse all nbrs
        curr_path.push_back(bob);
        for(int nbr: adj[bob]){
            if(nbr!=parent and findBobPath(adj,nbr,bob,curr_path,bob_path))
                return true;
        }
        curr_path.pop_back();
        return false;
    }
    int findMaxIncomeForAlice(vector<vector<int>>& adj,int alice,int parent,vector<int>& amount){
        int max_income = INT_MIN;
        for(int nbr: adj[alice]){
            if(nbr!=parent){
                int income = findMaxIncomeForAlice(adj,nbr,alice,amount);
                if(income + amount[alice] > max_income)
                    max_income = income + amount[alice];
            }
        }
        return max_income==INT_MIN?amount[alice]:max_income;
    }
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob,vector<int>& amount) {
        //Step-1: Make Adj List
        int n=amount.size();
        vector<vector<int>> adj(n);
        for(auto edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        //Step-2: Find the Bob to root path
        vector<int> curr_path,bob_path;
        findBobPath(adj,bob,-1,curr_path,bob_path);

        //Step-3: Update amount of half of the path nodes to 0
        int size = bob_path.size();
        int i;
        for(i=0;i<size/2;++i)
            amount[bob_path[i]]=0;
        
        if(size&1)  amount[bob_path[i]]=0;
        else        amount[bob_path[i]]/=2;//Half contribution for common meeting point

        //Step-4: Apply DFS to find the max sum
        return findMaxIncomeForAlice(adj,0,-1,amount);
    }
};