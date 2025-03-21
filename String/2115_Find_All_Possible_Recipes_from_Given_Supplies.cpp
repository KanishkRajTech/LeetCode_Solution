class Solution {
    public:
        vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
            unordered_map<string, vector<string>> graph; 
            unordered_map<string, int> inDegree; 
            for (int i = 0; i < recipes.size(); i++) {
                inDegree[recipes[i]] = ingredients[i].size();
                for (const string& ing : ingredients[i]) {
                    graph[ing].push_back(recipes[i]); 
                }
            }
            
     
            queue<string> q;
            unordered_set<string> available(supplies.begin(), supplies.end());
    
            for (const string& sup : supplies) {
                q.push(sup);
            }
    
            vector<string> result;
    
    
            while (!q.empty()) {
                string curr = q.front();
                q.pop();
                
    
                if (inDegree.count(curr)) {
                    result.push_back(curr);
                }
    
      
                for (const string& dependent : graph[curr]) {
                    if (--inDegree[dependent] == 0) {
                        q.push(dependent);
                        available.insert(dependent); 
                    }
                }
            }
    
            return result;
        }
    };
    