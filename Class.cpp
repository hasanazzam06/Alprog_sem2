#include "Class.h"

Dosen::Dosen(string data, int n){
	name = data;
	id = n;
}

string Dosen::getName(){
	return name;
}

void Dosen::setName(string m){
	name = m;
}
		
void Dosen::setId(int n){
	id = n;
}

Kelas::Kelas(string m,float n, int jml, Dosen data) :dosen(data){
	namaKelas = m;
	nilai = n;
	sks = jml;
}
void Kelas::showDetail(){
	cout<<"Kelas: "<<namaKelas<<", Nilai: "<<nilai<<", SKS: "<<sks<<", Dosen: "<<dosen.getName()<<endl;
}

float Kelas::getNilai(){
	return nilai;
}

int Kelas::getSKS(){
	return sks;
}
				
void Kelas::setNilai(float m){
	nilai = m;
}
		
void Kelas::setSKS(int n){
	sks = n;
}
		
void Kelas::setNamaKelas(string n){
	namaKelas = n;
}

Mahasiswa::Mahasiswa(string n, int m, Kelas w,Kelas x, Kelas y,Kelas z,Jurusan jur) :alprog(w),sisben(x),matdis(y),fislis(z){
	nama = n;
	id = m;
	jurusan = jur;
}
		
float Mahasiswa::getIPK(){
	float ipk = (alprog.getNilai()*alprog.getSKS()+sisben.getNilai()*sisben.getSKS()+matdis.getNilai()*matdis.getSKS()+fislis.getNilai()*fislis.getSKS())/
	(alprog.getSKS()+sisben.getSKS()+matdis.getSKS()+fislis.getSKS());
	return ipk;
}
		
string Mahasiswa::jurusanToString(Jurusan j) {
   	switch(j) {
        case ELEKTRO: return "Teknik Elektro";
        case BIOMEDIK: return "Teknik Biomedik";
       	case KOMPUTER: return "Teknik Komputer";
        default: return "Jurusan Tidak Diketahui";
	}
}
		
void Mahasiswa::showDetail(){
	cout<<"Nama: "<<nama<<", ID: "<<id<<", Jurusan: "<<jurusanToString(jurusan)<<endl;
	alprog.showDetail();
	sisben.showDetail();
	matdis.showDetail();
	fislis.showDetail();
	cout<<"IPK: "<< fixed << setprecision(2)<<getIPK()<<endl;
}


