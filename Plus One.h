class Solution {
public:
    /*****************************************************************/
    /*  Given a non-negative number represented as an array of digits, 
    /*  plus one to the number.
    /*  The digits are stored such that the most significant digit is 
    /*  at the head of the list.
    /*****************************************************************/
    
    /*****************************************************************/
    /*  思路：
    /*  1）如果某次相加没有产生进位，循环可以提前结束
    /*  2）如果最后还有进位，在数组头插入1
    /*****************************************************************/
    vector<int> plusOne(vector<int>& digits) {
        bool carry = true;

        for(int i=digits.size() - 1; i >= 0 && carry; i--) {
            carry = (++digits[i] %= 10) == 0;
        }

        if(carry) {
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};