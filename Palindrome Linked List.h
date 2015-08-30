/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    /*****************************************************************************/
    /*  Given a singly linked list, determine if it is a palindrome.
    /*  Follow up:
    /*  Could you do it in O(n) time and O(1) space?
    /*****************************************************************************/
    
    /*****************************************************************************/
    /*  思路：
    /*  1）注意O(n)的时间复杂度并不表示只能遍历一次，可以遍历几次，但几次线性叠加
    /*     后的数量级仍是n；空间复杂度为O(1)并不是说只能申请一个辅助空间，而是指
    /*     空间大小与链表长度n无关
    /*  2）既然是回文——对称，那么就要找到链表的中点，复杂度O(n / 2)，奇数偶数要
    /*     稍微注意一下
    /*  3）把链表后半部分翻转，如果前半部分和后半部分一样，则返回true，否则false
    /*****************************************************************************/
    bool isPalindrome(ListNode * head) {
        if(head == NULL || head->next == NULL)
            return true;
        ListNode * slow = head;
        ListNode * fast = head;
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = reverseList(slow->next);
        slow = slow->next;
        while(slow != NULL){
            if(head->val != slow->val)
                return false;
            head = head->next;
            slow = slow->next;
        }
        return true;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode * pre = NULL;
        ListNode * next = NULL;
        while(head != NULL){
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
};