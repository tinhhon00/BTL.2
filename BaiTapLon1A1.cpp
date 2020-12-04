#include<iostream> 
#include<string>
#include<conio.h>
#include<Windows.h>
#include<vector> 
using namespace std;
class Student
{ 
	protected:
		string Name;
		int Age;
		float Maths,English,Phyical;
		int Studentcode; 
		bool KT; 
	public:
		Student();
		~Student();
		void  TextColor(int z);
		virtual void Import () ;
		virtual void Export () ;
		virtual float Totalscore() =0; 
		string Get_Name()
        {
            return this->Name;
        }
        int Studentcode_A()
		{
			return this->Studentcode; 
		}
        bool Getter_KT()
        {
            return KT;
        }
        void Setter(bool kt)
        {
            this->KT = kt;
        }
	
};
Student::Student() 
{
	Name="";
	Age=0;
	Maths=0;
	English=0;
	Phyical=0; 
}
Student::~Student()
{		
} 
void Student ::TextColor(int z)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,z);
}
void Student::Import()
{
	TextColor(2) ;
	cin.ignore();
	cout<<"\n\t\t\t\t\t--Import  Name  :" ;
	getline(cin,Name);
	cout<<"\n\t\t\t\t\t--Import Age :" ;
	cin>>Age ;
	cout<<"\n\t\t\t\t\t--Import Code  Student	: " ;
	cin>>Studentcode; 
	cout<<"\n\n\t\t\t\t\t--Import Maths :" ; 
	cin>>Maths; 
	cout<<"\n\t\t\t\t\t--Import English :" ;
	cin>>English ;
	cout<<"\n\t\t\t\t\t--Import Phyical:" ;
	cin >>Phyical;
}
void Student::Export()
{
	cout<<"\n\t\t\t\t\t--Name  Student  :" <<Name<<endl;
	cout<<"\n\t\t\t\t\t--Age Studetn  :" <<Age<<endl;
	cout<<"\n\t\t\t\t\t--Code Student  :" <<Studentcode<<endl; 
	cout<<"\n\t\t\t\t\t--Maths::English::Phyical::"<<Maths<<"---"<<English<<"---"<<Phyical<<endl; 
} 
class CNTTA:public Student 
{
	private :
		string Village;
	public :
		 CNTTA();
		~CNTTA(); 
		void Import();
		void Export(); 
		float  Totalscore();
}; 
CNTTA::CNTTA() 
{
	Village=" "; 
}
CNTTA::~CNTTA()
{	
} 
void CNTTA::Import() 
{
	Student::Import(); 
	cin.ignore(1);
	cout<<"\n\t\t\t\t\t --Import  Village :"; 
	getline(cin,Village); 
	
}
void CNTTA::Export() 
{
	Student::Export();
	cout<<"\n\t\t\t\t\t--Village:"<<Village<<endl; 
	 
}
float CNTTA::Totalscore ()
{

	return((Maths+English+Phyical)/3);
}


