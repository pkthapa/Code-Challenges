#include "main.h"

char ch = 'A';
void resetA()
{
    if (ch > 'Z')
    {
        ch = 'A';
    }
}

void printPyramid(int n)
{
    for (int i = 1; i <= n; ++i)
    {
        for (int j = n; j > i; --j)
        {
            cout << " ";
        }

        for (int k = 1; k <= i; ++k)
        {
            cout << ch++;
            resetA();
        }

        for (int l = 1; l < i; ++l)
        {
            cout << ch++;
            resetA();
        }
        cout << "\n";
    }
}

int main()
{
    int i = 0;
    cout << "Enter pyramid height:";
    cin >> i;
    printPyramid(i);
    return 0;
}

/*
Output:
         A
        BCD
       EFGHI
      JKLMNOP
     QRSTUVWXY
    ZABCDEFGHIJ
   KLMNOPQRSTUVW
  XYZABCDEFGHIJKL
 MNOPQRSTUVWXYZABC
DEFGHIJKLMNOPQRSTUV
*/
