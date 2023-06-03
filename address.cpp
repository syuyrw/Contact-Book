#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Contact {
    string firstName;
    string lastName;
    string phoneNumber;
};

void addContact();
void searchContact();
void displayAllContacts();

int main() {
    int choice;
    while (true) {
        cout << "Contact Book" << endl;
        cout << "1. Add Contact" << endl;
        cout << "2. Search Contact" << endl;
        cout << "3. Display All Contacts" << endl;
        cout << "4. Exit" << endl << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                searchContact();
                break;
            case 3:
                displayAllContacts();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl << endl;
        }
    }
}

void addContact() {
    Contact contact;
    cout << endl << "Enter first name: " << endl;
    cin >> contact.firstName;
    cout << "Enter last name: " << endl;
    cin >> contact.lastName;
    cout << "Enter phone number: " << endl;
    cin >> contact.phoneNumber;

    ofstream file("contacts.txt", ios::app);
    if (file.is_open()) {
        file << contact.firstName << " " << contact.lastName << " " << contact.phoneNumber << endl << endl;
        file.close();
        cout << "Contact added successfully." << endl << endl;
    } else {
        cerr << "Error opening file." << endl << endl;
    }
}

void searchContact() {
    string firstName, lastName, phoneNumber, keyword;
    bool found = false;

    cout << "Enter name to search: " << endl;
    cin >> keyword;

    ifstream file("contacts.txt");
    if (file.is_open()) {
        while (file >> firstName >> lastName >> phoneNumber) {
            if (firstName == keyword || lastName == keyword) {
                cout << firstName << " " << lastName << ": " << phoneNumber << endl;
                found = true;
            }
        }
        file.close();
        if (!found) {
            cout << "No contacts found with that name." << endl << endl;
        }
    } else {
        cerr << "Error opening file." << endl << endl;
    }
}

void displayAllContacts() {
    string firstName, lastName, phoneNumber;

    ifstream file("contacts.txt");
    if (file.is_open()) {
        while (file >> firstName >> lastName >> phoneNumber) {
            cout << firstName << " " << lastName << ": " << phoneNumber<<endl;;
        }
        file.close();
    } else {
        cerr<< "Error opening file."<<endl << endl;;
    }
}
