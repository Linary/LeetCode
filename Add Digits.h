class Solution {
public:
    /***********************************************************************/
    /*  Given a non-negative integer num, repeatedly add all its digits 
    /*  until the result has only one digit.
    /*  For example:
    /*  Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. 
    /*  Since 2 has only one digit, return it.
    /*  Follow up:
    /*  Could you do it without any loop/recursion in O(1) runtime?
    /***********************************************************************/
    
    /***********************************************************************/
    /*  思路：稍微思考一下就发现，非9的倍数的数加和就是对9求余
    /*  9的倍数就返回9，0返回0
    /***********************************************************************/
    int addDigits(int num) {
        return 1 + (num - 1) % 9;
    }
};