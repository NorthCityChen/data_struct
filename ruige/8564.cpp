/*
 * @Author: Mr.Sen
 * @LastEditTime: 2020-10-23 10:39:48
 * @Description: 链式队列【模板类】
 * @Website: https://grimoire.cn
 * @Copyright: 2020 Mr.Sen All rights reserved.
 */
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class queueNode
{
private:
    typedef struct linkNode
    {
        // linkNode *front, *rear;
        T data;
        linkNode *next;
    }linkNode, *link;
    link front, rear;
    int size_queue;
public:
    queueNode()
    {
        link s = new linkNode;
        s->next = NULL;
        s->data = 0;
        front = s;
        rear = s;
        size_queue = 0;
    }
    void push(T value)
    {
        link s = new linkNode;
        s->data = value;
        s->next = NULL;
        rear->next = s;
        rear = rear -> next;
        size_queue++;
        // cout << rear->data << endl;
        // cout << front->data << endl;
    }
    T pop()
    {
        if (front == rear)
        {
            cout << "EMPTY QUEUE !!!" << endl;
            exit(0);
        }
        link q = front;
        front = front->next;
        T value = front->data;
        delete q;
        size_queue--;
        return value;
        // link q = front
    }
    T back()
    {
        return front -> next -> data;
    }
    int size()
    {
        return size_queue;
    }
};

int main()
{
    queueNode <int> s;
    int x;
    while (cin >> x && x != 0)
    {
        s.push(x);
    }
    while (s.size())
    {
        cout << s.pop() << " ";
    }
    cout << endl;
    return 0;
}