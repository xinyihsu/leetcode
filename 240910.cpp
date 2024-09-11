//2807. Insert Greatest Common Divisors in Linked List
#include <iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode *current = head, *next = head->next;
        while (next) {
            ListNode* newNode = new ListNode(computeGCD(current->val, next->val), next);
            current->next = newNode;

            current = next;
            next = current->next;
        }

        return head;
    }

    int computeGCD(int first, int second) {
        if (second < first) swap(first, second);

        for (int i = first; i > 0; i--) {
            if (!(first % i) && !(second % i)) return i;
        }

        return 1;
    }
};