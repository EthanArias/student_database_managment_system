#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <conio.h>
#include <stdlib.h>

struct ID {
	std::string nameofstudent;
	std::string number;
	long double gradepoint;
};

struct node {
	ID data;
	node* next;
	node* back;
};

class Studentdatabase {
public:
	Studentdatabase() { 
		first = last = NULL; 
		counter = 1; 
	};
	int construct(long int i, std::string n, std::string x, long double y) {
		if (first == NULL) {
			type = i;
			new_node = new node;
			new_node->data.nameofstudent = n;
			new_node->data.number = x;
			new_node->data.gradepoint = y;
			new_node->next = NULL;
			new_node->back = NULL;
			first = new_node;
			last = new_node;
			++counter;
			return 1;
		}
		else {
			std::cout << "You had already used the create obtion previously";
			return 0;
		};
	};
	int insertelement(std::string n, std::string x, long double y) {
		if (first != NULL) {
			switch (type) {
			case 1:
				if (first->data.nameofstudent[0] >= n[0]) {
					first->back = new_node;
					new_node->next = first;
					new_node->back = NULL;
					first = new_node;
					++counter;
					return 1;
				}
				else if (last->data.nameofstudent[0] <= n[0]) {
					last->next = new_node;
					new_node->next = NULL;
					new_node->back = last;
					last = new_node;
					++counter;
					return 1;
				}
				else {
					node* current = first;
					node* curr_next = current->next;
					for (; curr_next->next != NULL;) {
						current = current->next;
						curr_next = curr_next->next;
						if (curr_next->data.nameofstudent[0] >= n[0])
							break;
					}
					curr_next->back = new_node;
					new_node->next = curr_next;
					new_node->back = current;
					current->next = new_node;
					++current;
					return 1;
				}
				break;
			case 2:
				if (first->data.number >= x) {
					first->back = new_node;
					new_node->next = first;
					new_node->back = NULL;
					first = new_node;
					++counter;
					return 1;
				}
				else if (last->data.number <= x) {
					last->next = new_node;
					new_node->next = NULL;
					new_node->back = last;
					last = new_node;
					++counter;
					return 1;
				}
				else {
					node* current = first;
					node* curr_next = current->next;
					for (; curr_next->next != NULL;) {
						current = current->next;
						curr_next = curr_next->next;
						if (curr_next->data.number >= x)
							break;
					}
					curr_next->back = new_node;
					new_node->next = curr_next;
					new_node->back = current;
					current->next = new_node;
					++current;
					return 1;
				}
				break;
			}
		}
		else {
			std::cout << "You are requested to use the create option first " << std::endl;
			return 0;
		}
	}
	int deletelement(std::string x) {
		if (first != NULL) {
			node* del_first = first;
			node* del_last = last;
			node* del_next = del_first->next;
			node* del_back = last->back;
			if (first->data.number == x) {
				first = del_next;
				delete(del_next);
				--counter;
				return 1;
			}
			else if (last->data.number == x) {
				last = del_back;
				last->next = NULL;
				delete(del_last);
				--counter;
				return 1;
			}
			else {
				for (; del_first->next != NULL;) {
					del_first = del_first->next;
					del_back = del_first->back;
					del_next = del_first->next;

					if (del_first->data.number == x) {
						del_next->back = del_first->back;
						del_back->next = del_first->next;
						delete(del_first);
						flag = 1;
						--counter;
						return 1;
					}
				}
			}
			if (flag == 0) {
				std::cout << "Sorry the entered ID is incorrect " << std::endl;
				return 3;
			}
		}
		else {
			std::cout << "Sorry, the database is empty!!" << std::endl;
		}
	}
	void print() {
		std::cout << "Student Name\t\tStudent ID\t Net GradePoint\n\n";
		node* pri_ele = first;
		for (; pri_ele != NULL;) {
			std::cout << pri_ele->data.nameofstudent << "\t" 
				<< pri_ele->data.number << "\t" << pri_ele->data.gradepoint << std::endl;
			pri_ele = pri_ele->next;
		}
	}
	int savefile() {
		node* save = first;
		int fs = 0;
		std::ofstream fout("save.txt");
		if (!fout.is_open()) {
			std::cout << "Sorry the file could not be opened\t" << "save.txt" << std::endl;
			return 0;
		}
		fout << "Student Name\t\tStudent ID\t Net GradePoint\n\n";
		for (; save != NULL;) {
			std::cout << save->data.nameofstudent << "\t"
				<< save->data.number << "\t" << save->data.gradepoint << std::endl;
			save = save->next;
			fs = 1;
		}
		fout.close();
		if (fs == 0) {
			std::cout << "Sorry, the database is empty!!" << std::endl;
			return 0;
		}
		else {
			std::cout << "Change done successfully" << std::endl;
			return 1;
		}
	}
	int searchelement(std::string x) {
		node* sch = first;
		int f = 0;
		if (first == NULL) {
			std::cout << "Sorry, the database is empty!!" << std::endl;
			return 0;
		}
		else {
			while (sch != NULL) {
				if (sch->data.number == x) {
					std::cout << sch->data.nameofstudent << "\t"
						<< sch->data.number << "\t" << sch->data.gradepoint << std::endl;
					sch = sch->next;
					f = 1;
					return 1;
					break;
				}
				sch = sch->next;
			}
			if (f == 0) {
				std::cout << "Sorry, the entered ID is incorrect " << std::endl;
				return 3;
			}
		}
	}
	void help() {
		system("CLS");
		std::cout << "This system focuses on the database system in college, there are certain funcions which have various funcionalities\n"
			<< "Create Funcion :\n"
			<< "In this funcion, you need to create a database if you want to insert certain data, then use the insert funcion\n"
			<< "Insert/Delete/Search Funcions :\n"
			<< "In this funcion you can insert/delete/search data. These funcions can only be used after the create funcion\n"
			<< "Save Funcion :\n"
			<< "All the inputted information must be saved for future use in save.txt file\n"
			<< "Thank you for reading! We hope you found the information useful\n";
	}
private:
	node *first, *last, *new_node;
	long int type;
	int counter;
	int flag = 0;
};

