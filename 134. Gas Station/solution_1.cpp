class Solution {
private:
    
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for (int i = 0; i < gas.size(); ++ i) {
            int station = i, sum = 0;
            while (sum >= 0) {
                sum += gas[station];
                sum -= cost[station];
                if (sum >= 0) {
                    station = (station == gas.size() - 1) ? 0 : station + 1;
                    if (station == i)
                        return i;
                }
                else
                    break;
            }
        }
        return -1;
    }
};