#include<iostream>
#include<iomanip>
#include<fstream>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include <cstdlib>
#include <windows.h>
using namespace std;

void gotoxy(int,int);
void display();
void add();
void search();
void sort();
void del();
void modify();
void sbyname();
void sbyid();
void sbycategory();
void sbypubcom();
void sbypubyear();
void sbyauthor();
void sortas();
void sortds();
void sortasname();
void sortasid();
void sortascategory();
void sortaspubcom();
void sortaspubyear();
void sortasauthor();
void sortdsname();
void sortdsid();
void sortdscategory();
void sortdspubcom();
void sortdspubyear();
void sortdsauthor();
void dbyname();
void dbyid();
void dbycategory();
void dbypubcom();
void dbypubyear();
void dbyauthor();
void mbyname();
void mbyid();
void mbycategory();
void mbypubcom();
void mbypubyear();
void mbyauthor();

struct book
{
    int id;
    char name[100];
    char author[100];
    char category[40];
    char pubCompany[100];
    char pubMonth[10];
    int pubYear;
};

book books[1000]; //array of structures
int n=0;

void gotoxy(int x,int y)
{
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void display()
{
	system("cls");
	cout<< "You are currently in the DISPLAY function\n";
	cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
	cout<<setw(10)<<"\"Book ID\""<<setw(50)<<"\"Book Name\""<<setw(30)<<"\"Author Name\""<<setw(30)<<"\"Category\""<<setw(30)<<"\"Publication\""<<setw(30)<<"\"Month of Publication\""<<setw(30)<<"\"Year of Publication\""<<endl;
	cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
	for(int i=0;i<n;i++)
	{
        cout<<setw(10)<<books[i].id<<setw(50)<<books[i].name<<setw(30)<<books[i].author<<setw(30)<<books[i].category<<setw(30)<<books[i].pubCompany<<setw(30)<<books[i].pubMonth<<setw(30)<<books[i].pubYear<<endl;
		cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
	}
	cout<<"Press ENTER to return to the Main Menu";
	getch();
}

void add()
{
	char ch;
    char id1[6],year[4];
	do
	{
        system("cls");
		cout<<endl;
		cout<< "You are currently in the ADD Function\n";
		cout<<"Enter Book Name: ";
		gets(books[n].name);
		cout<<"Enter Book ID: ";
		gets(id1);
		books[n].id=atoi(id1);
		cout<<"Enter Author Name: ";
		gets(books[n].author);
		cout<<"Enter Book Category: ";
		gets(books[n].category);
		cout<<"Enter Publication Company Name: ";
		gets(books[n].pubCompany);
		cout<<"Enter Publication Month: ";
		gets(books[n].pubMonth);
		cout<<"Enter Publication Year: ";
		gets(year);
		books[n].pubYear=atoi(year);
		n++;
		cout<<"Do you want to add more books? [Y/N]";
		ch=getch();
	}while(ch!='n'&& ch!='N');
}

//search
void search(void)
{
    system("cls");
	cout <<setw(30)<< "You are currently in the SEARCH Function"<<endl
    << setw( 52 )<< "Please choose one of the options below: "
    << endl << setw( 71 )
    << "--------------------------------------------------------------"
    << endl << endl
    << setw( 31 ) << "( N ) Search by Name" << endl << endl
    << setw( 29 ) << "( I ) Search by ID" << endl << endl
    << setw( 38 ) << "( T ) Search by Author" << endl << endl
    << setw( 35 ) << "( C ) Search by Category" << endl << endl
    << setw( 46 ) << "( P ) Search by Publication Company" << endl << endl
    << setw( 43 ) << "( Y ) Search by Publication Year" << endl << endl
	<<setw( 32 ) << "Enter Option      [ ]" << endl << endl;
	gotoxy(30,16);
	switch(getche())
    {
        case 'n':
		case 'N':
         sbyname();
         break;
		case 'i':
		case 'I':
         sbyid();
         break;
		case 't':
		case 'T':
         sbyauthor();
         break;
		case 'c':
		case 'C':
         sbycategory();
         break;
		case 'p':
		case 'P':
         sbypubcom();
         break;
		case 'y':
		case 'Y':
         sbypubyear();
         break;
        default:
		 puts("\n\n \t\tSelect only from the given menu\n \t\tPress enter to go back to the main menu");
		 getch();
		 search();
		 getch();
       }
}

//search by name
void sbyname(void)
{
    char name[60];
	int loc,found=0;
	system("cls");
	cout<<endl;
	cout<<"You are currently searching by the name of the book\n";
	cout<<"Enter the name of book you want to search: ";
	gets(name);
	for(int i = 0;i<n;i++)
	{
		if(strcmp(books[i].name,name)==0)
		{
			loc=i;
			found = 1;
			cout<< "Record Found!"<<endl;
			cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
			cout<<setw(10)<<"\"Book ID\""<<setw(50)<<"\"Book Name\""<<setw(30)<<"\"Author Name\""<<setw(30)<<"\"Category\""<<setw(30)<<"\"Publication\""<<setw(30)<<"\"Month of Publication\""<<setw(30)<<"\"Year of Publication\""<<endl;
			cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
			cout<<setw(10)<<books[loc].id<<setw(50)<<books[loc].name<<setw(30)<<books[loc].author<<setw(30)<<books[loc].category<<setw(30)<<books[loc].pubCompany<<setw(30)<<books[loc].pubMonth<<setw(30)<<books[loc].pubYear<<endl;
			cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
		}
	}
	if(found == 0)
		cout<<"Record not Found"<<endl;
	cout<<"Press ENTER to return to the Main MENU";
	getch();
}

//search by author
void sbyauthor(void)
{
    char author[60];
	int loc,found=0;
	system("cls");
	cout<<endl;
	cout<<"You are currently searching by the author of the book\n";
	cout<<"Enter the name of the author of the book you want to search: ";
	gets(author);
	for(int i = 0;i<n;i++)
	{
		if(strcmp(books[i].author,author)==0)
		{
			loc=i;
			found = 1;
			cout<< "Record Found!"<<endl;
			cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
			cout<<setw(10)<<"\"Book ID\""<<setw(50)<<"\"Book Name\""<<setw(30)<<"\"Author Name\""<<setw(30)<<"\"Category\""<<setw(30)<<"\"Publication\""<<setw(30)<<"\"Month of Publication\""<<setw(30)<<"\"Year of Publication\""<<endl;
			cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
			cout<<setw(10)<<books[loc].id<<setw(50)<<books[loc].name<<setw(30)<<books[loc].author<<setw(30)<<books[loc].category<<setw(30)<<books[loc].pubCompany<<setw(30)<<books[loc].pubMonth<<setw(30)<<books[loc].pubYear<<endl;
			cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
		}
	}
	if(found == 0)
		cout<<"Record not Found"<<endl;
	cout<<"Press ENTER to return to the Main Menu";
	getch();
}

//search by id
void sbyid(void)
	{
		char ids[6];
		int id, loc,found=0;
		system("cls");
		cout<<endl;
		cout<<"You are currently searching by the ID of the book\n";
		cout<<"Enter the ID of the book you want to search: ";
		gets(ids);
		id=atoi(ids);
		for(int i = 0;i<n;i++)
		{
			if(books[i].id==id)
			{
				loc=i;
				found = 1;
				cout<< "Record Found!"<<endl;
				cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
				cout<<setw(10)<<"\"Book ID\""<<setw(50)<<"\"Book Name\""<<setw(30)<<"\"Author Name\""<<setw(30)<<"\"Category\""<<setw(30)<<"\"Publication\""<<setw(30)<<"\"Month of Publication\""<<setw(30)<<"\"Year of Publication\""<<endl;
				cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
				cout<<setw(10)<<books[loc].id<<setw(50)<<books[loc].name<<setw(30)<<books[loc].author<<setw(30)<<books[loc].category<<setw(30)<<books[loc].pubCompany<<setw(30)<<books[loc].pubMonth<<setw(30)<<books[loc].pubYear<<endl;
				cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
			}
		}
		if(found == 0)
			cout<<"Record not Found"<<endl;
		cout<<"Press ENTER to return to the Main Menu";
		getch();
	}

//search by category
void sbycategory()
{
    char category[60];
	int loc,found=0;
	system("cls");
	cout<<endl;
	cout<<"You are currently searching by the category of the book\n";
	cout<<"Enter the category of the book you want to search: ";
	gets(category);
	for(int i = 0;i<n;i++)
	{
		if(strcmp(books[i].category,category)==0)
		{
			loc=i;
			found = 1;
			cout<< "Record Found!"<<endl;
			cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
			cout<<setw(10)<<"\"Book ID\""<<setw(50)<<"\"Book Name\""<<setw(30)<<"\"Author Name\""<<setw(30)<<"\"Category\""<<setw(30)<<"\"Publication\""<<setw(30)<<"\"Month of Publication\""<<setw(30)<<"\"Year of Publication\""<<endl;
			cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
			cout<<setw(10)<<books[loc].id<<setw(50)<<books[loc].name<<setw(30)<<books[loc].author<<setw(30)<<books[loc].category<<setw(30)<<books[loc].pubCompany<<setw(30)<<books[loc].pubMonth<<setw(30)<<books[loc].pubYear<<endl;
			cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
		}
	}
	if(found == 0)
		cout<<"Record not Found"<<endl;
	cout<<"Press ENTER to return to the Main Menu";
	getch();
}

//search by pubCompany
void sbypubcom()
{
    char company[60];
	int loc,found=0;
	system("cls");
	cout<<endl;
	cout<<"You are currently searching by the publication company of the book\n";
	cout<<"Enter the publication company of the book you want to search: ";
	gets(company);
    for(int i = 0;i<n;i++)
	{
		if(strcmp(books[i].pubCompany,company)==0)
		{
            loc=i;
			found = 1;
			cout<< "Record Found!"<<endl;
			cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
			cout<<setw(10)<<"\"Book ID\""<<setw(50)<<"\"Book Name\""<<setw(30)<<"\"Author Name\""<<setw(30)<<"\"Category\""<<setw(30)<<"\"Publication\""<<setw(30)<<"\"Month of Publication\""<<setw(30)<<"\"Year of Publication\""<<endl;
			cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
			cout<<setw(10)<<books[loc].id<<setw(50)<<books[loc].name<<setw(30)<<books[loc].author<<setw(30)<<books[loc].category<<setw(30)<<books[loc].pubCompany<<setw(30)<<books[loc].pubMonth<<setw(30)<<books[loc].pubYear<<endl;
			cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
        }
	}
	if(found == 0)
		cout<<"Record not Found"<<endl;
	cout<<"Press ENTER to return to the Main Menu";
	getch();
}

//search by pubYear
void sbypubyear()
{
    char year[4];
	int yr,loc,found=0;
	system("cls");
	cout<<endl;
	cout<<"You are currently searching by the year of publication of the book\n";
	cout<<"Enter the year of publication of the book you want to search: ";
	gets(year);
	yr=atoi(year);
	for(int i = 0;i<n;i++)
	{
		if(books[i].pubYear==yr)
		{
			loc=i;
			found = 1;
			cout<< "Record Found!"<<endl;
			cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
			cout<<setw(10)<<"\"Book ID\""<<setw(50)<<"\"Book Name\""<<setw(30)<<"\"Author Name\""<<setw(30)<<"\"Category\""<<setw(30)<<"\"Publication\""<<setw(30)<<"\"Month of Publication\""<<setw(30)<<"\"Year of Publication\""<<endl;
			cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
			cout<<setw(10)<<books[loc].id<<setw(50)<<books[loc].name<<setw(30)<<books[loc].author<<setw(30)<<books[loc].category<<setw(30)<<books[loc].pubCompany<<setw(30)<<books[loc].pubMonth<<setw(30)<<books[loc].pubYear<<endl;
			cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
		}
	}
	if(found == 0)
		cout<<"Record not Found"<<endl;
	cout<<"Press ENTER to return to the Main Menu";
	getch();
}

void sort()
{
    system("cls");
	cout <<setw( 27 )<< "You are currently in the SORT Function"<<endl
    << setw( 52 )<< "Please choose one of the options below: "
    << endl << setw( 71 )
    << "--------------------------------------------------------------"
    << endl << endl
    << setw( 40 ) << "( A ) Sort in Ascending Order" << endl << endl
    << setw( 41 ) << "( D ) Sort in Descending Order" << endl << endl
    <<setw( 32 ) << "Enter Option      [ ]" << endl << endl;
	gotoxy(30,8);
	switch(getche())
    {
        case 'a':
		case 'A':
         sortas();
         break;
		case 'd':
		case 'D':
         sortds();
         break;
        default:
		 puts("\n\n \t\tSelect only from the given menu\n \t\tPress enter to go back to the main menu");
		 getch();
		 sort();
		 getch();
       }
}

//sort in ascending order
void sortas()
{
	system("cls");
	cout <<setw( 27 )<< "You are currently in the ASCENDING SORT Function"<<endl
    << setw( 52 )<< "Please choose one of the options below: "
    << endl << setw( 71 )
    << "--------------------------------------------------------------"
    << endl << endl
    << setw( 29 ) << "( N ) Sort by Name" << endl << endl
    << setw( 27 ) << "( I ) Sort by ID" << endl << endl
    << setw( 36 ) << "( T ) Sort by Author" << endl << endl
    << setw( 33 ) << "( C ) Sort by Category" << endl << endl
    << setw( 44 ) << "( P ) Sort by Publication Company" << endl << endl
    << setw( 41 ) << "( Y ) Sort by Publication Year" << endl << endl
	<<setw( 32 ) << "Enter Option      [ ]" << endl << endl;
	gotoxy(30,16);
	switch(getche())
    {
        case 'n':
		case 'N':
         sortasname();
         break;
		case 'i':
		case 'I':
         sortasid();
         break;
		case 't':
		case 'T':
         sortasauthor();
         break;
		case 'c':
		case 'C':
         sortascategory();
         break;
		case 'p':
		case 'P':
         sortaspubcom();
         break;
		case 'y':
		case 'Y':
         sortaspubyear();
         break;
        default:
		 puts("\n\n \t\tSelect only from the given menu\n \t\tPress enter to go back to the main menu");
		 getch();
		 sortas();
		 getch();
    }
}

//sort in desending order

void sortds()
{
    system("cls");
	cout <<setw( 27 )<< "You are currently in the DESCENDING SORT Function"<<endl
    << setw( 52 )<< "Please choose one of the options below: "
    << endl << setw( 71 )
    << "--------------------------------------------------------------"
    << endl << endl
    << setw( 29 ) << "( N ) Sort by Name" << endl << endl
    << setw( 27 ) << "( I ) Sort by ID" << endl << endl
    << setw( 36 ) << "( T ) Sort by Author" << endl << endl
    << setw( 33 ) << "( C ) Sort by Category" << endl << endl
    << setw( 44 ) << "( P ) Sort by Publication Company" << endl << endl
    << setw( 41 ) << "( Y ) Sort by Publication Year" << endl << endl
	<<setw( 32 ) << "Enter Option      [ ]" << endl << endl;
	gotoxy(30,16);
    switch(getche())
    {
        case 'n':
		case 'N':
         sortdsname();
         break;

		case 'i':
		case 'I':
         sortdsid();
         break;

		case 't':
	    case 'T':
         sortdsauthor();
         break;

		case 'c':
		case 'C':
         sortdscategory();
         break;

		case 'p':
		case 'P':
         sortdspubcom();
         break;

		case 'y':
		case 'Y':
         sortdspubyear();
         break;

        default:
		 puts("\n\n \t\tSelect only from the given menu\n \t\tPress enter to go back to the main menu");
		 getch();
		 sortds();
		 getch();
    }
}

//sort in ascending order by id
void sortasid()
{
    int i,j;
    book temp;
    system("cls");
    cout<<endl;
    cout<< "Sorting in Ascending Order by ID\n";
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(books[j].id>books[j+1].id)
            {
                temp = books[j];
                books[j]=books[j+1];
                books[j+1]=temp;
            }
        }
    }
    display();
}

