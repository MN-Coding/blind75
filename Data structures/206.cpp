/*
Problem: 206. Reverse Linked List
Time Complexity = O(n)
Space Complexity = O(1)
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr, *node = head;
        while(node) {
            ListNode *temp = node->next;
            node->next = prev;
            prev = node;
            node = temp;
        }
        return prev;

    }
};
