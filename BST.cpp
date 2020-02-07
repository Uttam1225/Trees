#include <iostream>

using namespace std;

template<class t>
class abc
{
    int c=0;
    struct node
    {
        t data;
        node* left;
        node* right;
    } *ptr;

public:

    node* root;

    abc()
    {
        root=nullptr;
    }
    ~abc()
    {
        delete root;
    }
    node* newNode()
    {
        return new node;
    }
    void insNode(t value);
    void Inorder(node*);
    void Postorder(node*);
    void Preorder(node*);
    void delNode(node*,int);
    void insNewNode(t value)
    {
        ptr=root;
        while(1)
        {
            if(value<ptr->data)
            {
                if(ptr->left==nullptr)
                {
                    ptr->left=newNode();
                    ptr=ptr->left;
                    ptr->data=value;
                    ptr->left=ptr->right=nullptr;
                    break;
                }
                else if(ptr->left!= nullptr)
                    ptr=ptr->left;
            }
            else
            {
                if(ptr->right==nullptr)
                {
                    ptr->right=newNode();
                    ptr=ptr->right;
                    ptr->data=value;
                    ptr->left=ptr->right=nullptr;
                    break;
                }
                else if(ptr->right!= nullptr)
                    ptr=ptr->right;
            }
        }
    }
};

template<class t>
void abc<t>::insNode(t value)
{
    if(root==nullptr)
    {
        root=newNode();
        root->data=value;
        root->left=root->right=nullptr;
    }
    else
    {
        ptr=root;
        while(true)
        {
            if(value<ptr->data)
            {
                if(ptr->left==nullptr)
                {
                    ptr->left=newNode();
                    ptr=ptr->left;
                    ptr->data=value;
                    ptr->left=ptr->right=nullptr;
                    break;
                }
                else
                    if(ptr->left not_eq nullptr)
                        ptr=ptr->left;
            }
            else
            {
                if(ptr->right==nullptr)
                {
                    ptr->right=newNode();
                    ptr=ptr->right;
                    ptr->data=value;
                    ptr->left=ptr->right=nullptr;
                    break;
                }
                else
                    if(ptr->right not_eq nullptr)
                        ptr=ptr->right;
            }
        }
    }
}

template<class t>
void abc<t>::delNode(node* ptr,int ele)
{
    if(ptr!=nullptr)
    {
        if(ele<ptr->data)
        {
            if(ele==ptr->data)
            {

            }
            else
                delNode(ptr->left,ele);
        }
    }
}

template<class t>
void abc<t>::Inorder(node* ptr)
{
    if(ptr!=nullptr)
    {
        Inorder(ptr->left);
        cout<<ptr->data<<"  ";
        Inorder(ptr->right);
    }
}

template<class t>
void abc<t>::Preorder(node* ptr)
{
    if(ptr!=nullptr)
    {
        cout<<ptr->data<<"  ";
        Inorder(ptr->left);
        Inorder(ptr->right);
    }
}

template<class t>
void abc<t>::Postorder(node* ptr)
{
    if(ptr!=nullptr)
    {
        Inorder(ptr->left);
        Inorder(ptr->right);
        cout<<ptr->data<<"  ";
    }
}

int main()
{
    abc<int> a;
    a.insNode(10);
    a.insNode(5);
    a.insNode(15);
    a.insNode(6);
    a.insNode(13);
    a.insNode(4);
    a.insNode(16);
    a.insNode(2);
    cout<<"Preorder trav : ";
    a.Preorder(a.root);
    cout<<"\n\nInorder trav : ";
    a.Inorder(a.root);
    cout<<"\n\nPostorder trav : ";
    a.Postorder(a.root);
    a.insNewNode(12);
    a.insNewNode(134);
    a.insNewNode(1);
    a.insNewNode(3);
    a.insNewNode(125);
    cout<<"\n\nInorder trav after adding new nodes : ";
    a.Inorder(a.root);
    cout<<"\n\n";
    //cout<<"Deleting any node in BST : ";
    //a.delNode(a.root,13);
    return 0;
}
