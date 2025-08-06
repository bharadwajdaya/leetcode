#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;
struct Node
{
    int val;
    Node* next;
    Node(int x): val(x),next(nullptr){};
};
Node* reverseInGroups(Node* root,int k)
{
    Node* dummy=new Node(0);
    dummy->next=root;
    Node* curr=dummy->next;
    int n=0;
    while(curr)
    {
        n++;
        curr=curr->next;
    }
    cout<<"Count "<<n<<endl;
    Node* prev;
    prev=dummy;
    Node* next;
    while(n>=k)
    {
        curr=prev->next;
        next=curr->next;
        
        for(int i=1;i<k;i++)
        {
            curr->next=next->next;
            next->next=prev->next;
            prev->next=next;
            next=curr->next;
        }
        prev=curr;
        n-=k;
    }
    return dummy->next;
}
int main()
{
    Node* node=new Node(1);
    node->next=new Node(2);
    node->next->next=new Node(3);
    node->next->next->next=new Node(4);
    node->next->next->next->next=new Node(5);
    node->next->next->next->next->next=new Node(6);
    Node* res=reverseInGroups(node,2);
    while (res) {
        cout << res->val << " ";
        res = res->next;
    }
    return 0;
}
