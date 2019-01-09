#include <iostream>
using namespace std;
class Doubly{
	int data, listLen;
	Doubly *prev, *next, *head;
public:
	Doubly() : data(0), prev(NULL), next(NULL), head(NULL), listLen(0){}
	Doubly(int n){
		data = n;
		prev = next = NULL;
	}
	~Doubly(){}
	void InsertBegin(int);
	void InsertEnd(int);
	void PrintBegin();
	void PrintEnd();
	void SwapNode(int);
	void PrintBeginRecursively(Doubly *);
	void PrintEndRecursively(Doubly *);
	Doubly *GetHead();
};

Doubly *Doubly :: GetHead(){
	return head;
}
/*---
 * Insert a node at the end.
 * InsertEnd(1): 1
 * InsertEnd(2): 1 -> 2
 * InsertEnd(3): 1 -> 2 -> 3
 * InsertEnd(4): 1 -> 2 -> 3 -> 4
 */
void Doubly :: InsertEnd(int value){
	listLen++;

	if(!GetHead()){
		head = new Doubly(value);
		return;
	}

	Doubly *temp = GetHead();
	while(temp->next){
		temp = temp->next;
	}

	temp->next = new Doubly(value);
	temp->next->prev = temp;
}

/*---
 * Insert a node at the beginning.
 * InsertBegin(1): 1
 * InsertBegin(2): 2 -> 1
 * InsertBegin(3): 3 -> 2 -> 1
 * InsertBegin(4): 4 -> 3 -> 2 -> 1
 */
void Doubly :: InsertBegin(int value){
	listLen++;

	if(!GetHead()){
		head = new Doubly(value);
		return;
	}
	Doubly *temp = new Doubly(value);

	temp->next = GetHead();
	head->prev = temp;
	head = temp;
}

/*---
 * Print nodes from the beginning.
 * List: 1 -> 2 -> 3 -> 4
 * Output: 1 -> 2 -> 3 -> 4
 */
void Doubly :: PrintBegin(){
	if(!GetHead()){
		cout<<"PrintBegin::Empty list.\n";
		return;
	}

	Doubly *temp = GetHead();
	while(temp){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

/*---
 * Print nodes from the beginning recursively.
 * List: 1 -> 2 -> 3 -> 4
 * Output: 1 -> 2 -> 3 -> 4
 */
void Doubly :: PrintBeginRecursively(Doubly *startNode){
	if(startNode){
		cout<<startNode->data<<" ";
		PrintBeginRecursively(startNode->next);
	}
}

/*---
 * Print nodes from the end recursively.
 * List: 1 -> 2 -> 3 -> 4
 * Output: 4 -> 3 -> 2 -> 1
 */
void Doubly :: PrintEndRecursively(Doubly *startNode){
	if(startNode){
		PrintEndRecursively(startNode->next);
		cout<<startNode->data<<" ";
	}
}

/*---
 * Print nodes from the end.
 * List: 1 -> 2 -> 3 -> 4
 * Output: 4 -> 3 -> 2 -> 1
 */
void Doubly :: PrintEnd(){
	if(!GetHead()){
		cout<<"PrintEnd::Empty list.\n";
		return;
	}

	Doubly *temp = GetHead();
	int listLen = 1;
	while(temp->next){
		listLen++;
		temp = temp->next;
	}

	//!! 'temp' becomes 'head' node from reverse.
	while(temp){
		cout<<temp->data<<" ";
		temp = temp->prev;
	}
	cout<<endl;
}

/*---
 * Left-swap -> Right-swap
 * E.g. 1: 10 -> 15 -> 20 -> 25. whichData = 15
 * Result: Left-swap: 15 -> 10 -> 20 -> 25, Right-swap: 15 -> 20 -> 10 -> 25
 *
 * E.g. 2: 10 -> 15 -> 20 -> 25. whichData = 20
 * Result: Left-swap: 10 -> 20 -> 15 -> 25, Right-swap: 10 -> 20 -> 25 -> 15
 *
 * E.g. 3: 10 -> 15 -> 20 -> 25. whichData = 10
 * Result: Left-swap: Not feasible, Right-swap: 15 -> 10 -> 20 -> 25
 */
void Doubly :: SwapNode(int whichData)
{
    cout<<"To swap="<<whichData<<endl;
	Doubly *temp, *prev;
	if(!(temp = GetHead())){
		cout<<"Empty list.\n";
		return;
	}

	int offset = 0;
	bool hit = false;
	while(temp && !hit){
		if(temp->data == whichData){
			hit = true;
		}
		offset++;
		prev = temp;
		temp = temp->next;
	}
	//cout<<"length="<<listLen<<", whichData="<<whichData<<", hit="<<hit<<", offset="<<offset<<", current data="<<prev->data<<endl;
	if(hit){
        if(offset > 1){//!! Left swap
            Doubly *t_prev, *t_next;
            int t = 1;
            temp = GetHead();

            while(t++ < offset){
                temp = temp->next;
            }
            t_prev = temp->prev;
            t_next = temp->next;

            temp->prev = temp->prev->prev;
            if(temp->prev){
                temp->prev->next = temp;
            }

            t_prev->next = temp->next;
            if(temp->next){
                t_next->prev = t_prev;
            }

            temp->next = t_prev;
            t_prev->prev = temp;

            //!! Update 'head' node.
            temp = GetHead();
            while(temp->prev){
                temp = temp->prev;
            }
            head = temp;
        }

        if(offset < listLen){//!! Right swap
            Doubly *t_prev, *t_next;
            int t = 1;
            temp = GetHead();

            while(t++ < offset){
                temp = temp->next;
            }
            t_prev = temp->prev;
            t_next = temp->next;

            temp->next = temp->next->next;
            if(temp->next){
                temp->next->prev = temp;
            }

            t_next->prev = t_prev;
            if(t_prev){
                t_prev->next = t_next;
            }
            temp->prev = t_next;
            t_next->next = temp;

            //!! Update 'head' node.
            temp = GetHead();
            while(temp->prev){
                temp = temp->prev;
            }
            head = temp;
        }
	}
}

int main()
{
	Doubly d, d1;
	//d.PrintBegin();

	d.InsertEnd(10);
	d.InsertEnd(15);
	d.InsertEnd(20);
	d.InsertEnd(25);

	/*d.InsertBegin(1);
	d.InsertBegin(2);
	d.InsertBegin(3);
	d.InsertBegin(4);*/
	d.PrintBegin();
	//d.PrintEnd();
	//d.PrintBeginRecursively(d.GetHead());
	//d.PrintEndRecursively(d.GetHead());
	d.SwapNode(10);
	d.PrintBegin();
	//d.PrintEnd();
	return 0;
}