class CNTTB:public Student
{
	private:
		int Schoolday;
	public:
		CNTTB() ;
		~CNTTB(); 
		void Import() ;
		void Export() ;
		float  Totalscore();

}; 
CNTTB::CNTTB()
{
	Schoolday=0;	
} 
CNTTB::~CNTTB()
{
} 
void CNTTB::Import() 
{
	Student::Import();
	cout<<"\n\t\t\t\t\t--Import  School Day ";
	cin>>Schoolday; 
		
}
void CNTTB::Export()
{
	Student::Export();
	cout<<"\n\t\t\t\t\t--School Day:" <<Schoolday<<endl; 
	
} 
float CNTTB::Totalscore()
{
	return(((Maths+English+Phyical)/3)+1) ;
}
class Teacher
{
	private:
		vector<Student*>SV;
	public:
		Teacher() ;
		~Teacher(); 
	 	void  Import();
	 	void  Export(); 
	 	void  Sort();//sap xep diem tb 
	 	float TotalscoreTB(); //tinh tong diem trung binh 
	 	void  TotalscoreMAX();// tim so diem tb lon nhat  
	 	void  Search();//tim sinh vien theo ten  
	 	void  Code();//tim sinh vien theo ma 
	 	void  Revoke();//bo mot sinh vien  theo ma   
	 	void TextColor(int z);
	 	void gotoxy(int x,int y);
	 	void chaychu();
	 	void color(int color ) ;
	 	
}; 
Teacher::Teacher()
{
} 
Teacher::~Teacher() 
{
}
void Teacher::Import()
{
	int chon;
		do{
			system("cls");
			cout<<"\n\t\t\t\t\t";
			cout<<"\n\t\t\t\t\t";
			cout<<"\n\t\t\t\t\t";
			cout<<"\n\t\t\t\t\t";
			cout<<"\n\t\t\t\t\t";
			TextColor(32);
			cout<<"\n\t\t\t\t\t------------MENU------------"; 
			TextColor(3);
			cout<<"\n\t\t\t\t\t 1. Enter Student CNTTA.";
			cout<<"\n\t\t\t\t\t";
            cout<<"\n\t\t\t\t\t 2. Enter Student CNTTB.";
            cout<<"\n\t\t\t\t\t";
            cout<<"\n\t\t\t\t\t 3. Exit. ";
			cout<<"\n\t\t\t\t\t";
			cout<<"\n\t\t\t\t\t________________________________________"<<endl;
			cout<<"\n\t\t\t\t\t";
			TextColor(64);
            cout<<"\n\t\t\t\t\t Enter The Option: ";
            TextColor(3);
            cin>>chon;
			Student*X; 
		switch(chon)
		{
			case 1:
			{
				X=new CNTTA;
				X->Import();
				X->Setter(true);
				SV.push_back(X);
				break; 
			 } 
			case 2:
			 {
			 	X =new CNTTB;
				X->Import() ;
				X->Setter(false);
				SV.push_back(X);
				break;
			  } 
			case 3:
			{ 
				break; 
			 }
			 default:
			 {
			 	cout<<" \n\t\t\t\t\t Unreasonable Choice." <<endl;
				 break; 
			  } 
		}	
	} 		while(chon != 3);
}
void Teacher::Export()
{
	for(int i=0;i <SV.size();i++)
	{
	cout<<"\n\t\t\t\t\t________________________________________"<<endl;
	if(SV[i]->Getter_KT()==true )
	{
		cout<<"\n\t\t\t\t\t Student  CNTTA:" <<i+1<<endl; 
		SV[i]->Export();
		cout<<"\n\t\t\t\t\t Total Score TB:" <<(size_t)SV[i] ->Totalscore()<<endl; 
		 
	}	
	if(SV[i]->Getter_KT()==false) 
	{
		cout<<"\n\t\t\t\t\tStudent  CNTTB:" <<i +1<<endl;
		SV[i]->Export();
		cout<<"\n\t\t\t\t\tTotal Score TB:"<<(size_t)SV[i] ->Totalscore()<<endl;
	}
	}
 } 
void Teacher::Sort() // sap xep  
{
	Student*LV; 
	for(int i=0;i < SV.size();++i) 
	{
		for(int j=i+1; j<SV.size() ;++j)
		 {
			if(SV[i]->Totalscore() > SV[j]->Totalscore()) 
			{
			  LV=SV[i];
			  SV[i]=SV[j];
			  SV[j]=LV; 
			  
			}
		}
	}
}

float Teacher::TotalscoreTB() //tinh tong diem trung binh 
{
	float sum=0;
	for(int i=0;i<SV.size();i++) 
	{
		sum=sum+SV[i]->Totalscore();
	}
	return sum; 
}
void  Teacher::TotalscoreMAX()//diem trung binh cao nhat 
{
	float Max=SV[0]->Totalscore();
	for(int i=1;i<SV.size();i++) 
	{
		if((size_t)SV[i]->Totalscore()>Max) 	
			Max=(size_t)SV[i] ->Totalscore();
	}
	cout<<"\n";
	cout<<"\n";
	cout <<"\n\t\t\t\t Point TB Max:" <<Max<<endl; 
 } 

