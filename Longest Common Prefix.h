class Solution {
public:
    /******************************************************************/
    /*  思路：
    /*  1）两重循环，外层遍历字符串内部，当下标索引大于某一个字符串的
    /*     范围时，返回
    /*  2）内层循环遍历字符串数组内部，当前字符串的当前下标处的字符不
    /*     等于上一个字符串当前下标字符时，返回
    /******************************************************************/
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        for(int idx = 0; strs.size() > 0; prefix += strs[0][idx], idx++)
            for(int i = 0; i < strs.size(); i++)
                if(idx >= strs[i].size() || (i > 0 && strs[i][idx] != strs[i-1][idx]))
                    return prefix;
        return prefix;
    }
};