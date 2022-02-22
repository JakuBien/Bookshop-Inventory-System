#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
#include <vector>

using namespace std;

//Konstruktor obiektu typu ksiazka
class Book {
	int stock;
	bool available;

public:
	string author;
	string title;

	Book() {
		cout << "Author: ";
		getline(cin, author);
		cout << "Title: ";
		getline(cin, title);
		cout << "Stock: ";
		cin >> stock;
		if (!cin.good()) {
			throw invalid_argument("Wrong input.");
		}
		available = true;
	}

	void showData() {
		putchar('\n');
		if (!available) {
			cout << "Whis book is not available." << endl;
		}
		cout << "Author:" << author << endl;
		cout << "Title: " << title << endl;
		cout << "Stock: " << stock << endl;
	}

	void restock(int s) {
		stock += s;
		available = true;
	}

	void bookSold() {
		stock--;
		cout << "Book sold" << endl;
		if (stock == 0) {
			available = false;
		}
	}
};



int main() {
	vector<Book*> Library;
	int i;
	try {
		while (true) {
			cout << "What do you want to do?" << endl;
			cout << "Add new book - 1" << endl;
			cout << "Find a book - 2" << endl;
			cout << "Buy a book - 3" << endl;
			cout << "Restock a book - 4" << endl;
			cout << "Close - 0" << endl;
			cout << "Input: ";
			cin >> i;

			if (!cin.good()) {
				throw invalid_argument("Wrong input.");
			}
			cin.ignore();

			switch (i)
			{
			case 0:
				goto exit_loop;
				break;
			case 1:
				{
					Book* book = new Book();
					Library.push_back(book);
					break;
				}
			case 2:
				if (Library.size() == 0) {
					throw logic_error("The library is empty.");
				}
				{
					cout << "\nImput the title or the author:" << endl;
					string s;
					getline(cin, s);
					for (int j = 0; j < Library.size(); j++) {
						if (s == Library[j]->author || s == Library[j]->title) {
							Library[j]->showData();
						}
					}
					break;
				}
			case 3:
				{
					cout << "\nImput the author: ";
					string s1, s2;
					getline(cin, s1);
					cout << "Input the title: ";
					getline(cin, s2);
					for (int j = 0; j < Library.size(); j++) {
						if (s1 == Library[j]->author && s2 == Library[j]->title) {
							cout << "Do you want to buy this book?" << endl;
							cout << "Buy - 1\tExit - 0" << endl;
							int k;
							cin >> k;
							if (!cin.good() || (k != 1 && k != 0)) {
								throw invalid_argument("Wrong input.");
							}
							cin.ignore();

							if (k == 1) {
								Library[j]->bookSold();
							}
							break;
						}
					}
					break;
				}
			case 4:
				{
					cout << "\nImput the author: ";
					string s1, s2;
					getline(cin, s1);
					cout << "Input the title: ";
					getline(cin, s2);
					for (int j = 0; j < Library.size(); j++) {
						if (s1 == Library[j]->author && s2 == Library[j]->title) {
							cout << "Amount: ";
							int am;
							cin >> am;
							Library[j]->restock(am);
							break;
						}
					}
					break;
				}
			}
			system("pause");
			system("cls");
		}
		exit_loop:;
	}
	catch(invalid_argument &e){
		cout << "Error: " << e.what() << endl;
	}
	catch (logic_error& e) {
		cout << e.what() << endl;
	}
	
	cout << "Koniec programu";
}