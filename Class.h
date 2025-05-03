#ifndef Class_H
#define Class_H

#include<iostream>
#include <iomanip>
using namespace std;

enum Jurusan {
    ELEKTRO,
    BIOMEDIK,
    KOMPUTER
};

class Dosen{
	private:
		string name;
		int id;
	public:
		Dosen(string data, int n);
		string getName();
		void setName(string m);
		void setId(int n);
};

class Kelas{
	private:
		string namaKelas;
		float nilai;
		int sks;
		Dosen dosen;
		
	public:
		Kelas(string m,float n, int jml, Dosen data);
		void showDetail();
		float getNilai();
		int getSKS();
		void setNilai(float m);
		void setSKS(int n);
		void setNamaKelas(string n);
};

class Mahasiswa{
	private:
		string nama;
		int id;
		Kelas alprog,sisben,matdis,fislis;
		Jurusan jurusan;
	
	public:
		Mahasiswa(string n, int m, Kelas w,Kelas x, Kelas y,Kelas z,Jurusan jur);
		float getIPK();
		string jurusanToString(Jurusan j);
		void showDetail();
};

#endif