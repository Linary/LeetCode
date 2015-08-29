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
    /*************************************************************/
    /*  You are given two linked lists representing two non-negative numbers. 
    /*  The digits are stored in reverse order and each of their nodes contain 
    /*  a single digit. Add the two numbers and return it as a linked list.
    /*  Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
    /*  Output: 7 -> 0 -> 8
    /*************************************************************/
    
    /*************************************************************/
    /*  思路：按位相加，进位往后传递
    /*  1）如果两个链表未同时到达尾节点，到达的节点值用0代替
    /*  2）每次求和要带上进位位，进位位等于和除10的商
    /*  3）求和的结果求余后的值作为当前节点的值
    /*************************************************************/ 
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *  head = NULL;
        ListNode ** p = &head;
        int extra = 0;
        while (l1 || l2 || extra) {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + extra;
            extra = sum / 10;
            *p = new ListNode(sum % 10);
            //p->next = new ListNode(sum % 10);
            p = &((*p)->next);
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }
        return head;
    }
};