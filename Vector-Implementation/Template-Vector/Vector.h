#include "main.h"
template <class T>
class Vector
{
    T *data;
    int vSize;
    int vCapacity;
public:
    Vector();
    ~Vector();
    void PushBack(const T&);
    void PopBack();
    int Size() const;
    int Capacity() const;
    void Reserve(const int&);
    bool Empty() const;
    void Clear();
    T& operator[](const int&);
};
///////////////////////////////////////////////////////////////////////////
template <class T>
Vector<T>::Vector(){
    data = nullptr;
    vSize = 0;
    vCapacity = 0;
}
///////////////////////////////////////////////////////////////////////////
template <class T>
Vector<T>::~Vector(){ delete[] data; }
///////////////////////////////////////////////////////////////////////////
template <class T>
void Vector<T>::PushBack(const T& val)
{
    if(vSize == vCapacity)
    {
        if(vCapacity == 0)
        {
            Reserve(1);
        }
        else
        {
            Reserve(2 * vCapacity);
        }
    }
    data[vSize] = val;
    vSize++;
}
///////////////////////////////////////////////////////////////////////////
template <class T>
void Vector<T>::PopBack()
{
    vSize--;
}
///////////////////////////////////////////////////////////////////////////
template <class T>
int Vector<T>::Size() const{ return vSize; }
///////////////////////////////////////////////////////////////////////////
template <class T>
int Vector<T>::Capacity() const{ return vCapacity; }
///////////////////////////////////////////////////////////////////////////
template <class T>
void Vector<T>::Reserve(const int& newCapacity)
{
    T *newData;
    try
    {
        newData = new T[newCapacity];
    }
    catch(...){
        cout << "Memory allocation failure...";
    }

    for(int i = 0; i < vSize; i++)
    {
        newData[i] = data[i];
    }
    delete[] data;

    data = newData;
    vCapacity = newCapacity;
}
///////////////////////////////////////////////////////////////////////////
template <class T>
bool Vector<T>::Empty() const
{
    return (vSize == 0);
}
///////////////////////////////////////////////////////////////////////////
template <class T>
void Vector<T>::Clear()
{
    vSize = 0;
    vCapacity = 0;

    if(data)
    {
        delete[] data;
        data = nullptr;
    }
}
///////////////////////////////////////////////////////////////////////////
template <class T>
T& Vector<T>::operator[](const int& offset)
{
    return data[offset];
}
