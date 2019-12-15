#include "main.h"
class Vector
{
    int *data;
    int vSize;
    int vCapacity;
public:
    Vector();
    ~Vector();
    void PushBack(int);
    void PopBack();
    int Size() const;
    int Capacity() const;
    void Reserve(int);
    bool Empty() const;
    void Clear();
    int& operator[](const int&);
};
