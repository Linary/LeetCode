class Solution {
public:

    /***********************************************************************/
    /*  Write a program to check whether a given number is an ugly number.
    /*  Ugly numbers are positive numbers whose prime factors only include 
    /*  2, 3, 5. For example, 6, 8 are ugly while 14 is not ugly since it 
    /*  includes another prime factor 7.
    /*  Note that 1 is typically treated as an ugly number.
    /***********************************************************************/

    /***********************************************************************/
    /*  思路：
    /*  1）只要能被2、3、5整除，就一顺除
    /*  2）除到最后看结果是不是 1 
    /***********************************************************************/
    bool isUgly(int num) {
        if(num == 0) return false;

        while(num % 2 == 0) num /= 2;
        while(num % 3 == 0) num /= 3;
        while(num % 5 == 0) num /= 5;

        return num == 1;
    }
};