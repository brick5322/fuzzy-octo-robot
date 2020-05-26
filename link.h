//Created 2020 by Liu Fubaichuan
#ifndef NULL 0
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
    friend void Node_delete(Node* p);
    friend void Node_Add_after(Node*&,void*);
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
void Node_delete(Node* p)
{
    p->Node_backward();
    now->next = p->next;
    delete p;
    p = NULL;
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
