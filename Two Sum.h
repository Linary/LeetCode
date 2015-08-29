
class Solution {
public:

    /***************************************************************/ 
    /*  Given an array of integers, find two numbers such that they add up to a specific target number.
    /*  The function twoSum should return indices of the two numbers such that they add up to the target, 
    /*  where index1 must be less than index2. Please note that your returned answers (both index1 and 
    /*  index2) are not zero-based.
    /*  You may assume that each input would have exactly one solution.
    /*  Input: numbers={2, 7, 11, 15}, target=9
    /*  Output: index1=1, index2=2 
    /***************************************************************/

    /***************************************************************/
    /*  思路：把暂未匹配上的元素存到哈希表，元素值本身作为键，
    /*  其索引作为值。遍历array时，在哈希表中查找与其配对的值，
    /*  找不到就把当前元素存到哈希表，找到就退出循环，并把配对
    /*  元素和当前元素的索引返回
    /***************************************************************/

    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> table;
        vector<int> result;
        for (unsigned int i = 0; i < nums.size(); i++) {
            auto it = table.find(target - nums[i]);
            if (it != table.end()) {
                result.push_back(it->second);
                result.push_back(i + 1);
                break;
            } else {
                table[nums[i]] = i + 1;
            }
        }
        return result;
    }
};