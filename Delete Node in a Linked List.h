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

    /************************************************************/
    /*  思路：
    /*  1）拷贝后一个节点的内容至当前节点
    /*  2）删除后一个节点
    /************************************************************/
    void deleteNode(ListNode* node) {
        auto next = node->next;
        *node = *next;
        delete next;
    }
};