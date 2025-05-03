#ifndef header_CS8_selasa_H
#define header_CS8_selasa_H

#include<iostream>
#include<vector>

using namespace std;

class Book{
	private:
		string title,author;
	public:
		Book(string n,string m);
		string getTitle() const;
		string getAuthor() const;
};

class Library{
	private:
		vector<Book> books;
	public:
		void addBook();
		void showbooks();
};

int menu();
#endif