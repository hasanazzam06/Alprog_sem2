#include<iostream>
#include<vector>

using namespace std;

class Item{
	private:
		string name;
		string type;
	public:
		Item(string n,string m){
			name = n;
			type = m;
		}
		
		string getName() const{
			return name;
		}
		
		string getType() const{
			return type;
		}
};

class Inventory{
	private:
		vector<Item> items;
	public:
		void addItem(){
			string n,m;
    		cout << "Name Item: ";
    		cin >> n;
    		cout << "Type Item (Weapon/Poison): ";
   			cin >> m;
   			cout<<"Item added!"<<endl;
			items.push_back(Item(n,m));
		}
		
		void showItems(){
			for(const auto& it : items){
				cout<<it.getName()<<" ("<<it.getType()<<")"<<endl;
			}
		}
		
		void getItems(){
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
			cout<<"Poison "<<p<<"x"<<endl;
		}
};

class Game{
	private:
		Inventory inve;
	public:
		int showMenu(){
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
		
		void handleAddItem(){
			inve.addItem();
		}
		
		void handleShowItems(){
			inve.showItems();
		}
		
		void countItemType(){
			inve.getItems();
		}
		
		void run(){
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
};


int main(){
	
	Game game;
	game.run();
	
	return 0;
}
