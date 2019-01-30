#include<iostream>
#include<fstream>
#include<cstdlib>  // DevCpp++ IDE
#include<iomanip>
#include<cstring>
#include<windows.h>

//25,50,66,77,87,106,118,128,248
using namespace std;

struct InfoNaglowek{
	int rozmiar;
	int szerokosc;
	int wysokosc;
	int rozmiarObrazka;
	char caly[54];
	int pixele;
};

struct kolor{
	
	unsigned char RED;
	unsigned char GREEN;
	unsigned char BLUE;
	unsigned char rezerwa;

};

void rozpiszWstep(InfoNaglowek &Info, fstream &otwarty)
{
	otwarty.seekg(14);
	otwarty.read(reinterpret_cast<char*>(&Info.rozmiar), 4);
	otwarty.read(reinterpret_cast<char*>(&Info.szerokosc), 4);
	otwarty.read(reinterpret_cast<char*>(&Info.wysokosc), 4);
	otwarty.seekg(34);
	otwarty.read(reinterpret_cast<char*>(&Info.rozmiarObrazka), 4);
	otwarty.seekg(0);
	otwarty.read(reinterpret_cast<char*>(&Info.caly[0]),54);	
}

KolorywTab(kolor T[], fstream &otwarty, InfoNaglowek Info)
{
	
	
	for(int i=0; i<Info.pixele;i++)
	{
		otwarty.read(reinterpret_cast<char*>(&T[i].RED),1);
		otwarty.read(reinterpret_cast<char*>(&T[i].GREEN),1);
		otwarty.read(reinterpret_cast<char*>(&T[i].BLUE),1);
		otwarty.read(reinterpret_cast<char*>(&T[i].rezerwa),1);
	}
		otwarty.clear();
}

DzielnaKolory(kolor T[], InfoNaglowek Info)
{
		ofstream otwieracz;
		char a=0;
			
		otwieracz.open("niebieski.bmp",ios::out|ios::binary);
		otwieracz.write(reinterpret_cast<char*>(&Info.caly[0]),54);	
		for(int i=0; i<Info.pixele;i++){
			otwieracz.write(reinterpret_cast<char*>(&T[i].RED),1);
			otwieracz.write(reinterpret_cast<char*>(&a),1);
			otwieracz.write(reinterpret_cast<char*>(&a),1);
			otwieracz.write(reinterpret_cast<char*>(&T[i].rezerwa),1);
			}
		otwieracz.close();
		
		
		otwieracz.open("zielony.bmp",ios::out|ios::binary);
		otwieracz.write(reinterpret_cast<char*>(&Info.caly[0]),54);	
		for(int i=0; i<Info.pixele;i++){
			otwieracz.write(reinterpret_cast<char*>(&a),1);
			otwieracz.write(reinterpret_cast<char*>(&T[i].GREEN),1);
			otwieracz.write(reinterpret_cast<char*>(&a),1);
			otwieracz.write(reinterpret_cast<char*>(&T[i].rezerwa),1);
		}
		otwieracz.close();
	
		otwieracz.open("czerwony.bmp",ios::out|ios::binary);
		otwieracz.write(reinterpret_cast<char*>(&Info.caly[0]),54);	
		for(int i=0; i<Info.pixele;i++){
			otwieracz.write(reinterpret_cast<char*>(&a),1);
			otwieracz.write(reinterpret_cast<char*>(&a),1);
			otwieracz.write(reinterpret_cast<char*>(&T[i].BLUE),1);
			otwieracz.write(reinterpret_cast<char*>(&T[i].rezerwa),1);
		}
		otwieracz.close();
	

}


DzielnaKolory2(kolor T[], InfoNaglowek Info)
{
		ofstream otwieracz;
		char a=0;
			
		otwieracz.open("niebieski2.bmp",ios::out|ios::binary);
		otwieracz.write(reinterpret_cast<char*>(&Info.caly[0]),54);	
		for(int i=0; i<Info.pixele;i++){
			otwieracz.write(reinterpret_cast<char*>(&T[i].RED),1);
			otwieracz.write(reinterpret_cast<char*>(&a),1);
			otwieracz.write(reinterpret_cast<char*>(&a),1);
			otwieracz.write(reinterpret_cast<char*>(&T[i].rezerwa),1);

			}
		otwieracz.close();
		
		
		otwieracz.open("zielony2.bmp",ios::out|ios::binary);
		otwieracz.write(reinterpret_cast<char*>(&Info.caly[0]),54);	
		for(int i=0; i<Info.pixele;i++){
			otwieracz.write(reinterpret_cast<char*>(&a),1);
			otwieracz.write(reinterpret_cast<char*>(&T[i].GREEN),1);
			otwieracz.write(reinterpret_cast<char*>(&a),1);
			otwieracz.write(reinterpret_cast<char*>(&T[i].rezerwa),1);
		}
		otwieracz.close();
	
		otwieracz.open("czerwony2.bmp",ios::out|ios::binary);
		otwieracz.write(reinterpret_cast<char*>(&Info.caly[0]),54);	
		for(int i=0; i<Info.pixele;i++){
			otwieracz.write(reinterpret_cast<char*>(&a),1);
			otwieracz.write(reinterpret_cast<char*>(&a),1);
			otwieracz.write(reinterpret_cast<char*>(&T[i].BLUE),1);
			otwieracz.write(reinterpret_cast<char*>(&T[i].rezerwa),1);
		}
		otwieracz.close();
	

}


