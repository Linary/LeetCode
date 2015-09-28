class Solution {
public:
    /***************************************************************/
    /*  Move Zeroes
    /*  Given an array nums, write a function to move all 0's to the 
    /*  end of it while maintaining the relative order of the non-zero elements.
    /*  For example, given nums = [0, 1, 0, 3, 12], after calling 
    /*  your function, nums should be [1, 3, 12, 0, 0].
    /*  Note:
    /*  You must do this in-place without making a copy of the array.
    /*  Minimize the total number of operations.
    /***************************************************************/
    
    /***************************************************************/
    /*  思路：冒泡法
    /*  1）两层循环，外层从 0 ~ n - 1，内层从 1 ~ n
    /*  2）如果前一个元素为 0，而元素不为 0，则交换，由于此时外层的
    /*     a[i]一定不为 0 了，可以退出当前内层循环
    /***************************************************************/
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1;i ++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] == 0 && nums[j] != 0) {
                    int temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;
                    
                    break;
                }
            }
        }
    }
};