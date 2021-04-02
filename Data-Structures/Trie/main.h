/*
 * main.h
 *
 *      Author: Pankaj
 */

#ifndef MAIN_H_
#define MAIN_H_

#include <iostream>
#include <vector>

using namespace std;

const int MAX_NODES = 26;
class Trie
{
	class TrieNode
	{
	public:
		bool m_isWordEndsHere;
		TrieNode *m_childPtr[::MAX_NODES];
	};
	TrieNode *root;
public:
	Trie()
	{
		root = createNode();
	}
	TrieNode *createNode()
	{
		TrieNode* newNode = new TrieNode;
		newNode->m_isWordEndsHere = false;

		for (int i = 0; i < ::MAX_NODES; ++i)
		{
			newNode->m_childPtr[i] = nullptr;
		}
		return newNode;
	}

	void insert(const string& str)
	{
		TrieNode *curr = root;
		int index = 0;
		for (size_t i = 0; i < str.length(); ++i)
		{
			index = str[i] - 'a';
			if (nullptr == curr->m_childPtr[index])
			{
				curr->m_childPtr[index] = createNode();
			}
			curr = curr->m_childPtr[index];
		}
		curr->m_isWordEndsHere = true;
	}

	bool search(const string& str) const
	{
		TrieNode *curr = root;
		int index = 0;

		for (size_t i = 0; i < str.length(); ++i)
		{
			index = str[i] - 'a';
			if (nullptr == curr->m_childPtr[index])
			{
				return false;
			}
			curr = curr->m_childPtr[index];
		}
		return (curr->m_isWordEndsHere);
	}
};

#endif /* MAIN_H_ */