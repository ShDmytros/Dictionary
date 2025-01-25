#include <iostream>
#include <map>
#include <Windows.h>
#include <fstream>
#include <string>
#include <vector>
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

		cout << "Type a learning word that you want to find: ";
		cin >> learning_language_word;

		auto seeking_word = dict.find(learning_language_word);
		if (seeking_word != end(dict))
			cout << seeking_word->first << " - " << seeking_word->second << endl;
		else
		{
			setting.setColor(4);
			cout << "Sorry we couldn't found the word, maybe" << endl;
			cout << "it's not exist." << endl;
			setting.setColor(7);
		}
	}


	void AddAWord(map<string, string>& dict)
	{
		string learning_language_word;
		string native_language_word;

		cin.ignore();
		cout << "Type a word from language that you study: ";
		getline(cin, learning_language_word);

		auto seeking_word = dict.find(learning_language_word);
		if (seeking_word != end(dict))
		{
			setting.setColor(4);
			cout << "Word have already exists!" << endl;
			setting.setColor(7);
			return;
		}

		cout << "Type a word from language that your native: ";
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

		cout << "Type a word from language you study that you want to delete: ";
		getline(cin, learning_language_word);

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

		cout << "Type a learning word that you want to edit: ";
		getline(cin, learning_language_word);

		auto seeking_word = dict.find(learning_language_word);
		if (seeking_word != end(dict))
		{
			string native_language_word;
			cout << "Type a new translation of the word: ";
			getline(cin, native_language_word);

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
		cout << endl << "---------------------------------------------------" << endl;
	}
};


class WorkingWithFiles
{
	GraphicSettings setting;

public:
	void exportData(const map<string, string>& dict)
	{
		if (dict.size() == 0) {
			setting.setColor(4);
			cout << "Sorry you don't have any words yet!" << endl;
			setting.setColor(7);
			return;
		}

		cin.ignore();
		string filePath;
		cout << "Type where do you want to save the file, like 'D:\\Files\\New Folder'." << endl;
		cout << "if you want to save file in the program folder, just type 1: ";
		getline(cin, filePath);


		if (filePath != "1") filePath = filePath + "/dictionary.txt";
		else				 filePath = "dictionary.txt";

		ofstream data_file(filePath);

		if (data_file.is_open()) {
			for (auto it = dict.begin(); it != dict.end(); ++it)
				data_file << it->first << "-" << it->second << "\n";
			data_file.close();

			setting.setColor(2);
			cout << "Data exported successfully!" << endl;
			setting.setColor(7);
		}
		else {
			setting.setColor(4);
			cout << "Error, something went wrong!" << endl;
			cout << "Maybe the way you typed is not exist!" << endl;
			setting.setColor(7);
		}
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
		if (dict.size() == 0) {
			setting.setColor(4);
			cout << "Sorry you don't have any words yet!" << endl;
			setting.setColor(7);
			return;
		}

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


class Exercises
{
	GraphicSettings setting;

public:
	void guessAWord(map<string, string> dict)
	{
		if (dict.size() == 0) {
			setting.setColor(4);
			cout << "Sorry you don't have any words yet!" << endl;
			setting.setColor(7);
			return;
		}

		cin.ignore();
		int askedWord_index;
		string askedWord_foreign;
		string askedWord_native;
		string answear;

		setting.setColor(6);
		cout << "Type '1' if you want to leave earlier!" << endl;
		setting.setColor(7);

		while (dict.size() != 0)
		{
			askedWord_index = rand() % dict.size();

			int currentIndex = 0;

			for (const auto& pair : dict)
			{
				if (currentIndex == askedWord_index)
				{
					askedWord_foreign = pair.first;
					askedWord_native = pair.second;
				}
				currentIndex++;
			}

			cout << "Translate a word '" << askedWord_foreign << "' into your native language: ";
			getline(cin, answear);

			if (answear == askedWord_native)
			{
				setting.setColor(2);
				cout << "Congratulation! You are right!" << endl;
				setting.setColor(7);
				dict.erase(askedWord_foreign);
			}
			else if (answear == "1") return;
			else
			{
				setting.setColor(4);
				cout << "You should study harder the word of " << askedWord_foreign << "." << endl;
				setting.setColor(7);
			}
		}

		setting.setColor(2);
		cout << "Alright, you guessed all words!" << endl;
		setting.setColor(7);
	}
};


class Menu
{
protected:
	int option;
	map<string, string> dict;

	GraphicSettings setting;
	WorkingWithFiles files{};
	WorkingWithWords words{};
	Exercises exercise{};
public:
	Menu(map<string, string>& _dict) : option{ 0 }, dict{ _dict } {}
	~Menu()
	{
		setting.setColor(4);
		cout << "Exit!" << endl;
		setting.setColor(7);
	}

	void menu_self()
	{
		files.readData(dict);
		cout << "------------------" << endl;
		cout << "|      Menu      |" << endl;
		cout << "------------------" << endl;
		setting.setColor(30);
		cout << "Choose your option:" << endl;
		setting.setColor(9);
		cout << "1.Find word" << endl;;
		cout << "2.Add a new word" << endl;
		cout << "3.Delete a word" << endl;
		cout << "4.Edit a word" << endl;
		cout << "5.Show all words" << endl;
		cout << "6.Export Data" << endl;
		cout << "7.Delete All Data" << endl;
		cout << "8.Game 'Guess a word'" << endl;
		cout << "9.Exit" << endl;
		setting.setColor(7);

		cout << "Write your option (1, 2, 3, 4, 5, 6, 7, 8, 9): ";
		cin >> option;

		if (option == 1)
		{
			system("cls");
			words.FindAWord(dict);
			cout << endl;
			menu_self();
		}

		if (option == 2)
		{
			system("cls");
			words.AddAWord(dict);
			files.saveData(dict);
			cout << endl;
			menu_self();
		}

		if (option == 3)
		{
			system("cls");
			words.DeleteAWord(dict);
			files.saveData(dict);
			cout << endl;
			menu_self();
		}

		if (option == 4)
		{
			system("cls");
			words.EditAWord(dict);
			files.saveData(dict);
			cout << endl;
			menu_self();
		}

		if (option == 5)
		{
			system("cls");
			words.showAllWords(dict);
			cout << endl;
			menu_self();
		}

		if (option == 6)
		{
			system("cls");
			files.exportData(dict);
			cout << endl;
			menu_self();
		}

		if (option == 7)
		{
			system("cls");
			files.deleteData(dict);
			cout << endl;
			menu_self();
		}

		if (option == 8)
		{
			system("cls");
			exercise.guessAWord(dict);
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
	srand(time(0));

	map<string, string> dictionary;
	Menu menu(dictionary);
	menu.menu_self();
}