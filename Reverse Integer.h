class Solution {
public:

    /***************************************************************************/
    /*  Reverse digits of an integer.
    /*  Example1: x = 123, return 321
    /*  Example2: x = -123, return -321
    /***************************************************************************/
    
    /***************************************************************************/
    /*  思路：
    /*  关键点在于溢出的处理，大于INT_MAX或小于INT_MIN都返回0
    /***************************************************************************/
    int reverse(int x) {
        long long result = 0;
        while (x) {
            result = result * 10 + x % 10;
            x /= 10;
            if (result < INT_MIN || result > INT_MAX) 
                return 0;
        }
        
        return int(result);
    }
};