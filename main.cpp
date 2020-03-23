#include <bits/stdc++.h>

using namespace std;

template<class t>

class abc
{
public:
    struct node
    {
        t data;
        node* l;
        node* r;
    }*root, *ptr;
    abc()
    {
        root=nullptr;
    }
    node* newNode()
    {
        return new node;
    }

    void inorder(node* ptr)
    {
        if(!ptr)
            return;
        inorder(ptr->l);
        cout<<ptr->data<<" ";
        inorder(ptr->r);
    }

    void createRootNode(t value)
    {
        if(root==nullptr)
        {
            root=newNode();
            ptr=root;
            ptr->data=value;
            ptr->l=ptr->r=nullptr;
        }
        else
        {
            char ch;
            cout<<"for push to left press 'l' or press 'r' for right: ";
            cin>>ch;
            ptr=root;
            if(ch=='l')
            {
                if(ptr->l==nullptr)
                {
                    ptr->l=newNode();
                    ptr=ptr->l;
                    ptr->data=value;
                    ptr->l=ptr->r=nullptr;
                }
                else
                {
                    while(ptr->l!=nullptr)
                        ptr=ptr->l;
                }
            }
            else if(ch=='r')
            {
                if(ptr->r==nullptr)
                {
                    ptr->r=newNode();
                    ptr=ptr->r;
                    ptr->data=value;
                    ptr->l=ptr->r=nullptr;
                }
                else
                {
                    while(ptr->r!=nullptr)
                        ptr=ptr->r;
                }
            }
            else
                cout<<"\n\n\nInvalid choice!!!"<<endl;
        }
    }
};

int main()
{
    abc<int> a;
    a.createRootNode(10);
    a.createRootNode(12);
    a.createRootNode(14);
    a.createRootNode(13);
    a.createRootNode(18);
    a.createRootNode(17);

    a.inorder(a.root);
    return 0;
}