void show();
int check_num(int x = 0);
int menu();
void login();

int main() {
	show();
	Studentdatabase obj;
	long int type, test, num_cases, num_insert, num_del, num_search, check_insert, check_del, check_search;
	long double gradepoint;
	std::string nameofstudent, id;

	test = 1;

	std::cout << "Enter your choice: ";
	num_cases = check_num(3);

	while (test == 1) {
		switch (num_cases) {
		case 1:
			system("CLS");
			std::cout << "Please enter the student's Name, ID, and GPA" << std::endl;

			std::getline(std::cin, nameofstudent);
			while (nameofstudent[0] < 65 || nameofstudent[0] > 122) {
				std::cout << "Sorry, Wrong Input!!" << std::endl;
				std::getline(std::cin, nameofstudent);
			}

			std::getline(std::cin, id);
			while (!(std::cin >> gradepoint) || gradepoint > 4) {
				std::cin.clear();
				while (std::cin.get() != '\n') continue;
				std::cout << "Sorry, Wrong Input!!" << std::endl;
			}
			while (std::cin.get() != '\n') continue;

			std::cout << "What is your perferred database arrangment? \n"
				<< "1. Student Name" << "\t2. Student ID"
				<< std::endl;

			type = check_num(2);

			obj.construct(type, nameofstudent, id, gradepoint);

			num_cases = menu();

			break;
		case 2:
			system("CLS");
			std::cout << "Please enter the number of students that you want to save in the database " << std::endl;

			check_insert = 1;
			num_insert = check_num(0);

			for (int i = 1; i <= num_insert; ++i) {
				if (check_insert == 1) {
					std::cout << "Please enter the name, id, and gpa of the student " << std::endl;

					std::getline(std::cin, nameofstudent);
					while (nameofstudent[0] < 65 || nameofstudent[0] > 122) {
						std::cout << "Sorry, Your entered name is incorrect!!" << std::endl;
						std::getline(std::cin, nameofstudent);
					}

					std::getline(std::cin, id);
					while (!(std::cin >> gradepoint) || gradepoint > 4) {
						std::cin.clear();
						while (std::cin.get() != '\n') continue;
						std::cout << "Sorry, Wrong Input!!" << std::endl;
					}
					while (std::cin.get() != '\n') continue;

					check_insert = obj.insertelement(nameofstudent, id, gradepoint);
				}
			}
			num_cases = menu();
			break;
		case 3:
			system("CLS");
			std::cout << "Please enter numbers of the students that you want to delete " << std::endl;
			check_del = 1;
			num_del = check_num(0);

			for (int i = 1; i <= num_del; ++i) {
				if (check_del != 0) {
					std::cout << "Please enter Student ID" << std::endl;

					std::getline(std::cin, id);
					check_del = obj.deletelement(id);
					if (check_del == 3) --i;
				}
			}
			num_cases = menu();

			break;
		case 4:
			system("CLS");
			std::cout << "Please enter numbers of the students that you want to search for " << std::endl;
			check_search = 1;
			num_search = check_num();

			for (int i = 1; i <= num_search; ++i) {
				if (check_search != 0) {
					std::cout << "Please enter Student ID" << std::endl;

					std::getline(std::cin, id);
					check_search = obj.searchelement(id);
					if (check_del == 3) --i;
				}
			}
			num_cases = menu();

			break;
		case 5:
			system("CLS");
			obj.print();
			num_cases = menu();
			break;
		case 6:
			system("CLS");
			int save_check;
			save_check = obj.savefile();
			num_cases = menu();
			break;
		case 7:
			obj.help();
			num_cases = menu();
			break;
		case 8:
			exit(EXIT_SUCCESS);
			break;
		default:
			std::cout << "Sorry, wrong input!! " << std::endl;
			std::cout << "Enter your desired choice: " << std::endl;
			num_cases = check_num(3);
			break;
		}
	}
}

