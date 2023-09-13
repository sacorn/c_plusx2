/**

Purpose: Create a simple abstraction of a person.

@author Salvador Cornejo
@version 1.0 
*/

#include <iostream>
#include <iomanip>
#include <sstream>
#include <climits>
#include <cstdlib>
#include <vector>
using namespace std;

class Person {
public:
    /* Initializes veriables to 0 and none for each object with no perameters */
    Person();
    /* Saves info of parameters into variables.*/
    Person(string newName, int newAge, double newIncome);
    /* Returns name saved in variable*/
    string getName() const;
    /* Returns age from variable*/
    int getAge() const;
    /* Returns Income*/
    double getIncome() const;
    /* Assigns parameter info into name variable*/
    void setName(string newName);
    /* assigns parameter info into age variable*/
    void setAge(int newAge);
    /* assigns parameter info into income variable*/
    void setIncome(double newIncome);
    /* prints info*/
    void print() const;
    /* Aligns info*/
    string toString() const;
    /* Saves input info.*/
    void read();
    
private:
    string name;
    int age;
    double income;
};

Person::Person() {
    name = "none";
    age = 0;
    income = 0;
}

Person::Person(string newName, int newAge, double newIncome){
    name = newName;
    age = newAge;
    income = newIncome;
}

string Person::getName() const {
    return name;
}

int Person::getAge() const {
    return age;
}

double Person::getIncome() const {
    return income;
}

void Person::setName(string newName) {
    name = newName;
}

void Person::setAge(int newAge) {
    age = newAge;
}

void Person::setIncome(double newIncome) {
    income = newIncome;
}

void Person::print() const {
    cout << setw(18) << left << name << setw(6) << right << age << setw(11) << right
    << fixed << setprecision(2) << income << endl;
}

void Person::read() {
    cout << "\nAdding a new contact:\n";
    cout << "Enter the name of the person: ";
    cin >> ws;
    getline(cin, name);
    cout << "Enter the age for " << name << " : ";
    cin >> age;
    cout << "Enter the income for " << name << " : ";
    cin >> income;
}

/**
 This function returns a string value that contains all the data about a person.
 
 source: http://www.cplusplus.com/reference/sstream/stringstream/str/
 */
string Person::toString() const {
    stringstream ss;
    ss << setw(18) << left << name << setw(6) << right << age << setw(11) << right <<
    fixed << setprecision(2) << income;
    string str = ss.str();
    return str;
}


void listContacts(vector<Person> contacts) {
    cout << "\n\nContact list:\n";
    cout << "# Name                 Age     Income\n";
    for (unsigned i = 0; i < contacts.size(); i++) {
        cout << i + 1 << " ";
        contacts[i].print();
    }
}

void addContact(vector<Person>& contacts) {
    Person temp;
    temp.read();
    contacts.push_back(temp);
}

void deleteContact(vector<Person>& contacts) {
    cout << "\n\nDeleting a contact:\n";
    listContacts(contacts);
    int contactToDelete = 0;
    cout << "Enter the number of the contact: ";
    cin >> contactToDelete;// keep in mind that we have to leave the previous contacts where they are in case they decide to choose contact 4 for ex.
    contactToDelete--;
    for (unsigned i = contactToDelete; i <= contacts.size() - 1; i++) {// we - from contact.size bc we want it to match our vector, since vect. starts 4rm 0.
        contacts[i] = contacts[i + 1];
    }
    contacts.pop_back();
}

void changeIncome(vector<Person>& contacts) {
    cout << "\n\nChange income for a contact:\n";
    listContacts(contacts);
    int chooseContact = 0;
    double newIncome = 0;
    cout << "Enter the number of the contact: ";
    cin >> chooseContact;
    chooseContact--;
    cout << "Enter the new income: ";
    cin >> newIncome;
    contacts[chooseContact].setIncome(newIncome);
}

void ageRange(vector<Person>& contacts) {
    cout << "\n\nSearching by Age\n";
    int minAge,maxAge = 0;
    cout << "Enter the minimum age: ";
    cin >> minAge;
    cout << "Enter the maximum age: ";
    cin >> maxAge;
    cout << "Name                 Age     Income\n";
    
    for (unsigned i = 0; i < contacts.size(); i++) {
        if (minAge <= contacts[i].getAge() && maxAge >= contacts[i].getAge()) {
            contacts[i].print();
        }
            
    }
}


int main() {
    
    Person Ed("Ed Parrish", 42, 72470.42);
    Person Emma("Emma Hacker", 24, 71916.24);
    Person John("John Q Public", 37, 55775.37);
    
    
    vector<Person> contacts = {Ed, Emma, John};
    
    
    int choice = 1;
    while ( choice != 0) {
        
        cout << "\nPlease choose one of the following operations: \n"
    << "0. Exit program\n"
    << "1. List contacts\n"
    << "2. Add a contact\n"
    << "3. Delete a contact\n"
    << "4. Change contact income\n"
    << "5. List by age range\n"
    << "Choice (0-5): ";
        
        cin >> choice;
        if ( choice == 1) {
            listContacts(contacts);
        }
        else if (choice == 2) {
            addContact(contacts);
        }
        else if (choice == 3) {
            deleteContact(contacts);
        }
        else if (choice == 4) {
            changeIncome(contacts);
        }
        else if (choice == 5) {
            ageRange(contacts);
        }
    }

        return 0;
}
