#include "main.h"

/*
Start(int) will be called only once at the beginning.
Ack(int) will acknowledge.
GetNextNonAck() will get the next acknowledgement.

E.g.
Start(3)
GetNextNonAck() should return 3.
If Ack(3) is executed, then GetNextNonAck() will return 4.
If Ack(4) is executed, then GetNextNonAck() will return 5.
If Ack(6) is executed, then GetNextNonAck() will return 5.
If Ack(7) is executed, then GetNextNonAck() will return 5.
If Ack(5) is executed, then GetNextNonAck() will return 8 (because ack for 6 & 7 are already executed).
If Ack(2) is executed, then GetNextNonAck() will return 8 (ack 2 will be skipped because the start number is 3).
If Ack(3) is executed again, then GetNextNonAck() will return 8.

Boundary conditions: No -ve integers will be given. No overflow.
No overflow condition.
*/

class ACK
{
    int startNumber = 5;
    vector<int> seq;

public:
    void Start(const int data)
    {
        startNumber = data;
    }
  
    void Ack(const int ack)
    {
        if(ack >= startNumber)
        {
            seq.push_back(ack); // O(logn)
            sort(seq.begin(), seq.end());
        }
        else
        {
            cout << "Invalid ack number." << endl;
        }
    }

    int GetNextNonAck() const
    {
        const int processedNumberSize = seq.size();
        if (0 == processedNumberSize)
        {
            return startNumber;
        }
        if ((startNumber + processedNumberSize) > seq[processedNumberSize - 1]) //O(logn)
        {
            return startNumber + processedNumberSize;
        }
        else
        {
            int loopVar = processedNumberSize - 1;
            while (loopVar >= 0)
            {
                if ((startNumber + loopVar) >= seq[loopVar]) // O(nlogn)
                {
                    return seq[loopVar] + 1;
                }
                --loopVar;
            }
            return startNumber;
        }
    }
};

int main()
{
    ACK obj;
    int inp = 0;
    cout << "Start number: ";
    cin >> inp;
    obj.Start(inp);

    while (true)
    {
        cout << "0: GetNextNonAck()" << endl;
        cout << "1: Ack()" << endl;
        cout << "-1: Exit" << endl;
        cout << "Input: ";
        cin >> inp;

        if (-1 == inp) break;

        switch(inp)
        {
            case 0:
                cout << "Next ack: " << obj.GetNextNonAck() << endl;
                break;
            case 1:
                cout << "Give ack of: ";
                cin >> inp;
                obj.Ack(inp);
                break;
        }
        cout << endl;
    }
    return 0;
}