void AkcjaKolory(kolor T[], InfoNaglowek Info, int a, int b, int c, int d, int e, int f,int g, int h,int m)
{	
	int k;
	unsigned char B[Info.pixele];

	
		for(int i=1;i<Info.pixele-2;i++)
		{	
		
			if(i>=Info.pixele-1-Info.szerokosc)
				k=T[i].RED*a+T[i+1].RED*e+T[i-1].RED*f+T[i-Info.szerokosc].RED*g+T[i-Info.szerokosc].RED*h+T[i-1-Info.szerokosc].RED*m;
		
			else	if(i<=Info.szerokosc)
				k=T[i].RED*a+T[i+Info.szerokosc].RED*b+T[i+Info.szerokosc].RED*c+T[i-1+Info.szerokosc].RED*d+T[i+1].RED*e+T[i-1].RED*f;
			else
				k=T[i].RED*a+T[i+Info.szerokosc].RED*b+T[i+Info.szerokosc].RED*c+T[i-1+Info.szerokosc].RED*d+T[i+1].RED*e+T[i-1].RED*f+T[i-Info.szerokosc].RED*g+T[i-Info.szerokosc].RED*h+T[i-1-Info.szerokosc].RED*m;
				
			
			if((a+b+c+d+e+f+g+h+m)!=0)
			{
				k/=(a+b+c+d+e+f+g+h+m);
			}
			
			if(k<0)k=0;
			if(k>255)k=255;
			B[i]=k;
				
		}
	
	
		for(int i =1;i<Info.pixele-2;i++)
		{
			T[i].RED=B[i];
			
		}
		
		for(int i=1;i<Info.pixele-2;i++)
		{	
			if(i>=Info.pixele-1-Info.szerokosc)
				k=T[i].GREEN*a+T[i+1].GREEN*e+T[i-1].GREEN*f+T[i-Info.szerokosc].GREEN*g+T[i-Info.szerokosc].GREEN*h+T[i-1-Info.szerokosc].GREEN*m;
			
			else if(i<=Info.szerokosc)
				k=T[i].GREEN*a+T[i+Info.szerokosc].GREEN*b+T[i+Info.szerokosc].GREEN*c+T[i-1+Info.szerokosc].GREEN*d+T[i+1].GREEN*e+T[i-1].GREEN*f;			
			else
				k=T[i].GREEN*a+T[i+Info.szerokosc].GREEN*b+T[i+Info.szerokosc].GREEN*c+T[i-1+Info.szerokosc].GREEN*d+T[i+1].GREEN*e+T[i-1].GREEN*f+T[i-Info.szerokosc].GREEN*g+T[i-Info.szerokosc].GREEN*h+T[i-1-Info.szerokosc].GREEN*m;
				
			
			if((a+b+c+d+e+f+g+h+m)!=0)
			{
				k/=(a+b+c+d+e+f+g+h+m);
			}
			
			if(k<0)k=0;
			if(k>255)k=255;
			B[i]=k;
				
		}
	
	
		for(int i =1;i<Info.pixele-2;i++)
		{
			T[i].GREEN=B[i];
			
		}


for(int i=1;i<Info.pixele-2;i++)
		{		
			if(i>=Info.pixele-1-Info.szerokosc)
				k=T[i].BLUE*a+T[i+1].BLUE*e+T[i-1].BLUE*f+T[i-Info.szerokosc].BLUE*g+T[i-Info.szerokosc].BLUE*h+T[i-1-Info.szerokosc].BLUE*m;
			
			else if(i<=Info.szerokosc)
				k=T[i].BLUE*a+T[i+Info.szerokosc].BLUE*b+T[i+Info.szerokosc].BLUE*c+T[i-1+Info.szerokosc].BLUE*d+T[i+1].BLUE*e+T[i-1].BLUE*f;			
			else
				k=T[i].BLUE*a+T[i+Info.szerokosc].BLUE*b+T[i+Info.szerokosc].BLUE*c+T[i-1+Info.szerokosc].BLUE*d+T[i+1].BLUE*e+T[i-1].BLUE*f+T[i-Info.szerokosc].BLUE*g+T[i-Info.szerokosc].BLUE*h+T[i-1-Info.szerokosc].BLUE*m;
				
			
			if((a+b+c+d+e+f+g+h+m)!=0)
			{
				k/=(a+b+c+d+e+f+g+h+m);
			}
			
			if(k<0)k=0;
			if(k>255)k=255;
			B[i]=k;
				
		}
	
	
		for(int i =1;i<Info.pixele-2;i++)
		{
			T[i].BLUE=B[i];
			
		}


	
}



