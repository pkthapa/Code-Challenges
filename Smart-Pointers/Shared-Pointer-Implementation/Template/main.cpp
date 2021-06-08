#include "main.h"

template <class T>
class Shared_ptr
{
    T *p;
    int *refCount = nullptr; // For ease to maintain the count between different Shared_ptr objects.
    /*
    Why refCount is not static type?

    A static variable is a kind of global variable. Meaning, if a static variable is defined in a class that means this variable is shared among all objects of that class, irrespective of whether all objects are linked or not.

    shared_ptr<int> sp1(new int);
    shared_ptr<int> sp2(sp1);

    Here, sp1 & sp2 will have a refCount = 2, because sp1 and sp2 are linked.

    shared_ptr<int> sp3(new int);

    If refCount were static, then the refCount of sp3 would have been 3.
    The expected value of sp3's refCount is 1 because sp3 is not linked to neither sp1 nor sp2.
    */

public:
    Shared_ptr() : p(nullptr), refCount(new int(0))
    {}

    Shared_ptr(T* temp) : p(temp), refCount(new int(0))
    {
        if (nullptr != temp)
        {
            ++(*this->refCount);
        }
    }

    // Shallow copy: Copy constructor
    Shared_ptr(const Shared_ptr& obj)
    {
        this->p = obj.p; // Share the underlying pointer.
        this->refCount = obj.refCount; // Share the refCount.

        // If the pointer is not null, then increase the refCount;
        if (nullptr != obj.p)
        {
            (*refCount)++;
        }
    }

    // Shallow copy: Copy assignment
    // Reference by reference is a must here. If return by value, then copy constructor will be called.
    Shared_ptr& operator=(const Shared_ptr& obj)
    {
        // Clean existing objects.
        delete this->p;
        delete this->refCount;

        this->p = obj.p;
        this->refCount = obj.refCount;

        if (nullptr != obj.p)
        {
            (*this->refCount)++;
        }
        return *this;
    }

    // Move constructor
    Shared_ptr(Shared_ptr&& dyingObj)
    {
        this->p = dyingObj.p;
        this->refCount = dyingObj.refCount;

        // Cleanup the dyingObj.
        dyingObj.p = nullptr;
        dyingObj.refCount = nullptr;
    }

    // Move assignment
    Shared_ptr& operator=(Shared_ptr&& dyingObj)
    {
        this->p = dyingObj.p;
        this->refCount = dyingObj.refCount;

        // Cleanup the dyingObj.
        dyingObj.p = dyingObj.refCount = nullptr;

        return *this;
    }

    int* operator->() const
    {
        return p; // this->p;
    }

    int& operator*() const
    {
        return *p; // *this->p;
    }

    int use_count() const
    {
        return *this->refCount; // *refCount;
    }

    int* get() const
    {
        return p; // this->p
    }

    ~Shared_ptr()
    {
        cleanUp();
    }

private:
    void cleanUp()
    {
        (*refCount)--;
        if (*refCount == 0)
        {
            if (nullptr != p)
            {
                delete p;
            }
            delete refCount;
        }
    }
};


int main()
{
    Shared_ptr<int> sp(new int);
    cout << sp.get() << " " << sp.use_count() << endl;

    *sp = 2;

    Shared_ptr<int> sp1 = sp;
    cout << sp.get() << " " << sp.use_count() << endl;
    {
        Shared_ptr<int> sp2 = sp;
        cout << sp.get() << " " << sp.use_count() << endl;
    }
    cout << sp.get() << " " << sp.use_count() << endl;
    Shared_ptr<int> sp3 = sp1;
    cout << sp.get() << " " << sp.use_count() << endl;

    cout << "print:" << *sp3 << endl;
    return 0;
}

/*
Output:
0x7fffd4724eb0 1
0x7fffd4724eb0 2
0x7fffd4724eb0 3
0x7fffd4724eb0 2
0x7fffd4724eb0 3
print:2
*/