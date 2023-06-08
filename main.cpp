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
	cout << " Вас приветствует программа по дополнению слов по ввдённым буквам " << endl
		 << " ВАЖНО!!! Программа может дополнять только английские слова, " << endl
		 << " поэтому вводите только английские символы! " << endl;
	while (true)//loop so that the program does not end without our desire
	{
		cout << "\n------------------------------------\n";
		cout << "Выберите один из следующих вариантов: " << endl
			<< "1 - Ввести букву для нахождения возможного слова " << endl
			<< "2 - Добавить новое слово в словарь " << endl
			<< "q - Закончить программу" << endl;
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
			cout << "Вы вышли из программы "  << endl;
			break;
		}
		switch (choice)
		{
		case'1':
		{
			string word;
			cout << "Введите букву: " << endl;
			cin >> word;
			if (Searchendofword(root, word))
			{
				cout << "Возможно вы хотите написать: " << createEnd(root, word) << endl;
			}
			else
			{
				cout << "Нет совпадений по данному запросу, попробуйте ввести слово короче, а лучше всего одну букву " << endl;
			}
			break;
		}
		case '2':
		{
			string newWord;
			cout << "Введите слово для дополнения его в словарь " << endl;
			cin >> newWord;
			insert(root, newWord);
			cout << "Слово " << newWord << " Успешно добавлено в словарь " << endl;
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