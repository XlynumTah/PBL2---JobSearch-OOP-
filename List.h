#include <iostream>
#include <assert.h>
#pragma once
using namespace std;
template <class T>
struct Node
{
    T data;
    struct Node<T> *next;
};
template <class T>
Node<T> *createNode(T x)
{
    Node<T> *t = new Node<T>;
    t->next = nullptr;
    t->data = x;
    return t;
}
template <class T>
class List;
template <class T>
ostream &operator<<(ostream &, const List<T> &);
template <class T>
class List
{
private:
    Node<T> *head;

public:
    List();
    List(const List &);
    ~List();
    // void Erase();
    T &operator[](const int &);
    int GetLength() const;
    friend ostream &operator<<<>(ostream &, const List<T> &);
    // void Reallocate(int); //Fast
    // void Resize(int); //Slow
    // void Insert(T, int);
    void Remove(const T &);
    void AddFirst(const T &);
    void AddLast(const T &);
    int IndexOf(const T &);
};

template <class T>
List<T>::List() : head(nullptr)
{
}

template <class T>
List<T>::List(const List &l) : head(l.head)
{
}

template <class T>
List<T>::~List()
{
    Node<T> *p;
    while (this->head != nullptr)
    {
        p = this->head;
        this->head = this->head->next;
        delete p;
    }
}

// template<class T>
// void List<T>::Erase()
// {

// }
template <class T>
T &List<T>::operator[](const int &i)
{
    assert(i >= 0 && i < this->GetLength());
    Node<T> *p = this->head;
    for (int j = 0; j < i; j++)
    {
        p = p->next;
    }
    return p->data;
}

template <class T>
int List<T>::GetLength() const
{
    int length = 0;
    for (Node<T> *t = this->head; t != nullptr; t = t->next)
    {
        ++length;
    }
    return length;
}

template <class T>
ostream &operator<<(ostream &o, const List<T> &l)
{
    for (Node<T> *t = l.head; t != nullptr; t = t->next)
    {
        o << t->data;
    }
    return o;
}

// template<class T>
// void List<T>::Reallocate(int newlength) //Fast
// {

// }

// template<class T>
// void List<T>::Resize(int newlength) //Slow
// {

// }

// template<class T>
// void List<T>::Insert(T s, int index)
// {
//     if(index >= 0 && index <= GetLength())
//     {
//         Node<T> *p = new Node<T>;
//         int k = 0;
//         while(k != index - 1)
//         {
//             p = p->next;
//             k++;
//         }
//         Node<T> *t = new Node<T>;
//         t->data = s;
//         t->next = p->next;
//         p->next = t;
//     }
// }

template <class T>
void List<T>::Remove(const T &s)
{
    Node<T> *t = this->head;
    if (t->data == s)
    {
        this->head = t->next;
    }
    for (; t->next != nullptr; t = t->next)
    {
        if (t->next->data == s)
        {
            t->next = t->next->next;
        }
        return;
    }
}

template <class T>
void List<T>::AddFirst(const T &s)
{
    Node<T> *p = createNode(s);
    p->next = this->head;
    this->head = p;
    // p->data = s;
    // p->next = nullptr;
    // head->next = p;
    // Insert(s,0);
}

template <class T>
void List<T>::AddLast(const T &s)
{
    Node<T> *t = createNode(s);
    Node<T> *p = this->head;
    if (this->head == nullptr)
    {
        this->head = t;
    }
    else
    {
        while (p->next != nullptr)
        {
            p = p->next;
        }
        p->next = t;
    }
}

template <class T>
int List<T>::IndexOf(const T &s)
{
    int index = -1;
    if (this->head == nullptr)
        return index;
    Node<T> *p = this->head;
    for (int i = 0; i < this->GetLength(); i++)
    {
        if (p->data == s)
        {
            index = i;
            break;
        }
        p = p->next;
    }
    return index;
}