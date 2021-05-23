template <class T>
class Unique_ptr
{
    T* ptr = nullptr;

public:
    Unique_ptr() : ptr(nullptr)
    {}

    Unique_ptr(T* p) : ptr(p)
    {}

    ~Unique_ptr()
    {
        if (nullptr != ptr)
        {
            delete ptr;
        }
    }

    Unique_ptr(const Unique_ptr& obj) = delete;
    Unique_ptr& operator=(const Unique_ptr& obj) = delete;

    T* operator->()
    {
        return ptr; //this->ptr
    }

    T& operator*()
    {
        return *ptr; //*(this->ptr)
    }

    Unique_ptr(Unique_ptr&& dyingObj)
    {
        this->ptr = dyingObj.ptr;
        dyingObj.ptr = nullptr;
    }

    void operator=(Unique_ptr&& dyingObj)
    {
        this->ptr = dyingObj.ptr;
        dyingObj.ptr = nullptr;
    }

    T* get() const
    {
        return this->ptr;
    }
};

int main()
{
    Unique_ptr<int> up(new int);
    cout << "up points to:" << up.get() << endl;
    
    Unique_ptr<int> up1(move(up));
    cout << "up1 created and content of up moved to up1\n";
    cout << "up points to:" << up.get() << endl;
    cout << "up1 points to:" << up1.get() << endl;

    return 0;
}