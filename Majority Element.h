class Solution {
public:

    /*******************************************************************/
    /*  Given an array of size n, find the majority element. The majority 
    /*  element is the element that appears more than ⌊ n/2 ⌋ times.
    /*  You may assume that the array is non-empty and the majority 
    /*  element always exist in the array.
    /*******************************************************************/
    
    /*******************************************************************/
    /*  思路：
    /*  1）出现超过一半的元素，它的出现次数比其他所有元素的次数之和还多
    /*  2）扫描数组，result 保存目前出现次数最多的元素，times 保存该元素
    /*     出现次数，当前元素与 result 不等时，times 减一，否则加一
    /*  3）当 times==0 时，替换 result
    /*******************************************************************/
    int majorityElement(vector<int>& nums) {
        int result = nums[0];
        int times = 1;
        for (unsigned int i = 1; i < nums.size(); i++) {
            if (times == 0) {
                result = nums[i];
                times = 1;
            } else if (result == nums[i]) {
                times++;
            } else {
                times--;
            }
        }
        return result;
    }
};