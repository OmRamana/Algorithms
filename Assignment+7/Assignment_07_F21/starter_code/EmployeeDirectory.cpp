#include "EmployeeDirectory.hpp"

// [HELPER FUNCTIONS]
char EmployeeDirectory::getLastInitial(string name) {
    int found_ix = name.find(' ');

    if (found_ix != string::npos)
        return name[found_ix + 1];

    return '\0';
}

void EmployeeDirectory::printEmployee(LLNode* n) {
    if (n == NULL) {
        cout << "LLNode is NULL." << endl;
    }
    else {
        cout << "Employee Information" << endl;
        cout << "====================" << endl;
        cout << "ID     : " << n->empId << endl;
        cout << "Name   : " << n->empName << endl;
        cout << "Level  : " << n->empLevel << endl;
        cout << "Phone  : " << n->empPhone << endl;
        cout << "Joined : " << n->empJoiningYear << endl;
    }
}


// [TO BE IMPLEMENTED]
// ----------------------------------------------------------------------------

EmployeeDirectory::EmployeeDirectory() {
    // TODO
}

// ----------------------------------------------------------------------------

EmployeeDirectory::~EmployeeDirectory() {
    // TODO
}

// ----------------------------------------------------------------------------

TreeNode* EmployeeDirectory::searchCharNode(char key) {
    // TODO
}

// ----------------------------------------------------------------------------

void EmployeeDirectory::showEmployeeDirectory() {
    // TODO
}

// ----------------------------------------------------------------------------

LLNode* EmployeeDirectory::searchEmployee(int empId, string empName) {
    // TODO
}

// ----------------------------------------------------------------------------

void EmployeeDirectory::insertEmployee(int empId, string empName, int empLevel, string empPhone, int empJoiningYear) {
    // TODO
}

// ----------------------------------------------------------------------------

void EmployeeDirectory::removeEmployee(int empId, string empName) {
    // TODO
}

// ----------------------------------------------------------------------------

void EmployeeDirectory::leftRotate(TreeNode* curr) {
    // TODO
}

// ----------------------------------------------------------------------------
