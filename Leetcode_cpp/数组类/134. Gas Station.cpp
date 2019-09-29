class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum=0;
        int num = gas.size();
        int index = -1;
        int total = 0;
        for(int i=0;i<num;i++)
        {
            sum+=gas[i]-cost[i];
            total+=gas[i]-cost[i];
            if (sum<0)
            {
                index=i;
                sum=0;
            }
        }
        
        return total<0?-1:index+1;
    }
};