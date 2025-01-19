#include <iostream>
#include <map>
#include <algorithm>
#include <Windows.h>
#include <fstream>
#include <string>
using namespace std;


class GraphicSettings
{
public:
	void setColor(int color) { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color); }
};


class WorkingWithWords
{
	GraphicSettings setting;

public:
	void FindAWord(map<string, string>& dict)
	{
		if (dict.size() == 0) {
			setting.setColor(4);
			cout << "Sorry you don't have any words yet!" << endl;
			setting.setColor(7);
			return;
		}

		string learning_language_word;

		setting.setColor(10);
		cout << "Type a learning word that you want to find: ";
		setting.setColor(7);
		cin >> learning_language_word;

		auto seeking_word = dict.find(learning_language_word);
		if (seeking_word != end(dict))
			cout << seeking_word->first << " - " << seeking_word->second << endl;
		else
		{
			setting.setColor(4);
			cout << "Sorry we couldn't found the word, maybe" << endl;
			cout << "it's not exist. Please type 2 and write it," << endl;
			cout << "if you made a mistake durring typing." << endl;
			setting.setColor(7);
		}
	}


	void AddAWord(map<string, string>& dict)
	{
		string learning_language_word;
		string native_language_word;

		setting.setColor(10);
		cout << "Type a word from language that you study: ";
		setting.setColor(7);
		cin >> learning_language_word;

		auto seeking_word = dict.find(learning_language_word);
		if (seeking_word != end(dict))
		{
			setting.setColor(4);
			cout << "Word have already exists!" << endl;
			setting.setColor(7);
			return;
		}

		setting.setColor(10);
		cout << "Type a word from language that your native: ";
		setting.setColor(7);
		cin >> native_language_word;

		dict.insert({ learning_language_word, native_language_word });
	}


	void DeleteAWord(map<string, string>& dict)
	{
		if (dict.size() == 0) {
			setting.setColor(4);
			cout << "Sorry you don't have any words yet!" << endl;
			setting.setColor(7);
			return;
		}

		string learning_language_word;

		setting.setColor(10);
		cout << "Type a word from language you study that you want to delete: ";
		setting.setColor(7);
		cin >> learning_language_word;

		if (dict.erase(learning_language_word))
		{
			setting.setColor(6);
			cout << "Word deleted successfully!" << endl;
			setting.setColor(7);
		}

		else {
			setting.setColor(4);
			cout << "Word not found!" << endl;
			setting.setColor(7);
			return;
		}
	}


	void EditAWord(map<string, string>& dict)
	{
		if (dict.size() == 0) {
			setting.setColor(4);
			cout << "Sorry you don't have any words yet!" << endl;
			setting.setColor(7);
			return;
		}

		string learning_language_word;

		setting.setColor(10);
		cout << "Type a learning word that you want to edit: ";
		setting.setColor(7);
		cin >> learning_language_word;

		auto seeking_word = dict.find(learning_language_word);
		if (seeking_word != end(dict))
		{
			string native_language_word;
			setting.setColor(10);
			cout << "Type a new translation of the word: ";
			setting.setColor(7);
			cin >> native_language_word;

			dict[learning_language_word] = native_language_word;
		}
		else
		{
			setting.setColor(4);
			cout << "Sorry we couldn't found the word, maybe"
				"it's not exist, please type 2 and write it in this case." << endl;
			setting.setColor(7);
		}
	}

	void showAllWords(const map<string, string>& dict)
	{
		if (dict.size() == 0) {
			setting.setColor(4);
			cout << "Sorry you don't have any words yet!" << endl;
			setting.setColor(7);
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
	GraphicSettings setting;

public:
	void ExportData(const map<string, string>& dict)
	{
		ofstream data_file("dictionary.txt");
		if (data_file.is_open()) {
			for (auto it = dict.begin(); it != dict.end(); ++it)
				data_file << it->first << "-" << it->second << "\n";
			data_file.close();

			setting.setColor(6);
			cout << "Data exported successfully!" << endl;
			setting.setColor(7);
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

			setting.setColor(6);
			cout << "Data saved successfully!" << endl;
			setting.setColor(7);
		}
		else
		{
			setting.setColor(4);
			cout << "Data is not saved!" << endl;
			setting.setColor(7);
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

	void deleteData(map<string, string>& dict)
	{
		setting.setColor(4);
		cout << "Are you sure, that you want to delete everything? (1 - Yes, 2 - No): ";
		setting.setColor(7);
		int option;
		cin >> option;

		if (option == 1)
		{
			string fileName = "dictionary.dict";
			ofstream data_file(fileName, ios::trunc);

			if (data_file.is_open()) {
				data_file.close();
				dict = {};
				setting.setColor(4);
				cout << "Data have been deleted successfully!" << endl;
				setting.setColor(7);
			}
		}
		else
		{
			setting.setColor(6);
			cout << "Your choice is to not delete!" << endl;
			setting.setColor(7);
		}
	}
};


class Menu : public GraphicSettings, public WorkingWithWords, public WorkingWithFiles
{
protected:
	int option;
	map<string, string> dict;
public:
	Menu(int _option, map<string, string>& _dict) : option{ _option }, dict{ _dict } {}
	Menu(map<string, string>& _dict) : option{ 0 }, dict{ _dict } {}
	~Menu() 
	{ 
		setColor(4);
		cout << "Exit!" << endl; 
		setColor(7);
	}

	void menu_self()
	{
		readData(dict);
		cout << "------------------" << endl;
		cout << "|      Menu      |" << endl;
		cout << "------------------" << endl;
		setColor(175);
		cout << "Choose your option:" << endl;
		setColor(9);
		cout << "1.Find word" << endl;;
		cout << "2.Add new word" << endl;
		cout << "3.Delete a word" << endl;
		cout << "4.Edit a word" << endl;
		cout << "5.Show all words" << endl;
		cout << "6.Export Data" << endl;
		cout << "7.Delete All Data" << endl;
		cout << "8.Exit" << endl;
		setColor(7);
		
		cout << "Write your option (1, 2, 3, 4, 5, 6, 7, 8): ";
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

		if (option == 7)
		{
			system("cls");
			deleteData(dict);
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