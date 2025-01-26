#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Kelas Contact: untuk menyimpan informasi tentang kontak
class Contact {
private:
    string name;    // nama kontak       
    string address; // alamat kontak
    string power;   // kekuatan kontak

public:
    // Constructor
    Contact(string n = "", string a = "", string p = "") : name(n), address(a), power(p) {}

    // Method untuk mengatur data contact
    void setContact(string n, string a, string p) {
        name = n;
        address = a;
        power = p;
    }

    // Method untuk menampilkan detail kontak
    string getName() const {
        return name;
    }

    string getAddress() const {
        return address;
    }

    string getPower() const {
        return power;
    }

    // Method untuk menampilkan detail contact
    void displayContact() const {
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Power: " << power << endl;
    }
};

// Kelas PhoneBook: untuk menyimpan dan mengelola daftar kontak
class PhoneBook {
private:
    vector<Contact> contacts;   //  Vector untuk menyimpan daftar kontak
    const int MAX_CONTACTS = 8; // Maksimal jumlah kontak yang dapat disimpan

public:
    //  Method untuk menambahkan kontak baru
    void addContact(const Contact& contact) {
        if (contacts.size() >= MAX_CONTACTS) {
            // Jika sudah penuh, hapus kontak awal
            contacts.erase(contacts.begin());
        }
        contacts.push_back(contact);
        cout << "Contact added successfully!" << endl;
    }

    // Method untuk mencari kontak berdasarkan nama
    void searchContact(const string& name) const {
        bool found = false;
        for (const auto& contact : contacts) {
            if (contact.getName() == name) {
                found = true;
                cout << "Contact found:" << endl;
                contact.displayContact();
                break;
            }
        }
        if (!found) {
            cout << "Contact not found!" << endl;
        }
    }

    // Method untuk menampilkan semua kontak
    void displayAllContacts() const {
        if (contacts.empty()) {
            cout << "PhoneBook is empty!" << endl;
            return;
        }

        cout << "Contacts in PhoneBook:" << endl;
        for (size_t i = 0; i < contacts.size(); ++i) {
            cout << i + 1 << ". " << contacts[i].getName() << endl;
        }
    }

    //  Method untuk menghapus semua kontak
    void clearContacts() {
        contacts.clear();
    }
};

// Fungsi utama (main)
int main() {
    PhoneBook phoneBook;
    int choice;

    do {
        cout << "\nPhoneBook Menu:" << endl;
        cout << "1. Add Contact" << endl;
        cout << "2. Search Contact" << endl;
        cout << "3. Display All Contacts" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        cin.ignore(); // Menghapus karakter newline dari input

        if (choice == 1) {
            string name, address, power;
            cout << "Enter name: ";
            getline(cin, name);
            cout << "Enter address: ";
            getline(cin, address);
            cout << "Enter power: ";
            getline(cin, power);

            Contact contact(name, address, power);
            phoneBook.addContact(contact);

        } else if (choice == 2) {
            string name;
            cout << "Enter the name of the contact to search: ";
            getline(cin, name);
            phoneBook.searchContact(name);

        } else if (choice == 3) {
            phoneBook.displayAllContacts();

        } else if (choice == 4) {
            cout << "Exiting program..." << endl;
            phoneBook.clearContacts();
        } else {
            cout << "Invalid choice! Please try again." << endl;
        }

    } while (choice != 4);

    return 0;
}