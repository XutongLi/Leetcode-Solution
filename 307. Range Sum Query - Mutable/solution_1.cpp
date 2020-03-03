class NumArray {
private:
    vector<int> arr;
public:
    NumArray(vector<int>& nums) {
        arr = nums;
        for (int i = 1; i < arr.size(); ++ i)
            arr[i] += arr[i - 1];
        
    }
    
    void update(int i, int val) {
        if (i >= arr.size())
            return;
        int diff = (i > 0 ? arr[i] - arr[i - 1] : arr[i]) - val;
        arr[i] = i > 0 ? arr[i - 1] + val : val;
        for (int j = i + 1; j < arr.size(); ++ j)
            arr[j] -= diff;
    }
    
    int sumRange(int i, int j) {
        return i > 0 ? (arr[j] - arr[i - 1]) : arr[j]; 
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */