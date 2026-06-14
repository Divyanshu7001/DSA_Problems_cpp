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
    int pairSum(ListNode* head) {
        vector<int> temp;
        ListNode* dh = head;
        while (dh != NULL) {
            temp.push_back(dh->val);
            dh = dh->next;
        }

        int i = 0, j = temp.size() - 1;
        int res = 0;
        while (i < j) {
            res = max(res, temp[i] + temp[j]);
            i++;
            j--;
        }

        return res;
    }
};