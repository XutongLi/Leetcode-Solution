class Solution {
private:
    vector<int> arr, idx;
public:
    Solution(vector<int>& nums) {
        srand(time(NULL));
        arr = nums;
        idx = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        arr = idx;
        return arr;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        for (int i = 0; i < arr.size(); ++ i)
            swap(arr[i], arr[rand() % (arr.size() - i) + i]);
        return arr;
    }
};
// Fisher Yates algorithm 
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */