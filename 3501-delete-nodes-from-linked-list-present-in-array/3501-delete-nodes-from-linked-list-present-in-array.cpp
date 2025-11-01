//No delete calls needed..leetcode does that stuff internally
//T.C=O(N)
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(nums.begin(), nums.end());

        while (head != NULL && st.find(head->val) != st.end()) {
            //ListNode* temp = head;
            head = head->next;
            //delete (temp);
        }

        ListNode* dh = head;
        while (dh != NULL && dh->next != NULL) {
            if (st.find(dh->next->val) != st.end()) {
                //ListNode* temp = dh->next;
                dh->next = dh->next->next;
                //delete (temp);
            } else
                dh = dh->next;
        }

        return head;
    }
};

// T.C=O(NâM)=>T.L.E
// class Solution {
// public:
//     ListNode* removeNode(int se, ListNode* head) {

//         while (head && head->val == se) {
//             head = head->next;
//         }

//         ListNode* dh = head;
//         while (dh && dh->next != nullptr) {
//             if (dh->next->val == se) {
//                 dh->next = dh->next->next;
//             } else
//                 dh = dh->next;
//         }

//         return head;
//     }

//     ListNode* modifiedList(vector<int>& nums, ListNode* head) {
//         for (int num : nums) {
//             ListNode* modifiedHead = removeNode(num, head);
//             head = modifiedHead;
//         }

//         return head;
//     }
// };