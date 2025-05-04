/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
 */

//@lc code=start

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// With Map
// class Solution
// {
// public:
//     ListNode *deleteDuplicates(ListNode *head)
//     {
//         if (!head)
//             return nullptr;

//         unordered_map<int, int> store;
//         store[head->val] = 1;

//         ListNode *dh = head;

//         while (dh->next != nullptr)
//         {
//             if (store.find(dh->next->val) == store.end())
//             {
//                 store[dh->next->val] = 1;
//                 dh = dh->next;
//             }
//             else
//             {
//                 dh->next = dh->next->next;
//             }
//         }
//         return head;
//     }
// };

// simple
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head)
            return nullptr;
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *dh = head;

        while (dh->next != nullptr)
        {
            if (dh->val == dh->next->val)
            {
                dh->next = dh->next->next;
            }
            else
                dh = dh->next;
        }
        return head;
    }
};

// @lc code=end
