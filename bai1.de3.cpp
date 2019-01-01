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
vector <Contact> DB;
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
	FILE *f = fopen("input.dat", "wb");
	for(int i=0;i<db.size();i++)
		fwrite(&db[i],sizeof(Contact),1,f);
	fclose(f);
		
}
void DocFdb(){
 	FILE *f = fopen("input.dat", "rb");
	for(int i=0;i<db.size();i++)
		{
			Contact c;
			fread(&c,sizeof(Contact),1,f);
			DB.push_back(c);
		}
 }
void Themmoi(Contact c){
				// Nhap truc tiep
  char tent[20];  //="Truc Ly";
  char emailt[20];  //="hpnhoxinh@gmail.com";
  char diachit[50];  //="Nguyen Dinh Chieu";
  char sdtt[11];  //="0969957850";

//Cho nguoi dung tu nhap
do{
	cout<<"\n Nhap ten contact muon tao: ";
	fflush(stdin);
	cin.getline(tent,20);
	if(strcmp(tent,"\0")!=0){
	strcpy(c.ten,tent);
	
	cout<<"\n Nhap gioi tinh (0 or 1): ";
	cin>>c.gioitinh;
	
	cout<<"\n Nhap email: ";
	fflush(stdin);
	cin.getline(emailt,20);
	strcpy(c.email,emailt);

	cout<<"\n Nhap dia chi: ";
	fflush(stdin);	
	cin.getline(diachit,50);	
	strcpy(c.diachi,diachit);

	cout<<"\n Nhap so dien thoai: ";
	fflush(stdin);	
	cin.getline(sdtt,11);
	strcpy(c.sdt,sdtt);
	DB.push_back(c);
		
	}

}while(strcmp(tent,"\0")!=0);
	
	GhiFdb();	
}
void Xuat(Contact c){
   cout<<"\n Ten contact: "<<c.ten<<endl;
   
   if(c.gioitinh == 1)
   cout<<"\nGioi tinh: Nam \n";
   else
   cout<<"\nGioi tinh: Nu \n";
   
   cout<<"Dia chi: "<<c.diachi<<endl;
   cout<<"So dien thoai : "<<c.sdt<<endl;
   cout<<"Email: "<<c.email<<endl;
}
void Lietke(){
	DocFdb();
	for(int i=0;i<DB.size();i++)
		{
			Xuat(DB[i]);
		}
}
void Capnhat(){
	
	char sdtt[11]; 
	do{
		cout<<"\n Nhap sdt cua ban ghi can chinh sua: ";
		cin.getline(sdtt,11);
		
		if(strcmp(sdtt,"\0")!=0)
			{
			for(int i = 0; i <DB.size(); i++)
			
			if(strcmp(DB[i].sdt,sdtt)==0){
				
			char  tentt[20];
			char sdttt[11];
			char emailtt[20];
			char diachitt[50];
			bool gttt;
			// gan gtri da co vao 1 bien tam
			strcpy(tentt,DB[i].ten);
			strcpy(sdttt,DB[i].sdt);
			strcpy(emailtt,DB[i].email);
			strcpy(diachitt,DB[i].diachi);
			gttt = DB[i].gioitinh;
			
				cout<<"\n Nhap ten muon sua: ";
				fflush(stdin);
				cin.getline(DB[i].ten,20);
				if(strcmp(DB[i].ten, "\0" )== 0)
		    	strcpy(DB[i].ten,tentt);
			
				cout<<"\n Nhap gioi tinh can sua (bat buoc; nu: 0 or nam: 1): ";
				cin>>DB[i].gioitinh;
				
				cout<<"\n Nhap sdt muon sua: ";
				fflush(stdin);
				cin.getline(DB[i].sdt,11);
				if(strcmp(DB[i].sdt, "\0" )== 0)
			    strcpy(DB[i].sdt,sdttt);
				
			
				cout<<"\n Nhap email muon sua: ";
				fflush(stdin);
				cin.getline(DB[i].email,20);
				if(strcmp(DB[i].email, "\0" )== 0)
			    strcpy(DB[i].email,emailtt);
											
				cout<<"\n Nhap diachi muon sua: ";
				fflush(stdin);
				cin.getline(DB[i].diachi,50);
				if(strcmp(DB[i].diachi, "\0" )== 0)
				strcpy(DB[i].diachi,diachitt);
				
					
			}
		}
	}while(strcmp(sdtt,"\0")!=0);
}

int Tim(char tent[20]){
	for(int i=0; i<DB.size(); i++)
		if(strcmp(DB[i].ten,tent) == 0)
			return i; 
	return -1;
}

void Xoacontact(){
	char tent[20];
	do{
		cout<<"\n Nhap ten cua ban ghi can xoa: ";
		cin.getline(tent,20);
		
		if(strcmp(tent,"\0")!=0)
		{
			int vt = Tim(tent);
			int n = DB.size();
			if(vt == -1) cout<<"\n Khong co contact nay!";
			else{
				for(int i=0;i<DB.size();i++){
				if(strcmp(DB[i].ten,tent)==0)
				DB.erase(DB.begin()+i);	
				}
			}
		}
			
	}while(strcmp(tent,"\0")!=0);
}


void Intheoten(){
	char tent[20];
	do{
		cout<<"\n Nhap ten cua ban ghi muon tim: ";
		cin.getline(tent,20);
		
		if(strcmp(tent,"\0")!=0)
		{
			for(int i = 0; i <DB.size(); i++)
			if(strcmp(DB[i].ten,tent)==0)
				Xuat(DB[i]);				
		}
			
	}while(strcmp(tent,"\0")!=0);
}

int main(){
	int chon;
	int ktra = 1;
while(ktra == 1){

	cout<<"--------------MENU----------------";
	cout<<"\n 1.Them contact\n";
	cout<<"\n 2.Chinh sua contact\n";
	cout<<"\n 3.Tim contact\n";
	cout<<"\n 4.Xoa contact\n";
	cout<<"\nChon 1 or 2 or 3 or 4: ";
	cin>>chon;
	
	if(chon == 1){
		Contact c;	
		Themmoi(c);		
		Lietke();
	}
	if(chon == 2){
		Capnhat();
		cout<<"\n Xuat db sau khi sua:\n";
		Lietke();
	}	

	if(chon == 3)
	Intheoten();
	
	if(chon == 4){
		Xoacontact();
		cout<<"\n Xuat db sau khi xoa:\n";
		Lietke();	
	}
	
	cout<<"\n Ban co muon tiep tuc ? (co: 1 or ko: 0) ";
	cin>>ktra;

}
	getch();
}
