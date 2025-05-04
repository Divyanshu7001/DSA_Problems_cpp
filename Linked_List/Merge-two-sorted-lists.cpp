/*
 *
 * [21] Merge Two Sorted Lists
 *
 * You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
Return the head of the merged linked list.
 *
 *
 * Example:
 *
 * Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
 * Input: list1 = [], list2 = []
Output: []
 *Input: list1 = [], list2 = [0]
Output: [0]

 */

// Definition for singly-linked list.
#include <iostream>
using namespace std;

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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *head1 = list1;
        ListNode *head2 = list2;
        ListNode *temp = new ListNode(0);
        ListNode *firstNode = temp;

        if (!head1 && !head2)
            return nullptr;
        if (!head1)
            return head2;
        if (!head2)
            return head1;

        while (head1 && head2)
        {
            if (head1->val <= head2->val)
            {
                temp->next = head1;
                head1 = head1->next;
            }
            else
            {
                temp->next = head2;
                head2 = head2->next;
            }
            temp = temp->next;
        }

        if (head1)
        {
            temp->next = head1;
        }

        if (head2)
        {
            temp->next = head2;
        }
        return firstNode->next;
    }
};

ListNode *createList(int n)
{
    if (n <= 0)
        return nullptr;

    int val;
    cout << "Enter first element value: ";
    cin >> val;
    ListNode *head = new ListNode(val);
    ListNode *current = head;

    for (int i = 1; i < n; ++i)
    {
        cout << "Enter " << i + 1 << " element value: ";
        cin >> val;
        current->next = new ListNode(val);
        current = current->next;
    }
    return head;
}

void printList(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->val;
        if (head->next)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    int n1, n2;

    cout << "Enter number of elements in first list: ";
    cin >> n1;
    cout << "Enter " << n1 << " sorted values for first list:" << endl;
    ListNode *list1 = createList(n1);

    cout << "Enter number of elements in second list: ";
    cin >> n2;
    cout << "Enter " << n2 << " sorted values for second list:" << endl;
    ListNode *list2 = createList(n2);

    //Merged List function calling
    Solution solution;
    ListNode *mergedHead = solution.mergeTwoLists(list1, list2);
    cout << "Merged sorted list: ";
    printList(mergedHead);

    return 0;
}