
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
    /*  给出一个长度为m的排序数组：A，可以将其分成两部分
    /*  {A[0], A[1], ... , A[i - 1]} | {A[i], A[i + 1], ... , A[m - 1]}
    /*  右半部份（m-i个元素）的所有元素都大于左半部分（i个元素），共有 m+1 
    /*  种分法：i：0 ~ m。对数组B，有同样的分法，左边 j 个元素，右边 n-j个
    /*  把 A、B 的左半部分放到一起，右半部份放到一起
    /*            LeftPart           |            RightPart 
    /*  {A[0], A[1], ... , A[i - 1]} | {A[i], A[i + 1], ... , A[m - 1]}
    /*  {B[0], B[1], ... , B[j - 1]} | {B[j], B[j + 1], ... , B[n - 1]}
    /*    
    /*  如果我们能保证:
    /*  1)左半部分长度等于右半部份或右半部份加 1
    /*  2)右半部份的所有元素都大于左半部分
    /*  那么 median 就好找了
    /*  为了保证上面两个条件，我们只需：
    /*  1) i + j == m - i + n - j (or: m - i + n - j + 1)
    /*      if n >= m, we just need to set: 
    /*          i = 0 ~ m, j = (m + n + 1) / 2 - i
    /*  2) B[j - 1] <= A[i] and A[i - 1] <= B[j]
    /*      考虑到边界条件，我们只需：
    /*      (j == 0 or i == m or B[j - 1] <= A[i]) and 
    /*      (i == 0 or j == n or A[i - 1] <= B[j])
    /*  所以，我们要做的就是：
    /*  从 0 ~ m 中搜寻满足条件的 i 
    /*  可以用二分查找法：
    /*  1）set imin, imax = 0, m, then start searching in [imin, imax]
    /*  2）i = (imin + imax) / 2; j = (m + n + 1) / 2 - i
    /*  3）if B[j - 1] > A[i]: continue searching in [i + 1, imax]
    /*     else if A[i - 1] > B[j]: continue searching in [imin, i - 1]
    /*     else: bingo! this is our object "i"
    /*  找到这样的 i 之后
    /*  max(A[i - 1], B[j - 1]) (when m + n is odd)
    /*  or (max(A[i - 1], B[j - 1]) + min(A[i], B[j])) / 2 (when m + n is even)        
    /***************************************************************/

    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if (m > n) 
            return findMedianSortedArrays(B, n, A, m);
        int minidx = 0, maxidx = m, i, j, num1, mid = (m + n + 1) >> 1, num2;
        while (minidx <= maxidx) {
            i = (minidx + maxidx) >> 1;
            j = mid - i;
            if (i < m && j > 0 && B[j - 1] > A[i]) 
                minidx = i + 1;
            else if (i > 0 && j < n && B[j] < A[i - 1]) 
                maxidx = i - 1;
            else {
                if (i == 0) 
                    num1 = B[j-1];
                else if (j == 0) 
                    num1 = A[i - 1];
                else 
                    num1 = max(A[i-1],B[j-1]);
                break;
            }
        }
        if (((m + n) & 1)) 
            return num1;
        if (i == m) 
            num2 = B[j];
        else if (j == n) 
            num2 = A[i];
        else 
            num2 = min(A[i], B[j]);
        return (num1 + num2) / 2.0;
    }
};