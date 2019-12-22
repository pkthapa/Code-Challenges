#include "String.h"
/////////////////////////////////////////////////////////
String::String()
{
    cout << "String() const" << endl;
    m_string = nullptr;
    m_size = 0;
}
/////////////////////////////////////////////////////////
String::String(const String &s)
{
    cout << "String(String &) const" << endl;
    m_size = s.m_size;
    m_string = new char[m_size];
    for(int i = 0; i < m_size; i++)
    {
        m_string[i] = s.m_string[i];
    }
}
/////////////////////////////////////////////////////////
String::~String()
{
    cout << "String() dest" << endl;
    delete[] m_string;
}
/////////////////////////////////////////////////////////
String::String(const char *p)
{
    cout << "String() char * const" << endl;
    int i = 0;
    const char *t = p;

    while(*p++)
    {
        i++;
    }

    m_string = new char[i];
    int j = 0;

    for(j; *t; t++,j++)
    {
        m_string[j] = *t;
    }
    m_size = j;
}
/////////////////////////////////////////////////////////
int String::Length() const
{
    cout << "String() Length()" << endl;
    if(m_string == nullptr)
    {
        return 0;
    }
    else
    {
        return m_size;
    }
}
/////////////////////////////////////////////////////////
char & String::operator[] (unsigned int x)
{
    return m_string[x];
}
/////////////////////////////////////////////////////////
void String::operator =(const String&s)
{
    m_string = s.m_string;
    m_size = s.Length();
}
/////////////////////////////////////////////////////////
ostream & operator<<(ostream &os, const String &s)
{
    cout << "String() operator << " << endl;
    for(int i = 0; i < s.Length(); i++)
    {
        os << s.m_string[i];
    }
    return os;
}
/////////////////////////////////////////////////////////
bool operator==(const String &s, const String &t)
{
    if(s.Length() != t.Length())
    {
        return false;
    }
    else
    {
        for(int i = 0; i < s.Length(); i++)
        {
            if(s.m_string[i] != t.m_string[i])
            {
                return false;
            }
        }
    }
    return true;
}
/////////////////////////////////////////////////////////
