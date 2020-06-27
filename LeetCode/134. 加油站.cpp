class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for(int i=0;i<gas.size();i++)
        {
            int current_gas=0;
            int j=0;
            for(;j<gas.size();j++)
            {
                current_gas+=gas[(i+j)%gas.size()];
                if(current_gas<cost[(i+j)%gas.size()])
                    break;
                else
                    current_gas-=cost[(i+j)%gas.size()];
            }
            if(j==gas.size())return i;
        }
        return -1;
    }
};