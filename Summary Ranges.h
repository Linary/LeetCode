class Solution {
public:
    
    /*************************************************************************/
    /*  Given a sorted integer array without duplicates, return the summary of 
    /*  its ranges.
    /*  For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
    /*************************************************************************/
    
    /*************************************************************************/
    /*  思路：
    /*  1）两个指针确定连续子串范围，左右都是闭的
    /*  2）添加完一个后都定位到上一个子串末尾的后一个几点
    /*************************************************************************/
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if (nums.empty()) 
            return res;
        
        const int size_n = nums.size();
        for (int i = 0; i < size_n;) {
            int start = i, end = i;
            // 确定连续子串
            while (end + 1 < size_n && nums[end + 1] == nums[end] + 1) 
                end++;
            if (end > start) 
                res.push_back(to_string(nums[start]) + "->" + to_string(nums[end]));
            else 
                res.push_back(to_string(nums[start]));
            i = end + 1;
        }
        return res;
    }
};