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

void Capnhat();
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
void Capnhat(){
	char sdtt[11]; 
	do{
		cout<<endl<<"Nhap sdt cua ban ghi can chinh sua: ";
		cin.getline(sdtt,11);
		if(strcmp(sdtt,"\0")!=0)
			{
			for(int i = 0; i <db.size(); i++)
			if(strcmp(db[i].sdt,sdtt)==0){
				
				cout<<endl<<"Nhap ten muon sua: ";
				cin.getline(db[i].ten,20);
				
				cout<<endl<<"Nhap sdt muon sua: ";
				cin.getline(db[i].sdt,10);
			
				cout<<endl<<"Nhap email muon sua: ";
				cin.getline(db[i].email,20);
											
				cout<<endl<<"Nhap diachi muon sua: ";
				cin.getline(db[i].diachi,50);
				
					
			}
		}
	}while(strcmp(sdtt,"\0")!=0);
}

int Tim(char tent[20]){
	for(int i=0; i<db.size(); i++)
		if(strcmp(db[i].ten,tent) == 0)
			return i; 
	return -1;
}

void Xoacontact(){
	char tent[20];
	do{
		cout<<endl<<"Nhap ten cua ban ghi can xoa: ";
		cin.getline(tent,20);
		
		if(strcmp(tent,"\0")!=0)
		{
			int vt = Tim(tent);
			int n = db.size();
			if(vt == -1) cout<<endl<<"Khong co contact nay!";
			else{
				for(int i = vt;i<n-1;i++)
					db[i] = db[i+1];
					db.pop_back();
				
			}
		}
			
	}while(strcmp(tent,"\0")!=0);
}

void Intheoten(){
	char tent[20];
	do{
		cout<<endl<<"Nhap ten cua ban ghi muon tim: ";
		cin.getline(tent,20);
		
		if(strcmp(tent,"\0")!=0)
		{
			for(int i = 0; i <db.size(); i++)
			if(strcmp(db[i].ten,tent)==0){
				Xuat(db[i]);					
				}
		}
			
	}while(strcmp(tent,"\0")!=0);
}

int main(){
	
	Contact c;
	
	Themmoi(c);	
	Lietke();
	Capnhat();
	Lietke();
	Xoacontact();
	Lietke();
	Intheoten();
	getch();
}
