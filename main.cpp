#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;

class program{
	public:
		ifstream wejscie;
		ofstream wyjscie;
		string napis;
		program();
		~program();
	void sprawdz_plik();
	void wczytaj();
	void losowanie();
	void zapis();
};
program::program(){
	wejscie.open("wejscie.txt");
	wyjscie.open("wyjscie.txt");
}
program::~program(){
	wejscie.close();
	wyjscie.close();
}
void program::sprawdz_plik(){
	if(wejscie.good()&&wyjscie.good()){
	}
	else
	{
		cout<<"blad";
	}
}
void program::wczytaj(){
	while(!wejscie.eof()){
		getline(wejscie,napis);
		losowanie();
		zapis();
	}
}
void program::losowanie(){
	cout<<napis<<" ";
	srand(time(NULL));
	int x;
	for(int i=1;i<3;i++){
		for(int j=0;j<napis.length();j++){
			x = rand() % napis.length();
			swap(napis[j],napis[x]);
		}
	}
	cout<<napis<<endl;
}
void program::zapis(){
	wyjscie<<"anagram: "<<napis<<endl;
}
int main() {
	program p1;
	p1.sprawdz_plik();
	p1.wczytaj();
	return 0;
}
