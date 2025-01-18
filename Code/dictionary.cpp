#include <iostream>
#include <map>
#include <algorithm>
#include <Windows.h>
#include <fstream>
#include <string>
using namespace std;


class WorkingWithWords
{
public:
	void FindAWord(map<string, string>& dict)
	{
		if (dict.size() == 0) {
			cout << "Sorry you don't have any words yet!" << endl;
			return;
		}

		string learning_language_word;

		cout << "Type a learning word that you want to find: ";
		cin >> learning_language_word;

		auto seeking_word = dict.find(learning_language_word);
		if (seeking_word != end(dict))
			cout << seeking_word->first << " - " << seeking_word->second << endl;
		else
		{
			cout << "Sorry we couldn't found the word, maybe"
				"it's not exist, please type 2 and write it in this case." << endl;
		}
	}


	void AddAWord(map<string, string>& dict)
	{
		string learning_language_word;
		string native_language_word;

		for (auto it = dict.begin(); it != dict.end(); ++it)
		{
			if (it->first == learning_language_word)
			{
				cout << "Sorry the word have exist!" << endl;
				return;
			}

		}

		cout << "Type a word from language that you study: ";
		cin >> learning_language_word;

		cout << "Type a word from language that your native: ";
		cin >> native_language_word;

		dict.insert({ learning_language_word, native_language_word });
	}


	void DeleteAWord(map<string, string>& dict)
	{
		if (dict.size() == 0) {
			cout << "Sorry you don't have any words yet!" << endl;
			return;
		}

		string learning_language_word;

		cout << "Type a word from language you study that you want to delete: ";
		cin >> learning_language_word;

		dict.erase(learning_language_word);
	}


	void EditAWord(map<string, string>& dict)
	{
		if (dict.size() == 0) {
			cout << "Sorry you don't have any words yet!" << endl;
			return;
		}

		string learning_language_word;

		cout << "Type a learning word that you want to edit: ";
		cin >> learning_language_word;

		auto seeking_word = dict.find(learning_language_word);
		if (seeking_word != end(dict))
		{
			string native_language_word;
			cout << "Type a new translation of the word: ";
			cin >> native_language_word;

			dict[learning_language_word] = native_language_word;
		}
		else
		{
			cout << "Sorry we couldn't found the word, maybe"
				"it's not exist, please type 2 and write it in this case." << endl;
		}
	}

	void showAllWords(const map<string, string>& dict)
	{
		if (dict.size() == 0) {
			cout << "Sorry you don't have any words yet!" << endl;
			return;
		}

		for (auto it = dict.begin(); it != dict.end(); ++it)
		{
			cout << it->first << " - " << it->second << "\n";
		}
	}
};


class WorkingWithFiles
{
public:
	void ExportData(const map<string, string>& dict)
	{
		ofstream data_file("dictionary.txt");
		if (data_file.is_open()) {
			for (auto it = dict.begin(); it != dict.end(); ++it)
				data_file << it->first << "-" << it->second << "\n";
			data_file.close();
			cout << "Data exported successfully!" << endl;
		}
		else
			cout << "Error!" << endl;
	}

	void saveData(const map<string, string>& dict)
	{
		string fileName = "dictionary.dict";
		ofstream data_file(fileName, ios::trunc);
		if (data_file.is_open()) {
			for (auto it = dict.begin(); it != dict.end(); ++it)
			{
				data_file << it->first << "\n" << it->second << "\n";
			}
			data_file.close();
			cout << "Data saved successfully!" << endl;
		}
		else
		{
			cout << "Data is not saved!" << endl;
			Sleep(2000);
		}
	}

	void readData(map<string, string>& dict)
	{
		string fileName = "dictionary.dict";
		ifstream file(fileName);

		if (!file.is_open()) return;

		string learning_language_word;
		string native_language_word;
		while (getline(file, learning_language_word)) {
			getline(file, native_language_word);
			//cout << "'" << learning_language_word << "' '" << native_language_word << "'" << endl;
			dict.insert({ learning_language_word, native_language_word });
		}

		file.close();
	}
};


class Menu : public WorkingWithWords, public WorkingWithFiles
{
protected:
	int option;
	map<string, string> dict;
public:
	Menu(int _option, map<string, string>& _dict) : option{ _option }, dict{ _dict } {}
	Menu(map<string, string>& _dict) : option{ 0 }, dict{ _dict } {}
	~Menu() { cout << "Exit!" << endl; }

	void menu_self()
	{
		readData(dict);
		cout << "------------------" << endl;
		cout << "|      Menu	 |" << endl;
		cout << "------------------" << endl;
		cout << "Choose your option:" << endl;
		cout << "1.Find word" << endl;;
		cout << "2.Add new word" << endl;
		cout << "3.Delete a word" << endl;
		cout << "4.Edit a word" << endl;
		cout << "5.Show all words" << endl;
		cout << "6.Export Data" << endl;
		cout << "7.Exit" << endl;

		cout << "Write your option (1, 2, 3, 4, 5, 6, 7): ";
		cin >> option;

		if (option == 1)
		{
			system("cls");
			FindAWord(dict);
			cout << endl;
			menu_self();
		}

		if (option == 2)
		{
			system("cls");
			AddAWord(dict);
			saveData(dict);
			cout << endl;
			menu_self();
		}

		if (option == 3)
		{
			system("cls");
			DeleteAWord(dict);
			saveData(dict);
			cout << endl;
			menu_self();
		}

		if (option == 4)
		{
			system("cls");
			EditAWord(dict);
			saveData(dict);
			cout << endl;
			menu_self();
		}

		if (option == 5)
		{
			system("cls");
			showAllWords(dict);
			cout << endl;
			menu_self();
		}

		if (option == 6)
		{
			system("cls");
			ExportData(dict);
			cout << endl;
			menu_self();
		}

		else {
			return;
		}
	}
};




int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	map<string, string> dictionary;
	Menu menu(2, dictionary);
	menu.menu_self();
}