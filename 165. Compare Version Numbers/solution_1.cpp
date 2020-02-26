class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> vec1, vec2;
        string tmp;
        stringstream str1(version1);
        while (getline(str1, tmp, '.'))
            vec1.push_back(stoi(tmp));
        stringstream str2(version2);
        while (getline(str2, tmp, '.'))
            vec2.push_back(stoi(tmp));
        int i;
        for (i = 0; i < min(vec1.size(), vec2.size()); ++ i) {
            if (vec1[i] > vec2[i])
                return 1;
            else if (vec1[i] < vec2[i])
                return -1;
        }
        if (i < vec1.size()) {
            for (int j = i; j < vec1.size(); ++ j)
                if (vec1[j] > 0)
                    return 1;
        }
        else if (i < vec2.size()) {
            for (int j = i; j < vec2.size(); ++ j)
                if (vec2[j] > 0)
                    return -1;
        }
        return 0;
    }
};