#include "Header_CS8_hasan.h"


Item::Item(string n,string m){
	name = n;
	type = m;	
}
		
string Item::getName() const{
	return name;
}
		
string Item::getType() const{
	return type;
}


void Inventory::addItem(){
	string n,m;
    cout << "Name Item: ";
   	cin >> n;
   	cout << "Type Item (Weapon/Poison): ";
   	cin >> m;
   	cout<<"Item added!"<<endl<<endl;
	items.push_back(Item(n,m));
}
		
void Inventory::showItems(){
	
	cout<<"Current Inventory: "<<endl;
	for(const auto& it : items){
		cout<<it.getName()<<" ("<<it.getType()<<")"<<endl;
	}
	cout<<endl;
}
		
void Inventory::getItems(){
	int w,p;
	w=p=0;
	string temp;
			
	for(const auto& it : items){
				
		temp = it.getType();
				
		if(temp == "Weapon"){
			w++;
		}else if( temp == "Poison"){
			p++;
		}
	}
	cout<<"Weapon "<<w<<"x"<<endl;
	cout<<"Poison "<<p<<"x"<<endl<<endl;
}


int Game::showMenu(){
	int menu;
	cout<<"====Game Inventory Menu===="<<endl;
	cout<<"1. Add Item"<<endl;
	cout<<"2. Show Inventory"<<endl;
	cout<<"3. Count Item Types"<<endl;
	cout<<"4. Exit"<<endl;
	
	cout<<"masukkan pilihan : ";
	cin>>menu;
	cout<<"--------------------"<<endl;

	return menu;
}
		
void Game::handleAddItem(){
	inve.addItem();
}
		
void Game::handleShowItems(){
	inve.showItems();
}
		
void Game::countItemType(){
	inve.getItems();
}
		
void Game::run(){
	while(1){
		int cek = 0;
				
		int option = showMenu();
				
		switch(option){
			case 1:
				handleAddItem();
				break;
			case 2:
				handleShowItems();
				break;
			case 3:
				countItemType();
				break;
			case 4:
				cek = 1;
				printf("program telah selesai terimkasih!!");
				break;
			default:
				printf("masukkan input yang sesuai!!");
		}
				
		if(cek != 0){
			break;
		}
	}
}

