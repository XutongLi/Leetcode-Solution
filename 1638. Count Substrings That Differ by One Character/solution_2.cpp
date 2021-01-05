class Solution {
public:
    int countSubstrings(string s, string t) {
        int m = s.size(), n = t.size();
        int ldp[102][102] = {0};
        int rdp[102][102] = {0};
        
        for (int i = 0; i < m; ++ i) 
            for (int j = 0; j < n; ++ j) 
                if (s[i] == t[j])
                    ldp[i + 1][j + 1] = ldp[i][j] + 1;

                
        for (int i = m - 1; i >= 0; -- i) 
            for (int j = n - 1; j >= 0; -- j) 
                if (s[i] == t[j])
                    rdp[i + 1][j + 1] = rdp[i + 2][j + 2] + 1;

        
        int res = 0;
        for (int i = 0; i < m; ++ i)
            for (int j = 0; j < n; ++ j)
                if (s[i] != t[j])
                    res += (ldp[i][j] + 1) * (rdp[i + 2][j + 2] + 1);
        return res;
        
    }
};

// dp O(n^2)