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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        int count = 0;
        ListNode* dh = head;
        while (dh != nullptr) {
            count++;
            dh = dh->next;
        }
        if (count <= 2)
            return {-1, -1};

        vector<int> st;
        int i = 1, prev = head->val;
        dh = head->next;
        while (dh->next != nullptr) {
            if ((dh->val > prev && dh->val > dh->next->val) ||
                (dh->val < prev && dh->val < dh->next->val)) {
                st.push_back(i);
            }
            prev = dh->val;
            i++;
            dh = dh->next;
        }

        if (st.size() < 2)
            return {-1, -1};

        if (st.size() == 2)
            return {st[1] - st[0], st[1] - st[0]};

        int minRes = INT_MAX;
        for (int i = 1; i < st.size(); i++) {
            if (st[i] - st[i - 1] < minRes)
                minRes = st[i] - st[i - 1];
        }
        return {minRes, st[st.size() - 1] - st[0]};
    }
};