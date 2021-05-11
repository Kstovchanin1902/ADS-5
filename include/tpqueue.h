// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <cassert>

template<typename T>
class TPQueue {
   private:
        struct Item {
            T data; 
            Item* next;
        };
    public:
        TPQueue ():head(nullptr), tail(nullptr) {}
        ~TPQueue ();
        void push (const T&);
        T pop();
        void print() const;
    private:
        TPQueue::Item* create (const T&);
        Item *head;
        Item *tail;
};
template <typename T>
TPQueue<T>::~TPQueue ()
{
    while (head)
    {
        pop ();
    }
}
template <typename T>
void TPQueue<T>::push (const T& inData)
{
    if (head && tail)
    {
        Item* temp = head;
        int prior = inData.prior;
        if (head -> data.prior >= prior) 
        {
            while (temp)
            {
                if (temp -> next)
                {
                    if (prior > temp -> next -> data.prior)
                    {
                        Item *inner = create (inData);
                        inner -> next = temp -> next;
                        temp -> next = inner;
                        break;
                    }
                }
                else
                {
                    temp -> next = create (inData);
                    break;
                }
                temp = temp -> next;
            }
        }
        else
        {
            head = create (inData);
            head -> next = temp;
        }
    }
    else
    {
        head = create(inData);
        tail = head;
    }
}
template <typename T>
T TPQueue<T>::pop ()
{
    if (head)
    {
        Item *temp = head -> next;
        T data = head -> data;
        delete head;
        head = temp;
        return data;
    }
    else
    {
        return (T) 0;
    }
}
template <typename T>
void TPQueue<T>::print () const
{
    Item *temp = head;
    while (temp)
    {
        std::cout << "char = " << temp -> data.ch;
        std::cout << " prior = " << temp -> data.prior << std::endl;
        temp = temp -> next;
    }
}
struct SYM {
  char ch;
  int  prior;
};

#endif // INCLUDE_TPQUEUE_H_
