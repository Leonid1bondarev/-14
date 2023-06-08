#include <iostream>
#include "Trie.h"

using namespace std;
int main()
{
	string words[] = {
		{"admin"},
		{"batman"},
		{"cat"},
		{"call"},
		{"cult"},
		{"deep"},
		{"elephant"},
		{"fish"},
		{"giraffe"},
		{"house"},
		{"inner"},
		{"jelly"},
		{"kite"},
		{"long"},
		{"mouse"},
		{"newt"},
		{"octopus"},
		{"pig"},
		{"queen"},
		{"rocket"},
		{"run"},
		{"rut"},
		{"snake"},
		{"throne"},
		{"umbrella"},
		{"vase"},
		{"whale"},
		{"xylophone"},
		{"young"},
		{"zebra"},
	}; //words for each letter of the alphabet
	TrieNode* root = getNewNode();
	for (auto& word : words)//fill the tree with words
	{
		insert(root, word);
	}
	setlocale(LC_ALL, "rus");
	cout << " ��� ������������ ��������� �� ���������� ���� �� ������� ������ " << endl
		 << " �����!!! ��������� ����� ��������� ������ ���������� �����, " << endl
		 << " ������� ������� ������ ���������� �������! " << endl;
	while (true)//loop so that the program does not end without our desire
	{
		cout << "\n------------------------------------\n";
		cout << "�������� ���� �� ��������� ���������: " << endl
			<< "1 - ������ ����� ��� ���������� ���������� ����� " << endl
			<< "2 - �������� ����� ����� � ������� " << endl
			<< "q - ��������� ���������" << endl;
		cout << "------------------------------------\n";

		char choice;//choice of options for further work of the program
		cin >> choice;
		try
		{
			if (!(choice == '1' || choice == '2' || choice == 'q'))
			{
				throw "Error choice!";
			}

		}
		catch (const char* exception)
		{
			cout << exception << endl;
			continue;
		}


		if (choice == 'q')
		{
			cout << "�� ����� �� ��������� "  << endl;
			break;
		}
		switch (choice)
		{
		case'1':
		{
			string word;
			cout << "������� �����: " << endl;
			cin >> word;
			if (Searchendofword(root, word))
			{
				cout << "�������� �� ������ ��������: " << createEnd(root, word) << endl;
			}
			else
			{
				cout << "��� ���������� �� ������� �������, ���������� ������ ����� ������, � ����� ����� ���� ����� " << endl;
			}
			break;
		}
		case '2':
		{
			string newWord;
			cout << "������� ����� ��� ���������� ��� � ������� " << endl;
			cin >> newWord;
			insert(root, newWord);
			cout << "����� " << newWord << " ������� ��������� � ������� " << endl;
			break;
		}
		default:
		{
			cout << "Operator specified incorrectly" << endl;
			break;
		}
		}
	}
}