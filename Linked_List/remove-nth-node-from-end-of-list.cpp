/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 *
 * Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example 1:
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:
Input: head = [1], n = 1
Output: []

Example 3:
Input: head = [1,2], n = 1
Output: [1]
 *
 *
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
class Solution
{
public:
    int getSize(ListNode *head)
    {
        int count = 0;
        while (head != nullptr)
        {
            count++;
            head = head->next;
        }
        return count;
    }

    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int sizeOfList = getSize(head);
        int NodeToDelete = sizeOfList - n;

        // Case when we need to delete the head
        if (NodeToDelete == 0)
        {
            ListNode *temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        ListNode *dh = head;
        int count = 0;

        while (dh->next != nullptr)
        {
            if (count + 1 == NodeToDelete)
            {
                ListNode *temp = dh->next;
                dh->next = dh->next->next;
                delete temp;
                return head;
            }
            count++;
            dh = dh->next;
        }

        return head;
    }
};
