#include<iostream>
using namespace std;

#define numberofusers 20     /*you can change the number of users as you like*/
#define numberofbooks 10     /*you can change the number of books as you like*/

struct librarian
{
	string name, password;
};

librarian librarian_information[4];

void function1()
{
	for (int i = 0; i < 4; i++)
	{
		cout << "Please enter the new username of the librarian number " << i + 1 << " : ";
		cin >> librarian_information[i].name;
		cout << "Please enter the new password of the librarian number " << i + 1 << " : ";
		cin >> librarian_information[i].password;
	}
}

struct user
{
	string ID, name, email, password, accounttype;
	int contacts[3], creationdate[3];
};

user user_information[numberofusers];
int u1 = 0;
void function2()
{
	while (true)
	{
		string username, password, condition;
		cout << "Enter the credential username and password. \n";
		cout << "Username: ";
		cin >> username;
		cout << "Password: ";
		cin >> password;
		int flag = 0;
		for (int i = 0; i < 4; i++)
		{
			if (username == librarian_information[i].name && password == librarian_information[i].password)
			{
				flag = 1;
				cout << "Please enter the user's ID: ";
				cin >> user_information[u1].ID;
				cout << "Please enter the user's name: ";
				cin >> user_information[u1].name;
				cout << "Please enter the user's E-mail: ";
				cin >> user_information[u1].email;
				cout << "Please enter the user's password: ";
				cin >> user_information[u1].password;
				cout << "Please enter the user's account type(Student/Stuff/Guest): ";
				cin >> user_information[u1].accounttype;
				if (user_information[u1].accounttype != "Student" && user_information[u1].accounttype != "student" && user_information[u1].accounttype != "STUDENT" &&
					user_information[u1].accounttype != "Stuff" && user_information[u1].accounttype != "stuff" && user_information[u1].accounttype != "STUFF" &&
					user_information[u1].accounttype != "Guest" && user_information[u1].accounttype != "guest" && user_information[u1].accounttype != "GUEST")
				{
					cout << "Invalid account type. \n";
					break;
				}
				cout << "Please enter the user's account creation date(day - month(in numbers) - year). \n";
				cout << "Day: ";
				cin >> user_information[u1].creationdate[0];
				cout << "month: ";
				cin >> user_information[u1].creationdate[1];
				cout << "year: ";
				cin >> user_information[u1].creationdate[2];
				if (user_information[u1].creationdate[0] <= 31 && user_information[u1].creationdate[0] >= 1 && user_information[u1].creationdate[1] <= 12 && user_information[u1].creationdate[1] >= 1 && user_information[u1].creationdate[2] <= 2020)
				{
					if (user_information[u1].creationdate[1] == 4 || user_information[u1].creationdate[1] == 6 || user_information[u1].creationdate[1] == 9 || user_information[u1].creationdate[1] == 11)   /*this mounths contain only 30 days*/
					{
						if (user_information[u1].creationdate[0] == 31)
						{
							cout << "Invalid date, please try again. \n";
						}
					}
					else if (user_information[u1].creationdate[1] == 2 && user_information[u1].creationdate[2] % 4 == 0 && user_information[u1].creationdate[0] > 29)   /*the years that it's module 4 = 0 , february will be 29 days*/
					{
						cout << "Invalid date, please try again. \n";
						break;
					}
					else if (user_information[u1].creationdate[1] == 2 && user_information[u1].creationdate[2] % 4 != 0 && user_information[u1].creationdate[0] > 28)
					{
						cout << "Invalid date, please try again. \n";
						break;
					}
					else
					{
						cout << "Please enter the user's set of contact numbers(maximum three). \n";
						int t = 0;
						while (true)
						{
							cout << "Please enter the user's contact number: ";
							cin >> user_information[u1].contacts[t];
							if (t >= 2)
							{
								break;
							}
							cout << "Do you want to add more contact number? (y/n) ";
							cin >> condition;
							if (condition == "n" || condition == "N")
							{
								break;
							}
							if (condition != "y" && condition != "Y")
							{
								cout << "Invalid answer. \n";
								break;
							}
							t++;
						}
					}
				}
				else
				{
					cout << "Invalid date, please try again. \n";
					break;
				}
				u1++;
			}
			if (flag == 1)
			{
				break;
			}
		}
		if (flag == 0)
		{
			cout << "Invalid username or password, Please try again. \n";
		}
		else
		{
			break;
		}
	}
}

struct book
{
	string title, category, edition;
	int production_year, numberofcopies;
};

book book_information[numberofbooks];
int u2 = 0;
void function3()
{
	cout << "Please enter the title of the book: ";
	cin >> book_information[u2].title;
	cout << "Please enter the production year of the book: ";
	cin >> book_information[u2].production_year;
	cout << "Please enter the number of copies of the book: ";
	cin >> book_information[u2].numberofcopies;
	cout << "Please enter the category of the book: ";
	cin >> book_information[u2].category;
	cout << "Please enter the edition of the book: ";
	cin >> book_information[u2].edition;
	u2++;
}

void function4()
{
	char search_character;
	string search_title;
	int search_production_year, test__title = 0, test__productionyear = 0;
	cout << "Do you want to search for a book by it's title or production year? (t/p): ";
	cin >> search_character;
	if (search_character == 't' || search_character == 'T')
	{
		cout << "Enter the title of the book: ";
		cin >> search_title;
		for (int i = 0; i < numberofbooks; i++)
		{
			if (search_title == book_information[i].title)
			{
				test__title = 1;
				cout << "The production year of this book is " << book_information[i].production_year << endl;
				cout << "The number of copies of this book is " << book_information[i].numberofcopies << endl;
				cout << "The category of this book is " << book_information[i].category << endl;
				cout << "The edition of this book is " << book_information[i].edition << endl;
			}
		}
		if (test__title == 0)
		{
			cout << "There is no book it's title " << search_title << ". \n";
		}
	}
	else if (search_character == 'p' || search_character == 'P')
	{
		cout << "Enter the production year of the book: ";
		cin >> search_production_year;
		for (int i = 0; i < numberofbooks; i++)
		{
			if (search_production_year == book_information[i].production_year)
			{
				test__productionyear = 1;
				cout << "The title of this book is " << book_information[i].title << endl;
				cout << "The numberofcopies of this book is " << book_information[i].numberofcopies << endl;
				cout << "The category of this book is " << book_information[i].category << endl;
				cout << "The edition of this book is " << book_information[i].edition << endl;
			}
		}
		if (test__productionyear == 0)
		{
			cout << "There is no book it's production year " << search_production_year << ". \n";
		}
	}
	else
	{
		cout << "Invalid answer. \n";
	}
}

void function5()
{
	string buyusername, buyemail, buypassword, buytitle;
	cout << "Please enter your username, e-mail and password. \n";
	cout << "Usernamse: ";
	cin >> buyusername;
	cout << "E-mail: ";
	cin >> buyemail;
	cout << "Password: ";
	cin >> buypassword;
	for (int i = 0; i < numberofusers; i++)
	{
		if (buyusername == user_information[i].name && buyemail == user_information[i].email && buypassword == user_information[i].password)
		{
			if (user_information[i].accounttype == "Stuff" || user_information[i].accounttype == "stuff" || user_information[i].accounttype == "STUFF")
			{
				cout << "Please enter the title of the book you want to buy: ";
				cin >> buytitle;
				for (int i = 0; i < numberofbooks; i++)
				{
					if (buytitle == book_information[i].title)
					{
						if (book_information[i].numberofcopies >= 2)
						{
							cout << "Your request for buy this book was accepted. \n";
							book_information[i].numberofcopies--;
						}
						else
						{
							cout << "Sorry your request for buy this book was rejected because this is the only copy of this book in the library. \n";
						}
					}
				}
			}
			else
			{
				cout << "Sorry your request for buy this book was rejected because you are not a stuff member in the library. \n";
			}
		}
		else
		{
			cout << "Sorry your request for buy this book was rejected because you are not a user(member) in the library. \n";
		}
	}
}