//sort in descending order by id
void sortdsid()
{
    int i,j;
    book temp;
    system("cls");
    cout<<endl;
    cout<< "Sorting in Descending Order by ID\n";
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(books[j].id<books[j+1].id)
            {
                temp = books[j];
                books[j]=books[j+1];
                books[j+1]=temp;
            }
        }
    }
    display();
}

//sort in ascending order by year
void sortaspubyear()
{
    int i,j;
    book temp;
    system("cls");
    cout<<endl;
    cout<< "Sorting in Ascending Order by Publishing Year\n";
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(books[j].pubYear>books[j+1].pubYear)
            {
                temp = books[j];
                books[j]=books[j+1];
                books[j+1]=temp;
            }
        }
    }
    display();
}

//sort in descending order by year
void sortdspubyear()
{
    int i,j;
    book temp;
    system("cls");
    cout<<endl;
    cout<< "Sorting in Descending Order by Publishing Year\n";
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(books[j].pubYear<books[j+1].pubYear)
            {
                temp = books[j];
                books[j]=books[j+1];
                books[j+1]=temp;
            }
        }
    }
    display();
	}

//sort in ascending order by name
void sortasname()
{
    int i,j;
    book temp;
    system("cls");
    cout<<endl;
    cout<< "Sorting in Ascending Order by Name\n";
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(strcmp(books[j].name,books[j+1].name)>0)
            {
                temp = books[j];
                books[j]=books[j+1];
                books[j+1]=temp;
            }
        }
    }
    display();
}

