#include<iostream>
#include<Windows.h>
#include<stdlib.h>
#include<string>
using namespace std;
#define NO_OF_LIBRARIANS 4
#define NO_OF_USERS 12
#define NO_OF_BOOKS 10

struct Librarian
{
	string Username;
	string Password;
};

Librarian Librarians[NO_OF_LIBRARIANS] = { "sam_2020","Sam@2020","peter_2021","Peter@2021","omar_2022","Omar@2022","zeina_2023","Zeina@2023" };

struct Date
{
	int day, month, year;
};
struct User
{
	int ID;
	string Name;
	string Email;
	string Password;
	string AccountType;
	Date CreationDate;
	string No_of_contacts[3];
};

User Users[NO_OF_USERS] = { 0 };

struct Book
{
	string Title;
	int ProductionYear;
	int No_of_copies;
	string Category;
	string Edition;
};

Book Books[NO_OF_BOOKS];

void DisplayMainMenu();
void ValidateLibrarian(Librarian L[], int no_of_librarians, string& username);
void DisplayLibrarianMenu();
void CreateNewUsers(User U[], int no_of_users);
void AddBooks(Book B[], int no_of_books);
void DisplayBooks(Book B[], int no_of_books);
void DisplayInformation(User U[], int no_of_users, Date date);
void ValidateUser(User U[], int no_of_users, string& email);
void DisplayUserMenu();
void SearchForABook();
void SearchbyTitle(Book B[], int no_of_books, string& title);
void SearchbyYear(Book B[], int no_of_books, int& year);
void BuyBooks(User U[], int no_of_users, Book B[], int no_of_books,int& i);

int main()
{
	system("COLOR F0");
	cout << "                                                            " << endl;
	cout << "\t\t\t< < < Welcome to Library Management System > > >\t\t\t" << endl;
	cout << "\t\t\t------------------------------------------------\t\t\t" << endl;
	cout << endl << endl;
	DisplayMainMenu();
	return 0;
}

void DisplayMainMenu()
{
	cout << "\t-> Choose an option from the following to log in : " << endl;
	cout << "\t---------------------------------------------------" << endl;
	cout << "\t0.Librarian" << endl;
	cout << "\t1.User" << endl;
	cout << "\t2.Quit" << endl;
	cout << "\t--------------------------------" << endl;
	int option;
	cout << "\t-> Please enter your option : ";
	cin >> option; cout << endl;
	cout << "\t--------------------------------" << endl;
	switch (option)
	{
	case 0:
	{
		string username_of_librarian;
		cout << "\t-> Please confirm your identity" << endl;
		cout << "\t-------------------------------" << endl;
		cout << "\tEnter your username : ";
		cin >> username_of_librarian; cout << endl;
		ValidateLibrarian(Librarians, NO_OF_LIBRARIANS, username_of_librarian);
		break;
	}
	case 1:
	{
		string email_of_user;
		cout << "\t-> Please confirm your identity  " << endl;
		cout << "\t-----------------------------" << endl;
		cout << "\tEnter your email : ";
		cin >> email_of_user; cout << endl;
		ValidateUser(Users, NO_OF_USERS, email_of_user);
		cout << "\t--------------------------------" << endl;
		break;
	}
	case 2:
	{
		break;
	}
	default:
	{
		cout << "\tInvalid choice." << endl;
		cout << "\t--------------------------------" << endl;
		DisplayMainMenu();
	}
	}
}

void ValidateLibrarian(Librarian L[], int no_of_librarians, string& username)
{
	for (int i = 0; i < no_of_librarians; i++)
	{
		if (username == Librarians[i].Username)
		{
			string password_of_librarian;
			cout << "\tEnter your password : ";
			cin >> password_of_librarian;
			if (password_of_librarian == L[i].Password)
			{
				cout << endl;
				cout << "\t-----------------------------" << endl;
				cout << "\tLoged in successfully !" << endl;
				cout << "\t-------------------------------" << endl;
				DisplayLibrarianMenu();
			}
			else
			{
				cout << endl;
				cout << "\t-----------------------------" << endl;
				cout << "\tWrong Password !" << endl << endl;
				cout << "\t-----------------------------" << endl;
				cout << "\tEnter your username : ";
				cin >> username; cout << endl;
				ValidateLibrarian(L, no_of_librarians, username);
			}
		}
	}
}

