#include <iostream>
#include <vector>
using namespace std;

class Stack{
protected:
    virtual ~Stack() {};
    virtual int pop(int &elem) = 0;
    virtual int push(int &elem) = 0;
    virtual int size() const = 0;
    virtual int empty() const = 0;
    virtual int full() const = 0;
    virtual int peek(int, int &elem) const = 0;
    virtual void print() = 0;
};

class LIFO_Stack : public Stack {
public:
    LIFO_Stack(vector<int> &elems): _top(0),_elems(elems)
    {}
    LIFO_Stack()
    {}
    ~LIFO_Stack()
    {}
    int pop(int &elem)
    {
        if (empty()) {
            cerr << "LIFO_Stack is empty()\n";
            return false;
        }
        cout << "pop top= " << _top << endl;
        elem = _elems[--_top];
        _elems.pop_back();
        return true;
    }
    int push(int &val)
    {
        if (full()) {
            cerr << "LIFO_Stack is full()\n";
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
    int peek(int, int &) const
    {
        return false;
    }
    void print()
    {
        vector<int>::iterator ibeg = _elems.begin();
        vector<int>::iterator iend = _elems.end();
        cout << "size =" << _elems.size() << endl;
        for (; ibeg != iend; ibeg++) {
            cout << *ibeg << " ";
        }
        cout << endl;
        cout << "size =" << _elems.size() << endl;
    }

private:
    vector<int> _elems;
    int _top;
};

class Peekback_Stack : public Stack {
public:
    Peekback_Stack(vector<int> &elems): _top(0), _elems(elems)
    {}
    Peekback_Stack()
    {}
    ~Peekback_Stack()
    {}
    int pop(int &elem)
    {
        if (empty()) {
            cerr << "Peekback_Stack is empty()\n";
            return false;
        }
        cout << "pop top= " << _top << endl;
        elem = _elems[--_top];
        _elems.pop_back();
        return true;
    }
    int push(int &val)
    {
        if (full()) {
            cerr << "Peekback_Stack is full()\n";
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
    int peek(int index, int &elem) const
    {
        if (empty())
            return false;
        else if ((index<0) || (index >= size()))    
            return false;

        elem= _elems[index];
        return true;
    }
    void print()
    {
        vector<int>::iterator ibeg = _elems.begin();
        vector<int>::iterator iend = _elems.end();
        cout << "size =" << _elems.size() << endl;
        for (; ibeg != iend; ibeg++) {
            cout << *ibeg << " ";
        }
        cout << endl;
        cout << "size =" << _elems.size() << endl;
    }

private:
    vector<int> _elems;
    int _top;
};

int main(void)
{
    cout << "begin:" << endl;
    LIFO_Stack lfstack;
    int elem;
    cout << "begin:" << endl;
//    Peekback_Stack pbstack;
    for (int i = 0; i < 10; i++) {
        lfstack.push(i);
     //   pbstack.push(i);
    }
    cout << "Lifo stack:" << endl;
    lfstack.print();
    cout << "Lifo stack end" << endl;
    lfstack.pop(elem);
    cout << elem << endl;
    lfstack.pop(elem);
    cout << elem << endl;
    lfstack.print();
    cout << "lifo size:" << lfstack.size() << endl;
#if 0
    cout << "Peekback stack:";
    pbstack.print();
    pbstack.print();
    pbstack.pop(elem);
    cout << elem << endl;
    pbstack.peek(5, elem);
    cout << elem << endl;
#endif
    return 0;
}
