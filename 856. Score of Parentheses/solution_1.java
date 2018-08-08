//stack
//56%
class Solution {
    public int scoreOfParentheses(String S) {
        Stack<Integer> stack = new Stack<>();
        char[] ca = S.toCharArray();
        int curr = 0;
        for (int i = 0; i < ca.length; i++) {
            if (ca[i] == '(') {
                stack.push(curr);
                stack.push(i);
                curr = 0;
            } 
            else {
                int idx = stack.pop();
                int val = stack.pop();
                if (idx == i - 1) {
                    curr = curr + 1 + val;
                } 
                else {
                    curr = curr * 2 + val;
                }
            }
        }
        return curr;
    }
}