Polacz(kolor T[], InfoNaglowek Info)
{
		
		ofstream koncowy;	
		koncowy.open("koncowy.bmp", ios::out|ios::binary);
		
		koncowy.write(reinterpret_cast<char*>(&Info.caly[0]),54);
		for(int i=0; i<Info.pixele;i++){
			koncowy.write(reinterpret_cast<char*>(&T[i].RED),1);
			koncowy.write(reinterpret_cast<char*>(&T[i].GREEN),1);
			koncowy.write(reinterpret_cast<char*>(&T[i].BLUE),1);
			koncowy.write(reinterpret_cast<char*>(&T[i].rezerwa),1);

		}
		
		koncowy.close();
}



int main(){
	
	char nazwa[50];
	fstream otwarty;
	
	cout<<"Podaj nazwe obrazu (lub sciezke jesli to konieczne): "<<endl;
	cin>> nazwa;
	
	otwarty.open(nazwa, ios::in | ios::binary);
	if(!otwarty)
		{
			cout<<"Nie mozna otworzyc obrazu";
			return 1;
		}
	
	cout<<"Udalo sie otworzyc."<<endl;
	
	InfoNaglowek Info;
	
	rozpiszWstep(Info, otwarty);
	Info.pixele=Info.szerokosc*Info.wysokosc;
	kolor T[Info.pixele];	
	KolorywTab(T, otwarty, Info);
	
	otwarty.close();
	
	DzielnaKolory(T,Info);
	cout<<"Jakiego filtra chces uzyc?"<<endl;
	cout<<"1. Usredniajacy (Rozmazujacy)"<<endl;
	cout<<"2. Wyostrzajacy"<<endl;		
	cout<<"3. Uwypuklajacy"<<endl;
	cout<<"4. Gradientowy"<<endl;
	cout<<"5. Wykrywajacy krawedzie"<<endl;
	cout<<"6. Filtr Laplace'a'"<<endl;
	cout<<"7. Filtr Sobel'a"<<endl;
	cout<<"8. Wlasny"<<endl;
	
	int w;
	cin>>w;
		
	switch(w){
		
		case 1 : AkcjaKolory(T,Info,1,1,1,1,1,1,1,1,1);  break;
		case 2 : AkcjaKolory(T,Info,9,-1,-1,-1,-1,-1,-1,-1,-1); break;
		case 3 : AkcjaKolory(T,Info,1,-1,0,1,-1,1,-1,0,1);  break;
		case 4 : AkcjaKolory(T,Info,-2,-1,-1,1,-1,1,1,1,1); break;
		case 5 : AkcjaKolory(T,Info,1,0,0,0,-1,0,0,0,0); break;
		case 6 : AkcjaKolory(T,Info,4,0,-1,0,-1,-1,0,-1,0); break;
		case 7 : AkcjaKolory(T,Info,0,1,2,1,0,0,-1,-2,-1); break;
		case 8 : 
		
					cout<<"Wprowadz po kolei:"<<endl;
					cout<<"1   2   3"<<endl<<endl;
					cout<<"4   5   6"<<endl<<endl;
					cout<<"7   8   9"<<endl<<endl;
					
					int a,b,c,d,e,f,g,h,m;
					cout<<"1:";
					cin>>b;
					cout<<"2:";
					cin>>c;
					cout<<"3:";
					cin>>d;
					cout<<"4:";
					cin>>e;
					cout<<"5:";
					cin>>a;
					cout<<"6:";
					cin>>f;
					cout<<"7:";
					cin>>g;
					cout<<"8:";
					cin>>h;
					cout<<"9:";
					cin>>m;
				AkcjaKolory(T, Info,a,b,c,d,e,f,g,h,m);	break;
					
			
		}	
		
		DzielnaKolory2(T, Info);
		Polacz(T,Info);
		
		
		
		
	
	return 0;
}
