void Teacher::Search() //tim sinh vien theo ten  
{
	int count=0; 
	string NameP;
	cin.ignore(); 
	cout<<"\n";
	cout<<"\n\t\t\t\Tenter The Search Name:" ;
	getline(cin,NameP) ;
	for(int i=0 ;i<SV.size();i++) 
	{
		if(SV[i]->Get_Name()==NameP)
		{
			if(SV[i]->Getter_KT()==true) 
			{
				cout<<"\n\t\t\t\t\t*****Students Need To Find Is ::--Students CNTTA--" <<endl; 
				count++;
			}
			if(SV[i]->Getter_KT()==false) 
			{
				cout<<"\n\t\t\t\t\t*****Students Need To Find Is ::--Students CNTTB--" <<endl; 
				count++;
			}
			SV[i]->Export();
		}
	}
	if (count==0){
		cout<<"\n";
		cout<<"\n \t\t\t\t Invalid Code." <<endl; 
	}
	
}
void Teacher::Code()//tim sinh vien theo ma
 
{
	int Count=0; 
	int CodeC;
	cout<<"\n\t\t\t\t Enter The Code To Look For :" ;
	cin>>CodeC;
	for(int i=0;i<SV.size();i++)
	{
		if(SV[i]->Studentcode_A()==CodeC) 
		{
			if (SV[i]->Getter_KT()==true)
			{
				cout<<"\n";
				cout<<"\n";
		 	cout<<"\n\t\t\t\t\t Students Need To Find Is ::--Students CNTTA--" <<endl; 
		 		Count++;
			}
			if(SV[i]->Getter_KT()==false) 
			{
				cout<<"\n";
				cout<<"\n";
				cout<<"\n\t\t\t\t\t Students Need To Find Is ::--Students CNTTB--" <<endl; 
					Count++;
			}
			SV[i] ->Export();
		}  
 	}
 		if (Count==0){
 			cout<<"\n";
		cout<<"\n\t\t\t\t Invalid Code." <<endl;
	}
 	
}

void Teacher::Revoke()
{
	string  ID; 
	cout<<"\n";
	cout<<"\n";
	cout<<" Enter The Student's Name To Delete:" ;
	cin.ignore(1);
	getline(cin,ID);
	int Count=0;
	for(int i=0;i<SV.size();i++) 
	{
		if(ID==SV[i]->Get_Name() )
		{
			SV.erase(SV.begin() +i);
			Count ++;
			 
		}
		Export() ;
	if(Count==0) {
		cout<<"\n";
		cout<<"\n";
	cout<<"\n \t\t\t\tDoes Not Have This Name.\n" ;
				}	
		
}
}
void Teacher::TextColor(int z)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,z);
}
void Teacher::gotoxy(int x,int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
void Teacher::color(int color) 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
}
void Teacher::chaychu()
{
	char a[104] = "  ****      BAI TAP LON CNTT K60     ****  ", b[104], c[40];
	strcpy(b, a);
	strcat(a, b);
	for (int i = 0; i < strlen(a); i++)
	{
		strncpy(c, a + i, 61);
		c[41] = 0;
		Sleep(100);
		gotoxy(37, 12);
		for (int i = 0; i < 43; i++)
		{
			cout << char(206);
		}
		gotoxy(37, 13);
		cout << char(1)<< c<< char(1);
		gotoxy(37, 14);
		for (int i = 0; i < 43; i++)
		{
			cout << char(206);
		}
		if (i == strlen(b)) i = 0;
	}
}


