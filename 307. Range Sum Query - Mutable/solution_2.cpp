class NumArray {
private:
    vector<int> tree;   //tree idx从1开始，tree[i]=tree[i*2]+tree[i*2+1]
    int n;
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        tree.assign(2 * n, 0);
        //build tree  O(n)
        for (int i = n, j = 0; i < 2 * n; ++ i, ++ j)
            tree[i] = nums[j];
        for (int i = n - 1; i > 0; -- i)
            tree[i] = tree[2 * i] + tree[i * 2 + 1];
    }
    
    void update(int i, int val) {   //O(logn)
        i += n; //num[i]对应tree[i+n]
        tree[i] = val;
        while (i > 1) {
            int l = i, r = i;
            if (i % 2 == 0) //i为左子节点
                r = i + 1;
            else
                l = i - 1;
            i /= 2;
            tree[i] = tree[l] + tree[r];   
        }
    }
    
    int sumRange(int i, int j) {    //O(logn)
        i += n;
        j += n;
        int sum = 0;
        while (i <= j) {
            if (i % 2 == 1) 
                sum += tree[i ++];
            if (j % 2 == 0)
                sum += tree[j --];
            i /= 2;
            j /= 2;
        }
        return sum;
    }
};
//segment tree
//https://leetcode.com/articles/range-sum-query-mutable/
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */