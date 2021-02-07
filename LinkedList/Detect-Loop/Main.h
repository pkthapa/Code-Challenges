#include <iostream>
#include <map>
#include <vector>
#include <stdio.h>
#include <cstddef>
#include <algorithm>
#include <stack>
//#include <bits/stdc++.h>
using namespace std;

class LL
{
public:
    LL();
    LL(int);
    ~LL();
    void insert(const int);
    void display() const;
    bool detectLoop();

    int m_data;
    LL *m_next;
    LL *m_head;
};