int main() {	
	Teacher TC;	
	TC.TextColor(3);	
	TC.gotoxy(30,14);
	TC.chaychu();		
	int Choose;					
		while(true) 
		{
		
			system("cls");
			TC.TextColor(32);
			TC.gotoxy(31,2);
			cout<<"                                                        ";
			cout<<"\n"; 
			cout<<"\n"; 
			TC.TextColor(32);
			cout<<"\n\t\t\t\t\t------------MENU------------"; 
			TC.TextColor(3);
			cout<<"\n\t\t\t\t\t  1. Enter Information.";
			cout<<"\n\t\t\t\t"; 
            cout<<"\n\t\t\t\t\t  2. Information Export.";
           	cout<<"\n\t\t\t\t"; 
            cout<<"\n\t\t\t\t\t  3. Total Score TB.";
           	cout<<"\n\t\t\t\t"; 
            cout<<"\n\t\t\t\t\t  4. Find TB Max .";
           	cout<<"\n\t\t\t\t"; 
            cout<<"\n\t\t\t\t\t  5. Find Students By Name.";
           	cout<<"\n\t\t\t\t"; 
            cout<<"\n\t\t\t\t\t  6. Find Students By Code.";
           	cout<<"\n\t\t\t\t"; 
            cout<<"\n\t\t\t\t\t  7. Sort.";
           	cout<<"\n\t\t\t\t"; 
            cout<<"\n\t\t\t\t\t  8. Delete Students By Name." ;
            cout<<"\n\t\t\t\t"; 
            cout<<"\n\t\t\t\t\t  0. Exit.";
           	cout<<"\n\t\t\t\t"; 
			cout<<"\n\t\t\t\t"; 
			TC.TextColor(64);
            cout<<"\n\t\t\t\t\t Tenter Your Selection. ";
            TC.TextColor(3);
            TC.TextColor(32);
			TC.gotoxy(85,10);
			cout<<"  ";
			TC.TextColor(32);
			TC.gotoxy(85,9);
			cout<<"  ";	
			TC.TextColor(32);
			TC.gotoxy(85,8);
			cout<<"  ";	
			TC.TextColor(32);
			TC.gotoxy(85,7);
			cout<<"  ";	
			TC.TextColor(32);
			TC.gotoxy(85,6);
			cout<<"  ";	
			TC.TextColor(32);
			TC.gotoxy(85,5);
			cout<<"  ";	
			TC.TextColor(32);
			TC.gotoxy(85,4);
			cout<<"  ";	
			TC.TextColor(32);
			TC.gotoxy(85,3);
			cout<<"  ";	
			TC.TextColor(32);
			TC.gotoxy(85,11);
			cout<<"  ";	
			TC.TextColor(32);
			TC.gotoxy(85,12);
			cout<<"  ";	
			TC.TextColor(32);
			TC.gotoxy(85,13);
			cout<<"  ";	
			TC.TextColor(32);
			TC.gotoxy(85,14);
			cout<<"  ";	
			TC.TextColor(32);
			TC.gotoxy(85,15);
			cout<<"  ";	
			TC.TextColor(32);
			TC.gotoxy(85,16);
			cout<<"  ";	
			TC.TextColor(32);
			TC.gotoxy(85,17);
			cout<<"  ";	
			TC.TextColor(32);
			TC.gotoxy(85,18);
			cout<<"  ";	
			TC.TextColor(32);
			TC.gotoxy(85,19);
			cout<<"  ";	
			TC.TextColor(32);
			TC.gotoxy(85,20);
			cout<<"  ";	
			TC.TextColor(32);
			TC.gotoxy(85,21);
			cout<<"  ";	
			TC.TextColor(32);
			TC.gotoxy(85,22);
			cout<<"  ";	
			TC.TextColor(32);
			TC.gotoxy(85,23);
			cout<<"  ";	
			TC.TextColor(32);
			TC.gotoxy(85,24);
			cout<<"  ";	
			TC.TextColor(32);
			TC.gotoxy(85,25);
			cout<<"  ";	
			TC.TextColor(32);
			TC.gotoxy(85,26);
			cout<<"  ";	
			TC.TextColor(32);
			TC.gotoxy(85,27);
			cout<<"  ";	
			TC.TextColor(32);
			TC.gotoxy(31,28);
			cout<<"                                                        ";
			
            TC.TextColor(32);
			TC.gotoxy(31,10);
			cout<<"  ";
			TC.TextColor(32);
			TC.gotoxy(31,9);
			cout<<"  ";	
			TC.TextColor(32);
			TC.gotoxy(31,8);
			cout<<"  ";	
			TC.TextColor(32);
			TC.gotoxy(31,7);
			cout<<"  ";	
			TC.TextColor(32);
			TC.gotoxy(31,6);
			cout<<"  ";	
			TC.TextColor(32);
			TC.gotoxy(31,5);
			cout<<"  ";	
			TC.TextColor(32);
			TC.gotoxy(31,4);
			cout<<"  ";	
			TC.TextColor(32);
			TC.gotoxy(31,3);
			cout<<"  ";	
			TC.TextColor(32);
			TC.gotoxy(31,11);
			cout<<"  ";	
			TC.TextColor(32);
			TC.gotoxy(31,12);
			cout<<"  ";	
			TC.TextColor(32);
			TC.gotoxy(31,13);
			cout<<"  ";	
			TC.TextColor(32);
			TC.gotoxy(31,14);
			cout<<"  ";	
			TC.TextColor(32);
			TC.gotoxy(31,15);
			cout<<"  ";	
			TC.TextColor(32);
			TC.gotoxy(31,16);
			cout<<"  ";	
			TC.TextColor(32);
			TC.gotoxy(31,17);
			cout<<"  ";	
			TC.TextColor(32);
			TC.gotoxy(31,18);
			cout<<"  ";	
			TC.TextColor(32);
			TC.gotoxy(31,19);
			cout<<"  ";	
			TC.TextColor(32);
			TC.gotoxy(31,20);
			cout<<"  ";	
			TC.TextColor(32);
			TC.gotoxy(31,21);
			cout<<"  ";	
			TC.TextColor(32);
			TC.gotoxy(31,22);
			cout<<"  ";	
			TC.TextColor(32);
			TC.gotoxy(31,23);
			cout<<"  ";	
			TC.TextColor(32);
			TC.gotoxy(31,24);
			cout<<"  ";	
			TC.TextColor(32);
			TC.gotoxy(31,25);
			cout<<"  ";	
			TC.TextColor(32);
			TC.gotoxy(31,26);
			cout<<"  ";	
			TC.TextColor(32);
			TC.gotoxy(31,27);
			cout<<"  ";	
			TC.TextColor(3);
            
            
            cin>>Choose;
            switch(Choose)
			{
				case 1:
				{
			
					TC.Import();
					break;
					system("pause");
				}
				case 2:
				{	
					
					TC.Export();
					system("pause");
					break;
			    }		
				case 3: 
				{
					
					cout<<"	\n\t\t\t\t Total Score TB :"<<TC.TotalscoreTB()<<endl;
					system("pause");
					break; 
				}
				case 4:
				{
					
					TC.TotalscoreMAX();
					system("pause");
					break; 
				} 
				case 5:
				{
					
					TC.Search();
					system("pause");
					break; 
				}
				case 6:
				{
				
					TC.Code(); 
					system("pause");
					break; 
			 	}
			 	
				 case 7:
				{
					
				 	TC.Sort();
				 	TC.Export();
				 	system("pause");
				 	break; 
				} 
				case 8:
				{
					
					TC.Revoke(); 
					system("pause");
					break; 
				 } 
				case 0:
				{
					exit(0) ;
					system("pause");
					 break;
				} 
				default:
                {
                    cout<<"Illegal"<<endl;
                    break;
                }
			} 
		}
		system("pause");
    return 0;
}






































 
