#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;


class contact {
private:
	char fName[50], lName[50], addres[50], email[50];
	long long pNo;

public:
	void creatContact() {
		cout << "Enter your first name: ";
		cin >>getline(fName,50);
		cout << "Enter your last name: ";
		cin >> pNo;
		cout << "Enter address: ";
		cin >> address;
		cout << "Enter email: ";
		cin >> email;

	}
	void showContact() {
		cout << "Name: " << fName << " " << lName << endl;
		cout << "Phone: " << pNo<<endl;
		cout << "Address: " << address << endl;
		cout << "Email: " << email << endl;
	}

	void writeOnFile() {
		char ch;
		ofstream f1;
		f1.open("CMS.dat", ios::binary | ios::app);


		do {
			createContact();
			f1.write(reinterpret_cast<char*>(this), sizeof(*this));
			cout << "Do you have next data?(y/n)";
			cin >> ch;
		} while (ch == 'y');
		cout << "Contact has been sucessfully Created....";
		f1.close();
	}

	void readFromFile() {
		ifstream f2;
		f2.open("CMS.dat", ios::binary);

		cout << "\n====================================\n";
		cout << "LIST OF CONTACT";
		COUT << "\n=======================================\n";
		while (!f2.eof()) {
			if (f2.read(reinterpret_cast<char*>(this), sizeof(*this)))
			{
				showContact();
				cout << "\n=================================\n";
			}
		}
		f2.close();
	}
	void searchOnFile() {
		ifstream f3;
		long long phone;
		cout << "Enter pnone no. ";
		cin >> phone;
		f3.open("CMS.dat", ios::binary);
		while (!f3.eof()) {
			if (f3.read(reinterpret_cast<char*>(this), sizeof(*this)))
			{
				if (phone == pNo) {
					showContact();
					return;
				}
			}
		}
		cout << "\n\nNO record found";
		f3.close();
	}

	void deleteFromFile() {
		long long phone;
		int flag = 0;
		ofsrteam f4;
		ifstream f5;
		f5.open("CMS.dat", ios::binary);
		f4.open("temp.dat", ios::binary);
		cout << "Enter phone no. to delete:: ";
		cin >> phone;
		while (!f5.eof()) {
			if (f5.read(reinterpret_cast<char*>(this), sizeof(*this)))
			{
				if (pNo != phone) {
					f4.write(reinterpret_cast<char*>(this), sizeof(*this));
				}
				else flag = 1;
			}
		}
		f5.close();
		f4.close();
		remove("CMS.dat");
		rename("temp.dat", "CSM.dat");
		flag == = 1 ? cout << "\tContact Deleted..." : cout << "\tContact Not found...";

	}

	void editContact() {
		long long phone;
		fstream f6;

		cout << "Edit contact";
		cout << "\n======================================\n";
		cout << "Enter the phone number to be edit: ";
		cin >> phone;
		f6.open("CMS.dat", ios::binary | ios::out | ios::in);
		while (!f6.eof()) {
			if (f6.read(reinterpret_cast<char*>(this), sizeof(*this)))
			{
				if (phone == pNo) {
					cout << "Enter new record\n";
					createContact();

					int pos = -1*sizeof(*this);
					f6.seekp(reinterpret_cast<char*>(this), sizeof(*this));
					f6.write(reinterpret_cast<char*>(this), sizeof(*this));
					cout << endl << endl << "\tContact Successfully Updated...";
					return;
				}
			}
		}
		cout << "\n\nNo Record found";
		f6.close();
	}


};
int main() {
	system("cls");
	system("Color 3F");
	cout << "\n\n\n\n\n\n\t\t * WELCOME TO THE CONTACT MANAGEMENT SYSTEM *";
	getch();

	while (1) {
		contact c1;
		int choice;

		system("cls");
		system("Color 03");

		cout << "\nContact Management System";
		cout << "\n\nMAIN MENU";
		cout << "\n==================================================\n";
		cout << "[1] Add a new Contact\n";
		cout << "[2] List all Contact\n";
		cout << "[3] Search for Constact\n";
		cout << "[4] Edit a Contact\n";
		cout << "[0] Exit";
		cout << "\n=====================================================\n";
		cout << "Enter you choice: ";
		cin >> choice;

		swich(choice) {
			case 1:
				system("cls");
				c1.writeOnFile();
				break;
			case 2:
				system("cls");
				c1.readFromFile();
				break;
			case 3:
				system("cls");
				c1.searchOnFile();
				break;
			case 4:
				system("cls");
				c1.deleteFromFile();
				break;
			case 5:
				system("cls");
				c1.editContact();
				break;
			case 0:
				system("cls");
				cout << "\n\n\n\n\t\tThank you for using CMS." << endl << endl;
				exit(0);
				break;

			default:
				continue;
		}

	}

	return 0;



}




















