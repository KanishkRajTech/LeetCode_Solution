class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0;
        int totalCost = 0;
        // for(int gasVal : gas){
        //     totalGas += gasVal;
        // }
        // for(int costVal : cost){
        //     totalCost += costVal;
        // }
        // if( totalGas < totalCost) return -1;

        int start = 0;
        int cg = 0;
        for(int i = 0; i < gas.size(); i++){
            totalGas += gas[i];
              totalCost += cost[i];
            cg += (gas[i] - cost[i]);
            if(cg < 0){
                start = i+1;
                cg = 0;
            }
        }
        return totalGas < totalCost ? -1 : start;
        // return start;
    }
};