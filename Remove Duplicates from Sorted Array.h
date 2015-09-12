class Solution {
public:
    
    /***************************************************************************/
    /*  Given a sorted array, remove the duplicates in place such that each 
    /*  element appear only once and return the new length.
    /*  Do not allocate extra space for another array, you must do this in place
    /*  with constant memory.
    /***************************************************************************/
    
    /***************************************************************************/
    /*  思路：
    /*  1）因为数组是排序的，两个指针一前一后就好了
    /***************************************************************************/
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int count = 1;
        for (int i = 0, j = 1; j < nums.size(); j++) {
            if (nums[i] != nums[j]) {
                nums[++i] = nums[j];
                count++;
            }
        }
        return count;
    }
};