//sort in descending order by name
void sortdsname()
{
    int i,j;
    book temp;
    system("cls");
    cout<<endl;
    cout<< "Sorting in Descending Order by Name\n";
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(strcmp(books[j].name,books[j+1].name)<0)
            {
                temp = books[j];
                books[j]=books[j+1];
                books[j+1]=temp;
            }
        }
    }
    display();
}

//sort in ascending order by author
void sortasauthor()
{
    int i,j;
    book temp;
    system("cls");
    cout<<endl;
    cout<< "Sorting in Ascending Order by Author\n";
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(strcmp(books[j].author,books[j+1].author)>0)
            {
                temp = books[j];
                books[j]=books[j+1];
                books[j+1]=temp;
            }
        }
    }
    display();
}

//sort in descending order by author
void sortdsauthor()
{
    int i,j;
    book temp;
    system("cls");
    cout<<endl;
    cout<< "Sorting in Descending Order by Author\n";
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(strcmp(books[j].author,books[j+1].author)<0)
            {
                temp = books[j];
                books[j]=books[j+1];
                books[j+1]=temp;
            }
        }
    }
    display();
}

//sort in ascending order by category
void sortascategory()
	{
		int i,j;
		book temp;
		system("cls");
		cout<<endl;
		cout<< "Sorting in Ascending Order by Category\n";
		for(i=0;i<n;i++)
		{
			for(j=0;j<n-i-1;j++)
			{
				if(strcmp(books[j].category,books[j+1].category)>0)
				{
					temp = books[j];
					books[j]=books[j+1];
					books[j+1]=temp;
				}
			}
		}
		display();
	}

