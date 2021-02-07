#include "Main"

LL::LL()
{
    m_data = 0;
    m_next = nullptr;
    m_head = nullptr;
}

LL::LL(int data)
{
    m_data = data;
    m_next = nullptr;
}

LL::~LL()
{
}

void LL::insert(const int data)
{
    LL *newNode = new LL(data);
    
    if(m_head == nullptr)
    {
        m_head = newNode;
    }
    else
    {
        LL *temp = m_head;
        while(temp->m_next != nullptr)
        {
            temp = temp->m_next;
        }
        temp->m_next = newNode;
    }
}

void LL::display() const
{
    LL *temp = m_head;
    
    if(temp == nullptr)
    {
        cout << "Empty list." << endl;
    }
    else
    {
        cout << endl << "printing starts >>> ";
        while(temp != nullptr)
        {
            cout << temp->m_data << " ";
            temp = temp->m_next;
        }
        cout << endl;
    }
}

bool LL::detectLoop()
{
    bool isLoop = false;
    if(m_head == nullptr)
    {
        isLoop = false;
    }
    else
    {
        LL *slow = m_head, *fast = m_head;
        while(slow != nullptr && fast != nullptr && fast->m_next != nullptr)
        {
            slow = slow->m_next;
            fast = fast->m_next->m_next;
            
            if(slow == fast)
            {
                return true;
            }
        }
        
    }
    return isLoop;
}

int main()
{
    LL ll;
    ll.insert(1);
    ll.insert(2);
    ll.insert(4);
    ll.insert(8);
    ll.insert(5);
    ll.insert(59);

    ll.display();

    ll.m_head->m_next->m_next->m_next->m_next->m_next->m_next = ll.m_head;
    //cout << ll.m_head->m_next->m_data << endl;
    //ll.display();

    if(ll.detectLoop())
    {
        cout << "Loop detected." << endl;
    }
    else
    {
        cout << "No loop." << endl;
    }
    return 0;
}