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
    ListNode* deleteMiddle(ListNode* head) {
        int n = 0;
        ListNode* dh = head;

        while (dh != NULL) {
            n++;
            dh = dh->next;
        }

        if (n == 1){
            return NULL;
        }
        if (n == 2) {
            head->next = NULL;
            return head;
        }

        int midCount = n / 2 - 1, i = 0;
        dh = head;
        while (i < midCount) {
            dh = dh->next;
            i++;
        }
        dh->next = dh->next->next;
        return head;
    }
};