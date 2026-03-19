/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */class Solution {
public:

    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        while (head != NULL) {
            ListNode* nextNode = head->next;
            head->next = prev;
            prev = head;
            head = nextNode;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) return true;

        ListNode *fast = head;
        ListNode *slow = head;

      
        while (fast->next != NULL && fast->next->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }

        
        ListNode *second = reverse(slow->next);

        ListNode *first = head;

      
        while (second != NULL) {
            if (first->val != second->val) return false;
            first = first->next;
            second = second->next;
        }

        return true;
    }
};