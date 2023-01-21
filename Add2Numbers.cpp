#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode dummyHead(0);
    ListNode* curr = &dummyHead;
    int carry = 0;
    while (l1 || l2) {
        int x = l1 ? l1->val : 0;
        int y = l2 ? l2->val : 0;
        int total = x + y + carry;
        carry = total / 10;
        curr->next = new ListNode(total % 10);
        curr = curr->next;
        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }
    if (carry > 0) {
        curr->next = new ListNode(carry);
    }
    return dummyHead.next;
}

int main() {
    // Test code goes here
    return 0;
}
