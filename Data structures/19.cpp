/*
Problem: 19. Remove Nth Node From End of List
Time Complexity: O(n)
Space Complexity: O(1)
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *node = head, *v = head;
        for (int i = 0; i < n; i++) {
            v = v->next;
        }
        if (v == nullptr) {
            return head->next;
        }
        while (v->next != nullptr) {
            node = node->next;
            v = v->next;
        }
        ListNode* temp = node->next;
        node->next = node->next->next;
        return head;
    }
};
