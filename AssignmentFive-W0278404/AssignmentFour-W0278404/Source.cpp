#include <iostream>
#include <conio.h>
#include <fstream>
#include <time.h>
#include <string>

#include "Tree.h"
#include "BinarySearch.h"
#include "SequentialSearch.h"
#include "Hashing.h"

using namespace std;

void Build(string FileName);
void SpellCheck(string FileName);
bool Checker(string word);
void PrintAVL(BinaryNode*, int);

int tableLength = 47;
Tree WordTree;
BinaryNode* root;

int main()
{
	clock_t starting;
	clock_t ending;

	BinarySearch bs;
	SequentialSearch ss;

	Hashing hasher;
	hasher.Start();

	int SequentialArray[1000];

	for (int i = 0; i < 1000, i++;) {
		SequentialArray[i] = i + 1;
	}
	starting = clock();
	for (int i = 0; i < 1000; i++)
	{
		ss.search(SequentialArray, i, 999);
	}
	ending = clock();

	cout << "Search Time: " << (float)ending - (float)starting << " seconds" << endl;

	starting = clock();
	for (int i = 0; i < 1000; i++)
	{
		bs.search(SequentialArray, i+1, 999);
	}
	ending = clock();


	cout << "Binary Search Time: " << (float)ending - (float)starting << " seconds" << endl;
	_getch();

	cout << "Words From Dictionary: " << endl;

	ifstream Reader;
	string wordToCheck = "";

	Reader.open("dictionary.txt");

	if (Reader.is_open())
	{
		while (Reader >> wordToCheck)
		{
			if (Checker(wordToCheck))
			{
				cout << "  " << wordToCheck << endl;

				hasher.Hash(wordToCheck);
				WordTree.Root = WordTree.Insert(WordTree.Root, wordToCheck);

			}
		}
	}

	Reader.close();

	_getch();
	cout << "Hash Table:" << endl;

	hasher.PrintHashTable();


	_getch();
	cout << "Mispelled Words:" << endl;
	wordToCheck = "";

	Reader.open("mispelled.txt");

	if (Reader.is_open())
	{
		while (Reader >> wordToCheck)
		{
			for (int x = 0; x < wordToCheck.size(); x++)
			{
				if (wordToCheck[x] == '.')
				{
					wordToCheck.erase(x, 1);
				}
				if (wordToCheck[x] == '"')
				{
					wordToCheck.erase(x, 1);
				}
				if (wordToCheck[x] == ',')
				{
					wordToCheck.erase(x, 1);
				}
				if (wordToCheck[x] >= 'A' && wordToCheck[x] <= 'Z')
				{
					wordToCheck[x] = tolower(wordToCheck[x]);
				}
			}


			if (Checker(wordToCheck))
			{
				if (WordTree.Search(WordTree.Root, wordToCheck) == false)
				{
					cout << " " << wordToCheck << endl; 
				}
			}
		}
	}

	Reader.close();

	_getch();
}






//Checks to make sure every charector in the work is a letter
bool Checker(string wordToCheck)
{
	for (int x = 0; x < wordToCheck.size(); x++)
	{
		if ((wordToCheck[x] >= 'a' && wordToCheck[x] <= 'z') || (wordToCheck[x] >= 'A' && wordToCheck[x] <= 'Z'))
		{
			return true;
		}
	}
	return false;
}

//Prints out the tree
void PrintAVL(BinaryNode* node, int spacing)
{

	if (node != NULL)
	{
		string word;

		for (int x = 0; x < spacing; x++)
		{
			word += " ";
		}

		PrintAVL(node->RightLeaf, spacing + 10);

		cout << word << node->storedWord << endl;

		PrintAVL(node->LeftLeaf, spacing + 10);
	}
}

//hashes
int hash(string key)
{
	int value = 0;
	for (int i = 0; i < key.length(); i++)
		value += key[i];
	return value % tableLength;
}