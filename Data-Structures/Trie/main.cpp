#include "main.h"

// Driver Code
int main()
{
	Trie *root = new Trie;
	vector<string> v {"hello", "this", "is", "a", "trie", "testing", "sample", "pneumonoultramicroscopicsilicovolcanoconiosis"};
	for (auto i : v)
	{
		root->insert(i);
	}

	vector<string> v1 {"hello", "these", "are", "trie", "testing", "samples", "pneumonoultramicroscopicsilicovolcanoconiosis"};
	for (auto i : v1)
	{
		cout << "'" << i << "'" << " is " << (root->search(i) ? "found" : "not found") << endl;
	}
	return 0;
}
/*
Output:
'hello' is found
'these' is not found
'are' is not found
'trie' is found
'testing' is found
'samples' is not found
'pneumonoultramicroscopicsilicovolcanoconiosis' is found
*/