void DisplayLibrarianMenu()
{
	int choice_of_librarian;
	cout << "\t-> What would you like to do ?" << endl;
	cout << "\t-----------------------------" << endl;
	cout << "\t1. Create new accounts for users." << endl;
	cout << "\t2. Add books." << endl;
	cout << "\t3. Display books." << endl;
	cout << "\t4. Display information about users whose accounts where created within the last 7 days." << endl;
	cout << "\t5. Log out." << endl;
	cout << "\t-----------------------------" << endl;
	cout << "\t-> Please enter your choice : ";
	cin >> choice_of_librarian;
	cout << endl;
	cout << "\t-----------------------------" << endl;
	switch (choice_of_librarian)
	{
	case 1:
	{
		cout << "\t-> Please enter information about 12 users" << endl;
		cout << "\t-----------------------------" << endl;
		CreateNewUsers(Users, NO_OF_USERS);
		cout << "\t-----------------------------" << endl;
		DisplayLibrarianMenu();
		break;
	}
	case 2:
	{
		cout << "\t-> PLease enter information about 10 books" << endl;
		cout << "\t-----------------------------" << endl;
		AddBooks(Books, NO_OF_BOOKS);
		cout << "\t-----------------------------" << endl;
		DisplayLibrarianMenu();
		break;
	}
	case 3:
	{
		DisplayBooks(Books, NO_OF_BOOKS);
		cout << "\t-----------------------------" << endl;
		DisplayLibrarianMenu();
		break;
	}
	case 4:
	{
		Date date;
		cout << "\tEnter the date of today : ";
		cin >> date.day; cout << " ";
		cin >> date.month; cout << " ";
		cin >> date.year; cout << endl;
		DisplayInformation(Users, NO_OF_USERS, date);
		cout << "\t-----------------------------" << endl;
		DisplayLibrarianMenu();
		break;
	}
	case 5:
	{
		cout << "\t-----------------------------" << endl;
		DisplayMainMenu();
		break;
	}
	default:
	{
		cout << "Invalid choice." << endl;
		cout << "\t-----------------------------" << endl;
		DisplayLibrarianMenu();
	}
	}
}

void CreateNewUsers(User U[], int no_of_users)
{
	for (int i = 0; i < no_of_users; i++)
	{
		cout << "\tUser #" << i + 1 << endl;
		cout << "\tEnter the ID : ";
		cin >> U[i].ID;
		cout << "\tEnter the name : ";
		cin.ignore();
		getline(cin, U[i].Name);
		cout << "\tEnter the email : ";
		cin >> U[i].Email;
		cout << "\tEnter the password : ";
		cin >> U[i].Password;
		cout << "\tEnter the account type : ";
		cin >> U[i].AccountType;
		cout << "\tEnter the creation date : ";
		cin >> U[i].CreationDate.day;  cout << " ";
		cin >> U[i].CreationDate.month;  cout << " ";
		cin >> U[i].CreationDate.year;
		cout << "\tEnter 3 contact numbers : ";
		for (int j = 0; j < 3; j++)
		{
			cin >> U[i].No_of_contacts[j];
			cout << endl << "\t\t\t\t  ";
		}
		cout << endl;
		cout << "\t-----------------------------" << endl;
	}
}

void AddBooks(Book B[], int no_of_books)
{
	for (int i = 0; i < no_of_books; i++)
	{
		cout << "\tFor book #" << i + 1 << endl;
		cout << "\tEnter the title of the book : ";
		cin >> B[i].Title;
		cout << "\tEnter the production year of the book : ";
		cin >> B[i].ProductionYear;
		cout << "\tEnter the number of copies of the book : ";
		cin >> B[i].No_of_copies;
		cout << "\tEnter the category of the book : ";
		cin >> B[i].Category;
		cout << "\tEnter the edition of the book : ";
		cin >> B[i].Edition;
		cout << "\t-----------------------------" << endl;
	}
	cout << endl;
}