//sort in descending order by category
void sortdscategory(void)
{
    int i,j;
    book temp;
    system("cls");
    cout<<endl;
    cout<< "Sorting in Descending Order by Category\n";
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(strcmp(books[j].category,books[j+1].category)<0)
            {
                temp = books[j];
                books[j]=books[j+1];
                books[j+1]=temp;
            }
        }
    }
    display();
}

//sort in ascending order by company
void sortaspubcom()
{
    int i,j;
    book temp;
    system("cls");
    cout<<endl;
    cout<< "Sorting in Ascending Order by Publication Company\n";
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(strcmp(books[j].pubCompany,books[j+1].pubCompany)>0)
            {
                temp = books[j];
                books[j]=books[j+1];
                books[j+1]=temp;
            }
        }
    }
    display();
}

//Sort in descending order by company
void sortdspubcom(void)
{
    int i,j;
    book temp;
    system("cls");
    cout<<endl;
    cout<< "Sorting in Descending Order by Publication Company\n";
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(strcmp(books[j].pubCompany,books[j+1].pubCompany)<0)
            {
                temp = books[j];
                books[j]=books[j+1];
                books[j+1]=temp;
            }
        }
    }
    display();
}

//delete
void del(void)
	{
		system("cls");

	   cout <<setw( 29 )<< "You are currently in the DELETE Function"<<endl
       << setw( 52 )<< "Please choose one of the options below: "
       << endl << setw( 71 )
       << "--------------------------------------------------------------"
       << endl << endl
       << setw( 31 ) << "( N ) Delete by name" << endl << endl
       << setw( 29 ) << "( I ) Delete by Id" << endl << endl
       << setw( 38 ) << "( T ) Delete by author name" << endl << endl
       << setw( 35 ) << "( C ) Delete by Category" << endl << endl
       << setw( 46 ) << "( P ) Delete by Publication Company" << endl << endl
       << setw( 43 ) << "( Y ) Delete by Publication Year" << endl << endl
       <<setw( 32 ) << "Enter Option      [ ]" << endl << endl;
       gotoxy(30,16);
       switch(getche())
       {
        case 'n':
		case 'N':
         dbyname();
         break;
		case 'i':
		case 'I':
         dbyid();
         break;
		case 't':
		case 'T':
         dbyauthor();
         break;
		case 'c':
		case 'C':
         dbycategory();break;
		case 'p':
		case 'P':
         dbypubcom();break;
		case 'y':
		case 'Y':
         dbypubyear();break;
        default:
		 puts("\n\n \t\tSelect only from the given menu.....\n\t\tPress enter to select again.....");
		 getch();
		 del();
		 getch();
       }
	}

