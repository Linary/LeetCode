class Solution {
public:
    /************************************************************/
    /*	Given an array and a value, remove all instances of that 
    /*	value in place and return the new length.
	/*	The order of elements can be changed. It doesn't matter 
	/*	what you leave beyond the new length.
	/************************************************************/
    int removeElement(vector<int>& nums, int val) {
        int count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) {
                nums[count++] = nums[i];
            }
        }
        return count;
    }
};