void function6()
{
	int todayday, todaymonth, todayyear;
	cout << "Please enter today's date(day - month(in numbers) - year). \n";
	cout << "Day: ";
	cin >> todayday;
	cout << "month: ";
	cin >> todaymonth;
	cout << "year: ";
	cin >> todayyear;
	cout << endl;
	if (todayday <= 31 && todayday >= 1 && todaymonth <= 12 && todaymonth >= 1 && todayyear <= 2020)
	{
		if (todaymonth == 4 || todaymonth == 6 || todaymonth == 9 || todaymonth == 11)   /*this months contain only 30 days*/
		{
			if (todayday == 31)
			{
				cout << "Invalid date, please try again. \n";
			}
		}
		else if (todaymonth == 2 && todayyear % 4 == 0 && todayday > 29)   /*the years that it's module 4 = 0 , february will be 29 days*/
		{
			cout << "Invalid date, please try again. \n";
		}
		else if (todaymonth == 2 && todayyear % 4 != 0 && todayday > 28)
		{
			cout << "Invalid date, please try again. \n";
		}
		else
		{
			cout << "The information of the new users whose accounts were created within the last 7 days: \n \n";
			if (todayday >= 8)
			{
				int todayday2 = todayday - 7;
				for (int i = 0; i < numberofusers; i++)
				{
					if (todayday > user_information[i].creationdate[0] && todayday2 <= user_information[i].creationdate[0] && todaymonth == user_information[i].creationdate[1] && todayyear == user_information[i].creationdate[2])
					{
						cout << "The information of the user number " << i + 1 << " : \n";
						cout << "The user's name: " << user_information[i].name << endl;
						cout << "The user's ID: " << user_information[i].ID << endl;
						cout << "The user's E-mail: " << user_information[i].email << endl;
						/*cout << "The user's password: " << user_information[i].password;*/
						cout << "The user's account type: " << user_information[i].accounttype;
						cout << "The user's creation date: " << user_information[i].creationdate[0] << "/" << user_information[i].creationdate[1] << "/" << user_information[i].creationdate[2] << endl;
						cout << "The user's set of contacs: \n" << user_information[i].contacts[0] << endl << user_information[i].contacts[1] << endl << user_information[i].contacts[2] << endl << endl;
					}
				}
			}
			else if (todayday < 8)
			{
				if (todaymonth == 2 || todaymonth == 4 || todaymonth == 6 || todaymonth == 8 || todaymonth == 9 || todaymonth == 11)        /*the mounth before these mounths contains 31 days*/
				{
					if (todayday == 1)
					{
						for (int i = 0; i < numberofusers; i++)
						{
							for (int k = 31; k >= 25; k--)
							{
								if (user_information[i].creationdate[0] == k && user_information[i].creationdate[1] == todaymonth - 1 && user_information[i].creationdate[2] == todayyear)
								{
									cout << "The information of the user number " << i + 1 << " : \n";
									cout << "The user's name: " << user_information[i].name << endl;
									cout << "The user's ID: " << user_information[i].ID << endl;
									cout << "The user's E-mail: " << user_information[i].email << endl;
									/*cout << "The user's password: " << user_information[i].password << endl;*/
									cout << "The user's account type: " << user_information[i].accounttype << endl;
									cout << "The user's account creation date: " << user_information[i].creationdate[0] << "/" << user_information[i].creationdate[1] << "/" << user_information[i].creationdate[2] << endl;
									cout << "The user's set of contacs: \n" << user_information[i].contacts[0] << endl << user_information[i].contacts[1] << endl << user_information[i].contacts[2] << endl << endl;
								}
							}
						}
					}
					else if (todayday == 2)
					{
						for (int i = 0; i < numberofusers; i++)
						{
							if (user_information[i].creationdate[0] == 1 && user_information[i].creationdate[1] == todaymonth && user_information[i].creationdate[2] == todayyear)
							{
								cout << "The information of the user number " << i + 1 << " : \n";
								cout << "The user's name: " << user_information[i].name << endl;
								cout << "The user's ID: " << user_information[i].ID << endl;
								cout << "The user's E-mail: " << user_information[i].email << endl;
								/*cout << "The user's password: " << user_information[i].password << endl;*/
								cout << "The user's account type: " << user_information[i].accounttype << endl;
								cout << "The user's account creation date: " << user_information[i].creationdate[0] << "/" << user_information[i].creationdate[1] << "/" << user_information[i].creationdate[2] << endl;
								cout << "The user's set of contacs: \n" << user_information[i].contacts[0] << endl << user_information[i].contacts[1] << endl << user_information[i].contacts[2] << endl << endl;
							}
							for (int k = 31; k >= 26; k--)
							{
								if (user_information[i].creationdate[0] == k && user_information[i].creationdate[1] == todaymonth - 1 && user_information[i].creationdate[2] == todayyear)
								{
									cout << "The information of the user number " << i + 1 << " : \n";
									cout << "The user's name: " << user_information[i].name << endl;
									cout << "The user's ID: " << user_information[i].ID << endl;
									cout << "The user's E-mail: " << user_information[i].email << endl;
									/*cout << "The user's password: " << user_information[i].password << endl;*/
									cout << "The user's account type: " << user_information[i].accounttype << endl;
									cout << "The user's account creation date: " << user_information[i].creationdate[0] << "/" << user_information[i].creationdate[1] << "/" << user_information[i].creationdate[2] << endl;
									cout << "The user's set of contacs: \n" << user_information[i].contacts[0] << endl << user_information[i].contacts[1] << endl << user_information[i].contacts[2] << endl << endl;
								}
							}
						}
					}
					else if (todayday == 3)
					{
						for (int i = 0; i < numberofusers; i++)
						{
							for (int k = 1; k <= 2; k++)
							{
								if (user_information[i].creationdate[0] == k && user_information[i].creationdate[1] == todaymonth && user_information[i].creationdate[2] == todayyear)
								{
									cout << "The information of the user number " << i + 1 << " : \n";
									cout << "The user's name: " << user_information[i].name << endl;
									cout << "The user's ID: " << user_information[i].ID << endl;
									cout << "The user's E-mail: " << user_information[i].email << endl;
									/*cout << "The user's password: " << user_information[i].password << endl;*/
									cout << "The user's account type: " << user_information[i].accounttype << endl;
									cout << "The user's account creation date: " << user_information[i].creationdate[0] << "/" << user_information[i].creationdate[1] << "/" << user_information[i].creationdate[2] << endl;
									cout << "The user's set of contacs: \n" << user_information[i].contacts[0] << endl << user_information[i].contacts[1] << endl << user_information[i].contacts[2] << endl << endl;
								}
							}
							for (int k = 31; k >= 27; k--)
							{
								if (user_information[i].creationdate[0] == k && user_information[i].creationdate[1] == todaymonth - 1 && user_information[i].creationdate[2] == todayyear)
								{
									cout << "The information of the user number " << i + 1 << " : \n";
									cout << "The user's name: " << user_information[i].name << endl;
									cout << "The user's ID: " << user_information[i].ID << endl;
									cout << "The user's E-mail: " << user_information[i].email << endl;
									/*cout << "The user's password: " << user_information[i].password << endl;*/
									cout << "The user's account type: " << user_information[i].accounttype << endl;
									cout << "The user's account creation date: " << user_information[i].creationdate[0] << "/" << user_information[i].creationdate[1] << "/" << user_information[i].creationdate[2] << endl;
									cout << "The user's set of contacs: \n" << user_information[i].contacts[0] << endl << user_information[i].contacts[1] << endl << user_information[i].contacts[2] << endl << endl;
								}
							}
						}
					}
					else if (todayday == 4)
					{
						for (int i = 0; i < numberofusers; i++)
						{
							for (int k = 1; k <= 3; k++)
							{
								if (user_information[i].creationdate[0] == k && user_information[i].creationdate[1] == todaymonth && user_information[i].creationdate[2] == todayyear)
								{
									cout << "The information of the user number " << i + 1 << " : \n";
									cout << "The user's name: " << user_information[i].name << endl;
									cout << "The user's ID: " << user_information[i].ID << endl;
									cout << "The user's E-mail: " << user_information[i].email << endl;
									/*cout << "The user's password: " << user_information[i].password << endl;*/
									cout << "The user's account type: " << user_information[i].accounttype << endl;
									cout << "The user's account creation date: " << user_information[i].creationdate[0] << "/" << user_information[i].creationdate[1] << "/" << user_information[i].creationdate[2] << endl;
									cout << "The user's set of contacs: \n" << user_information[i].contacts[0] << endl << user_information[i].contacts[1] << endl << user_information[i].contacts[2] << endl << endl;
								}
							}
							for (int k = 31; k >= 28; k--)
							{
								if (user_information[i].creationdate[0] == k && user_information[i].creationdate[1] == todaymonth - 1 && user_information[i].creationdate[2] == todayyear)
								{
									cout << "The information of the user number " << i + 1 << " : \n";
									cout << "The user's name: " << user_information[i].name << endl;
									cout << "The user's ID: " << user_information[i].ID << endl;
									cout << "The user's E-mail: " << user_information[i].email << endl;
									/*cout << "The user's password: " << user_information[i].password << endl;*/
									cout << "The user's account type: " << user_information[i].accounttype << endl;
									cout << "The user's account creation date: " << user_information[i].creationdate[0] << "/" << user_information[i].creationdate[1] << "/" << user_information[i].creationdate[2] << endl;
									cout << "The user's set of contacs: \n" << user_information[i].contacts[0] << endl << user_information[i].contacts[1] << endl << user_information[i].contacts[2] << endl << endl;
								}
							}
						}
					}
					else if (todayday == 5)
					{
						for (int i = 0; i < numberofusers; i++)
						{
							for (int k = 1; k <= 4; k++)
							{
								if (user_information[i].creationdate[0] == k && user_information[i].creationdate[1] == todaymonth && user_information[i].creationdate[2] == todayyear)
								{
									cout << "The information of the user number " << i + 1 << " : \n";
									cout << "The user's name: " << user_information[i].name << endl;
									cout << "The user's ID: " << user_information[i].ID << endl;
									cout << "The user's E-mail: " << user_information[i].email << endl;
									/*cout << "The user's password: " << user_information[i].password << endl;*/
									cout << "The user's account type: " << user_information[i].accounttype << endl;
									cout << "The user's account creation date: " << user_information[i].creationdate[0] << "/" << user_information[i].creationdate[1] << "/" << user_information[i].creationdate[2] << endl;
									cout << "The user's set of contacs: \n" << user_information[i].contacts[0] << endl << user_information[i].contacts[1] << endl << user_information[i].contacts[2] << endl << endl;
								}
							}
							for (int k = 31; k >= 29; k--)
							{
								if (user_information[i].creationdate[0] == k && user_information[i].creationdate[1] == todaymonth - 1 && user_information[i].creationdate[2] == todayyear)
								{
									cout << "The information of the user number " << i + 1 << " : \n";
									cout << "The user's name: " << user_information[i].name << endl;
									cout << "The user's ID: " << user_information[i].ID << endl;
									cout << "The user's E-mail: " << user_information[i].email << endl;
									/*cout << "The user's password: " << user_information[i].password << endl;*/
									cout << "The user's account type: " << user_information[i].accounttype << endl;
									cout << "The user's account creation date: " << user_information[i].creationdate[0] << "/" << user_information[i].creationdate[1] << "/" << user_information[i].creationdate[2] << endl;
									cout << "The user's set of contacs: \n" << user_information[i].contacts[0] << endl << user_information[i].contacts[1] << endl << user_information[i].contacts[2] << endl << endl;
								}
							}
						}
					}
					else if (todayday == 6)
					{
						for (int i = 0; i < numberofusers; i++)
						{
							for (int k = 1; k <= 5; k++)
							{
								if (user_information[i].creationdate[0] == k && user_information[i].creationdate[1] == todaymonth && user_information[i].creationdate[2] == todayyear)
								{
									cout << "The information of the user number " << i + 1 << " : \n";
									cout << "The user's name: " << user_information[i].name << endl;
									cout << "The user's ID: " << user_information[i].ID << endl;
									cout << "The user's E-mail: " << user_information[i].email << endl;
									/*cout << "The user's password: " << user_information[i].password << endl;*/
									cout << "The user's account type: " << user_information[i].accounttype << endl;
									cout << "The user's account creation date: " << user_information[i].creationdate[0] << "/" << user_information[i].creationdate[1] << "/" << user_information[i].creationdate[2] << endl;
									cout << "The user's set of contacs: \n" << user_information[i].contacts[0] << endl << user_information[i].contacts[1] << endl << user_information[i].contacts[2] << endl << endl;
								}
							}
							for (int k = 31; k >= 30; k--)
							{
								if (user_information[i].creationdate[0] == k && user_information[i].creationdate[1] == todaymonth - 1 && user_information[i].creationdate[2] == todayyear)
								{
									cout << "The information of the user number " << i + 1 << " : \n";
									cout << "The user's name: " << user_information[i].name << endl;
									cout << "The user's ID: " << user_information[i].ID << endl;
									cout << "The user's E-mail: " << user_information[i].email << endl;
									/*cout << "The user's password: " << user_information[i].password << endl;*/
									cout << "The user's account type: " << user_information[i].accounttype << endl;
									cout << "The user's account creation date: " << user_information[i].creationdate[0] << "/" << user_information[i].creationdate[1] << "/" << user_information[i].creationdate[2] << endl;
									cout << "The user's set of contacs: \n" << user_information[i].contacts[0] << endl << user_information[i].contacts[1] << endl << user_information[i].contacts[2] << endl << endl;
								}
							}
						}
					}
					else if (todayday == 7)
					{
						for (int i = 0; i < numberofusers; i++)
						{
							for (int k = 1; k <= 6; k++)
							{
								if (user_information[i].creationdate[0] == k && user_information[i].creationdate[1] == todaymonth && user_information[i].creationdate[2] == todayyear)
								{
									cout << "The information of the user number " << i + 1 << " : \n";
									cout << "The user's name: " << user_information[i].name << endl;
									cout << "The user's ID: " << user_information[i].ID << endl;
									cout << "The user's E-mail: " << user_information[i].email << endl;
									/*cout << "The user's password: " << user_information[i].password << endl;*/
									cout << "The user's account type: " << user_information[i].accounttype << endl;
									cout << "The user's account creation date: " << user_information[i].creationdate[0] << "/" << user_information[i].creationdate[1] << "/" << user_information[i].creationdate[2] << endl;
									cout << "The user's set of contacs: \n" << user_information[i].contacts[0] << endl << user_information[i].contacts[1] << endl << user_information[i].contacts[2] << endl << endl;
								}
							}

							if (user_information[i].creationdate[0] == 31 && user_information[i].creationdate[1] == todaymonth - 1 && user_information[i].creationdate[2] == todayyear)
							{
								cout << "The information of the user number " << i + 1 << " : \n";
								cout << "The user's name: " << user_information[i].name << endl;
								cout << "The user's ID: " << user_information[i].ID << endl;
								cout << "The user's E-mail: " << user_information[i].email << endl;
								/*cout << "The user's password: " << user_information[i].password << endl;*/
								cout << "The user's account type: " << user_information[i].accounttype << endl;
								cout << "The user's account creation date: " << user_information[i].creationdate[0] << "/" << user_information[i].creationdate[1] << "/" << user_information[i].creationdate[2] << endl;
								cout << "The user's set of contacs: \n" << user_information[i].contacts[0] << endl << user_information[i].contacts[1] << endl << user_information[i].contacts[2] << endl << endl;
							}
						}
					}
				}
				else if (todaymonth == 5 || todaymonth == 7 || todaymonth == 10 || todaymonth == 12)      /*the month before these months contains 30 days*/
				{
					if (todayday == 1)
					{
						for (int i = 0; i < numberofusers; i++)
						{
							for (int k = 30; k >= 24; k--)
							{
								if (user_information[i].creationdate[0] == k && user_information[i].creationdate[1] == todaymonth - 1 && user_information[i].creationdate[2] == todayyear)
								{
									cout << "The information of the user number " << i + 1 << " : \n";
									cout << "The user's name: " << user_information[i].name << endl;
									cout << "The user's ID: " << user_information[i].ID << endl;
									cout << "The user's E-mail: " << user_information[i].email << endl;
									/*cout << "The user's password: " << user_information[i].password << endl;*/
									cout << "The user's account type: " << user_information[i].accounttype << endl;
									cout << "The user's account creation date: " << user_information[i].creationdate[0] << "/" << user_information[i].creationdate[1] << "/" << user_information[i].creationdate[2] << endl;
									cout << "The user's set of contacs: \n" << user_information[i].contacts[0] << endl << user_information[i].contacts[1] << endl << user_information[i].contacts[2] << endl << endl;
								}
							}
						}
					}
					else if (todayday == 2)
					{
						for (int i = 0; i < numberofusers; i++)
						{
							if (user_information[i].creationdate[0] == 1 && user_information[i].creationdate[1] == todaymonth && user_information[i].creationdate[2] == todayyear)
							{
								cout << "The information of the user number " << i + 1 << " : \n";
								cout << "The user's name: " << user_information[i].name << endl;
								cout << "The user's ID: " << user_information[i].ID << endl;
								cout << "The user's E-mail: " << user_information[i].email << endl;
								/*cout << "The user's password: " << user_information[i].password << endl;*/
								cout << "The user's account type: " << user_information[i].accounttype << endl;
								cout << "The user's account creation date: " << user_information[i].creationdate[0] << "/" << user_information[i].creationdate[1] << "/" << user_information[i].creationdate[2] << endl;
								cout << "The user's set of contacs: \n" << user_information[i].contacts[0] << endl << user_information[i].contacts[1] << endl << user_information[i].contacts[2] << endl << endl;
							}
							for (int k = 30; k >= 25; k--)
							{
								if (user_information[i].creationdate[0] == k && user_information[i].creationdate[1] == todaymonth - 1 && user_information[i].creationdate[2] == todayyear)
								{
									cout << "The information of the user number " << i + 1 << " : \n";
									cout << "The user's name: " << user_information[i].name << endl;
									cout << "The user's ID: " << user_information[i].ID << endl;
									cout << "The user's E-mail: " << user_information[i].email << endl;
									/*cout << "The user's password: " << user_information[i].password << endl;*/
									cout << "The user's account type: " << user_information[i].accounttype << endl;
									cout << "The user's account creation date: " << user_information[i].creationdate[0] << "/" << user_information[i].creationdate[1] << "/" << user_information[i].creationdate[2] << endl;
									cout << "The user's set of contacs: \n" << user_information[i].contacts[0] << endl << user_information[i].contacts[1] << endl << user_information[i].contacts[2] << endl << endl;
								}
							}
						}
					}
					else if (todayday == 3)
					{
						for (int i = 0; i < numberofusers; i++)
						{
							for (int k = 1; k <= 2; k++)
							{
								if (user_information[i].creationdate[0] == k && user_information[i].creationdate[1] == todaymonth && user_information[i].creationdate[2] == todayyear)
								{
									cout << "The information of the user number " << i + 1 << " : \n";
									cout << "The user's name: " << user_information[i].name << endl;
									cout << "The user's ID: " << user_information[i].ID << endl;
									cout << "The user's E-mail: " << user_information[i].email << endl;
									/*cout << "The user's password: " << user_information[i].password << endl;*/
									cout << "The user's account type: " << user_information[i].accounttype << endl;
									cout << "The user's account creation date: " << user_information[i].creationdate[0] << "/" << user_information[i].creationdate[1] << "/" << user_information[i].creationdate[2] << endl;
									cout << "The user's set of contacs: \n" << user_information[i].contacts[0] << endl << user_information[i].contacts[1] << endl << user_information[i].contacts[2] << endl << endl;
								}
							}
							for (int k = 30; k >= 26; k--)
							{
								if (user_information[i].creationdate[0] == k && user_information[i].creationdate[1] == todaymonth - 1 && user_information[i].creationdate[1] == todayyear)
								{
									cout << "The information of the user number " << i + 1 << " : \n";
									cout << "The user's name: " << user_information[i].name << endl;
									cout << "The user's ID: " << user_information[i].ID << endl;
									cout << "The user's E-mail: " << user_information[i].email << endl;
									/*cout << "The user's password: " << user_information[i].password << endl;*/
									cout << "The user's account type: " << user_information[i].accounttype << endl;
									cout << "The user's account creation date: " << user_information[i].creationdate[0] << "/" << user_information[i].creationdate[1] << "/" << user_information[i].creationdate[2] << endl;
									cout << "The user's set of contacs: \n" << user_information[i].contacts[0] << endl << user_information[i].contacts[1] << endl << user_information[i].contacts[2] << endl << endl;
								}
							}
						}
					}
					else if (todayday == 4)
					{
						for (int i = 0; i < numberofusers; i++)
						{
							for (int k = 1; k <= 3; k++)
							{
								if (user_information[i].creationdate[0] == k && user_information[i].creationdate[1] == todaymonth && user_information[i].creationdate[2] == todayyear)
								{
									cout << "The information of the user number " << i + 1 << " : \n";
									cout << "The user's name: " << user_information[i].name << endl;
									cout << "The user's ID: " << user_information[i].ID << endl;
									cout << "The user's E-mail: " << user_information[i].email << endl;
									/*cout << "The user's password: " << user_information[i].password << endl;*/
									cout << "The user's account type: " << user_information[i].accounttype << endl;
									cout << "The user's account creation date: " << user_information[i].creationdate[0] << "/" << user_information[i].creationdate[1] << "/" << user_information[i].creationdate[2] << endl;
									cout << "The user's set of contacs: \n" << user_information[i].contacts[0] << endl << user_information[i].contacts[1] << endl << user_information[i].contacts[2] << endl << endl;
								}
							}
							for (int k = 30; k >= 27; k--)
							{
								if (user_information[i].creationdate[0] == k && user_information[i].creationdate[1] == todaymonth - 1 && user_information[i].creationdate[2] == todayyear)
								{
									cout << "The information of the user number " << i + 1 << " : \n";
									cout << "The user's name: " << user_information[i].name << endl;
									cout << "The user's ID: " << user_information[i].ID << endl;
									cout << "The user's E-mail: " << user_information[i].email << endl;
									/*cout << "The user's password: " << user_information[i].password << endl;*/
									cout << "The user's account type: " << user_information[i].accounttype << endl;
									cout << "The user's account creation date: " << user_information[i].creationdate[0] << "/" << user_information[i].creationdate[1] << "/" << user_information[i].creationdate[2] << endl;
									cout << "The user's set of contacs: \n" << user_information[i].contacts[0] << endl << user_information[i].contacts[1] << endl << user_information[i].contacts[2] << endl << endl;
								}
							}
						}
					}
					else if (todayday == 5)
					{
						for (int i = 0; i < numberofusers; i++)
						{
							for (int k = 1; k <= 4; k++)
							{
								if (user_information[i].creationdate[0] == k && user_information[i].creationdate[1] == todaymonth && user_information[i].creationdate[2] == todayyear)
								{
									cout << "The information of the user number " << i + 1 << " : \n";
									cout << "The user's name: " << user_information[i].name << endl;
									cout << "The user's ID: " << user_information[i].ID << endl;
									cout << "The user's E-mail: " << user_information[i].email << endl;
									/*cout << "The user's password: " << user_information[i].password << endl;*/
									cout << "The user's account type: " << user_information[i].accounttype << endl;
									cout << "The user's account creation date: " << user_information[i].creationdate[0] << "/" << user_information[i].creationdate[1] << "/" << user_information[i].creationdate[2] << endl;
									cout << "The user's set of contacs: \n" << user_information[i].contacts[0] << endl << user_information[i].contacts[1] << endl << user_information[i].contacts[2] << endl << endl;
								}
							}
							for (int k = 30; k >= 28; k--)
							{
								if (user_information[i].creationdate[0] == k && user_information[i].creationdate[1] == todaymonth - 1 && user_information[i].creationdate[2] == todayyear)
								{
									cout << "The information of the user number " << i + 1 << " : \n";
									cout << "The user's name: " << user_information[i].name << endl;
									cout << "The user's ID: " << user_information[i].ID << endl;
									cout << "The user's E-mail: " << user_information[i].email << endl;
									/*cout << "The user's password: " << user_information[i].password << endl;*/
									cout << "The user's account type: " << user_information[i].accounttype << endl;
									cout << "The user's account creation date: " << user_information[i].creationdate[0] << "/" << user_information[i].creationdate[1] << "/" << user_information[i].creationdate[2] << endl;
									cout << "The user's set of contacs: \n" << user_information[i].contacts[0] << endl << user_information[i].contacts[1] << endl << user_information[i].contacts[2] << endl << endl;
								}
							}
						}
					}
					else if (todayday == 6)
					{
						for (int i = 0; i < numberofusers; i++)
						{
							for (int k = 1; k <= 5; k++)
							{
								if (user_information[i].creationdate[0] == k && user_information[i].creationdate[1] == todaymonth && user_information[i].creationdate[2] == todayyear)
								{
									cout << "The information of the user number " << i + 1 << " : \n";
									cout << "The user's name: " << user_information[i].name << endl;
									cout << "The user's ID: " << user_information[i].ID << endl;
									cout << "The user's E-mail: " << user_information[i].email << endl;
									/*cout << "The user's password: " << user_information[i].password << endl;*/
									cout << "The user's account type: " << user_information[i].accounttype << endl;
									cout << "The user's account creation date: " << user_information[i].creationdate[0] << "/" << user_information[i].creationdate[1] << "/" << user_information[i].creationdate[2] << endl;
									cout << "The user's set of contacs: \n" << user_information[i].contacts[0] << endl << user_information[i].contacts[1] << endl << user_information[i].contacts[2] << endl << endl;
								}
							}
							for (int k = 30; k >= 29; k--)
							{
								if (user_information[i].creationdate[0] == k && user_information[i].creationdate[1] == todaymonth - 1 && user_information[i].creationdate[2] == todayyear)
								{
									cout << "The information of the user number " << i + 1 << " : \n";
									cout << "The user's name: " << user_information[i].name << endl;
									cout << "The user's ID: " << user_information[i].ID << endl;
									cout << "The user's E-mail: " << user_information[i].email << endl;
									/*cout << "The user's password: " << user_information[i].password << endl;*/
									cout << "The user's account type: " << user_information[i].accounttype << endl;
									cout << "The user's account creation date: " << user_information[i].creationdate[0] << "/" << user_information[i].creationdate[1] << "/" << user_information[i].creationdate[2] << endl;
									cout << "The user's set of contacs: \n" << user_information[i].contacts[0] << endl << user_information[i].contacts[1] << endl << user_information[i].contacts[2] << endl << endl;
								}
							}
						}
					}
					else if (todayday == 7)
					{
						for (int i = 0; i < numberofusers; i++)
						{
							for (int k = 1; k <= 6; k++)
							{
								if (user_information[i].creationdate[0] == k && user_information[i].creationdate[1] == todaymonth && user_information[i].creationdate[2] == todayyear)
								{
									cout << "The information of the user number " << i + 1 << " : \n";
									cout << "The user's name: " << user_information[i].name << endl;
									cout << "The user's ID: " << user_information[i].ID << endl;
									cout << "The user's E-mail: " << user_information[i].email << endl;
									/*cout << "The user's password: " << user_information[i].password << endl;*/
									cout << "The user's account type: " << user_information[i].accounttype << endl;
									cout << "The user's account creation date: " << user_information[i].creationdate[0] << "/" << user_information[i].creationdate[1] << "/" << user_information[i].creationdate[2] << endl;
									cout << "The user's set of contacs: \n" << user_information[i].contacts[0] << endl << user_information[i].contacts[1] << endl << user_information[i].contacts[2] << endl << endl;
								}
							}
							if (user_information[i].creationdate[0] == 30 && user_information[i].creationdate[1] == todaymonth - 1 && user_information[i].creationdate[2] == todayyear)
							{
								cout << "The information of the user number " << i + 1 << " : \n";
								cout << "The user's name: " << user_information[i].name << endl;
								cout << "The user's ID: " << user_information[i].ID << endl;
								cout << "The user's E-mail: " << user_information[i].email << endl;
								/*cout << "The user's password: " << user_information[i].password << endl;*/
								cout << "The user's account type: " << user_information[i].accounttype << endl;
								cout << "The user's account creation date: " << user_information[i].creationdate[0] << "/" << user_information[i].creationdate[1] << "/" << user_information[i].creationdate[2] << endl;
								cout << "The user's set of contacs: \n" << user_information[i].contacts[0] << endl << user_information[i].contacts[1] << endl << user_information[i].contacts[2] << endl << endl;
							}
						}
					}
				}
				else if (todaymonth == 3)     /*the month before this month contains 28 or 29 days*/
				{
					if (todayday == 1)
					{
						for (int i = 0; i < numberofusers; i++)
						{
							if (todayyear % 4 == 0)
							{
								for (int k = 29; k >= 23; k--)
								{
									if (user_information[i].creationdate[0] == k && user_information[i].creationdate[1] == todaymonth - 1 && user_information[i].creationdate[2] == todayyear)
									{
										cout << "The information of the user number " << i + 1 << " : \n";
										cout << "The user's name: " << user_information[i].name << endl;
										cout << "The user's ID: " << user_information[i].ID << endl;
										cout << "The user's E-mail: " << user_information[i].email << endl;
										/*cout << "The user's password: " << user_information[i].password << endl;*/
										cout << "The user's account type: " << user_information[i].accounttype << endl;
										cout << "The user's account creation date: " << user_information[i].creationdate[0] << "/" << user_information[i].creationdate[1] << "/" << user_information[i].creationdate[2] << endl;
										cout << "The user's set of contacs: \n" << user_information[i].contacts[0] << endl << user_information[i].contacts[1] << endl << user_information[i].contacts[2] << endl << endl;
									}
								}
							}
							else
							{
								for (int k = 28; k >= 22; k--)
								{
									if (user_information[i].creationdate[0] == k && user_information[i].creationdate[1] == todaymonth - 1 && user_information[i].creationdate[2] == todayyear)
									{
										cout << "The information of the user number " << i + 1 << " : \n";
										cout << "The user's name: " << user_information[i].name << endl;
										cout << "The user's ID: " << user_information[i].ID << endl;
										cout << "The user's E-mail: " << user_information[i].email << endl;
										/*cout << "The user's password: " << user_information[i].password << endl;*/
										cout << "The user's account type: " << user_information[i].accounttype << endl;
										cout << "The user's account creation date: " << user_information[i].creationdate[0] << "/" << user_information[i].creationdate[1] << "/" << user_information[i].creationdate[2] << endl;
										cout << "The user's set of contacs: \n" << user_information[i].contacts[0] << endl << user_information[i].contacts[1] << endl << user_information[i].contacts[2] << endl << endl;
									}
								}
							}
						}
					}
					else if (todayday == 2)
					{
						for (int i = 0; i < numberofusers; i++)
						{
							if (user_information[i].creationdate[0] == 1 && user_information[i].creationdate[1] == todaymonth && user_information[i].creationdate[2] == todayyear)
							{
								cout << "The information of the user number " << i + 1 << " : \n";
								cout << "The user's name: " << user_information[i].name << endl;
								cout << "The user's ID: " << user_information[i].ID << endl;
								cout << "The user's E-mail: " << user_information[i].email << endl;
								/*cout << "The user's password: " << user_information[i].password << endl;*/
								cout << "The user's account type: " << user_information[i].accounttype << endl;
								cout << "The user's account creation date: " << user_information[i].creationdate[0] << "/" << user_information[i].creationdate[1] << "/" << user_information[i].creationdate[2] << endl;
								cout << "The user's set of contacs: \n" << user_information[i].contacts[0] << endl << user_information[i].contacts[1] << endl << user_information[i].contacts[2] << endl << endl;
							}
							if (todayyear % 4 == 0)
							{
								for (int k = 29; k >= 24; k--)
								{
									if (user_information[i].creationdate[0] == k && user_information[i].creationdate[1] == todaymonth - 1 && user_information[i].creationdate[2] == todayyear)
									{
										cout << "The information of the user number " << i + 1 << " : \n";
										cout << "The user's name: " << user_information[i].name << endl;
										cout << "The user's ID: " << user_information[i].ID << endl;
										cout << "The user's E-mail: " << user_information[i].email << endl;
										/*cout << "The user's password: " << user_information[i].password << endl;*/
										cout << "The user's account type: " << user_information[i].accounttype << endl;
										cout << "The user's account creation date: " << user_information[i].creationdate[0] << "/" << user_information[i].creationdate[1] << "/" << user_information[i].creationdate[2] << endl;
										cout << "The user's set of contacs: \n" << user_information[i].contacts[0] << endl << user_information[i].contacts[1] << endl << user_information[i].contacts[2] << endl << endl;
									}
								}
							}
							else
							{
								for (int k = 28; k >= 23; k--)
								{
									if (user_information[i].creationdate[0] == k && user_information[i].creationdate[1] == todaymonth - 1 && user_information[i].creationdate[2] == todayyear)
									{
										cout << "The information of the user number " << i + 1 << " : \n";
										cout << "The user's name: " << user_information[i].name << endl;
										cout << "The user's ID: " << user_information[i].ID << endl;
										cout << "The user's E-mail: " << user_information[i].email << endl;
										/*cout << "The user's password: " << user_information[i].password << endl;*/
										cout << "The user's account type: " << user_information[i].accounttype << endl;
										cout << "The user's account creation date: " << user_information[i].creationdate[0] << "/" << user_information[i].creationdate[1] << "/" << user_information[i].creationdate[2] << endl;
										cout << "The user's set of contacs: \n" << user_information[i].contacts[0] << endl << user_information[i].contacts[1] << endl << user_information[i].contacts[2] << endl << endl;
									}
								}
							}
						}
					}
					else if (todayday == 3)
					{
						for (int i = 0; i < numberofusers; i++)
						{
							for (int k = 1; k <= 2; k++)
							{
								if (user_information[i].creationdate[0] == k && user_information[i].creationdate[1] == todaymonth && user_information[i].creationdate[2] == todayyear)
								{
									cout << "The information of the user number " << i + 1 << " : \n";
									cout << "The user's name: " << user_information[i].name << endl;
									cout << "The user's ID: " << user_information[i].ID << endl;
									cout << "The user's E-mail: " << user_information[i].email << endl;
									/*cout << "The user's password: " << user_information[i].password << endl;*/
									cout << "The user's account type: " << user_information[i].accounttype << endl;
									cout << "The user's account creation date: " << user_information[i].creationdate[0] << "/" << user_information[i].creationdate[1] << "/" << user_information[i].creationdate[2] << endl;
									cout << "The user's set of contacs: \n" << user_information[i].contacts[0] << endl << user_information[i].contacts[1] << endl << user_information[i].contacts[2] << endl << endl;
								}
							}
							if (todayyear % 4 == 0)
							{
								for (int k = 29; k >= 25; k--)
								{
									if (user_information[i].creationdate[0] == k && user_information[i].creationdate[1] == todaymonth - 1 && user_information[i].creationdate[2] == todayyear)
									{
										cout << "The information of the user number " << i + 1 << " : \n";
										cout << "The user's name: " << user_information[i].name << endl;
										cout << "The user's ID: " << user_information[i].ID << endl;
										cout << "The user's E-mail: " << user_information[i].email << endl;
										/*cout << "The user's password: " << user_information[i].password << endl;*/
										cout << "The user's account type: " << user_information[i].accounttype << endl;
										cout << "The user's account creation date: " << user_information[i].creationdate[0] << "/" << user_information[i].creationdate[1] << "/" << user_information[i].creationdate[2] << endl;
										cout << "The user's set of contacs: \n" << user_information[i].contacts[0] << endl << user_information[i].contacts[1] << endl << user_information[i].contacts[2] << endl << endl;
									}
								}
							}
							else
							{
								for (int k = 28; k >= 24; k--)
								{
									if (user_information[i].creationdate[0] == k && user_information[i].creationdate[1] == todaymonth - 1 && user_information[i].creationdate[2] == todayyear)
									{
										cout << "The information of the user number " << i + 1 << " : \n";
										cout << "The user's name: " << user_information[i].name << endl;
										cout << "The user's ID: " << user_information[i].ID << endl;
										cout << "The user's E-mail: " << user_information[i].email << endl;
										/*cout << "The user's password: " << user_information[i].password << endl;*/
										cout << "The user's account type: " << user_information[i].accounttype << endl;
										cout << "The user's account creation date: " << user_information[i].creationdate[0] << "/" << user_information[i].creationdate[1] << "/" << user_information[i].creationdate[2] << endl;
										cout << "The user's set of contacs: \n" << user_information[i].contacts[0] << endl << user_information[i].contacts[1] << endl << user_information[i].contacts[2] << endl << endl;
									}
								}
							}
						}
					}
					else if (todayday == 4)
					{
						for (int i = 0; i < numberofusers; i++)
						{
							for (int k = 1; k <= 3; k++)
							{
								if (user_information[i].creationdate[0] == k && user_information[i].creationdate[1] == todaymonth && user_information[i].creationdate[2] == todayyear)
								{
									cout << "The information of the user number " << i + 1 << " : \n";
									cout << "The user's name: " << user_information[i].name << endl;
									cout << "The user's ID: " << user_information[i].ID << endl;
									cout << "The user's E-mail: " << user_information[i].email << endl;
									/*cout << "The user's password: " << user_information[i].password << endl;*/
									cout << "The user's account type: " << user_information[i].accounttype << endl;
									cout << "The user's account creation date: " << user_information[i].creationdate[0] << "/" << user_information[i].creationdate[1] << "/" << user_information[i].creationdate[2] << endl;
									cout << "The user's set of contacs: \n" << user_information[i].contacts[0] << endl << user_information[i].contacts[1] << endl << user_information[i].contacts[2] << endl << endl;
								}
							}
							if (todayyear % 4 == 0)
							{
								for (int k = 29; k >= 26; k--)
								{
									if (user_information[i].creationdate[0] == k && user_information[i].creationdate[1] == todaymonth - 1 && user_information[i].creationdate[2] == todayyear)
									{
										cout << "The information of the user number " << i + 1 << " : \n";
										cout << "The user's name: " << user_information[i].name << endl;
										cout << "The user's ID: " << user_information[i].ID << endl;
										cout << "The user's E-mail: " << user_information[i].email << endl;
										/*cout << "The user's password: " << user_information[i].password << endl;*/
										cout << "The user's account type: " << user_information[i].accounttype << endl;
										cout << "The user's account creation date: " << user_information[i].creationdate[0] << "/" << user_information[i].creationdate[1] << "/" << user_information[i].creationdate[2] << endl;
										cout << "The user's set of contacs: \n" << user_information[i].contacts[0] << endl << user_information[i].contacts[1] << endl << user_information[i].contacts[2] << endl << endl;
									}
								}
							}
							else
							{
								for (int k = 28; k >= 25; k--)
								{
									if (user_information[i].creationdate[0] == k && user_information[i].creationdate[1] == todaymonth - 1 && user_information[i].creationdate[2] == todayyear)
									{
										cout << "The information of the user number " << i + 1 << " : \n";
										cout << "The user's name: " << user_information[i].name << endl;
										cout << "The user's ID: " << user_information[i].ID << endl;
										cout << "The user's E-mail: " << user_information[i].email << endl;
										/*cout << "The user's password: " << user_information[i].password << endl;*/
										cout << "The user's account type: " << user_information[i].accounttype << endl;
										cout << "The user's account creation date: " << user_information[i].creationdate[0] << "/" << user_information[i].creationdate[1] << "/" << user_information[i].creationdate[2] << endl;
										cout << "The user's set of contacs: \n" << user_information[i].contacts[0] << endl << user_information[i].contacts[1] << endl << user_information[i].contacts[2] << endl << endl;
									}
								}
							}
						}
					}
					else if (todayday == 5)
					{
						for (int i = 0; i < numberofusers; i++)
						{
							for (int k = 1; k <= 4; k++)
							{
								if (user_information[i].creationdate[0] == k && user_information[i].creationdate[1] == todaymonth && user_information[i].creationdate[2] == todayyear)
								{
									cout << "The information of the user number " << i + 1 << " : \n";
									cout << "The user's name: " << user_information[i].name << endl;
									cout << "The user's ID: " << user_information[i].ID << endl;
									cout << "The user's E-mail: " << user_information[i].email << endl;
									/*cout << "The user's password: " << user_information[i].password << endl;*/
									cout << "The user's account type: " << user_information[i].accounttype << endl;
									cout << "The user's account creation date: " << user_information[i].creationdate[0] << "/" << user_information[i].creationdate[1] << "/" << user_information[i].creationdate[2] << endl;
									cout << "The user's set of contacs: \n" << user_information[i].contacts[0] << endl << user_information[i].contacts[1] << endl << user_information[i].contacts[2] << endl << endl;
								}
							}
							if (todayyear % 4 == 0)
							{
								for (int k = 29; k >= 27; k--)
								{
									if (user_information[i].creationdate[0] == k && user_information[i].creationdate[1] == todaymonth - 1 && user_information[i].creationdate[2] == todayyear)
									{
										cout << "The information of the user number " << i + 1 << " : \n";
										cout << "The user's name: " << user_information[i].name << endl;
										cout << "The user's ID: " << user_information[i].ID << endl;
										cout << "The user's E-mail: " << user_information[i].email << endl;
										/*cout << "The user's password: " << user_information[i].password << endl;*/
										cout << "The user's account type: " << user_information[i].accounttype << endl;
										cout << "The user's account creation date: " << user_information[i].creationdate[0] << "/" << user_information[i].creationdate[1] << "/" << user_information[i].creationdate[2] << endl;
										cout << "The user's set of contacs: \n" << user_information[i].contacts[0] << endl << user_information[i].contacts[1] << endl << user_information[i].contacts[2] << endl << endl;
									}
								}
							}
							else
							{
								for (int k = 28; k >= 26; k--)
								{
									if (user_information[i].creationdate[0] == k && user_information[i].creationdate[1] == todaymonth - 1 && user_information[i].creationdate[2] == todayyear)
									{
										cout << "The information of the user number " << i + 1 << " : \n";
										cout << "The user's name: " << user_information[i].name << endl;
										cout << "The user's ID: " << user_information[i].ID << endl;
										cout << "The user's E-mail: " << user_information[i].email << endl;
										/*cout << "The user's password: " << user_information[i].password << endl;*/
										cout << "The user's account type: " << user_information[i].accounttype << endl;
										cout << "The user's account creation date: " << user_information[i].creationdate[0] << "/" << user_information[i].creationdate[1] << "/" << user_information[i].creationdate[2] << endl;
										cout << "The user's set of contacs: \n" << user_information[i].contacts[0] << endl << user_information[i].contacts[1] << endl << user_information[i].contacts[2] << endl << endl;
									}
								}
							}
						}
					}
					else if (todayday == 6)
					{
						for (int i = 0; i < numberofusers; i++)
						{
							for (int k = 1; k <= 5; k++)
							{
								if (user_information[i].creationdate[0] == k && user_information[i].creationdate[1] == todaymonth && user_information[i].creationdate[2] == todayyear)
								{
									cout << "The information of the user number " << i + 1 << " : \n";
									cout << "The user's name: " << user_information[i].name << endl;
									cout << "The user's ID: " << user_information[i].ID << endl;
									cout << "The user's E-mail: " << user_information[i].email << endl;
									/*cout << "The user's password: " << user_information[i].password << endl;*/
									cout << "The user's account type: " << user_information[i].accounttype << endl;
									cout << "The user's account creation date: " << user_information[i].creationdate[0] << "/" << user_information[i].creationdate[1] << "/" << user_information[i].creationdate[2] << endl;
									cout << "The user's set of contacs: \n" << user_information[i].contacts[0] << endl << user_information[i].contacts[1] << endl << user_information[i].contacts[2] << endl << endl;
								}
							}
							if (todayyear % 4 == 0)
							{
								for (int k = 29; k >= 28; k--)
								{
									if (user_information[i].creationdate[0] == k && user_information[i].creationdate[1] == todaymonth - 1 && user_information[i].creationdate[2] == todayyear)
									{
										cout << "The information of the user number " << i + 1 << " : \n";
										cout << "The user's name: " << user_information[i].name << endl;
										cout << "The user's ID: " << user_information[i].ID << endl;
										cout << "The user's E-mail: " << user_information[i].email << endl;
										/*cout << "The user's password: " << user_information[i].password << endl;*/
										cout << "The user's account type: " << user_information[i].accounttype << endl;
										cout << "The user's account creation date: " << user_information[i].creationdate[0] << "/" << user_information[i].creationdate[1] << "/" << user_information[i].creationdate[2] << endl;
										cout << "The user's set of contacs: \n" << user_information[i].contacts[0] << endl << user_information[i].contacts[1] << endl << user_information[i].contacts[2] << endl << endl;
									}
								}
							}
							else
							{
								for (int k = 28; k >= 27; k--)
								{
									if (user_information[i].creationdate[0] == k && user_information[i].creationdate[1] == todaymonth - 1 && user_information[i].creationdate[2] == todayyear)
									{
										cout << "The information of the user number " << i + 1 << " : \n";
										cout << "The user's name: " << user_information[i].name << endl;
										cout << "The user's ID: " << user_information[i].ID << endl;
										cout << "The user's E-mail: " << user_information[i].email << endl;
										/*cout << "The user's password: " << user_information[i].password << endl;*/
										cout << "The user's account type: " << user_information[i].accounttype << endl;
										cout << "The user's account creation date: " << user_information[i].creationdate[0] << "/" << user_information[i].creationdate[1] << "/" << user_information[i].creationdate[2] << endl;
										cout << "The user's set of contacs: \n" << user_information[i].contacts[0] << endl << user_information[i].contacts[1] << endl << user_information[i].contacts[2] << endl << endl;
									}
								}
							}
						}
					}
					else if (todayday == 7)
					{
						for (int i = 0; i < numberofusers; i++)
						{
							for (int k = 1; k <= 6; k++)
							{
								if (user_information[i].creationdate[0] == k && user_information[i].creationdate[1] == todaymonth && user_information[i].creationdate[2] == todayyear)
								{
									cout << "The information of the user number " << i + 1 << " : \n";
									cout << "The user's name: " << user_information[i].name << endl;
									cout << "The user's ID: " << user_information[i].ID << endl;
									cout << "The user's E-mail: " << user_information[i].email << endl;
									/*cout << "The user's password: " << user_information[i].password << endl;*/
									cout << "The user's account type: " << user_information[i].accounttype << endl;
									cout << "The user's account creation date: " << user_information[i].creationdate[0] << "/" << user_information[i].creationdate[1] << "/" << user_information[i].creationdate[2] << endl;
									cout << "The user's set of contacs: \n" << user_information[i].contacts[0] << endl << user_information[i].contacts[1] << endl << user_information[i].contacts[2] << endl << endl;
								}
							}
							if (todayyear % 4 == 0)
							{
								if (user_information[i].creationdate[0] == 29 && user_information[i].creationdate[1] == todaymonth - 1 && user_information[i].creationdate[2] == todayyear)
								{
									cout << "The information of the user number " << i + 1 << " : \n";
									cout << "The user's name: " << user_information[i].name << endl;
									cout << "The user's ID: " << user_information[i].ID << endl;
									cout << "The user's E-mail: " << user_information[i].email << endl;
									/*cout << "The user's password: " << user_information[i].password << endl;*/
									cout << "The user's account type: " << user_information[i].accounttype << endl;
									cout << "The user's account creation date: " << user_information[i].creationdate[0] << "/" << user_information[i].creationdate[1] << "/" << user_information[i].creationdate[2] << endl;
									cout << "The user's set of contacs: \n" << user_information[i].contacts[0] << endl << user_information[i].contacts[1] << endl << user_information[i].contacts[2] << endl << endl;
								}
							}
							else
							{
								if (user_information[i].creationdate[0] == 28 && user_information[i].creationdate[1] == todaymonth - 1 && user_information[i].creationdate[2] == todayyear)
								{
									cout << "The information of the user number " << i + 1 << " : \n";
									cout << "The user's name: " << user_information[i].name << endl;
									cout << "The user's ID: " << user_information[i].ID << endl;
									cout << "The user's E-mail: " << user_information[i].email << endl;
									/*cout << "The user's password: " << user_information[i].password << endl;*/
									cout << "The user's account type: " << user_information[i].accounttype << endl;
									cout << "The user's account creation date: " << user_information[i].creationdate[0] << "/" << user_information[i].creationdate[1] << "/" << user_information[i].creationdate[2] << endl;
									cout << "The user's set of contacs: \n" << user_information[i].contacts[0] << endl << user_information[i].contacts[1] << endl << user_information[i].contacts[2] << endl << endl;
								}
							}
						}
					}
				}
				else if (todaymonth == 1)    /*the month before this month(the last month in the previous year) contains 31 days*/
				{
					if (todayday == 1)
					{
						for (int i = 0; i < numberofusers; i++)
						{
							for (int k = 31; k >= 25; k--)
							{
								if (user_information[i].creationdate[0] == k && user_information[i].creationdate[1] == 12 && user_information[i].creationdate[2] == todayyear - 1)
								{
									cout << "The information of the user number " << i + 1 << " : \n";
									cout << "The user's name: " << user_information[i].name << endl;
									cout << "The user's ID: " << user_information[i].ID << endl;
									cout << "The user's E-mail: " << user_information[i].email << endl;
									/*cout << "The user's password: " << user_information[i].password << endl;*/
									cout << "The user's account type: " << user_information[i].accounttype << endl;
									cout << "The user's account creation date: " << user_information[i].creationdate[0] << "/" << user_information[i].creationdate[1] << "/" << user_information[i].creationdate[2] << endl;
									cout << "The user's set of contacs: \n" << user_information[i].contacts[0] << endl << user_information[i].contacts[1] << endl << user_information[i].contacts[2] << endl << endl;
								}
							}
						}
					}
					else if (todayday == 2)
					{
						for (int i = 0; i < numberofusers; i++)
						{
							if (user_information[i].creationdate[0] == 1 && user_information[i].creationdate[1] == todaymonth && user_information[i].creationdate[2] == todayyear)
							{
								cout << "The information of the user number " << i + 1 << " : \n";
								cout << "The user's name: " << user_information[i].name << endl;
								cout << "The user's ID: " << user_information[i].ID << endl;
								cout << "The user's E-mail: " << user_information[i].email << endl;
								/*cout << "The user's password: " << user_information[i].password << endl;*/
								cout << "The user's account type: " << user_information[i].accounttype << endl;
								cout << "The user's account creation date: " << user_information[i].creationdate[0] << "/" << user_information[i].creationdate[1] << "/" << user_information[i].creationdate[2] << endl;
								cout << "The user's set of contacs: \n" << user_information[i].contacts[0] << endl << user_information[i].contacts[1] << endl << user_information[i].contacts[2] << endl << endl;
							}
							for (int k = 31; k >= 26; k--)
							{
								if (user_information[i].creationdate[0] == k && user_information[i].creationdate[1] == 12 && user_information[i].creationdate[2] == todayyear - 1)
								{
									cout << "The information of the user number " << i + 1 << " : \n";
									cout << "The user's name: " << user_information[i].name << endl;
									cout << "The user's ID: " << user_information[i].ID << endl;
									cout << "The user's E-mail: " << user_information[i].email << endl;
									/*cout << "The user's password: " << user_information[i].password << endl;*/
									cout << "The user's account type: " << user_information[i].accounttype << endl;
									cout << "The user's account creation date: " << user_information[i].creationdate[0] << "/" << user_information[i].creationdate[1] << "/" << user_information[i].creationdate[2] << endl;
									cout << "The user's set of contacs: \n" << user_information[i].contacts[0] << endl << user_information[i].contacts[1] << endl << user_information[i].contacts[2] << endl << endl;
								}
							}
						}
					}
					else if (todayday == 3)
					{
						for (int i = 0; i < numberofusers; i++)
						{
							for (int k = 1; k <= 2; k++)
							{
								if (user_information[i].creationdate[0] == k && user_information[i].creationdate[1] == todaymonth && user_information[i].creationdate[2] == todayyear)
								{
									cout << "The information of the user number " << i + 1 << " : \n";
									cout << "The user's name: " << user_information[i].name << endl;
									cout << "The user's ID: " << user_information[i].ID << endl;
									cout << "The user's E-mail: " << user_information[i].email << endl;
									/*cout << "The user's password: " << user_information[i].password << endl;*/
									cout << "The user's account type: " << user_information[i].accounttype << endl;
									cout << "The user's account creation date: " << user_information[i].creationdate[0] << "/" << user_information[i].creationdate[1] << "/" << user_information[i].creationdate[2] << endl;
									cout << "The user's set of contacs: \n" << user_information[i].contacts[0] << endl << user_information[i].contacts[1] << endl << user_information[i].contacts[2] << endl << endl;
								}
							}
							for (int k = 31; k >= 27; k--)
							{
								if (user_information[i].creationdate[0] == k && user_information[i].creationdate[1] == 12 && user_information[i].creationdate[2] == todayyear - 1)
								{
									cout << "The information of the user number " << i + 1 << " : \n";
									cout << "The user's name: " << user_information[i].name << endl;
									cout << "The user's ID: " << user_information[i].ID << endl;
									cout << "The user's E-mail: " << user_information[i].email << endl;
									/*cout << "The user's password: " << user_information[i].password << endl;*/
									cout << "The user's account type: " << user_information[i].accounttype << endl;
									cout << "The user's account creation date: " << user_information[i].creationdate[0] << "/" << user_information[i].creationdate[1] << "/" << user_information[i].creationdate[2] << endl;
									cout << "The user's set of contacs: \n" << user_information[i].contacts[0] << endl << user_information[i].contacts[1] << endl << user_information[i].contacts[2] << endl << endl;
								}
							}
						}
					}
					else if (todayday == 4)
					{
						for (int i = 0; i < numberofusers; i++)
						{
							for (int k = 1; k <= 3; k++)
							{
								if (user_information[i].creationdate[0] == k && user_information[i].creationdate[1] == todaymonth && user_information[i].creationdate[2] == todayyear)
								{
									cout << "The information of the user number " << i + 1 << " : \n";
									cout << "The user's name: " << user_information[i].name << endl;
									cout << "The user's ID: " << user_information[i].ID << endl;
									cout << "The user's E-mail: " << user_information[i].email << endl;
									/*cout << "The user's password: " << user_information[i].password << endl;*/
									cout << "The user's account type: " << user_information[i].accounttype << endl;
									cout << "The user's account creation date: " << user_information[i].creationdate[0] << "/" << user_information[i].creationdate[1] << "/" << user_information[i].creationdate[2] << endl;
									cout << "The user's set of contacs: \n" << user_information[i].contacts[0] << endl << user_information[i].contacts[1] << endl << user_information[i].contacts[2] << endl << endl;
								}
							}
							for (int k = 31; k >= 28; k--)
							{
								if (user_information[i].creationdate[0] == k && user_information[i].creationdate[1] == 12 && user_information[i].creationdate[2] == todayyear - 1)
								{
									cout << "The information of the user number " << i + 1 << " : \n";
									cout << "The user's name: " << user_information[i].name << endl;
									cout << "The user's ID: " << user_information[i].ID << endl;
									cout << "The user's E-mail: " << user_information[i].email << endl;
									/*cout << "The user's password: " << user_information[i].password << endl;*/
									cout << "The user's account type: " << user_information[i].accounttype << endl;
									cout << "The user's account creation date: " << user_information[i].creationdate[0] << "/" << user_information[i].creationdate[1] << "/" << user_information[i].creationdate[2] << endl;
									cout << "The user's set of contacs: \n" << user_information[i].contacts[0] << endl << user_information[i].contacts[1] << endl << user_information[i].contacts[2] << endl << endl;
								}
							}
						}
					}
					else if (todayday == 5)
					{
						for (int i = 0; i < numberofusers; i++)
						{
							for (int k = 1; k <= 4; k++)
							{
								if (user_information[i].creationdate[0] == k && user_information[i].creationdate[1] == todaymonth && user_information[i].creationdate[2] == todayyear)
								{
									cout << "The information of the user number " << i + 1 << " : \n";
									cout << "The user's name: " << user_information[i].name << endl;
									cout << "The user's ID: " << user_information[i].ID << endl;
									cout << "The user's E-mail: " << user_information[i].email << endl;
									/*cout << "The user's password: " << user_information[i].password << endl;*/
									cout << "The user's account type: " << user_information[i].accounttype << endl;
									cout << "The user's account creation date: " << user_information[i].creationdate[0] << "/" << user_information[i].creationdate[1] << "/" << user_information[i].creationdate[2] << endl;
									cout << "The user's set of contacs: \n" << user_information[i].contacts[0] << endl << user_information[i].contacts[1] << endl << user_information[i].contacts[2] << endl << endl;
								}
							}
							for (int k = 31; k >= 29; k--)
							{
								if (user_information[i].creationdate[0] == k && user_information[i].creationdate[1] == 12 && user_information[i].creationdate[2] == todayyear - 1)
								{
									cout << "The information of the user number " << i + 1 << " : \n";
									cout << "The user's name: " << user_information[i].name << endl;
									cout << "The user's ID: " << user_information[i].ID << endl;
									cout << "The user's E-mail: " << user_information[i].email << endl;
									/*cout << "The user's password: " << user_information[i].password << endl;*/
									cout << "The user's account type: " << user_information[i].accounttype << endl;
									cout << "The user's account creation date: " << user_information[i].creationdate[0] << "/" << user_information[i].creationdate[1] << "/" << user_information[i].creationdate[2] << endl;
									cout << "The user's set of contacs: \n" << user_information[i].contacts[0] << endl << user_information[i].contacts[1] << endl << user_information[i].contacts[2] << endl << endl;
								}
							}
						}
					}
					else if (todayday == 6)
					{
						for (int i = 0; i < numberofusers; i++)
						{
							for (int k = 1; k <= 5; k++)
							{
								if (user_information[i].creationdate[0] == k && user_information[i].creationdate[1] == todaymonth && user_information[i].creationdate[2] == todayyear)
								{
									cout << "The information of the user number " << i + 1 << " : \n";
									cout << "The user's name: " << user_information[i].name << endl;
									cout << "The user's ID: " << user_information[i].ID << endl;
									cout << "The user's E-mail: " << user_information[i].email << endl;
									/*cout << "The user's password: " << user_information[i].password << endl;*/
									cout << "The user's account type: " << user_information[i].accounttype << endl;
									cout << "The user's account creation date: " << user_information[i].creationdate[0] << "/" << user_information[i].creationdate[1] << "/" << user_information[i].creationdate[2] << endl;
									cout << "The user's set of contacs: \n" << user_information[i].contacts[0] << endl << user_information[i].contacts[1] << endl << user_information[i].contacts[2] << endl << endl;
								}
							}
							for (int k = 31; k >= 30; k--)
							{
								if (user_information[i].creationdate[0] == k && user_information[i].creationdate[1] == 12 && user_information[i].creationdate[2] == todayyear - 1)
								{
									cout << "The information of the user number " << i + 1 << " : \n";
									cout << "The user's name: " << user_information[i].name << endl;
									cout << "The user's ID: " << user_information[i].ID << endl;
									cout << "The user's E-mail: " << user_information[i].email << endl;
									/*cout << "The user's password: " << user_information[i].password << endl;*/
									cout << "The user's account type: " << user_information[i].accounttype << endl;
									cout << "The user's account creation date: " << user_information[i].creationdate[0] << "/" << user_information[i].creationdate[1] << "/" << user_information[i].creationdate[2] << endl;
									cout << "The user's set of contacs: \n" << user_information[i].contacts[0] << endl << user_information[i].contacts[1] << endl << user_information[i].contacts[2] << endl << endl;
								}
							}
						}
					}
					else if (todayday == 7)
					{
						for (int i = 0; i < numberofusers; i++)
						{
							for (int k = 1; k <= 6; k++)
							{
								if (user_information[i].creationdate[0] == k && user_information[i].creationdate[1] == todaymonth && user_information[i].creationdate[2] == todayyear)
								{
									cout << "The information of the user number " << i + 1 << " : \n";
									cout << "The user's name: " << user_information[i].name << endl;
									cout << "The user's ID: " << user_information[i].ID << endl;
									cout << "The user's E-mail: " << user_information[i].email << endl;
									/*cout << "The user's password: " << user_information[i].password << endl;*/
									cout << "The user's account type: " << user_information[i].accounttype << endl;
									cout << "The user's account creation date: " << user_information[i].creationdate[0] << "/" << user_information[i].creationdate[1] << "/" << user_information[i].creationdate[2] << endl;
									cout << "The user's set of contacs: \n" << user_information[i].contacts[0] << endl << user_information[i].contacts[1] << endl << user_information[i].contacts[2] << endl << endl;
								}
							}
							if (user_information[i].creationdate[0] == 31 && user_information[i].creationdate[1] == 12 && user_information[i].creationdate[2] == todayyear - 1)
							{
								cout << "The information of the user number " << i + 1 << " : \n";
								cout << "The user's name: " << user_information[i].name << endl;
								cout << "The user's ID: " << user_information[i].ID << endl;
								cout << "The user's E-mail: " << user_information[i].email << endl;
								/*cout << "The user's password: " << user_information[i].password << endl;*/
								cout << "The user's account type: " << user_information[i].accounttype << endl;
								cout << "The user's account creation date: " << user_information[i].creationdate[0] << "/" << user_information[i].creationdate[1] << "/" << user_information[i].creationdate[2] << endl;
								cout << "The user's set of contacs: \n" << user_information[i].contacts[0] << endl << user_information[i].contacts[1] << endl << user_information[i].contacts[2] << endl << endl;
							}
						}
					}
				}
			}
		}
	}
	else
	{
		cout << "Invalid date, please try again. \n";
	}
}

void main()
{
	string maincondition;
	int number;
	while (true)
	{
		cout << "What do you want?(1/2/3/4/5/6): \n";
		cout << "1. Create the 4 accounts of the librarians. \n";
		cout << "2. Create account for a new user. \n";
		cout << "3. Add information for a new book. \n";
		cout << "4. Search for a book. \n";
		cout << "5. Buy book(only for staff members). \n";
		cout << "6. Show this week's report. \n";
		cin >> number;
		if (number == 1)
		{
			function1();

		}
		else if (number == 2)
		{
			function2();

		}
		else if (number == 3)
		{
			function3();

		}
		else if (number == 4)
		{
			function4();

		}
		else if (number == 5)
		{
			function5();

		}
		else if (number == 6)
		{
			function6();

		}
		else
		{
			cout << "Invalid answer. \n";
		}
		cout << "Do you want anything more? (y/n): ";
		cin >> maincondition;
		if (maincondition == "n" || maincondition == "N")
		{
			break;
		}
		if (maincondition != "y" && maincondition != "Y")
		{
			cout << "Invalid answer. \n";
			break;
		}
	}
}