//delete by name
void dbyname()
{
    char name[60];
    int loc,found=0;
    system("cls");
    cout<<endl;
    cout<<"Deleting by the name of the book\n";
    cout<<"Enter the name of book you want to delete: ";
    gets(name);
    for(int i = 0;i<n;i++)
    {
        if(strcmp(books[i].name,name)==0)
        {
            loc=i;
            found = 1;
            for (i = loc;i<n-1;i++)
            {
                books[i]=books[i+1];
            }
            n--;
        }
    }
    if(found == 0)
        cout<<"Record not Found"<<endl;
    cout<<"Press ENTER to return to the Main Menu";
    getch();
}

//delete by author
void dbyauthor()
{
    char author[60];
    int loc,found=0;
    system("cls");
    cout<<endl;
    cout<<"Deleting by the author of the book\n";
    cout<<"Enter the author of book you want to delete: ";
    gets(author);
    for(int i = 0;i<n;i++)
    {
        if(strcmp(books[i].author,author)==0)
        {
            loc=i;
            found = 1;
            for (i = loc;i<n-1;i++)
            {
                books[i]=books[i+1];
            }
            n--;
        }
    }
    if(found == 0)
        cout<<"Record not Found"<<endl;
    cout<<"Press ENTER to return to the Main Menu";
    getch();
}

//dDelete by id
void dbyid()
{
    char ids[6];
    int id, loc,found=0;
    system("cls");
    cout<<endl;
    cout<<"Deleting by the ID of book\n";
    cout<<"Enter the ID of the book you want to delete: ";
    gets(ids);
    id=atoi(ids);
    for(int i = 0;i<n;i++)
    {
        if(books[i].id==id)
        {
            loc=i;
            found = 1;
            for (i = loc;i<n-1;i++)
            {
                books[i]=books[i+1];
            }
            n--;
        }
    }
    if(found == 0)
        cout<<"Record not Found"<<endl;
    cout<<"Press ENTER to return to the Main Menu";
    getch();
}

