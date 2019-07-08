#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<string>
#include<fstream>
#include<cstdlib>
#include<stdlib.h>
#include<sstream>
#include<windows.h>
#include<time.h>
using namespace std;
//user info variables
string blood_group;
string qty,area;
clock_t start;
fstream f;
int Id=1111;
int i,j;
char iuser[10];
char ipass[10];
struct password
{
	char user[10];
	char pass[10];
};
class Blood_Bank
{
    public:
        	//pack and unpack variables
			string Buf,Buf1;
			char buf[100];
			//donor info variables
			string name,bg,num_of_donation,last_dod,email,age,addr;
			string ph,AR;
			int ID;
			password Ad;
			string bank_locations[20]={"R T NAGAR","HEBBAL","DEVANAHALLI","HUNASMARANAHALLI","YELAHANKA","VASANTH NAGAR","KORAMANGALA",
			"MARATHAHALLI","MALLESHWARAM","SHIVAJI NAGAR"};
			string s[20]={"A+","A-","a+","a-","B+","B-","b+","b-","AB+","AB-","ab+","ab-","O+","O-","o+","o-"};
			boolean invalidFormat=false;
			//blood bank info variables
			string NAME,BG,AREA,QTY,PH;
			void reg();
			void user_info();
			void donors_info();
			void blood_bank_info();
			void modify_donor();
			void pack();
			void pack1();
			void write(fstream &);
			void write1(fstream &);
			void unpack();
			void unpack1();
			void unpack2();
			void read(fstream &);
			void pwd_chk();
			void create();
			void inp_pwd();
			void experience();
			void intro();
};
//Defines gotoxy() for ANSI C compilers.
void gotoxy(short x, short y) {
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void Blood_Bank::pwd_chk()
{
	system("CLS");
	int flag=0;
	f.open("usser.dat",ios::in|ios::binary);
	gotoxy(5,4);cout<<"   +-+-+-+-+-+-+-+-+        "<<endl;
	gotoxy(5,5);cout<<"       BLOOD BANK MANAGEMENT "<<endl;
	gotoxy(5,6);cout<<"               +-+-+-+-+-+-+-+-+"<<endl;
	gotoxy(5,7);cout<<"                     - let's save a life."<<endl;
	gotoxy(10,10);cout<<"\t\t\t\tLOGIN CREDENTIALS"<<endl;
	inp_pwd();
	while(f.read((char*)&Ad,sizeof(Ad)))
	{
		if(strcmp(Ad.user,iuser)==0)
		{
			if(strcmp(Ad.pass,ipass)!=0 )
			{
				continue;
			}
			else
			{
				flag=1;
				experience();
			}
		}
	}
	if(flag==0)
	{
		gotoxy(11,17);cout<<"Oops !!! Incorrect entry given"<<endl;
		gotoxy(11,19);cout<<"Directing you back ..........."<<endl;
		start=clock();
		while(clock()-start<=5000);//3000);
		f.close();
		intro();
	}
}
void Blood_Bank::create()
{
	system("CLS");
	f.open("usser.dat",ios::app|ios::binary);
	gotoxy(5,4);cout<<"   +-+-+-+-+-+-+-+-+        "<<endl;
	gotoxy(5,5);cout<<"       BLOOD BANK MANAGEMENT "<<endl;
	gotoxy(5,6);cout<<"               +-+-+-+-+-+-+-+-+"<<endl;
	gotoxy(5,7);cout<<"                     - let's save a life."<<endl;
	gotoxy(10,10);cout<<"\n\t\t\tCREATE ACCOUNT"<<endl;
	inp_pwd();
	strcpy(Ad.user,iuser);
	f.write((char*)&Ad,sizeof(Ad));
	strcpy(Ad.pass,ipass);
	f.write((char*)&Ad,sizeof(Ad));
	gotoxy(11,17);cout<<"Your Account has been successfully created!!"<<endl;
	gotoxy(11,19);cout<<"Directing you back ..........."<<endl;
	start=clock();
	while(clock()-start<=5000);//3000);
	f.close();
	intro();

}
void Blood_Bank::inp_pwd()
{
	char a;
	gotoxy(15,13);
	cout<<"\t\t\tUsername:";   
	cin>>iuser;;
	gotoxy(15,15);
	cout<<"\t\t\tPassword:";
	for(i=0;;i++)
	{
			 ipass[i]=getch();
			 if(ipass[i]!='\r')  putch('*');
			 if (ipass[i]=='\b')
			 {
			cout<<"\b\b  \b\b";
			i--; i--;
			 }
			 if(ipass[i]=='\r')  break;
	}
	ipass[i]='\0';
}
void Blood_Bank::experience()
{
	int ch;
	a:
	system("CLS");
	gotoxy(20,4);cout<<"           +-+-+-+-+-+-+-+-+        "<<endl;
	gotoxy(20,5);cout<<"                 BLOOD BANK MANAGEMENT "<<endl;
	gotoxy(20,6);cout<<"                         +-+-+-+-+-+-+-+-+"<<endl;
	gotoxy(20,7);cout<<"                        - let's save a life."<<endl;
	gotoxy(15,10);cout<<"                EXPERIENCE OUR SERVICES   "<<endl;
	gotoxy(15,13);cout<<"                      1.Register and Donate  "<<endl;
	gotoxy(15,14);cout<<"                      2.View Blood Donors and Blood Bank info  "<<endl;
	gotoxy(15,15);cout<<"                      3.Modify Donor Details "<<endl;
	gotoxy(15,16);cout<<"                      4.Logout  "<<endl;
	gotoxy(14,19);cout<<"               Enter your choice(1-4):  ";
	cin>>ch;
	switch(ch)
	{
		case 1:f.close();reg();break;
		case 2:f.close();user_info(); break;
		case 3:f.close();modify_donor();break;
		case 4:f.close();intro(); break;
		default: goto a;
	}
}

void Blood_Bank :: intro()
{
	
	system("CLS");
	int ch;
   	gotoxy(20,4);cout<<"        +-+-+-+-+-+-+-+-+        "<<endl;
	gotoxy(20,5);cout<<"                BLOOD BANK MANAGEMENT "<<endl;
	gotoxy(20,6);cout<<"                        +-+-+-+-+-+-+-+-+"<<endl;
	gotoxy(20,7);cout<<"                                      - let's save a life."<<endl;
	gotoxy(15,10);cout<<"                 WELCOME DEAR CUSTOMER   "<<endl;
	gotoxy(15,13);cout<<"                       1.Login  "<<endl;
	gotoxy(15,14);cout<<"                       2.Create Account  "<<endl;
	gotoxy(15,15);cout<<"                       3.Exit  "<<endl;
	gotoxy(14,17);cout<<"                Enter your choice(1-3):  ";
	cin>>ch;
	switch(ch)
	{
		case 1:pwd_chk(); break;
		case 2:create(); break;
		case 3:exit(0);
		default :intro(); break;
	}
}


void Blood_Bank :: pack()
{
	Buf=name+"|"+bg+"|"+num_of_donation+"|"+last_dod+"|"+ph+"|"+age+"|"+addr;
}

void Blood_Bank :: write(fstream &fp)
{
	fp.flush();
	fp<<Buf<<"\n";
	fp.flush();
}

void Blood_Bank :: write1(fstream  &fp)
{
	fp.flush();
	fp<<Buf1<<"\n";
	fp.flush();
}

void Blood_Bank :: unpack()
{
	
	char stg[100];
	int pos=0,count=0,k;
	while(count<7)
	{
		k=0;
		for(int i=pos;i<strlen(buf);i++,k++)
		{
			stg[k]=buf[i];
			pos++;
			if(buf[i]=='|')
				break;
		}
		stg[k]='\0';
		count++;
		if(count==1)
		    name=stg;
		if(count==2)
		    bg=stg;
		if(count==3)
		    num_of_donation=stg;
		if(count==4)
		    last_dod=stg;
		if(count==5)
		    ph=stg;
		if(count==6)
		    age=stg;
		if(count==7)
		    addr=stg;
	}
}

void Blood_Bank :: read(fstream &fp)
{
	fp.getline(buf,100,'\n');
}

void Blood_Bank :: unpack1()
{
	
	char stg[100];
	int pos=0,count=0,k;
	while(count<2)
	{
		k=0;
		for( i=pos;i<strlen(buf);i++,k++)
		{
			stg[k]=buf[i];
			pos++;
			if(buf[i]=='|')
				break;
		}
		stg[k]='\0';
		count++;
		if(count==1)ID=atoi(stg);
		if(count==2)AR=stg;
    }
}

void Blood_Bank :: unpack2()
{
	
	char stg[100];
	int pos=0,count=0,k;
	while(count<5)
	{
		k=0;
		for( i=pos;i<strlen(buf);i++,k++)
		{
			stg[k]=buf[i];
			pos++;
			if(buf[i]=='|')
				break;
		}
		stg[k]='\0';
		count++;
		if(count==1)NAME=stg;
		if(count==2)BG=stg;
		if(count==3)QTY=stg;
		if(count==4)PH=stg;
		if(count==5)AREA=stg;
    }
}

void Blood_Bank::modify_donor()
{
	fstream ff,f;
	Blood_Bank b3[100],b4[100];
	string a;
	int i,ch,id2;
	f.open("donors.txt",ios::in);	
	ff.open("id1.txt",ios::in);
	cout<<"Enter the Area:";
	cin>>a;
	cout<<"\nEnter your Donor ID:";
	cin>>id2;
	i=0;
	while(ff)
	{
		b3[i].read(ff);
		b3[i].unpack1();
		b4[i].read(f);
		b4[i].unpack();
		i++;
	}
	ff.close();
	f.close();
	int cnt=i-1;
	i=0;
	for(i=0;i<cnt;i++)
	{
		if(b3[i].AR==a)
		{
			check:if(b3[i].ID==id2)
			{
				do
				{
					cout<<"\n\n\nEnter the field you wish to change";
					cout<<"\n1.Name: "<<b4[i].name;
					cout<<"\n2.Blood Group: "<<b4[i].bg;
					cout<<"\n3.Age: "<<b4[i].age;
					cout<<"\n4.Address: "<<b4[i].addr;
					cout<<"\n5.Phone number: "<<b4[i].ph;
					cout<<"\n6.No of Donations: "<<b4[i].num_of_donation;
					cout<<"\n7.Last date of Donation: "<<b4[i].last_dod;
					cout<<"\n8.Exit"<<endl;
				choice:	cin>>ch;
					switch(ch)
					{
						case 1: cout<<"Enter the  Name:";
								cin>>b4[i].name;
								break;
						case 2: cout<<"Enter the Blood Group:";
								cin>>b4[i].bg;
								break;
						case 3: cout<<"Enter the Age:";
								cin>>b4[i].addr;
								break;
						case 4: cout<<"Enter the Address:";
								cin>>b4[i].ph;
								break;
						case 5: cout<<"Enter the Phone Number:";
								cin>>b4[i].num_of_donation;
								break;
						case 6: cout<<"Enter the No of Donation:";
								cin>>b4[i].last_dod;
								break;
						case 7: cout<<"Enter the new Name";
								cin>>b4[i].name;
								break;
						case 8:break;
						/**cout<<"\n\nDirecting you back ..........."<<endl;
								start=clock();
								while(clock()-start<4000);
								experience();**/
						default:cout<<"Enter the correct choice"<<endl;
					       	 goto choice;
					}
				}while(ch!=8);
			}
			else
			{
				cout<<"\nEnter the correct Donor ID ";
				cin>>id2;
				goto check;
			}	
		}
	}
	ff.open("donors.txt",ios::out);
	for(i=0;i<cnt;i++)
	{
		b4[i].pack();
		b4[i].write(ff);
	}
	cout<<"\n\nDirecting you back ..........."<<endl;
								start=clock();
								while(clock()-start<4000);
								experience();
}
	
void Blood_Bank::reg()
{
	system("CLS");
	gotoxy(20,4);cout<<"        +-+-+-+-+-+-+-+-+        "<<endl;
	gotoxy(20,5);cout<<"                BLOOD BANK MANAGEMENT "<<endl;
	gotoxy(20,6);cout<<"                        +-+-+-+-+-+-+-+-+"<<endl;
	gotoxy(20,7);cout<<"                                      - let's save a life."<<endl;
	int id;
	string str1;
	int ch1,ch2;
	void w1(int a,string z);
	ifstream fp1;
	fstream fp2;
	fp2.open("donors.txt",ios::app);
	fp1.open("id1.txt",ios::in);
	cout<<"\n\n\t\t\t\t\tEnter the following details";
	cout<<"\n\t\t\t\t\t\tEnter name:";
	cin>>name;
	cout<<"\n\t\t\t\t\t\tEnter Blood Group:";
	bg_valid:cin>>bg;
	int c=0;
	for(i=0;i<16;i++)
	{
		if(s[i]==bg)
		{
			c++;
			break;
		}
	}
	if(c==0)
	{
		cout<<"\n\t\t\t\t\t\tPlease enter correct Blood Group:";
		goto bg_valid;
	}
	cout<<"\n\t\t\t\t\t\tEnter No of Donation:";
	cin>>num_of_donation;
	cout<<"\n\t\t\t\t\t\tEnter Last date of donation(in format dd/mm/yyyy):";
	cin>>last_dod;
	/**string d;
	int dd[6];
	i=0;
	j=0;
	last_dod=last_dod+"\0";
	dv:while(last_dod[i]!='/')
	{
		if(last_dod[i]=='\0')
			break;
		else
		{
				d[j]=last_dod[i];
				i++;
				j++;
		}	
	}
	i++;
	goto dv;
	for(i=0,j=0;i<8;i+=2,j++)
	{
		std::string text=(d.substr(i,i+1));
		std::istringstream iss(text);
		iss >> dd[j];
	}
	cout<<dd;**/	
	mo:cout<<"\n\t\t\t\t\t\tEnter Phone number:";
	cin>>ph;
	invalidFormat = false;
	if(ph.length()!= 10)
   		invalidFormat = true;
	if(invalidFormat)	   	    
   	{
   		cout << "ERROR! Invalid phone number. Please re-enter your phone number: " << endl;
 		goto mo;
	}		
	cout<<"\n\t\t\t\t\t\tEnter Age:";
	cin>>age;
	cout<<"\n\t\t\t\t\t\tEnter Address:";
	cin>>addr;
	cout<<"\n\t\t\t\t\t\tChoose the center location to donate blood\n";
	for(i=0;i<10;i++)
	{
		cout<<"\t\t\t\t\t\t"<<i+1;
		cout<<". "<<bank_locations[i]<<endl;
	}
	cin>>ch1;
	ch2=ch1;
	cout<<"\t\tYou can donate blood in the center "<<bank_locations[ch2-1];
	int id1;
check:while(fp1)
	{
		
		fp1>>id1;
		if(Id==id1)
		{
			Id=Id+2;
			goto check;
		}
	}
	w1(Id,addr);
	cout<<"\nYour data is saved successfully......!!!!!!!!\nTHANK YOU!!!!!!!\nYour Donor ID is :"<<Id<<endl;
	pack();
	write(fp2);
	Id=Id+2;	
	fp1.close();
	fp2.close();
		start=clock();
    while(clock()-start<=10000);
	experience();
}

void w1(int i,string addr)
{
	ofstream fp;
	fp.open("id1.txt",ios::app);
	fp<<i<<"|"<<addr<<"\n";
}

void Blood_Bank :: user_info()
{
	system("CLS");
	string uname,u_ph;
	gotoxy(5,4);cout<<"   +-+-+-+-+-+-+-+-+        "<<endl;
	gotoxy(5,5);cout<<"          BLOOD BANK MANAGEMENT "<<endl;
	gotoxy(5,6);cout<<"                  +-+-+-+-+-+-+-+-+"<<endl;
	gotoxy(5,7);cout<<"                        - let's save a life."<<endl;
	cout<<"\n\n\t\t\tEnter the following details";
	cout<<"\n\t\t\t\t\tEnter Blood Group Required:";
	bgp_valid:cin>>blood_group;
	int c=0;
	for(i=0;i<16;i++)
	{
		if(s[i]==blood_group)
		{
			c++;
			break;
		}
	}
	if(c==0)
	{		cout<<"\n\t\t\t\t\t\tPlease enter correct Blood Group:";
			goto bgp_valid;
	}
	cout<<"\n\t\t\t\t\tEnter Area:";
	cin>>area;
	cout<<"\n\t\t\t\t\tEnter Quantity of Blood Required :";
	cin>>qty;
	blood_bank_info();
	donors_info();
}

void Blood_Bank :: donors_info()
{
	fstream fp1;
	Blood_Bank b1[100];
	fp1.open("donors.txt",ios::in);
	int i=0;
	int cnt=0;
	int c=0;
	while(fp1)
	{
		b1[i].read(fp1);
		b1[i].unpack();
		i++;
	}
	cnt=i-1;
	for(i=0;i<cnt;i++)
	{
		if(b1[i].bg==blood_group&&b1[i].addr==area)
		{
			if(i==0)
				cout<<"List of Donors of "<<blood_group<<"  blood group in "<<area<<" are as follows :"<<endl;
			c++;
			cout<<"\n\nName: "<<b1[i].name;
			cout<<"\nBlood Group: "<<b1[i].bg;
			cout<<"\nAge: "<<b1[i].age;
			cout<<"\nAddress: "<<b1[i].addr;
			cout<<"\nPhone number: "<<b1[i].ph;
			cout<<"\nNo of Donations: "<<b1[i].num_of_donation;
			cout<<"\nLast date of Donation: "<<b1[i].last_dod;
		}
	}
	if(c==0)
	{
		cout<<"\nThere are no Donors of "<<blood_group<<" in "<<area<<"."<<endl;
		for(i=0;i<cnt;i++)
		{
			if(b1[i].bg==blood_group)
			{
				if(i==0)
					cout<<"\n\nList of donors of "<<blood_group<<" blood in other places are as folows:"<<endl;
				c++;
				cout<<"\n\nName: "<<b1[i].name;
				cout<<"\nBlood Group: "<<b1[i].bg;
				cout<<"\nAge: "<<b1[i].age;
				cout<<"\nAddress: "<<b1[i].addr;
				cout<<"\nPhone number: "<<b1[i].ph;
				cout<<"\nNo of Donations: "<<b1[i].num_of_donation;
				cout<<"\nLast date of Donation: "<<b1[i].last_dod;
			}
		}
	}
//	if(c==0)
//		cout<<"\n\nThere are no Donors of "<<blood_group<<" blood avilable now."<<endl;
	fp1.close();
	start=clock();
	while(clock()-start<=20000);
	experience();
}
	
void Blood_Bank :: blood_bank_info()
{
	fstream fp;
	Blood_Bank b2[100];
	fp.open("blood_bank.txt",ios::in|ios::app);
	int i=0;
	int cnt=0;
	int c=0;
	while(fp)
	{
		b2[i].read(fp);
		b2[i].unpack2();
		i++;
	}
	cnt=i-1;
	
	
	for(i=0;i<cnt;i++)
	{
	//	cout<<"hellooooo"<<b2[i].QTY<<"hiiiiiii"<<qty;
	//	cout<<b2[i].AREA<<endl;
	//	cout<<b2[i].BG<<endl;
		if((b2[i].AREA==area)&&(b2[i].QTY<=qty)&&(b2[i].BG==blood_group))
		{
			if(i==0)
				cout<<"Blood Banks having required volume of "<<blood_group<<" blood in "<<area<<" are as follows:"<<endl;
			//cout<<"Blood Bank "<<i+1<<":"<<endl;
			c++;
			cout<<"\n\nBlood Bank Name: "<<b2[i].NAME;
			cout<<"\nRequired Blood Group: "<<b2[i].BG;
			cout<<"\nVolume of Blood available: "<<b2[i].QTY;
			cout<<"\nPhone number: "<<b2[i].PH;
			cout<<"\nAddress: "<<b2[i].AREA;
		}
	}
	if(c==0)
	{
		cout<<"\n\nThere are no Blood Banks having "<<qty<<" volume of "<<blood_group<<" blood."<<endl;
		for(i=0;i<cnt;i++)
		{
			if((b2[i].QTY<=qty)&&(b2[i].BG==blood_group))
			{
				if(i==0)
					cout<<"Blood Banks having required volume of "<<blood_group<<" blood in other areas are as follows:"<<endl;
			cout<<"Blood Bank "<<i+1<<":"<<endl;
			c++;
			cout<<"\n\nBlood Bank Name: "<<b2[i].NAME;
			cout<<"\nRequired Blood Group: "<<b2[i].BG;
			cout<<"\nVolume of Blood available: "<<b2[i].QTY;
			cout<<"\nPhone number: "<<b2[i].PH;
			cout<<"\nAddress: "<<b2[i].AREA;
			}
		}
	}
/**	if(c==0)
		cout<<"\n\nThere are no Blood Banks having required amount of "<<blood_group<<" blood."<<endl;**/
	fp.close();
}
int main()
{
	Blood_Bank b;
		gotoxy(20,6);
	cout<<"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+";
	gotoxy(20,7);
	cout<<"       |   Simple Blood Bank Management System   |";
	gotoxy(20,8);
	cout<<"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+";
	gotoxy(20,10);
	cout<<" There are four major blood groups determined by the presence or ";
	gotoxy(16,11);
	cout<<"absence of two antigens-A and B- on the surface of red blood cells";
	gotoxy(16,14);
	cout<<"Group A-has only the A antigen on red cells(and B antibody int he plasma)";
	gotoxy(16,16);
	cout<<"Group B-has only the B antigen on red cells(and A antibody in the plasma)";
	gotoxy(16,18);
	cout<<"Group AB-has both A and B antigens on red cells(but neither A nor B antibody in the plasma)";
	gotoxy(16,20);
	cout<<"Group O-has neither A nor B antigens on red cells(but both A and B antibody are in the plasma)";
	gotoxy(4,24);
	cout<<"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+";
		start=clock();
	while(clock()-start<=5000);//3000);
	b.intro();
	return 1;
}


