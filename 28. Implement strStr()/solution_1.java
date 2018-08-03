//use KMP
//12%
class Solution {
    public int strStr(String haystack, String needle) {
        if(needle.equals("")){
            return 0;
        }
        else if(haystack.equals("") && !needle.equals("")) {
            return -1;
        }
        else{
            int i, j;
            int M = needle.length();
            int N = haystack.length();
            int[][] DFA = new int[256][M];
            DFA[needle.charAt(0)][0] = 1;
            for (int state = 0, dfa_j = 1; dfa_j < needle.length(); dfa_j++) {
                for (int c = 0; c < 256; c++) {
                    DFA[c][dfa_j] = DFA[c][state];  //复制状态
                }
                DFA[needle.charAt(dfa_j)][dfa_j] = dfa_j + 1;  //匹配时模式字符串匹配下一位
                state = DFA[needle.charAt(dfa_j)][state];  //计算重启状态
            }
            for (i = 0, j = 0; i < N && j < M; i++) {
                j = DFA[haystack.charAt(i)][j];	//获取下一个i对应的j
            }
            if (j == M) {	//匹配到模式串
                return i - M;
            }
            else {	//未匹配到模式串
                return -1;
            }
        }
        
    }
   
}