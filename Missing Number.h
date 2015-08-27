
class Solution {
public:
    /** Missing Number
     *  Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, 
     *  find the one that is missing from the array.
     *  For example,
     *  Given nums = [0, 1, 3] return 2.
     *  Note: Your algorithm should run in linear runtime complexity. 
     *  Could you implement it using only constant extra space complexity?
     */

    /**
     * 思路：0加到n的和减去vector的值
     */ 
    int missingNumber(vector<int>& nums) {
        long long sum = 0;
        int n = nums.size();
        for (unsigned int i = 0; i < n; i++) {
            sum += nums[i];
        }
        return n * (n + 1) / 2 - sum;
    }
};