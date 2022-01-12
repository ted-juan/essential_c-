#include <iostream>
#include <vector>
using namespace std;


class Stack {
public:
    Stack(vector<int> &elems): _top(0),_elems(elems)
    {}
    Stack() : _top(0) 
    {}
    ~Stack()
    {}
    int pop(int &elem)
    {
        if (empty()) {
            cerr << "Stack is empty()\n";
            return false;
        }
        elem = _elems[--_top];
        _elems.pop_back();
        return true;
    }
    int push(int &val)
    {
        if (full()) {
            cerr << "Stack is full()\n";
            return false;
        }
        _elems.push_back(val);
        _top++;
        return true;
    }
    int size() const
    {
        return _elems.size();
    }
    int empty() const
    {
        return _elems.empty();
    }
    int full() const
    {
        return _elems.size() == _elems.max_size();
    }
    virtual int peek(int, int &) const
    {
        return false;
    }
    void print()
    {
        vector<int>::iterator ibeg = _elems.begin();
        vector<int>::iterator iend = _elems.end();
        for (; ibeg != iend; ibeg++) {
            cout << *ibeg << " ";
        }
        cout << endl;
    }

protected:
    vector<int> _elems;
    int _top;
};

class Peekback_Stack : public Stack {
public:
    int peek(int index, int &elem) const
    {
        if (empty())
            return false;
        else if ((index<0) || (index >= size()))    
            return false;

        elem= _elems[index];
        return true;
    }
};

int main(void)
{
    Stack lfstack;
    Peekback_Stack pbstack;
    int elem;
    for (int i = 0; i < 10; i++) {
        lfstack.push(i);
        pbstack.push(i);
    }
    cout << "Lifo stack:" << endl;
    lfstack.print();
    lfstack.pop(elem);
    cout << elem << endl;
    lfstack.pop(elem);
    cout << elem << endl;
    lfstack.print();

    cout << "Peekback stack:";
    pbstack.print();
    pbstack.pop(elem);
    cout << elem << endl;
    pbstack.peek(5, elem);
    cout << elem << endl;
    pbstack.print();

    return 0;
}
