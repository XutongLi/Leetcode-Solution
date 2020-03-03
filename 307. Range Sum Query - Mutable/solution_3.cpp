class NumArray {
private:
    struct TreeNode {
        int start, end, sum;
        TreeNode *left, *right;
        TreeNode (int st, int en) 
            : start(st), end(en), left(nullptr), right(nullptr), sum(0) {}
    };
    
    TreeNode *root = nullptr;
    
    TreeNode *buildTree(vector<int> &nums, int start, int end) {
        if (start > end)
            return nullptr;
        TreeNode *node = new TreeNode(start, end);
        if (start == end) 
            node->sum = nums[start];
        else {
            int mid = (end - start) / 2 + start;
            node->left = buildTree(nums, start, mid);
            node->right = buildTree(nums, mid + 1, end);
            node->sum = node->left->sum + node->right->sum;
        }
        return node;
    }
    
    void update(int idx, int val, TreeNode *node) {
        if (node->start == node->end) {
            node->sum = val;
            return;
        }
        int mid = (node->end - node->start) / 2 + node->start;
        if (idx <= mid)
            update(idx, val, node->left);
        else 
            update(idx, val, node->right);
        node->sum = node->left->sum + node->right->sum;
    }
    
    int sum(int start, int end, TreeNode *node) {
        if (start == node->start && end == node->end)
            return node->sum;
        int mid = (node->end - node->start) / 2 + node->start;
        if (start > mid)
            return sum(start, end, node->right);
        else if (end <= mid)
            return sum(start, end, node->left);
        else
            return sum(start, mid, node->left) + sum(mid + 1, end, node->right);
    }
public:
    NumArray(vector<int>& nums) {   //O(n)
        root = buildTree(nums, 0, nums.size() - 1);
    }
    
    void update(int i, int val) {   //O(logn)
        update(i, val, root);
    }
    
    int sumRange(int i, int j) {    //O(logn)
        return sum(i, j, root);
    }
};
//Segment Tree (tree version)
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */