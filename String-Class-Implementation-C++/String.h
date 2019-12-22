#include "Main.h"
class String
{
    int m_size;
    char *m_string;

public:
    String();
    String(const String &);
    String(const char *);
    ~String();
    int Length() const;
    //void resize(unsigned int, char);
    //void insert(unsigned int, String&);
    char& operator[](unsigned int);
    void operator =(const String&);
    void operator +=(const String&);

    friend bool operator==(const String &, const String &);
    friend bool operator<=(const String &, const String &);
    friend bool operator<(const String &, const String &);
    friend ostream & operator<<(ostream &, const String &);
};
