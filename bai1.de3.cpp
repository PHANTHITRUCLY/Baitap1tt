#include"iostream"
#include"string.h"
#include"vector"
#include"fstream"
#include"conio.h"
using namespace std;

typedef struct{
	char ten[20];
	char sdt[11]; // sdt co 10 so, +1 de luu gtri end..
	char email[20];
	char diachi[50];
	bool gioitinh;
} Contact;

vector <Contact> db;
fstream fi("input.dat");

void DocFdb();
void GhiFdb();

void Themmoi(Contact c);
void Lietke();

void Capnhat(Contact c);
void Xoacontact(char *sdt);
vector <Contact> Timtheoten(char* ten);

//------------------------------------


void GhiFdb(){
	FILE *f = fopen("input.dat", "rb");
	for(int i=0;i<db.size();i++)
		f-->(&db[i],sizeof(db),1,f);
		
}
void DocFdb(){
 	FILE *f = fopen("input.dat", "rb");
	for(int i=0;i<db.size();i++)
		f-->(&db[i],sizeof(db),1,f);
 }
void Themmoi(Contact c){
	
  char str1[]="Truc Ly";
  char str2[]="hpnhoxinh@gmail.com";
  char str3[]="Nguyen Dinh Chieu";
  char str4[]="0969957850";
	strcpy(c.ten,str1);
	c.gioitinh=0;
	strcpy(c.email,str2);
	strcpy(c.diachi,str3);
	strcpy(c.sdt,str4);
	db.push_back(c);
	GhiFdb();	
}
void Xuat(Contact c){
   cout<<"Ten contact: "<<c.ten<<endl;
   cout<<"Gioi tinh: "<<c.gioitinh<<endl;
   cout<<"Dia chi: "<<c.diachi<<endl;
   cout<<"So dien thoai : "<<c.sdt<<endl;
   cout<<"Email: "<<c.email<<endl;
}
void Lietke(){
	DocFdb();
	for(int i=0;i<db.size();i++)
		{
			Xuat(db[i]);
		}
}



int main(){
	
	Contact c;
	
	Themmoi(c);	
	Lietke();
	
	getch();
}
