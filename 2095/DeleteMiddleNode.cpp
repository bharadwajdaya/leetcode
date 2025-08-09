#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct Node
{
    int val;
    Node* next;
    Node(int x):val(x),next(nullptr){};
};
void deleteTheMiddleNode(Node* root)
{
    if(root==nullptr || root->next==nullptr)
    {
        return;
    }
    Node* slow=root;
    Node* fast=root;
    Node* toDelete;
    Node* prev;
    while(fast!=NULL && fast->next!=NULL)
    {
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    if(prev!=nullptr)
    {
        prev->next=slow->next;
        delete slow;
    }
}
int main()
{
    Node* root=new Node(1);
    root->next=new Node(2);
    root->next->next=new Node(3);
    root->next->next->next=new Node(4);
    root->next->next->next->next=new Node(5);
    deleteTheMiddleNode(root);
    for(int i=0;root!=nullptr;i++)
    {
        cout<<root->val<<",";
        root=root->next;
    }
    cout<<endl;
    return 0;
}