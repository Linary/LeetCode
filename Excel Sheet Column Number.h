class Solution {
public:
    /**************************************************************************/
    /*  Given a column title as appear in an Excel sheet, return its corresponding column number.
    /*  For example:
    /*  A -> 1
    /*  B -> 2
    /*  C -> 3
    /*  ...
    /*  Z -> 26
    /*  AA -> 27
    /*  AB -> 28 
    /**************************************************************************/

    /**************************************************************************/
    /*  思路：字符串流很好地实现了顺序获取字符
    /**************************************************************************/
    int titleToNumber(string s) {
        stringstream ss(s);
        int sum = 0;
    	char buf;
    	while (ss >> buf) {
            sum = sum * 26 + buf - 'A' + 1;
        }
        return sum;
    }
};