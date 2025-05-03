#include<iostream>

using namespace std;

class BaseCharacter{
	public:
		virtual void attack(){
			cout<<"serangan dengan damage sekian"<<endl;
		}
};


class Warior : public BaseCharacter{
	public:
		void attack() override{
			cout<<"warior menyerang dengan senjata"<<endl;
		}
};

class Mage : public BaseCharacter{
	public:
		void attack() override{
			cout<<"mage menyerang dengan sihir"<<endl;
		}
};

class Enemy : public BaseCharacter{
	private:
		int damage,health = 100;
	public:
		
		
		void takeDamage(){
			health-= damage;
			if(health<0){
				health = 0;
			}
			cout<<"musuh terserang, sisa darah"<<health<<endl;
			
		}
		
		bool isAlive(){
			return health > 0;
		}
};

int main(){
	Warior person_1;
	Mage person_2;
	
	BaseCharacter *ptr;
	
	ptr = &person_1;
	ptr->attack();
	ptr = &person_2;
	ptr->attack();
	
	Enemy p3;
	
	while(p3.isAlive()){
		p3.takeDamage(10);
	}
		
	return 0;
}