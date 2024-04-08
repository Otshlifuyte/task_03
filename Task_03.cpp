#include <iostream>
#include <string>
using namespace std;

class User {
protected:
    string name;

public:
    User(string name) : name(name) 
    {

    }
    virtual void accessResources() const {
        cout << name << " has basic user access." << endl;
    }
    virtual ~User() {}
};

class Employee : public virtual  User
{
public:
    string specialization;
    string tasks;

    Employee(string name, string specialization, string tasks) : User(name) {
        this->specialization = specialization;
        this->tasks = tasks;
    }

    void accessResources() const override  {
        cout << name << " has access to recourses for staff" << endl;
        cout << specialization << endl;
        cout << tasks << endl;

    }

};

class Manager : public virtual  User
{
public:
    string resourses;

    Manager(string name, string resources) : User(name) {
        this->resourses = resources;
    }

    void accessResources() const override
    {
        cout << name << "has access to the department recources and beyond" << endl;
        cout << resourses << endl;

    }
};

class Administrator : public Manager, public Employee
{
private:
    string administration;

public:
    Administrator(string name, string resources, string specialization, string tasks, string administration)
        : Manager(name, resources), Employee(name, specialization, tasks), User(name) {
        this->administration = administration;
    }
    
    void accessResources() const override
    {
        cout << name << "has access to recources at all levels" << endl;
        cout << administration << endl;
        cout << resourses << endl;
        cout << specialization << endl;
        cout << tasks << endl;

    }

};


int main() {

    User* currentUser;

    string password;
    cin >> password;

    if (password == "1234")
        currentUser = new Employee("Alex", "Builder", "Crushing");
    else if (password == "5678")
        currentUser = new Manager("Martin", "Documentation");
    else if (password == "0000")
        currentUser = new Administrator("John", "Rules", "Administrator", "Manage employees", "<Admin list>");
    else
        currentUser = new User("Matt");


    currentUser->accessResources();

    return 0;
}


// User class: The base class from which the
// all other classes are inherited. Includes
// basic information about the user (for example, name).

// Employee class: Derived from User, representing
// employee. Adds a level of access to resources specific
// for staff.

// Manager class: Derived from User, representing a manager.
// Managers have a higher level of access than regular ones
// employees, and can manage department resources.

// Administrator class: Derived class that should inherit
// properties and methods from both Employee and Manager. Administrators
// have the highest level of access allowing them to manage resources
// at all levels.

// Implement a class system using virtual inheritance,
// to solve the problem of diamond-shaped inheritance and correctly
// organize a hierarchy of classes User, Employee, Manager and
//Administrator. Every class must provide a method
// accessResources() demonstrating the user's access level.

