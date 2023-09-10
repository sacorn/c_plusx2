/**
 CS-11 Asn sample project, banco.cpp
 Purpose: Allows you to insert amount of money into your bank account and shop by "logging" into your bank account. Prints receipt after purchase. Allows more than 1 person to use this "BancoApp". Shows your balance and doesnt allow underage people buy beer. It doesnt allow people to buy things they cant afford, they are forced to buy something they can afford or leagally buy, wont accept the purchase unless they can afford it and are overage.
 
 @author Salvador Cornejo.
 @version 1.0 12/04/17
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <climits>
#include <cstdlib>
#include <vector>
using namespace std;

class Banco {
public:
    /** @parameter Sets member varibles to a value */
    Banco();
    /** @parameter reads info input by user */
    void read();
    /** @parameter reads in information from a file*/
    void read(ifstream& fin);
    /** @parameter saves money that is wished to spent by user */
    void setMoneySpent();
    /** @parameter saves name of purchse */
    void setPurchase();
    /** @parameter returns name of purchase */
    string getPurchase() const;
    /** @parameter returns name */
    string getName() const;
    /** @parameter returns money*/
    double getMoney() const;
    /** @parameter returns age */
    int getAge() const;
    /** @parameter returns money the user would like to spend */
    double getMoneySpent() const;
    /** @return returns password*/
    string getPassword() const;
    /** @parameter prints out information of person and purchase to to file */
    void receiptPrint(ofstream& fout) const;
    
private:
    string name;
    string password;
    string product;
    int age;
    double money;
    double moneySpent;
};

/** @parameter adds a new person to vector */
void addCustomer(vector<Banco>& person);

/** @parameter prints user's account */
void veiwBank(vector<Banco>& person);

/** @parameter loads file */
void loadData(vector<Banco>& person, string fileName);

/** @parameter opens up a file */
void receipt(vector<Banco> person, string name, string fileName);
    
/** @parameter allows user to insert name of product and price they want to purchase */
void shop(vector<Banco>& person);


int main() {

    const int one = 1;
    const int two = 2;
    const int three = 3;
    vector<Banco> person;
    loadData(person, "csProject.txt");
    int choice = 1;
    
    cout << "Welcome to BancoApp!\n\n";
    addCustomer(person);
        while (choice != 0) {
    cout << "\nTo view your bank account enter 1.\n";
    cout << "To shop enter 2.\n";
    cout << "To add someone new enter 3.\n";
    cout << "Choice: ";
    cin >> choice;
            if (choice == one) {
                veiwBank(person);
            }
            if (choice == two) {
                shop(person);
            }
           if (choice == three) {
                addCustomer(person);
            }
            
        }
}


/** @parameter Sets member varibles to a value */
Banco::Banco() {
    name = "N/A";
    product = "N'A";
    age = 0;
    money = 0;
    moneySpent = 0;
}

/** @parameter reads info input by user */
void Banco::read() {
    
    cout << "Please enter your name: ";
    cin >> ws;
    getline(cin,name);
    cout << "Please enter your age: ";
    cin >> age;
    cout << "Please enter a password: ";
    cin >> password;
    cout << "Please renter your passowrd to comfirm it's correct: ";
    string passwordTest;
    cin >> passwordTest;
    while (passwordTest != password) {
        cout << "Inncorect password! Please try again.\n";
        cout << "Please enter a password: ";
        cin >> password;
        cout << "Please renter your passowrd to comfirm it's correct: ";
        cin >> passwordTest;
    }
    cout << "Enter the amount you want to deposit into your savings account: ";
    cin >> money;
    
}
/** @return returns passwprd*/
string Banco::getPassword() const{
    return password;
    
}

/** @parameter adds a new person to vector */
void addCustomer(vector<Banco>& person) {
    Banco newPerson;// creates a profile everytime being used.
    newPerson.read();// sends that created profile to the read f(x).
    person.push_back(newPerson);// saves the info asked in read f(x) into vector person from the previous line.
}