//delete by category
void dbycategory()
{
    char category[60];
    int loc,found=0;
    system("cls");
    cout<<endl;
    cout<<"Deleting by the category of the book\n";
    cout<<"Enter the category of the book you want to delete: ";
    gets(category);
    for(int i = 0;i<n;i++)
    {
        if(strcmp(books[i].category,category)==0)
        {
            loc=i;
            found = 1;
            for (i = loc;i<n-1;i++)
            {
                books[i]=books[i+1];
            }
            n--;
        }
    }
    if(found == 0)
        cout<<"Record not Found"<<endl;
    cout<<"Press ENTER to return to the Main Menu";
    getch();
}

//delete by company
void dbypubcom()
	{
    char company[60];
    int loc,found=0;
    system("cls");
    cout<<endl;
    cout<<"Deleting by the publication company of book\n";
    cout<<"Enter the publication company of thebook you want to delete: ";
    gets(company);
    for(int i = 0;i<n;i++)
    {
        if(strcmp(books[i].pubCompany,company)==0)
        {
            loc=i;
            found = 1;
            for (i = loc;i<n-1;i++)
            {
                books[i]=books[i+1];
            }
            n--;
        }
    }
    if(found == 0)
        cout<<"Record not Found"<<endl;
    cout<<"Press ENTER to return to the Main Menu";
    getch();
}

//delete by year
void dbypubyear()
{
    char year[4];
    int yr,loc,found=0;
    system("cls");
    cout<<endl;
    cout<<"Deleting by year of publication of book\n";
    cout<<"Enter the year of publication of book you want to delete: ";
    gets(year);
    yr=atoi(year);
    for(int i = 0;i<n;i++)
    {
        if(books[i].pubYear==yr)
        {
            loc=i;
            found = 1;
            for (i = loc;i<n-1;i++)
            {
                books[i]=books[i+1];
            }
            n--;
        }
    }
    if(found == 0)
        cout<<"Record not Found"<<endl;
    cout<<"Press ENTER to return to the Main Menu";
    getch();
}

void modify()
{
	system("cls");
	cout <<setw( 29 )<< "You are currently in the MODIFY Function"<<endl
    << setw( 52 )<< "Please choose one of the options below: "
    << endl << setw( 71 )
    << "--------------------------------------------------------------"
    << endl << endl
    << setw( 31 ) << "( N ) Modify by Name" << endl << endl
    << setw( 29 ) << "( I ) Modify by ID" << endl << endl
    << setw( 38 ) << "( T ) Modify by Author" << endl << endl
    << setw( 35 ) << "( C ) Modify by Category" << endl << endl
    << setw( 46 ) << "( P ) Modify by Publication Company" << endl << endl
    << setw( 43 ) << "( Y ) Modify by Publication Year" << endl << endl
    <<setw( 32 ) << "Enter Option      [ ]" << endl << endl;
	gotoxy(30,16);
	switch(getche())
    {
        case 'n':
        case 'N':
         mbyname();
         break;
        case 'i':
        case 'I':
         mbyid();
         break;
        case 't':
        case 'T':
         mbyauthor();
         break;
        case 'c':
        case 'C':
         mbycategory();
         break;
        case 'p':
        case 'P':
         mbypubcom();
         break;
        case 'y':
        case 'Y': mbypubyear();break;
        default:
         puts("\n\n \t\tSelect only from the given menu\n \t\tPress enter to go back to the main menu");
         getch();
         modify();
         getch();
    }
}

//modify by name
void mbyname()
	{
		char name[60];
		int loc,found=0;
		system("cls");
		cout<<endl;
		cout<<"Modifying by the name of the book\n";
		cout<<"Enter the name of the book you want to modify: ";
		gets(name);
		for(int i = 0;i<n;i++)
		{
			if(strcmp(books[i].name,name)==0)
			{
				loc=i;
				found = 1;
				char ch;char id1[6],year[4];
				system("cls");
				cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
				cout<<setw(10)<<"\"Book ID\""<<setw(50)<<"\"Book Name\""<<setw(30)<<"\"Author Name\""<<setw(30)<<"\"Category\""<<setw(30)<<"\"Publication\""<<setw(30)<<"\"Month of Publication\""<<setw(30)<<"\"Year of Publication\""<<endl;
				cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
				cout<<setw(10)<<books[loc].id<<setw(50)<<books[loc].name<<setw(30)<<books[loc].author<<setw(30)<<books[loc].category<<setw(30)<<books[loc].pubCompany<<setw(30)<<books[loc].pubMonth<<setw(30)<<books[loc].pubYear<<endl;
				cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
				cout<<endl;
				cout<< "In Modify function\n";
				cout<<"Enter new Book Name: ";
				gets(books[loc].name);
				cout<<"MODIFIED!"<<endl;
		}
		if(found == 0)
			cout<<"Record not Found"<<endl;
		cout<<"Press ENTER to return to the Main Menu";
		getch();
		}
	}

