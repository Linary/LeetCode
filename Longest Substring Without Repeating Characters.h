class Solution {
public:
    
    /*******************************************************************/
    /*  Given a string, find the length of the longest substring without 
    /*  repeating characters. For example, the longest substring without 
    /*  repeating letters for "abcabcbb" is "abc", which the length is 3. 
    /*  For "bbbbb" the longest substring is "b", with the length of 1.
    /*******************************************************************/
    
    /**
     * 思路：动态规划
     * 1）用两个指针，记录当前最长子串的起始和结束位置
     * 2）扫描字符串s时，对于第一次出现的字符，加入到哈希表，值为其索引
     * 3）对于重复出现的值，更新起始指针和结束指针（往后移一位），
     *    并更新其在哈希表中的值，用新索引覆盖
     */
    
    int lengthOfLongestSubstring(string s) {
        vector<int> charIndex(256, -1);
        int longest = 0, m = 0;
    
        for (int i = 0; i < s.length(); i++) {
            m = max(charIndex[s[i]] + 1, m);    
            charIndex[s[i]] = i;
            longest = max(longest, i - m + 1);
        }
    
        return longest;
    }
};