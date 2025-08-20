#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
        {
            return nullptr;
        }
        unordered_map<Node*,Node*> _map;
        Node* curr=head;

        while(curr)
        {
            _map[curr]=new Node(curr->val);
            curr=curr->next;
        }
        curr=head;
        while(curr)
        {
            _map[curr]->next=_map[curr->next];
            if(curr->random)
            {
                _map[curr]->random=_map[curr->random];
            }
            curr=curr->next;
        }
        return _map[head];
    }
};