/** @parameter returns name */
string Banco::getName() const{
    return name;
}

/** @parameter returns money*/
double Banco::getMoney() const{
    return money;
}

/** @parameter saves money that is wished to spent by user */
void Banco::setMoneySpent() {
    cin >> moneySpent;
}

/** @parameter saves name of purchse */
void Banco::setPurchase() {
    cin >> ws;
    getline(cin,product);
}
/** @parameter returns name of purchase */
string Banco::getPurchase() const{
    return product;
}

/** @parameter returns age */
int Banco::getAge() const{
    return age;
}

/** @parameter returns money the user would like to spend */
double Banco::getMoneySpent() const{
    return moneySpent;
}

/** @parameter prints user's account */
void veiwBank(vector<Banco>& person) {
    cout << "Enter name: ";
    string name;
    cin >> ws;
    getline(cin,name);
    cout << "Enter your password: ";
    string password;
    cin >> password;
    
    for (unsigned i = 0; i < person.size(); i++) {
        if(person[i].getName() == name && person[i].getPassword() == password) {
            cout << person[i].getName() << " Your balance is: $" << person[i].getMoney() - person[i].getMoneySpent() << endl;
        }
    }
}

/** @parameter reads in information from a file*/
void Banco::read(ifstream& fin) {
    getline(fin, name);
    fin >> age;
    fin >> money;
}
/** @parameter loads file */
void loadData(vector<Banco>& person, string fileName) {
    ifstream fin;
    fin.open(fileName.c_str()); // or ifstream fin(fileName.c_str())
    if (fin.fail()) {
        cout << "Failed to open file.\n";
        exit(-1);
    }
    while(fin.good()) {
        Banco newPerson;
        newPerson.read(fin);
        if (fin.good()) {
            person.push_back(newPerson);
        }
    }
    fin.close();
}

/** @parameter prints out information of person and purchase to to file */
void Banco::receiptPrint(ofstream& fout) const{
    const int eight = 8;
    const int nineTeen = 19;
    const int ten = 10;
    const int two = 2;
    fout << "Customer: " << name << setw(eight) << right << "age: " << age <<
    setw(nineTeen) << right << "item purchased: " << getPurchase() << setw(ten) << right <<
    fixed << setprecision(two) << "total: $" << moneySpent << endl;
}

/** @parameter opens up a file */
void receipt(vector<Banco> person, string name, string fileName) {
    ofstream fout;
    fout.open(fileName.c_str());
    if (fout.fail()) {
        cout << "Failed to open file.\n";
        exit(-1);
    }
    for(unsigned i = 0; i < person.size(); i++) {
        if (person[i].getName() == name) {
            person[i].receiptPrint(fout);
        }
    }
    fout.close();
}

/** @parameter allows user to insert name of product and price they want to purchase */
void shop(vector<Banco>& person) {
    cout << "Enter name: ";
    const int drinkingAge = 21;
    string name;
    cin >> ws;
    getline(cin, name);
    for (unsigned i = 0; i < person.size(); i++) {
        if (person[i].getName() == name) {
            cout << "Enter the product you would like to purchase: ";
            person[i].setPurchase();
            while(person[i].getAge() < drinkingAge && person[i].getPurchase() == "beer") {
                cout << "You're in trouble, calling your parents now...\n";
                cout << "Try something else that you can legally purchase: ";
                person[i].setPurchase();
            }
            cout << "Enter the price of " << person[i].getPurchase() << " : ";
            person[i].setMoneySpent();
            while (person[i].getMoney() < person[i].getMoneySpent()) {
                cout << "Choose something you can afford!\n";
                cout << "Enter the product you would like to purchase: ";
                person[i].setPurchase();
                cout << "Enter the price of " << person[i].getPurchase() << " : ";
                person[i].setMoneySpent();
            }
            cout << "Printing receipt...\n";
            receipt(person, person[i].getName(), "receipt.txt");
            cout << "Receipt saved to you computer, all done.\n";
        }
    }
}