//modify by author
void mbyauthor()
{
    char author[60];
    int loc,found=0;
    system("cls");
    cout<<endl;
    cout<<"Modifying by the author of the book\n";
    cout<<"Enter the name of the author of the book you want to modify: ";
    gets(author);
    for(int i = 0;i<n;i++)
    {
        if(strcmp(books[i].author,author)==0)
        {
            loc=i;
            found = 1;
            char ch;char id1[6],year[4];
            system("cls");
            cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
            cout<<setw(10)<<"\"Book ID\""<<setw(50)<<"\"Book Name\""<<setw(30)<<"\"Author Name\""<<setw(30)<<"\"Category\""<<setw(30)<<"\"Publication\""<<setw(30)<<"\"Month of Publication\""<<setw(30)<<"\"Year of Publication\""<<endl;
            cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
            cout<<setw(10)<<books[loc].id<<setw(50)<<books[loc].name<<setw(30)<<books[loc].author<<setw(30)<<books[loc].category<<setw(30)<<books[loc].pubCompany<<setw(30)<<books[loc].pubMonth<<setw(30)<<books[loc].pubYear<<endl;
            cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
            cout<<endl;
            cout<< "In Modify function\n";
            cout<<"Enter new Author Name: ";
            gets(books[loc].author);
            cout<<"MODIFIED!"<<endl;
        }
    }
    if(found == 0)
        cout<<"Record not Found"<<endl;
    cout<<"Press ENTER to return to the Main Menu";
    getch();
}

//modify by id
void mbyid()
{
    char ids[6];
    int id, loc,found=0;
    system("cls");
    cout<<endl;
    cout<<"Modifying by the ID of the book\n";
    cout<<"Enter the ID of the book you want to modify: ";
    gets(ids);
    id=atoi(ids);
    for(int i = 0;i<n;i++)
    {
        if(books[i].id==id)
        {
            loc=i;
            found = 1;
            char ch;char id1[6],year[4];
            system("cls");
            cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
            cout<<setw(10)<<"\"Book ID\""<<setw(50)<<"\"Book Name\""<<setw(30)<<"\"Author Name\""<<setw(30)<<"\"Category\""<<setw(30)<<"\"Publication\""<<setw(30)<<"\"Month of Publication\""<<setw(30)<<"\"Year of Publication\""<<endl;
            cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
            cout<<setw(10)<<books[loc].id<<setw(50)<<books[loc].name<<setw(30)<<books[loc].author<<setw(30)<<books[loc].category<<setw(30)<<books[loc].pubCompany<<setw(30)<<books[loc].pubMonth<<setw(30)<<books[loc].pubYear<<endl;
            cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
            cout<<endl;
            cout<< "In Modify function\n";
            cout<<"Enter new Book ID: ";
            gets(id1);
            books[loc].id=atoi(id1);
            //cin.ignore();
            cout<<"MODIFIED!"<<endl;
        }
    }
    if(found == 0)
        cout<<"Record not Found"<<endl;
    cout<<"Press ENTER to return to the Main Menu";
    getch();
}

//modify by category
void mbycategory()
{
    char category[60];
    int loc,found=0;
    system("cls");
    cout<<endl;
    cout<<"Modifying by the category of the book\n";
    cout<<"Enter the category of the book you want to modify: ";
    gets(category);
    for(int i = 0;i<n;i++)
    {
        if(strcmp(books[i].category,category)==0)
        {
            loc=i;
            found = 1;
            char ch;char id1[6],year[4];
            system("cls");
            cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
            cout<<setw(10)<<"\"Book ID\""<<setw(50)<<"\"Book Name\""<<setw(30)<<"\"Author Name\""<<setw(30)<<"\"Category\""<<setw(30)<<"\"Publication\""<<setw(30)<<"\"Month of Publication\""<<setw(30)<<"\"Year of Publication\""<<endl;
            cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
            cout<<setw(10)<<books[loc].id<<setw(50)<<books[loc].name<<setw(30)<<books[loc].author<<setw(30)<<books[loc].category<<setw(30)<<books[loc].pubCompany<<setw(30)<<books[loc].pubMonth<<setw(30)<<books[loc].pubYear<<endl;
            cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
            cout<<endl;
            cout<< "In Modify function\n";
            cout<<"Enter new Book Category: ";
            gets(books[loc].category);
            cout<<"MODIFIED!"<<endl;
        }
    }
    if(found == 0)
        cout<<"Record not Found"<<endl;
    cout<<"Press ENTER to return to the Main Menu";
    getch();
}

