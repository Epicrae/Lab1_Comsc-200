#include <iostream>
using std::cin;
using std::cout;
using std::ios;
using std::endl;
#include "myFile.h"

#include <string>
using std::string;
using std::getline;
#include <cstdlib> 


struct car
{
    string car_name;
    int car_year;
    double car_miles;
    car* next;//pointer to the next car in the list
};

//function prototypes 
car* make_newCar(string name, int year, double miles);//create new car nodes 
void add(car*& head, string name, int year, double miles);
void delete_car(car*& head, string& car_todelete);
void display_welcome(car*& head);
void display_allcars(car* head);
void delete_allcars(car*& head);


int main() {
    std::string lab_desc = "Lab 1 linked list review\nComsc 210";
    print_id(lab_desc); 
    car* head = nullptr;
    display_welcome(head);   
    delete_allcars(head);
    
}

void display_welcome(car*& head) {
    string name;
    int year;
    double miles;
    char choice;
    string buf;

    cout << "Welcome to the Used Car Database!\n";

    while (true)
    {
        cout << "Choose an option:\n";
        cout << "1. Add a new car\n";
        cout << "2. Delete a car\n";
        cout << "3. Display all cars\n";
        cout << "4. Exit\n";
        cin >> choice;
        cin.ignore(1000, '\n');

        if (choice == '4') {
            cout << "exiting program\n";
            break;
        }


        switch (choice) {
        case '1':
            cout << "Enter car name:";
            getline(cin, name);
            cout << "Enter car year:";
            getline(cin, buf);
            year = atoi(buf.c_str());
            cin.ignore(1000,'\n');
            cout << "Enter car miles:";
            cin >> miles;
            cin.ignore(1000, '\n');
            add(head, name, year, miles);
            break;
        case '2':
            cout << "Enter the name of the car to delete: ";
            getline(cin, name);
            delete_car(head, name);
            break;
        case '3':
            display_allcars(head);
            break;
        default:
            cout << "Invalid, Please try again";
        }

    }
}

car* make_newCar(string name, int year, double miles) {
    car* new_car = new car;
    new_car->car_name = name;
    new_car->car_year = year;
    new_car->car_miles = miles;
    new_car->next = nullptr;
    return new_car;
}
void add(car*& head, string name, int year, double miles) {
    car* new_car = make_newCar(name, year, miles);
    new_car->next = head;
    head = new_car;
}
void delete_car(car*& head, string& car_todelete) {
    if (head == nullptr) {
        cout << "nothing to delete." << endl;
        return;
    }
    car* temp = head;
    car* prev = nullptr;

    // if the car to delete is the first node
    if (temp != nullptr && temp->car_name == car_todelete) {
        head = temp->next; //change head of list 
        delete temp;
        return;
    }

    //search for the car to be deleted
    while (temp != nullptr && temp->car_name != car_todelete){
        prev = temp;
        temp = temp->next;
    }

    // if car was not founf in the list
    if (temp == nullptr) {
        cout << "Car not found!" << endl;
        return;
    }
    //unlink and delete node
    prev->next = temp->next;
    delete temp;
}
void display_allcars(car* head) {
    if (head == nullptr) {
        cout << "Empty list" << endl;
        return;
    }
    car* current = head;
    while (current != nullptr) {
        cout << "Car name:" << current->car_name << ",";
        cout << "Year: " << current->car_year << ",";
        cout << "Miles: " << current->car_miles << endl;
        current = current->next;   

    }
}

void delete_allcars(car*& head) {
    while (head != nullptr) {
        car* temp = head;
        head = head->next;
        delete temp;
    }
}
