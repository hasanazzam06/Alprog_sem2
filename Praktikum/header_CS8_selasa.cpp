#include "header_CS8_selasa.h"

Book::Book(string n,string m){
	title = n;
	author = m;	
}
		
string Book::getTitle() const{
	return title;
}
		
string Book::getAuthor() const {
	return author;
}

 void Library::addBook(){
 	string n,m;
    cout << "Judul buku: ";
    cin >> n;
    cout << "author buku: ";
    cin >> m;
	books.push_back(Book(n,m));
}

void Library::showbooks(){
	for(const auto& bk : books){
		cout<<bk.getTitle()<<" by "<<bk.getAuthor()<<endl;
	}
}

int menu() {
	int menu;
	printf("\n====Library Menu====\n");
	printf("1. Add Book\n");
	printf("2. Show Books\n");
	printf("3. Exit\n");
	
	printf("masukkan pilihan : ");
	scanf("%d", &menu);
	printf("--------------------\n\n");

	return menu;
}
