class Solution {
public:

    /******************************************************************/
    /*  Given an integer n, return the number of trailing zeroes in n!.
    /*  Note: Your solution should be in logarithmic time complexity.
    /******************************************************************/
    
    /****************************************************************/
    /*  思路
	/*  原本看错了题目，以为是要求 n! 中二进制表示下的尾部 0 的个数，
	/*  那么就只需把 n 不断除以 2 ，直到为1为止，累计商的和就是结果
	/*  这里是10进制的尾部为0的个数，本来是不断除以10，但是 10 = 5 * 2，
	/*	出现了 5 的时候一定出现了 2，所以除以5就可以了
    /****************************************************************/
    int trailingZeroes(int n) {
        int num = 0;
		while (n) {
			num += (n /= 5);
		}
		return num;
    }
};