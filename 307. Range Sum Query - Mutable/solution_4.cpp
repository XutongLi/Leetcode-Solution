class NumArray {
private:
    vector<int> arr;
    vector<int> BIT;
    int n;
    
    //将arr中的每一位加入B它在BIT中应该求和的位置
    void init(int idx, int num) {
        ++ idx;
        while (idx <= n) {
            BIT[idx] += num;
            idx += idx & (-idx);    //如1->10->100
        }
    }
    
    int sumRange(int idx) {     //0-idx的和（包括arr[idx]）
        ++ idx;
        int sum = 0;
        while (idx > 0) {
            sum += BIT[idx];
            idx -= idx & (-idx);
        }
        return sum;
    }
public:
    NumArray(vector<int>& nums) {   //O(nlogn)
        arr = nums;
        n = arr.size();
        BIT.assign(n + 1, 0);
        for (int i = 0; i < n; ++ i)
            init(i, arr[i]);
    }
    
    void update(int i, int val) {   //O(logn)
        init(i, val - arr[i]);
        arr[i] = val;
    }
    
    int sumRange(int i, int j) {    //O(logn)
        return sumRange(j) - sumRange(i - 1);
    }
};
//Binary Indexed Tree
//x&-x 计算LSB (least significant bit)，即x的二进制数的最右的1
//https://leetcode.com/problems/range-sum-query-mutable/discuss/75753/Java-using-Binary-Indexed-Tree-with-clear-explanation

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */