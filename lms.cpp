#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main();
void login();
int welcome();
void admin();

int i=0,d=0;

struct member
{
	string mbnm,addr;
	long mbno;
};

struct book
{
	string bknm,author;
	long bkno;
	unsigned long doi;
	member mbissue;
};

book b[50];

void create_book()
{
	char r6;
	while(i<=50)
	{
		login();
		cout<<"\n****************     CREATE A BOOK     *******************\n\n";
		cout<<"\nYou can create "<<50-i<<" more books .....\n";
		cout<<"\n\nEnter book name : ";//<<endl;
		//getline(cin,b[i].bknm,'\n');
		cin>>b[i].bknm;
		cout<<"Enter author name : ";
		//getline(cin, b[i].author);
		cin>>b[i].author;
		b[i].bkno = i+1;
		cout<<"\n\nBook number : "<<b[i].bkno;
		cout<<"\n\n\nRECORD CREATED !!!\n";
		cout<<"\n\n\nDo you want to enter record of another book? (Y/N) : ";
		cin>>r6;

		if(r6=='Y'||r6=='y')
		{
			cout<<"\n\n-----------------------------------------------------------\n";
			i++;
			continue;
		}

		else
		{
			i++;
			break;
		}
	}

	admin();
}

void display_allb()
{
	login();
	cout<<"\n**************     DISPLAY ALL BOOKS     *****************\n\n";
	int j1;
	
	if(i==0)
		cout<<"\n\nNO RECORD EXISTS !!!\n";

	else
	{
		cout<<"\n\n==========================================================\n";
		cout<<"\n\nBOOK NO.\tBOOK NAME\t\tAUTHOR\n";
		cout<<"\n==========================================================\n";

		for(j1=0;j1<i;j1++)
			cout<<"\n\n"<<b[j1].bkno<<"\t\t"<<b[j1].bknm<<"\t\t"<<b[j1].author;
	}

	cout<<"\n\n----------------------------------------------------------";
	cout<<"\n\nPress any key to return to administrator's menu\n";
	admin();
}

void display_spb()
{
	char r7='Y';

	while(r7=='y'||r7=='Y')
	{
		login();
		cout<<"\n************     DISPLAY SPECIFIC BOOK     ***************\n\n";
		long bno;
		int j2,k=0;
		cout<<"\n\nEnter book number to be searched : ";
		cin>>bno;
		
		for(j2=0;j2<i;j2++)
		{
			if(b[j2].bkno==bno)
			{
				k=j2+1;
				break;
			}
		}
		
		if(k>0)
		{
			cout<<"\n\n===============================================================\n";
			cout<<"\n\nBOOK NO.\tBOOK NAME\t\tAUTHOR\n";	
			cout<<"\n===============================================================\n";
			cout<<"\n\n"<<b[k-1].bkno<<"\t"<<b[k-1].bknm<<"\t"<<b[k-1].author<<"\n";
			cout<<"\n\nISSUING MEMBER NUMBER : "<<b[k-1].mbissue.mbno<<"\n";
			cout<<"\n\nISSUING MEMBER NAME : "<<b[k-1].mbissue.mbnm<<"\n";
			cout<<"\n\nISSUING MEMBER ADDRESS : "<<b[k-1].mbissue.addr<<"\n";
			cout<<"\n\nDATE OF ISSUE : "<<b[k-1].doi<<"\n";
			cout<<"\n\n===============================================================\n";
		}
	
		else
			cout<<"\n\nNO RECORD FOUND !!!\n";
			
		cout<<"\n\n\nDo you want to search for another book? (Y/N) : ";
		cin>>r7;
		cout<<"\n\n----------------------------------------------------------\n";
	}
	
	admin();
}

void modify_book()
{
	char r8='y';
	while(r8=='Y'||r8=='y')
	{
		login();
		cout<<"\n**************     BOOK MODIFICATION     *****************\n\n";
		long bno;
		cout<<"\n\nEnter book number to be modified : ";
		cin>>bno;
		
		if(b[bno-1].bkno!=0)
		{
			cout<<"\n\nOriginal details of the book\n";
			cout<<"\n\n==========================================================\n";
			cout<<"\n\nBOOK NO.\tBOOK NAME\t\t\tAUTHOR\n";
			cout<<"\n==========================================================\n";
			cout<<"\n\n"<<b[bno-1].bkno<<"\t"<<b[bno-1].bknm<<"\t"<<b[bno-1].author<<endl;
			cout<<"\n\n----------------------------------------------------------\n";
			cout<<"\n\nEnter new details of book\n";
			cout<<"\n\nBook number : "<<b[bno-1].bkno;
			cout<<"\n\n\nBook name : ";
			cin>>b[bno-1].bknm;
			cout<<"\n\nAuthor : ";
			cin>>b[bno-1].author;
			cout<<"\n\n\nRECORD UPDATED !!!\n";
			cout<<"\n\n\nNew details of book\n";
			cout<<"\n\n==========================================================\n";
			cout<<"\n\nBOOK NO.\tBOOK NAME\t\t\tAUTHOR\n";
			cout<<"\n==========================================================\n";
			cout<<"\n\n"<<b[bno-1].bkno<<"\t"<<b[bno-1].bknm<<"\t"<<b[bno-1].author<<endl;
		}
	
		else
			cout<<"\n\nNO RECORD FOUND !!!\n";
	
		cout<<"\n\nDo you want to modify another book ? (Y/N) : ";
		cin>>r8;
	}
	
	admin();
}

void del_book()
{
	char r9='y';
	
	while(r9=='Y'||r9=='y')
	{
		login();
		cout<<"\n**************     BOOK DELETION     *****************\n\n";
		long bno;
		int j;
		cout<<"\n\nEnter book number to be deleted : ";
		cin>>bno;

		if((b[bno-1].bkno)!=0)		
		{
			cout<<"\n================================================================================\n";
			cout<<"\n\nBOOK NO.\tBOOK NAME\t\t\tAUTHOR\n";
			cout<<"\n\n================================================================================\n";
			cout<<"\n"<<b[bno-1].bkno<<"\t"<<b[bno-1].bknm<<"\t"<<b[bno-1].author<<"\n\n";
	
			for(j=bno-1;j<i;j++)
			{
				b[j].bknm = b[j+1].bknm ;
				b[j].author = b[j+1].author ;
				b[j].doi=b[j+1].doi;
				b[j].mbissue.mbnm = b[j+1].mbissue.mbnm ;
				b[j].mbissue.addr = b[j+1].mbissue.addr ;
				b[j].mbissue.mbno = b[j+1].mbissue.mbno;
			}
	
			i--;
			cout<<"\n\nBOOK RECORD DELETED SUCCESSFULLY !!!\n";
		}
		
		else
			cout<<"\n\nNO RECORD EXISTS !!!\n";
	
		cout<<"\n\n--------------------------------------------------------------\n\n";
		cout<<"\n\nDo you want to delete another book ? (Y/N) : ";
		cin>>r9;
	}
	
admin();
}

void login()
{
	cout<<"\n----------------------------------------------------------\n";	
	cout<<"                   YMCA LIBRARY                     \n";
	cout<<"----------------------------------------------------------\n";
	cout<<"\nTotal number of books in library (max. 50 books) : "<<i<<"\n\n";
}

void startup()
{
	int x;
	double y;
	char str[]="LIBRARY MANAGEMENT SYSTEM";
	cout<<"\n\n\n\n\n\n\n\n\n";
	cout<<"Made By :\t"<<"Pathikrit Pal\n"<<endl;
	cout<<"\n\n\n\n\n\n\n\t\tPress any key to continue\n";
	d=1;
}

int welcome()
{
	int r5;
	cout<<endl;
	cout<<"\t1. Book issue\n\n";
	cout<<"\t2. Book deposit\n\n";
	cout<<"\t3. Administrator menu\n\n";
	cout<<"\t4. Exit\n\n";
	cout<<"----------------------------------------------------------\n\n";
	cout<<"\n\tPLEASE SELECT YOUR OPTION (1-4) : ";
	cin>>r5;
	return(r5);
}