void show()
{
	login();
	std::cout << "\n\t ***** DATABASE MANAGMENT SYSTEM ***** \n" << std::endl;
	std::cout << " Press 1 to Create Database                   \n"
		<< " Press 2 to insert Data                             \n"
		<< " Press 3 to Delete Data                             \n"
		<< " Press 4 to Search for Data                         \n"
		<< " Press 5 to Print Data                              \n"
		<< " Press 6 to Save Data                               \n"
		<< " Press 7 for Help                                   \n"
		<< " Press 8 to Exit                                    \n";
}

int menu()
{
	int num_cases;
	std::cout << " Do you want to perform another operation?\n"
		<< " 1.Yes\t2.No\n";
	int t = check_num(1);

	if (t == 1) {
		system("CLS");
		show();
		std::cout << " Enter your desired choice: " << std::endl;
		num_cases = check_num(3);
		return num_cases;
	}
	else {
		return 8;
	}
}

void login() {
	std::string pass = "";
	char ch;
	std::cout << "\n\n\n\n\t\t\t\t\t****Database Managment System****";
	std::cout << "\n\n\n\n\n\n\n\t\t\t\t\tEnter the password: ";
	ch = _getch();
	while (ch != 13) {
		pass.push_back(ch);
		std::cout << "*";
		ch = _getch();
	}
		if (pass == "pass") {
			std::cout << "\n\n\t\t\t\t\tYour Access has been Granted " << std::endl;
		}
		else {
			std::cout << "\n\n\t\t\t\t\tYour Access has been Aborted"
				<<"...Press any other key to try agian....." << std::endl;
			ch = _getch();
			system("CLS");
			login();
		}
		system("PAUSE");
		system("CLS");
};

int check_num(int x)
{
	int num;
	switch (x) 
	{
	case 1:
	case 2:
		while (!(std::cin >> num) || num > 2) {
			std::cin.clear();
			while (std::cin.get() != '\n') continue;
			std::cout << "Sorry, wrong input!!" << std::endl;
		}
		while (std::cin.get() != '\n') continue;
		break;
	case 3:
		while (!(std::cin >> num) || num > 8) {
			std::cin.clear();
			while (std::cin.get() != '\n') continue;
			std::cout << "Sorry, wrong input!!" << std::endl;
		}
		while (std::cin.get() != '\n') continue;
		break;
	default:
		while (!(std::cin >> num)) {
			std::cin.clear();
			while (std::cin.get() != '\n') continue;
			std::cout << "Sorry, wrong input!!" << std::endl;
		}
		while (std::cin.get() != '\n') continue;
		break;
	}
	return num;
}