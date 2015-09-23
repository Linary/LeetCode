// 迭代实现二叉树中序遍历
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    stack<TreeNode *> st;
    TreeNode * cur = root;
    
    while (!st.empty() || cur) {
        if (cur) {
            st.push(cur);
            cur = cur->left;
        } else {
            cur = st.top();
            st.pop();
            result.push_back(cur->val);
            cur = cur->right;
        }
    }
    
    return result;
}

// 利用哈希表实现数组中寻找两个数的和等于给定值
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> result;
    if (nums.empty())
        return result;
    map<int, int> mp;
    for (unsigned int i = 0; i < nums.size(); i++) {
        auto it = mp.find(target - nums[i]);
        if (it != mp.end()) {
            // 如果已经找到
            result.push_back(it->second);
            result.push_back(i + 1);
            return result;
        } else {
            mp.insert(make_pair(nums[i], i + 1));
        }
    }
}

//---------------------------------------------------//
//              几个重要的排序算法                   //
//---------------------------------------------------//

void swap (int * data, int left, int rigt){
    int temp = data[left];
    data[left] = data[rigt];
    data[rigt] = temp;
}

/** 快速排序
 */
void quick_sort(int * data, int len) {
    if (len <= 1)
        return ;
    int left = 0, rigt = len - 1;
    int pivot = data[left];
    while (left < rigt) {
        for (; left < rigt; rigt--) {
            if (data[rigt] < pivot) {
                data[left++] = data[rigt];
                break;
            }
        }
        for (; left < rigt; left++) {
            if (data[left] > pivot) {
                data[rigt--] = data[left];
                break;
            }
        }
    }
    data[left] = pivot;
    quick_sort(data, left);
    quick_sort(data + left + 1, len - left - 1);
}

/** 堆排序
 */
void heap_adjust(int * data, int start, int end);
void heap_sort(int * data, int len) {
    if (data == NULL || len <= 1)
        return ;

    for (int i = len / 2 - 1; i >= 0; i--)
        heap_adjust(data, i, len - 1);
    for (int i = len - 1; i > 0; i--) {
        swap(data, 0, i);
        heap_adjust(data, 0, i - 1);
    }
}

void heap_adjust(int * data, int start, int end) {
    int temp = data[start];
    for (int i = start * 2 + 1; i <= end; i = i * 2 + 1) {
        // 这里的 i < end 千万别忘记了
        if (i < end && data[i] < data[i + 1])
            i++;
        if (temp > data[i])
            break;
        data[start] = data[i];
        start = i;
    }
    data[start] = temp;
}


/** 归并排序
 */
void divide(int * coll, int * data, int left, int rigt);
void merge(int * data, int * coll, int left, int mid, int rigt);
void merge_sort(int * data, int len) {
    if (data == NULL)
        return ;
    int * coll = new int[len];
    divide(coll, data, 0, len - 1);
    delete [] coll;
}

void divide(int * coll, int * data, int left, int rigt) {
    if (left == rigt)
        return ;
    int mid = (left + rigt) / 2;
    divide(coll, data, left, mid);
    divide(coll, data, mid + 1, rigt);
    merge(data, coll, left, mid, rigt);
}

void merge(int * data, int * coll, int left, int mid, int rigt) {
    int i = left, j = mid + 1, k = left;
    for (; i <= mid && j <= rigt; k++) {
        if (data[i] < data[j])
            coll[k] = data[i++];
        else
            coll[k] = data[j++];
    }
    while (i <= mid)
        coll[k++] = data[i++];
    while (j <= rigt)
        coll[k++] = data[j++];
    for (i = left; i <= rigt; i++)
        data[i] = coll[i];
}

// ACGT字符串中寻找出现超过一次的，占用内存小
vector<string> findRepeatedDnaSequences(string s) {
    unordered_map<int, int> m;
    vector<string> r;
    for (int t = 0, i = 0; i < s.size(); i++)
        if (m[t = t << 3 & 0x3FFFFFFF | s[i] & 7]++ == 1)
            r.push_back(s.substr(i - 9, 10));
    return r;

    // 这种内存超限
    // unordered_map<string, int> m;
    // vector<string> rs;
    // for (unsigned int t = 0, i = 10; i < s.size(); i++) {
    //     if (m[s.substr(i - 10, 10)]++ >= 1) {
    //         rs.push_back(s.substr(i - 10, 10));
    //     }
    // }
    // return rs;
}



// 还是没怎么看懂
int lengthOfLongestSubstring(string s) {
    if (s.empty())
        return 0;
            
    vector<int> charIndex(256, -1);
    int longest = 0, m = 0;

    for (int i = 0; i < s.length(); i++) {
        m = max(charIndex[s[i]] + 1, m);    // automatically takes care of -1 case
        charIndex[s[i]] = i;
        longest = max(longest, i - m + 1);
    }

    return longest;
}


string fractionToDecimal(int n, int d) {
    // zero numerator
    if (n == 0) return "0";

    string res;
    // determine the sign
    if (n < 0 ^ d < 0) res += '-';

    // remove sign of operands
    n = abs(n), d = abs(d);
    // append integral part
    res += to_string(n / d);
    // in case no fractional part
    if (n % d == 0) return res;

    res += '.';

    unordered_map<int, int> map;
    // simulate the division process
    for (int r = n % d; r; r %= d) {
        // meet a known remainder
        // so we reach the end of the repeating part
        if (map.count(r) > 0) {
            res.insert(map[r], 1, '(');
            res += ')';
            break;
        }
        // the remainder is first seen
        // remember the current position for it
        map[r] = res.size();

        r *= 10;
        // append the quotient digit
        res += to_string(r / d);
    }
    return res;
}