//modify by company
void mbypubcom()
{
    char company[60];
    int loc,found=0;
    system("cls");
    cout<<endl;
    cout<<"Modifying by the publication company of the book\n";
    cout<<"Enter the publication company of the book you want to modify: ";
    gets(company);
    for(int i = 0;i<n;i++)
    {
        if(strcmp(books[i].pubCompany,company)==0)
        {
            loc=i;
            found = 1;
            char ch;char id1[6],year[4];
            system("cls");
            cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
            cout<<setw(10)<<"\"Book ID\""<<setw(50)<<"\"Book Name\""<<setw(30)<<"\"Author Name\""<<setw(30)<<"\"Category\""<<setw(30)<<"\"Publication\""<<setw(30)<<"\"Month of Publication\""<<setw(30)<<"\"Year of Publication\""<<endl;
            cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
            cout<<setw(10)<<books[loc].id<<setw(50)<<books[loc].name<<setw(30)<<books[loc].author<<setw(30)<<books[loc].category<<setw(30)<<books[loc].pubCompany<<setw(30)<<books[loc].pubMonth<<setw(30)<<books[loc].pubYear<<endl;
            cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
            cout<<endl;
            cout<< "In Modify function\n";
            cout<<"Enter new Publication Company Name: ";
            gets(books[loc].pubCompany);
            cout<<"MODIFIED!"<<endl;
        }
    }
    if(found == 0)
        cout<<"Record not Found"<<endl;
    cout<<"Press ENTER to return to the Main Menu";
    getch();
}

//modify by year
void mbypubyear()
{
    char year[4];
    int yr,loc,found=0;
    system("cls");
    cout<<endl;
    cout<<"Modifying by the year of publication of the book\n";
    cout<<"Enter the year of publication of the book you want to modify: ";
    gets(year);
    yr=atoi(year);
    for(int i = 0;i<n;i++)
    {
        if(books[i].pubYear==yr)
        {
            loc=i;
            found = 1;
            char ch;char id1[6],year[4];
            system("cls");
            cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
            cout<<setw(10)<<"\"Book ID\""<<setw(50)<<"\"Book Name\""<<setw(30)<<"\"Author Name\""<<setw(30)<<"\"Category\""<<setw(30)<<"\"Publication\""<<setw(30)<<"\"Month of Publication\""<<setw(30)<<"\"Year of Publication\""<<endl;
            cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
            cout<<setw(10)<<books[loc].id<<setw(50)<<books[loc].name<<setw(30)<<books[loc].author<<setw(30)<<books[loc].category<<setw(30)<<books[loc].pubCompany<<setw(30)<<books[loc].pubMonth<<setw(30)<<books[loc].pubYear<<endl;
            cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
            cout<<endl;
            cout<< "In Modify function\n";
            cout<<"Enter new Publication Year: ";
            gets(year);
            books[loc].pubYear=atoi(year);
            cout<<"MODIFIED!"<<endl;
        }
    }
    if(found == 0)
        cout<<"Record not Found"<<endl;
    cout<<"Press ENTER to return to the Main Menu";
    getch();
}

int main()
{
    char c1;
    while(1)
    {
        system("cls");
        cout << setw( 25 ) << "-------------" << endl
        << setw( 25 ) << "| MAIN MENU |" << endl
        << setw( 25 ) << "-------------" << endl << endl
        << setw( 52 )
        << "Please choose one of the options below: "
          << endl << setw( 71 )
          << "--------------------------------------------------------------"
          << endl << endl
          << setw( 25 ) << "( A ) Add Book" << endl << endl
          << setw( 31 ) << "( O ) Sort all Books" << endl << endl
          << setw( 33 ) << "( S ) Search all Books" << endl << endl
          << setw( 33 ) << "( D ) Display all Books" << endl << endl
          << setw( 30 ) << "( T ) Delete a Book" << endl << endl
          << setw( 40 ) << "( M ) Update Book Information" << endl << endl
		  << setw( 21 ) << "( Q ) Quit" << endl << endl
		  <<setw( 32 ) << "Enter Option      [ ]" << endl << endl;
          gotoxy(30,21);

          switch(getche())
          {
              case 'a':
              case 'A':
               add();
               break;
              case 'd':
		 	  case 'D':
               display();
               break;
              case 'S':
		 	  case 's':
               search();
               break;
              case 't':
              case 'T':
               del();
               break;
		 	  case 'O':
		 	  case 'o':
               sort();
               break;
		 	  case 'm':
		 	  case 'M':
               modify();
               break;
		 	  case 'q':
		 	  case 'Q':
               exit(0);
               break;
		 	  default:
               puts("\n\n \t\tSelect only from the given menu\n \t\tPress enter to go back to the main menu");
			   getch();
       }
    }
}
