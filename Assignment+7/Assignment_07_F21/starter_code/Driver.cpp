#include "EmployeeDirectory.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

void displayMenu();

int main(int argc, char** argv) {

    if (argc != 2) {
        cout << "Invalid command-line arguments" << endl;
        cout << "Usage: ./a.out <EmployeeCSVFilename>" << endl;
        return 0;
    }

    // Processing the file
    ifstream fp(argv[1]);
    if (fp.fail()) {
        cout << "Error opening file." << endl;
        return 0;
    }
    
    // Declare the tree
    EmployeeDirectory* tree = new EmployeeDirectory;

    // Read from file, Build the tree
    string line, field;
    int empId, empLevel, empJoiningYear;
    string empName, empPhone;

    while (getline(fp, line)) {
        istringstream ss(line);

        getline(ss, field, ','); empId = stoi(field);
        getline(ss, field, ','); empName = field;
        getline(ss, field, ','); empLevel = stoi(field);
        getline(ss, field, ','); empPhone = field;
        getline(ss, field, ','); empJoiningYear = stoi(field);

        tree->insertEmployee(empId, empName, empLevel, empPhone, empJoiningYear);
    }
    fp.close();

    // Interactive menu starts here
    int input = 0;
    do {

        displayMenu();
        getline(cin, line);
        input = stoi(line);

        if (input == 1)
        {
            cout << "Enter empName: ";
            getline(cin, empName);

            cout << "Enter empId: ";
            getline(cin, line); empId = stoi(line);

            LLNode* t = tree->searchEmployee(empId, empName);
            tree->printEmployee(t);
        }
        else if (input == 2)
        {
            cout << "Enter empId: ";          getline(cin, field); empId = stoi(field);
            cout << "Enter empName: ";        getline(cin, field); empName = field;
            cout << "Enter empLevel: ";       getline(cin, field); empLevel = stoi(field);
            cout << "Enter empPhone: ";       getline(cin, field); empPhone = field;
            cout << "Enter empJoiningYear: "; getline(cin, field); empJoiningYear = stoi(field);

            tree->insertEmployee(empId, empName, empLevel, empPhone, empJoiningYear);
        }
        else if (input == 3)
        {
            cout << "Enter empName: ";
            getline(cin, empName);

            cout << "Enter empId: ";
            getline(cin, line); empId = stoi(line);

            tree->removeEmployee(empId, empName);
        }
        else if (input == 4)
        {
            tree->showEmployeeDirectory();
        }
        else if (input == 5)
        {
            cout << "Enter the BST char: ";
            getline(cin, line);

            TreeNode* t = tree->searchCharNode(line[0]);

            if (t) tree->leftRotate(t);
            else   cout << "BST Node not found." << endl;
        }
        else if (input == 6)
        {
            cout << "Exiting program." << endl;
        }
        else
        {
            cout << "Invalid input. Try again." << endl;
        }

        cout << endl;

    } while(input != 6);


    return 0;
}

void displayMenu() {
    cout << "====== Main Menu ======" << endl;
    cout << "1. Find employee" << endl;
    cout << "2. Insert Employee" << endl;
    cout << "3. Remove Employee" << endl;
    cout << "4. Show employee directory" << endl;
    cout << "5. Left rotate" << endl;
    cout << "6. Quit" << endl;
    cout << "SELECT: ";
}

