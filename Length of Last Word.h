class Solution {
public:
    /********************************************************************/
    /*  Given a string s consists of upper/lower-case alphabets and empty 
    /*  space characters ' ', return the length of last word in the string.
    /*  If the last word does not exist, return 0.
    /*  Note: A word is defined as a character sequence consists of non-space characters only.
    /*  For example, 
    /*  Given s = "Hello World",
    /*  return 5.
    /********************************************************************/
    
    /********************************************************************/
    /*  思路：
    /*  1）反向搜寻第一个非空格符
    /*  2）从该点继续搜寻第一个空格符
    /********************************************************************/
    int lengthOfLastWord(string s) {
        int len = 0, tail = s.length() - 1;
        while (tail >= 0 && s[tail] == ' ') tail--;
        while (tail >= 0 && s[tail] != ' ') {
            len++;
            tail--;
        }
        return len;
    }
};