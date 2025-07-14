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
    int getDecimalValue(ListNode* head) {
        ListNode* dh = head;
        vector<int> numbers;
        int result = 0;

        // Traverse and collect values
        while (dh != nullptr) {
            numbers.push_back(dh->val);
            dh = dh->next;
        }

        // Convert binary to decimal
        int n = numbers.size();
        for (int i = 0; i < n; ++i) {
            result += numbers[i] * pow(2, n - i - 1);
        }

        return result;
    }
};
