#include "main.h"

class Shared_ptr
{
    int *p;
    int *refCount = nullptr; // For ease to maintain the count between different Shared_ptr objects.

public:
    Shared_ptr() : p(nullptr), refCount(new int(0))
    {}

    Shared_ptr(int* temp) : p(temp), refCount(new int(0))
    {
        if (nullptr != temp)
        {
            ++(*refCount);
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
    Shared_ptr& operator=(const Shared_ptr& obj)
    {
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
    Shared_ptr sp(new int);
    cout << sp.get() << " " << sp.use_count() << endl;

    *sp = 2;

    Shared_ptr sp1 = sp;
    cout << sp.get() << " " << sp.use_count() << endl;
    {
        Shared_ptr sp2 = sp;
        cout << sp.get() << " " << sp.use_count() << endl;
    }
    cout << sp.get() << " " << sp.use_count() << endl;
    Shared_ptr sp3 = sp1;
    cout << sp.get() << " " << sp.use_count() << endl;

    cout << "print:" << *sp3 << endl;
    return 0;
}
/*
Output:
0x7fffd2d7deb0 1
0x7fffd2d7deb0 2
0x7fffd2d7deb0 3
0x7fffd2d7deb0 2
0x7fffd2d7deb0 3
print:2
*/