void DisplayBooks(Book B[], int no_of_books)
{
	cout << "\tList of books" << endl;
	cout << "\t-----------------------------" << endl << endl;
	cout << " Title & Production Year\tNumber of Copies\tCategory\t\tEdition" << endl;
	cout << "---------------------------------------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < no_of_books; i++)
	{
		cout << i << "." << B[i].Title << " (" << B[i].ProductionYear << ")" << "\t\t" << B[i].No_of_copies << "\t\t\t" << B[i].Category << "\t\t\t" << B[i].Edition << endl;
		cout << "---------------------------------------------------------------------------------------------------------------------------------" << endl;
	}
}

void DisplayInformation(User U[], int no_of_users, Date date)
{
	cout << "---------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "\tInformation about users who were created within the last 7 days from the date entered " << endl;
	cout << "---------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << " ID\tName\t\tEmail\t\t\tPassword\tAccount Type\t\tCreation date\t\tNumber of Contacts" << endl;
	cout << "---------------------------------------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < no_of_users; i++)
	{
		if (U[i].CreationDate.day <= date.day && U[i].CreationDate.day > (date.day - 7) && date.month == U[i].CreationDate.month && date.year == U[i].CreationDate.year)
		{
			cout << U[i].ID << "\t" << U[i].Name << "\t" << U[i].Email << "\t" << U[i].Password << "\t" << U[i].AccountType
				<< "\t\t\t" << U[i].CreationDate.day << " " << U[i].CreationDate.month << " " << U[i].CreationDate.year << "\t\t";
			for (int j = 0; j < 3; j++)
			{
				cout << U[i].No_of_contacts[j] << endl << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t";
			}
			cout << endl;
			cout << "---------------------------------------------------------------------------------------------------------------------------------" << endl;
		}
	}
}

void ValidateUser(User U[], int no_of_users, string& email)
{
	for (int i = 0; i < no_of_users; i++)
	{
		if (email == U[i].Email)
		{
			string password_of_user;
			cout << "\tEnter your password : ";
			cin >> password_of_user;
			if (password_of_user == U[i].Password)
			{
				cout << endl;
				cout << "\t-----------------------------" << endl;
				cout << "\tLoged in successfully !" << endl;
				cout << "\t-------------------------------" << endl;
				DisplayUserMenu();
			}
			else
			{
				cout << endl;
				cout << "\t-----------------------------" << endl;
				cout << "\tWrong Password !" << endl << endl;
				cout << "\t-----------------------------" << endl;
				cout << "\tEnter your email : ";
				cin >> email; cout << endl;
				ValidateUser(U, no_of_users, email);
			}
		}
	}
	cout << "\tSorry, you can't log in as accounts must be created by librarians first." << endl << endl;
	DisplayMainMenu();
}
		
void DisplayUserMenu()
{
	int choice_of_user;
	cout << "\tWhat would you like to do ?" << endl;
	cout << "\t-----------------------------" << endl;
	cout << "\t0. Search for a book " << endl;
	cout << "\t1. Buy a book " << endl;
	cout << "\t2. Log out " << endl;
	cout << "\t-----------------------------" << endl;
	cout << "\t->Please enter your choice : ";
	cin >> choice_of_user;
	cout << "\t-----------------------------" << endl;
	switch (choice_of_user)
	{
	case 0:
	{
		SearchForABook();
		cout << "\t-----------------------------" << endl;
		DisplayUserMenu();
		break;
	}
	case 1:
	{
		int ID;
		cout << "\tPlease enter your ID : ";
		cin >> ID; cout << endl;
		for (int i = 0; i < NO_OF_USERS; i++)
		{
			bool isFound = true;
			if (ID == Users[i].ID)
			{
				isFound = true;
			}
			else if (ID != Users[i].ID)
			{
				isFound = false;
			}
			if (isFound)
			{
				BuyBooks(Users, NO_OF_USERS, Books, NO_OF_BOOKS,i);
				break;
			}
		}
		cout << "\t-----------------------------" << endl;
		DisplayUserMenu();
		break;
	}
	case 2:
	{
		cout << "\t-----------------------------" << endl;
		DisplayMainMenu();
		break;
	}
	default:
	{
		cout << "Invalid choice." << endl;
		cout << "\t-----------------------------" << endl;
		DisplayUserMenu();
	}
	}
}

