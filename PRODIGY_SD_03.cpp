#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Contact {
private:
    string name;
    string phoneNumber;
    string emailAddress;

public:
    Contact(string name, string phoneNumber, string emailAddress) 
        : name(name), phoneNumber(phoneNumber), emailAddress(emailAddress) {}

    string getName() const {
        return name;
    }

    string getPhoneNumber() const {
        return phoneNumber;
    }

    string getEmailAddress() const {
        return emailAddress;
    }

    void displayContact() const { // Marking as const
        cout << "Name: " << name << endl;
        cout << "Phone Number: " << phoneNumber << endl;
        cout << "Email Address: " << emailAddress << endl;
        cout << "----------------------------" << endl;
    }
};

vector<Contact> contacts;

void addContact() {
    string name, phoneNumber, emailAddress;
    
    cin.ignore(); // Clear the input buffer
    cout << "Enter Name: ";
    getline(cin, name); // Use getline to handle spaces in the name
    cout << "Enter Phone Number: ";
    getline(cin, phoneNumber);
    cout << "Enter Email Address: ";
    getline(cin, emailAddress);

    Contact newContact(name, phoneNumber, emailAddress);
    contacts.push_back(newContact);
    cout << "Contact added successfully!" << endl;
}

void viewContacts() {
    if (contacts.empty()) {
        cout << "No contacts found." << endl;
    } else {
        cout << "Contact List:" << endl;
        for (const auto& contact : contacts) {
            contact.displayContact();
        }
    }
}

void editContact() {
    if (contacts.empty()) {
        cout << "No contacts found." << endl;
    } else {
        viewContacts();
        int index;
        cout << "Enter the index of the contact you want to edit: ";
        cin >> index;

        if (index >= 0 && index < contacts.size()) {
            cin.ignore(); // Clear the input buffer
            cout << "Editing Contact:" << endl;
            contacts[index].displayContact();

            string newName, newPhoneNumber, newEmailAddress;
            cout << "Enter new Name: ";
            getline(cin, newName);
            cout << "Enter new Phone Number: ";
            getline(cin, newPhoneNumber);
            cout << "Enter new Email Address: ";
            getline(cin, newEmailAddress);

            contacts[index] = Contact(newName, newPhoneNumber, newEmailAddress);
            cout << "Contact updated successfully!" << endl;
        } else {
            cout << "Invalid index. Please enter a valid index." << endl;
        }
    }
}

void deleteContact() {
    if (contacts.empty()) {
        cout << "No contacts found." << endl;
    } else {
        viewContacts();
        int index;
        cout << "Enter the index of the contact you want to delete: ";
        cin >> index;

        if (index >= 0 && index < contacts.size()) {
            cout << "Deleting Contact:" << endl;
            contacts[index].displayContact();
            contacts.erase(contacts.begin() + index);
            cout << "Contact deleted successfully!" << endl;
        } else {
            cout << "Invalid index. Please enter a valid index." << endl;
        }
    }
}

int main() {
    int choice;

    do {
        cout << "Contact Management System" << endl;
        cout << "1. Add New Contact" << endl;
        cout << "2. View Contacts" << endl;
        cout << "3. Edit Contact" << endl;
        cout << "4. Delete Contact" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                viewContacts();
                break;
            case 3:
                editContact();
                break;
            case 4:
                deleteContact();
                break;
            case 5:
                cout << "Exiting Contact Management System. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }

    } while (choice != 5);

    return 0;
}
