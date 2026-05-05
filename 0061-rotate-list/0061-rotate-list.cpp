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
    int listSize(ListNode* head) {
        int count = 0;
        ListNode* curr = head;
        while (curr != nullptr) {
            count++;
            curr = curr->next;
        }
        return count;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        int n = listSize(head);
        if (n == 0)
            return 0;
        if (k % n == 0)
            return head;
        int toTraverse = n - (k % n);
        ListNode* secondHead = head;

        while (toTraverse) {
            if (toTraverse == 1) {
                ListNode* temp = secondHead->next;
                secondHead->next = nullptr;
                secondHead = temp;
            } else {
                secondHead = secondHead->next;
            }
            toTraverse--;
        }

        ListNode* temp = secondHead;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = head;

        return secondHead;
    }
};