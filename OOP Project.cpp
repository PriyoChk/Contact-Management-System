#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Contact {
private:
    string name;
    string phoneNumber;
    string email;

public:
    Contact(const string& name, const string& phoneNumber, const string& email)
        : name(name), phoneNumber(phoneNumber), email(email) {}

    string getName() const {
        return name;
    }

    string getPhoneNumber() const {
        return phoneNumber;
    }

    string getEmail() const {
        return email;
    }
};

class ContactManager {
private:
    vector<Contact> contacts;

public:
    void addContact(const string& name, const string& phoneNumber, const string& email) {
        Contact contact(name, phoneNumber, email);
        contacts.push_back(contact);
        cout << "Contact added successfully." << endl;
    }

    void deleteContact(const string& name) {
        for (auto it = contacts.begin(); it != contacts.end(); ++it) {
            if (it->getName() == name) {
                contacts.erase(it);
                cout << "Contact deleted successfully." << endl;
                return;
            }
        }
        cout << "Contact not found." << endl;
    }
  void searchContact(const string& name) {
        for (const auto& contact : contacts) {
            if (contact.getName() == name) {
                cout << "Contact found:" << endl;
                cout << "Name: " << contact.getName() << endl;
                cout << "Phone Number: " << contact.getPhoneNumber() << endl;
                cout << "Email: " << contact.getEmail() << endl;
                return;
            }
        }
        cout << "Contact not found." << endl;
    }
    void displayContacts() const {
        if (contacts.empty()) {
            cout << "No contacts found." << endl;
        } else {
            cout << "Contacts:" << endl;
            for (const auto& contact : contacts) {
                cout << "Name: " << contact.getName() << endl;
                cout << "Phone Number: " << contact.getPhoneNumber() << endl;
                cout << "Email: " << contact.getEmail() << endl;
                cout << "--------------------------" << endl;
            }
        }
    }

};

int main() {
    ContactManager CM;
    string choice;

    while (true) {
        cout << "Menu:\n1. Add Contact\n2. search Contact\n3. Delete Contacts\n4.Display contact\n 5. Exit\nEnter your choice: ";
	getline(cin, choice);

        if (choice == "1")
		{
            string name, phoneNumber, email;
            cout << "Enter Name: ";
            getline(cin, name);
            cout << "Enter Phone Number: ";
            getline(cin, phoneNumber);
            cout << "Enter Email: ";
            getline(cin, email);
            CM.addContact(name, phoneNumber, email);
        }
        else if(choice=="2")
		{
			string name;
			cout<<"Enter the name of the contact to search: ";
			getline(cin, name);
		}
         else if (choice == "3")
		{
            string name;
            cout << "Enter Name of the contact to delete: ";
            getline(cin, name);
            CM.deleteContact(name);
        }
         else if (choice == "4")
		{
            CM.displayContacts();
        }
         else if (choice == "5")
		{
            break;
        }
         else
		{
            cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;
    }

    return 0;
}
