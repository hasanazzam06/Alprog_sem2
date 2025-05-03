#ifndef Header_CS8_hasan_H
#define Header_CS8_hasan_H

#include<iostream>
#include<vector>

using namespace std;

class Item{
	private:
		string name;
		string type;
	public:
		Item(string n,string m);
		
		string getName() const;
		
		string getType() const;
};

class Inventory{
	private:
		vector<Item> items;
	public:
		void addItem();
		
		void showItems();
		
		void getItems();
};

class Game{
	private:
		Inventory inve;
	public:
		int showMenu();
		
		void handleAddItem();
		
		void handleShowItems();
		
		void countItemType();
		
		void run();
};

#endif
