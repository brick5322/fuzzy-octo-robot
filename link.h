//Created 2020 by Liu Fubaichuan
#ifndef NULL
#define NULL 0
#endif 
#define now(p) now = p 
#ifndef __LINK_H__
#define __LINK_H__
class Node;
Node* now = NULL;
class Node
{
public:
    Node()
    {
        next = NULL;
        data_class = NULL;
        last = NULL;
    }
    friend void Node_add(Node*& p, void* input);
    friend Node* Node_delete(Node* p);
    friend void Node_Add_after(Node*&,void*);
    bool headnode();
    void* Node_forward();
    void* Node_backward();
private:
    void* data_class;
    Node* next;
    Node* last;
};
void Node_add(Node*& p, void* input)
{
    now = p;
    while (now->next != NULL)
        now->Node_forward();
    now->next = new Node;
    (now->next)->last = now;
    now->data_class = input;
}
Node* Node_delete(Node* p)
{
    if (p->last != NULL)
    {
        p->Node_backward();
        (p->next)->last = now;
        now->next = p->next;
        delete p;
        p = NULL;
        return NULL;
    }
    else
    {
        (p->next)->last = NULL;
        Node* a = p->next;
        delete p;
        return a;
    }
}
void Node_Add_after(Node*& A,void* input)
{   
    Node* s = A;
    now = A->next;
    Node* p = new Node;
    p->data_class = input;
    p->last = s;
    p->next = now;
    now->last = p;
    s->next = p;
}
bool Node::headnode()
{
    return !last;
}
void* Node::Node_forward()
{
    if (this == NULL)
        return NULL;
    void* data = data_class;
    now = next;
    return data;
}
void* Node::Node_backward()
{
    if (this == NULL)
        return NULL;
    void* data = data_class;
    now = last;
    return data;
}
#endif
