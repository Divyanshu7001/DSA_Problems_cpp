/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
 *
 * Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)


Example 1:
Input: head = [1,2,3,4]

Output: [2,1,4,3]

Example 2:
Input: head = []
Output: []

Example 3:
Input: head = [1]
Output: [1]

Example 4:
Input: head = [1,2,3]
Output: [2,1,3]
 */

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// class Solution
// {
// public:
//     ListNode *swapPairs(ListNode *head)
//     {
//         if (!head)
//             return nullptr;
//         // if (head == nullptr || head->next == nullptr)
//         //     return head;

//         ListNode *dh = head;
//         ListNode *fh = head;
//         ListNode *temp;

//         while (dh->next!=nullptr && fh->next!=nullptr)
//         {
//             if (dh == head)
//             {
//                 fh = fh->next;
//                 dh->next = dh->next->next;
//                 fh->next = head;
//                 head = fh;
//                 fh = fh->next;
//                 dh = dh->next;
//             }
//             else
//             {
//                 fh->next = fh->next->next;
//                 dh->next = fh->next->next;
//                 fh = fh->next;
//                 dh = dh->next;
//             }
//         }
//         return head;
//     }
// };
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        ListNode *dh = head;
        ListNode *fh = head->next;

        head = fh; // after first swap, new head will be second node

        while (true)
        {
            ListNode *nextPair = fh->next;
            fh->next = dh;

            if (!nextPair || !nextPair->next)
            {
                dh->next = nextPair;
                break;
            }

            dh->next = nextPair->next;

            // move dh and fh to next pair
            dh = nextPair;
            fh = dh->next;
        }

        return head;
    }
};

// @lc code=end
