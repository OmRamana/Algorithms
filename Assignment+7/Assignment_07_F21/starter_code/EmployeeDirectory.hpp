#ifndef EMPLOYEEDIRECTORY_HPP
#define EMPLOYEEDIRECTORY_HPP

#include <iostream>
#include <string>

using namespace std;

struct LLNode {
    int empId;
    int empLevel;               // employee's level
    int empJoiningYear;         // employee's joining year
    string empName;             // "<firstname> <lastname" of employee
    string empPhone;            // phone number of the employee

    LLNode* next  = NULL;       // pointer to the next node in LL

    // Constructor
    LLNode(int empId_, string empName_, int empLevel_, string empPhone_, int empJoiningYear_) {
        empId = empId_; empName = empName_; empLevel = empLevel_;
        empPhone = empPhone_; empJoiningYear = empJoiningYear_;
    }
};


struct TreeNode {

    char lastInitial;           // first character of last name
    LLNode*   head   = NULL;    // associated linked list

    TreeNode* parent = NULL;    // pointer to parent of this BST node
    TreeNode* left   = NULL;    // pointer to left child of this BST node
    TreeNode* right  = NULL;    // pointer to right child of this BST node

    // Constructor
    TreeNode(char lastInitial_) { lastInitial = lastInitial_; }
};


class EmployeeDirectory{
    private:
        TreeNode* root;

    public:
        // [HELPER FUNCTIONS]
        char getLastInitial(string name);
        void printEmployee(LLNode* n);

        // [TO BE IMPLEMENTED]
        EmployeeDirectory();
        ~EmployeeDirectory();
        TreeNode* searchCharNode(char key);
        void showEmployeeDirectory();
        LLNode* searchEmployee(int empId, string empName);
        void insertEmployee(int empId, string empName, int empLevel, string empPhone, int empJoiningYear);
        void removeEmployee(int empId, string empName);
        void leftRotate(TreeNode* curr);
};

#endif