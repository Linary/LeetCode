class Solution {
public:

    /*************************************************************************/
    /*  Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 
    /*  as one sorted array.
    /*  Note:
    /*  You may assume that nums1 has enough space (size that is greater or 
    /*  equal to m + n) to hold additional elements from nums2. The number of 
    /*  elements initialized in nums1 and nums2 are m and n respectively.
    /*************************************************************************/
    
    /*************************************************************************/
    /*  思路：
    /*  从后往前遍历即可
    /*************************************************************************/
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1, p2 = n - 1;
        int p3 = nums1.size() - 1;
        for (; p1 >= 0 && p2 >= 0; p3--) {
            if (nums1[p1] > nums2[p2]) {
                nums1[p3] = nums1[p1--];
            } else {
                nums1[p3] = nums2[p2--];
            }
        }
        
        while (p2 >= 0) {
            nums1[p3--] = nums2[p2--];
        }
    }
};