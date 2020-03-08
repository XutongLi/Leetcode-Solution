class Solution {
private:
    struct TreeNode {
        long cnt, low, high;
        TreeNode *left, *right;
        TreeNode(long lo, long hi) : low(lo), high(hi), left(nullptr), right(nullptr), cnt(0) {}
    };
    //build tree
    TreeNode *buildTree(const vector<long>& sums, int l, int r) {    //O(n)
        if (l > r)  return nullptr;
        TreeNode *node = new TreeNode(sums[l], sums[r]);
        if (l < r) {
            int m = (r - l) / 2 + l;
            node->left = buildTree(sums, l, m);
            node->right = buildTree(sums, m + 1, r);
        }
        return node;
    }
    //update cnt of tree node who includes this sum
    void updateTreeCnt(TreeNode *root, long sum) {   //O(logn)
        if (!root || root->low > sum || root->high < sum)  return;
        ++ root->cnt;   //if (root->low <= sum && sum <= root->high)
        updateTreeCnt(root->left, sum);
        updateTreeCnt(root->right, sum);
    }
    //get cnt of node in this range
    int getCnt(TreeNode *root, long lo, long up) {    //O(logn)
        if (!root || root->low > up || root->high < lo)
            return 0;
        if (root->low >= lo && root->high <= up)
            return root->cnt;
        else 
            return getCnt(root->left, lo, up) + getCnt(root->right, lo, up);
    }
    
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int len = nums.size();
        if (len == 0)     return 0;
        
        //get sum sorted vector
        unordered_set<long> st;
        long sum = 0;
        for (auto n : nums) {
            sum += n;
            st.insert(sum);
        }
        vector<long> sums(st.begin(), st.end());
        sort(sums.begin(), sums.end());
        
        //get segment tree based on sum sorted vector
        TreeNode *root = buildTree(sums, 0, sums.size() - 1);
        
        //update count of tree node and get res
        int res = 0;
        for (int i = len - 1; i >= 0; -- i) {
            updateTreeCnt(root, sum);   //将范围中包含sum的节点的cnt全部增加
            sum -= nums[i];
            res += getCnt(root, lower + sum, upper + sum);  //查找，可得到包含num[i]及之后元素的子数组中所有符合条件的
        }
        return res;
    }
};
//segment tree  (build as BST)
//time O(nlogn)
//lo <= sums[i] - sums[j] <= up -->> lo + sums[j] <= sums[i] <= up + sums[j]
//https://leetcode.com/problems/count-of-range-sum/discuss/78052/Segment-Tree-Solution-(C%2B%2B)-with-brief-explain
//https://leetcode.com/problems/count-of-range-sum/discuss/77987/Java-SegmentTree-Solution-36ms
