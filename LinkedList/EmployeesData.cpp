#include <iostream>
#include <string>
using namespace std;

struct ProjectNode
{
    string projectName;
    string projectCode;
    bool isCompleted;
    ProjectNode *next;

    ProjectNode(const string &pname, const string &pcode, bool status)
    {
        projectName = pname;
        projectCode = pcode;
        isCompleted = status;
        next = nullptr;
    }
};
struct EmployeeData
{
    string name;
    string employeeID;
    ProjectNode *head;

    EmployeeData(const string &n, const string &id)
    {
        name = n;
        employeeID = id;
        head = nullptr;
    }
};

class EmployeeNode
{
public:
    EmployeeData data;
    EmployeeNode *prev;
    EmployeeNode *next;

    EmployeeNode(const EmployeeData &d) : data(d), prev(nullptr), next(nullptr) {}
};

class EmployeeList
{
private:
    EmployeeNode *head;

public:
    EmployeeList() : head(nullptr) {}

    bool addEmployee(const string &employeeID, const string &name)
    {
        EmployeeNode *newEmployee = new EmployeeNode(EmployeeData(name, employeeID));
        if (!head || head->data.employeeID > employeeID)
        {
            newEmployee->next = head;
            if (head)
                head->prev = newEmployee;
            head = newEmployee;
            return true;
        }
        EmployeeNode *current = head;
        while (current->next && current->next->data.employeeID < employeeID)
        {
            current = current->next;
        }
        if (current->data.employeeID == employeeID)
            return false;
        newEmployee->next = current->next;
        newEmployee->prev = current;
        if (current->next)
            current->next->prev = newEmployee;
        current->next = newEmployee;
        return true;
    }

    bool addProject(const string &employeeID, const string &projectName, const string &projectCode, bool isCompleted)
    {
        EmployeeNode *current = head;
        while (current && current->data.employeeID != employeeID)
        {
            current = current->next;
        }
        if (!current)
            return false;
        ProjectNode *newProject = new ProjectNode(projectName, projectCode, isCompleted);
        newProject->next = current->data.head;
        current->data.head = newProject;
        return true;
    }

    bool removeEmployee(const string &employeeID)
    {
        EmployeeNode *current = head;
        while (current && current->data.employeeID != employeeID)
        {
            current = current->next;
        }
        if (!current)
            return false;
        if (current->prev)
            current->prev->next = current->next;
        if (current->next)
            current->next->prev = current->prev;
        if (current == head)
            head = current->next;
        delete current;
        return true;
    }

    void displayEmployee(const string &employeeID)
    {
        EmployeeNode *current = head;
        while (current && current->data.employeeID != employeeID)
        {
            current = current->next;
        }
        if (current)
        {
            cout << "Employee ID: " << current->data.employeeID << ", Name: " << current->data.name << endl;
            ProjectNode *project = current->data.head;
            while (project)
            {
                cout << "- Project Name: " << project->projectName << ", Code: " << project->projectCode << ", Completed: " << (project->isCompleted ? "Yes" : "No") << endl;
                project = project->next;
            }
        }
    }

    void displayAllEmployees(int order)
    {
        if (order == 0)
        {
            EmployeeNode *current = head;
            while (current)
            {
                displayEmployee(current->data.employeeID);
                current = current->next;
            }
        }
        else
        {
            EmployeeNode *current = head;
            while (current && current->next)
                current = current->next;
            while (current)
            {
                displayEmployee(current->data.employeeID);
                current = current->prev;
            }
        }
    }
};
int main()
{
    EmployeeList company;

    company.addEmployee("E001", "Alice Johnson");
    company.addEmployee("E002", "Bob Smith");
    company.addEmployee("E003", "Carol White");

    company.addProject("E001", "Project Alpha", "P100", true);
    company.addProject("E001", "Project Beta", "P101", false);
    company.addProject("E002", "Project Gamma", "P102", true);
    company.addProject("E003", "Project Delta", "P103", false);
    company.addProject("E003", "Project Epsilon", "P104", true);

    cout << "Displaying details of Employee E001:" << endl;
    company.displayEmployee("E001");

    cout << "\nDisplaying all employees in ascending order:" << endl;
    company.displayAllEmployees(0);

    cout << "\nDisplaying all employees in descending order:" << endl;
    company.displayAllEmployees(1);

    company.removeEmployee("E002");

    cout << "\nDisplaying all employees after removing Employee E002:" << endl;
    company.displayAllEmployees(0);

    return 0;
}
