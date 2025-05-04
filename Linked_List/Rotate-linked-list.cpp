/*
 *
 * [61] Rotate List
 *
 * Given the head of a linked list, rotate the list to the right by k places.

Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]

Example 2:
Input: head = [0,1,2], k = 4
Output: [2,0,1]
 *
 *
 */

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

// Simple but time limit error
// class Solution
// {
// public:
//     ListNode *rotateRight(ListNode *head, int k)
//     {

//         if (!head || !head->next)
//         {
//             return head;
//         }
//         int count = 0;
//         while (count < k)
//         {
//             ListNode *dh = head;
//             ListNode *temp;
//             while (dh->next->next != nullptr)
//             {
//                 dh = dh->next;
//             }

//             temp=dh->next;
//             dh->next=nullptr;
//             temp->next=head;
//             head=temp;
//             count++;
//         }
//         return head;
//     }
// };

// Find length, reduce k, go while loop and do like before
//  class Solution
//  {
//  public:
//      ListNode *rotateRight(ListNode *head, int k)
//      {
//          if (!head || !head->next)
//              return head;

//         //Get the length first
//         int n = 1;
//         ListNode *temp1 = head;
//         while (temp1->next != nullptr)
//         {
//             n++;
//             temp1 = temp1->next;
//         }

//         //Mod to reduce the size
//         //Logic: a list becomes same after rotated n times
//         k = k % n;
//         if (k == 0)
//             return head;

//         int count = 0;
//         while (count < k)
//         {
//             ListNode *dh = head;
//             ListNode *temp;
//             while (dh->next->next != nullptr)
//             {
//                 dh = dh->next;
//             }

//             temp = dh->next;
//             dh->next = nullptr;
//             temp->next = head;
//             head = temp;
//             count++;
//         }
//         return head;
//     }
// };

// Find length, reduce k, make the list circular,
// Get new tail by traveling n-k nodes
// point the head to newtail->next
// point newTail->next to nullptr
class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || !head->next)
            return head;

        int n = 1;
        ListNode *tail = head;
        while (tail->next != nullptr)
        {
            n++;
            tail = tail->next;
        }

        k = k % n;
        if (k == 0)
            return head;
        tail->next = head;
        for (int i = 0; i < n - k; i++)
        {
            tail = tail->next;
        }
        head = tail->next;
        tail->next = nullptr;
        return head;
    }
};
