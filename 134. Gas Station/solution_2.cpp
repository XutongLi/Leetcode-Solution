class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0, sum = 0, diff = 0;
        for (int i = 0; i < gas.size(); ++ i) {
            sum += gas[i] - cost[i];
            if (sum < 0) {
                start = i + 1;
                diff += sum;
                sum = 0;
            }
        }
        return sum + diff >= 0 ? start : -1;
    }
};