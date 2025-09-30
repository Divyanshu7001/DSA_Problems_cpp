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
    ListNode* mergeTwoLists(ListNode* first, ListNode* second) {
        // Dummy head node to simplify handling
        ListNode* dh = new ListNode();
        ListNode* tail = dh; // tail will track the end of the new merged list

        while (first && second) {
            if (first->val <= second->val) {
                tail->next = first;
                first = first->next;
            } else {
                tail->next = second;
                second = second->next;
            }
            tail = tail->next; // move the tail forward
        }
        if (first)
            tail->next = first;
        if (second)
            tail->next = second;

        return dh->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        ListNode* merged = lists[0];
        for (int i = 1; i < lists.size(); i++) {
            merged = mergeTwoLists(merged, lists[i]);
        }
        return merged;
    }
};