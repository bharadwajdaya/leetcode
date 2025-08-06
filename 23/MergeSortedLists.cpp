#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;

struct Node
{
    int val;
    Node* next;
    Node(int x): val(x),next(nullptr){}
};
struct Compare
{
    bool operator()(Node* a,Node* b)
    {
        return a->val>b->val;
    }
};
Node* mergeKLists(vector<Node*> lists)
{
    priority_queue<Node*,vector<Node*>,Compare> q;
    Node* dummy=new Node(0);
    for(auto list:lists)
    {
        q.push(list);
    }
    Node* curr=dummy;
    while(!q.empty())
    {
        Node* top=q.top();
        q.pop();
        curr->next=top;
        if(top->next)
        {
            q.push(top->next);
        }
        curr=curr->next;
    }
    return dummy->next;
}
int main()
{
    Node* l1 = new Node(1);
    l1->next = new Node(4);
    l1->next->next = new Node(5);

    Node* l2 = new Node(1);
    l2->next = new Node(3);
    l2->next->next = new Node(4);

    Node* l3 = new Node(2);
    l3->next = new Node(6);

    vector<Node*> lists = {l1, l2, l3};

    Node* merged = mergeKLists(lists);
    
    while (merged) 
    {
        cout << merged->val << " ";
        merged = merged->next;
    }
    return 0;
}
