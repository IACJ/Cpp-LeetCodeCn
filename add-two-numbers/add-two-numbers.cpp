//
// Created by AckleyJia on 2018/11/1.
//
#include <iostream>
#include <vector>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto fakeHead = new ListNode(0);
        ListNode * tmp = fakeHead;
        int v1;
        int v2;
        unsigned int v3 = 0;
        while (v3 != 0 || l1 != nullptr || l2 != nullptr ){
            if (l1 == nullptr){
                v1 = 0;
            } else {
                v1 = l1->val;
            }
            if (l2 == nullptr){
                v2 = 0;
            } else {
                v2 = l2->val;
            }
            tmp->next = new ListNode((v1+v2+v3) % 10);
            tmp = tmp->next;
            v3 = (v1+v2+v3) / 10;

            if (l1 != nullptr){
                l1 = l1->next;
            }
            if (l2 != nullptr){
                l2 = l2->next;
            }
        }
        return fakeHead->next;
    }
};


int main() {
    Solution solution;
    auto l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1 ->next->next = new ListNode(3);
    auto l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    cout << "hello" << endl;
    auto l3 = solution.addTwoNumbers(l1,l2);
}