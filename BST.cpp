#include<iostream>
using namespace std;

class Student {
    int roll_no, cet, age;
    string name, address;

public:
    Student *LC, *RC;
    void create();
    void insert(Student *root, Student *next);
    void inorderR(Student *root);
} *root = NULL, *S[100];

void Student::create() {
    root = new Student;
    cout << "Enter Roll number, Name, Age, Address, CET Score: ";
    cin >> root->roll_no >> root->name >> root->age >> root->address >> root->cet;
    root->LC = root->RC = NULL;
    
    int ch;
    do {
        cout << "Enter 1 to add another student, 0 to exit: ";
        cin >> ch;
        if (ch == 1) {
            Student *next = new Student;
            cout << "Enter Roll number, Name, Age, Address, CET Score: ";
            cin  >> next->roll_no >> next->name >> next->age >> next->address >> next->cet;
            next->LC = next->RC = NULL;
            insert(root, next);
        }
    } while (ch == 1);
}

void Student::insert(Student *root, Student *next) {
    if (root->cet > next->cet) {
        if (root->LC == NULL)
            root->LC = next;
        else
            insert(root->LC, next);
    } else if (root->cet < next->cet) {
        if (root->RC == NULL)
            root->RC = next;
        else
            insert(root->RC, next);
    }
}

void Student::inorderR(Student *root) {
    if (root == NULL) return;
    inorderR(root->LC);
    cout << "\n" << root->roll_no << "\t\t" << root->name << "\t\t" << root->age << "\t\t" << root->address << "\t\t" << root->cet;
    inorderR(root->RC);
}

int main() {
    int choice;
    do {
        cout << "\nMENU:\n1. Create Tree\n2. Display Records\n3. Exit\nEnter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                if (root == NULL) {
                    Student().create();
                } else {
                    cout << "Tree already created!";
                }
                break;
            case 2:
                if (root != NULL) {
                    cout << "\n" << "ROLL NO\tNAME\t\tAGE\t\tADDRESS\t\tCET";
                    root->inorderR(root);
                } else {
                    cout << "No records to display!";
                }
                break;

            case 3:
                cout << "Exiting program...";
                break;
            default:
                cout << "Invalid choice! Try again.";
        }
    } while (choice != 3);
    return 0;
}