void SearchForABook()
{
	int search_choice;
	cout << "\t-> By which way do you want to search for a book ?" << endl;
	cout << "\t-----------------------------" << endl;
	cout << "\t1. Search by Title. " << endl;
	cout << "\t2. Search by Year. " << endl;
	cout << "\t-----------------------------" << endl;
	cout << "\t-> Please enter your choice : ";
	cin >> search_choice; cout << endl;
	cout << "\t-----------------------------" << endl;
	switch (search_choice)
	{
	case 1:
	{
		string title;
		cout << "\tPlease enter the title of the book : ";
		cin >> title; cout << endl;
		SearchbyTitle(Books, NO_OF_BOOKS, title);
		break;
	}
	case 2:
	{
		int year;
		cout << "\tPlease enter the production year of the book : ";
		cin >> year; cout << endl;
		SearchbyYear(Books, NO_OF_BOOKS, year);
		break;
	}
	default:
	{
		cout << "\tInvalid choice." << endl;
		SearchForABook();
	}
	}
}

void SearchbyTitle(Book B[], int no_of_books, string& title)
{
	for(int i=0;i<no_of_books;i++)
	{
		if (title == B[i].Title)
		{
			cout << "\t-----------------------------" << endl;
			cout << "\t\tBook found ! " << endl;
			cout << "\t-----------------------------" << endl;
			cout << "\tTitle : " << B[i].Title << endl;
			cout << "\tProduction Year : " << B[i].ProductionYear << endl;
			cout << "\tCategory : " << B[i].Category << endl;
			cout << "\tEdition : " << B[i].Edition << endl;
			cout << "\t-----------------------------" << endl;
			DisplayUserMenu();
		}
	}
  cout << "\t\tBook is not found !" << endl << endl;
  DisplayUserMenu();
}

void SearchbyYear(Book B[], int no_of_books, int& year)
{
	for (int i = 0; i < no_of_books; i++)
	{
		if (year == B[i].ProductionYear)
		{
			cout << "\t-----------------------------" << endl;
			cout << "\t\tBook found ! " << endl;
			cout << "\t-----------------------------" << endl;
			cout << "\tTitle : " << B[i].Title << endl;
			cout << "\tProduction Year : " << B[i].ProductionYear << endl;
			cout << "\tCategory : " << B[i].Category << endl;
			cout << "\tEdition : " << B[i].Edition << endl;
			cout << "\t-----------------------------" << endl;
			DisplayUserMenu();
		}
	}
	cout << "\t\tBook is not found !" << endl << endl;
	DisplayUserMenu();
}

void BuyBooks(User U[], int no_of_users, Book B[], int no_of_books,int& i)
{
	if (U[i].AccountType == "Staff" || U[i].AccountType == "staff")
	{
		int index;
		int copies;
		DisplayBooks(B, no_of_books);
		cout << "\t-> Please enter the index of the book you want to buy : ";
		cin >> index; cout << endl;
		cout << "\t-> Please enter the number of copies you want : ";
		cin >> copies; cout << endl;
		if (copies <= B[index].No_of_copies && B[index].No_of_copies > 0)
		{
			cout << "\t\tPurchase complete ! " << endl;
			B[index].No_of_copies = B[index].No_of_copies - copies;
			DisplayUserMenu();
		}
		else
		{
			cout << "\t\tNo available copies ." << endl;
			DisplayUserMenu();
		}
	}
	else
	{
		cout << "\tSorry , Buying a book is not available for guests or students." << endl;
		cout << "\t-----------------------------" << endl;
		DisplayUserMenu();
	}
}