void bkissue()
{
	char r4='y';
	long bno;
	
	while(r4=='y'||r4=='Y')
	{
		login();
		cout<<"\n**************     BOOK ISSUE COUNTER     ****************\n\n";
		cout<<"\n\n\tEnter book number to be issued : ";
		cin>>bno;
		
		if(b[bno-1].bkno==0)
			cout<<"\n\n\tNO RECORD EXISTS !!!\n";

		else if(b[bno-1].mbissue.mbno!=0)
			cout<<"\n\n\tBOOK ISSUED ALREADY !!!\n";

		else
		{
			cout<<"\n\n==========================================================\n";
			cout<<"\n\nBOOK NO.\tBOOK NAME\tAUTHOR\n";
			cout<<"\n==========================================================\n";
			cout<<"\n"<<b[bno-1].bkno<<"\t"<<b[bno-1].bknm<<"\t"<<b[bno-1].author<<"\n\n";
			cout<<"\n==========================================================\n";
			cout<<"\n\n\tEnter membership number : ";
			cin>>b[bno-1].mbissue.mbno;
			cout<<"\n\tEnter member name : ";
			cin>>b[bno-1].mbissue.mbnm;
			cout<<"\n\tEnter member address : ";
			cin>>b[bno-1].mbissue.addr;
			cout<<"\n\tEnter date of issue (ddmmyy) : ";
			cin>>b[bno-1].doi;
			cout<<"\n\n\tBOOK ISSUED SUCCESSFULLY !!!\n";
			cout<<"\n\n\nPLEASE NOTE : Write current date on backside of book and submit within 15 days .\nFINE OF Rs. 1 FOR EACH DAY AFTER 15 DAYS PERIOD";
		}

		cout<<"\n\n\n----------------------------------------------------------\n";
		cout<<"\n\n\tDO YOU WANT TO ISSUE ANOTHER BOOK(Y/N) : ";
		cin>>r4;
	}
	main();
}

void bkreturn()
{
	
	//START :
	
		char r3='y';

	while(r3=='y'||r3=='Y')
	{
		login();	
		int j,k=0;
		long dor,bookno,mno;
		cout<<"\n**************     BOOK RETURN COUNTER    ****************\n";
		cout<<"\n\n\tEnter membership number : ";
		cin>>mno;
		
		for(j=0;j<i;j++)
		{
			if(b[j].mbissue.mbno==mno)
			{
				k++;
				cout<<"\n\n\tBOOK NO.\tNAME OF BOOK\tDATE OF ISSUE\n";
				cout<<"\n\t"<<b[j].bkno<<"\t"<<b[j].bknm<<"\t"<<b[j].doi<<"\n";
			}
		}
	
		if(k>0)	
		{
			cout<<"\n\n\tEnter book number to return : ";
			cin>>bookno;

			if(b[bookno-1].mbissue.mbno==mno)
			{
				b[bookno-1].mbissue.mbnm = "";
				b[bookno-1].mbissue.addr = "";
				b[bookno-1].mbissue.mbno = 0;
				cout<<"\n\n\tEnter number of days after which book is deposited : ";
				cin>>dor;
			
				if(dor>15)
					cout<<"\n\n\tFINE : Rs. "<<dor-15;
		
				b[bookno-1].doi=0;
				cout<<"\n\n\n\n\tBOOK RETURNED SUCCESSFULLY !!!\n";
			}
			
			else
			{
				cout<<"\n\n\tBOOK NOT ISSUED BY MEMBER NUMBER "<<mno<<" !!!\n";
				cout<<"\n\n\tPLEASE WAIT WHILE SYSTEM RE-INITIALISES .....\n";
				//for(double g=0;g<=999999999;g++);
				//	goto START;
			}
		}

		else
			cout<<"\n\n\tNO BOOK ISSUED !!!\n";
			
	cout<<"\n\n----------------------------------------------------------\n";
	cout<<"\n\n\tDO YOU WANT TO RETURN ANOTHER BOOK(Y/N) : ";
	cin>>r3;
	}
	
main();
}

void admin()
{
	login();
	cout<<"\n**************     ADMINISTRATOR MENU    *****************\n";
	int r2;
	cout<<"\n\n\t1.Create book";
	cout<<"\n\n\t2.Display all books ";
	cout<<"\n\n\t3.Display specific book ";
	cout<<"\n\n\t4.Modify book ";
	cout<<"\n\n\t5.Delete book ";
	cout<<"\n\n\t6.Back to main menu";
	cout<<"\n\n\tPlease Enter Your Choice (1-6) :  ";
	cin>>r2;

	switch(r2)	
	{
		case 1:	
			create_book();
			break;
	
		case 2:
			display_allb();
			break;
		
		case 3:
			display_spb();
			break;
		
		case 4:
			modify_book();
			break;
		
		case 5:
			del_book();
			break;
		
		case 6:
			main();
			break;
		
		default:
			cout<<"\a";
			admin();
	}
}

int main()
{
	if(d==0)	
		startup();

	int r1=0;
	login();
	r1=welcome();
	
	switch(r1)
	{
		case 1:
			bkissue();
			break;
		
		case 2:
			bkreturn();
			break;

		case 3:
			admin();
			break;

		case 4:
			cout<<"***************THANK YOU !!!!!****************";
			break;

		default:
			cout<<"\a";
	}
}
