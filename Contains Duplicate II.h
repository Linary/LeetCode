class Solution {
public:
    /*********************************************************************/
    /*  Given an array of integers and an integer k, find out whether 
    /*  there are two distinct indices i and j in the array such that 
    /*  nums[i] = nums[j] and the difference between i and j is at most k.
    /*********************************************************************/
    
    /*********************************************************************/
    /*  思路：窗口 + 哈希
    /*  1）创建一个哈希表，键为容器中的元素值
    /*  2）窗口尾端移出去的值对应的哈希表的值也删掉
    /*  总结：像这种判断元素是否重复的一般都是用哈希表
    /*********************************************************************/
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // 无序集合
        unordered_set<int> s;
        
        if (k <= 0) return false;
        if (k >= nums.size()) k = nums.size() - 1;
        
        for (int i = 0; i < nums.size(); i++) {
            if (i > k) 
                s.erase(nums[i - k - 1]);
            if (s.find(nums[i]) != s.end()) 
                return true;
            s.insert(nums[i]);
        }
        
        return false;
    }
};