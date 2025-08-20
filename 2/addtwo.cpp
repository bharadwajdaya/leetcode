#include<iostream>
#include<string>
#include<vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode(-1);
        ListNode* curr=dummy;
        int carry=0;
        while(l1 || l2 || carry)
        {
            int _val=carry;
            if(l1)
            {
                _val+=l1->val;
                l1=l1->next;
            }
            if(l2)
            {
                _val +=l2->val;
                l2=l2->next;
            }
            int _num=_val%10;
            carry=_val/10;
            curr->next=new ListNode(_num);
            curr=curr->next;
        }
        return dummy->next;
    }
};