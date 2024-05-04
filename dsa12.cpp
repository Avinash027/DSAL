#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib> // For exit()

using namespace std;

const int MAX_NAME_LENGTH = 50;
const int MAX_DESIGNATION_LENGTH = 50;

struct Employee {
    int employeeID;
    char name[MAX_NAME_LENGTH];
    char designation[MAX_DESIGNATION_LENGTH];
    double salary;
};

void createFiles() {
    ofstream dataFile("employee_data.dat");
    ofstream indexFile("employee_index.dat");
    if (!dataFile || !indexFile) {
        cerr << "Error creating files!" << endl;
        exit(1);
    }
    cout << "Files created successfully!" << endl;
}

void addEmployee(fstream& file) {
    Employee employee;
    cout << "Enter employee ID: ";
    cin >> employee.employeeID;
    cout << "Enter employee name: ";
    cin.ignore();
    cin.getline(employee.name, MAX_NAME_LENGTH);
    cout << "Enter employee designation: ";
    cin.getline(employee.designation, MAX_DESIGNATION_LENGTH);
    cout << "Enter employee salary: ";
    cin >> employee.salary;
    file.write(reinterpret_cast<char*>(&employee), sizeof(Employee));
    cout << "Employee added successfully!" << endl;
}

void deleteEmployee(fstream& file)
{
int employeeID; bool found = false;
Employee employee; cout << "Enter employee ID to delete: "; cin >>employeeID;
fstream tempfile("temp.dat", ios::out | ios::binary); file.seekg(0, ios::beg);
while (file.read(reinterpret_cast<char*>(&employee), sizeof(Employee)))
{
if (employee.employeeID != employeeID)
{
tempfile.write(reinterpret_cast<char*>(&employee), sizeof(Employee));
}
else
{
found = true;
}
}
file.close(); tempfile.close();
remove("employee_data.dat");
rename("temp.dat", "employee_data.dat");
if (found)
{
cout << "Employee deleted successfully!" << endl;
}
else
{
cout << "Employee not found!" << endl;
}
file.open("employee_data.dat", ios::in | ios::out | ios::binary);
}
void displayEmployee(fstream& file)
{
int employeeID; bool found = false;
Employee employee; cout << "Enter employee ID to display: "; cin >>employeeID;
file.seekg(0, ios::beg); while
(file.read(reinterpret_cast<char*>(&employee), sizeof(Employee)))
{
if (employee.employeeID == employeeID)
{
found = true;
break;
}
}
if (found)
{
cout << "Employee ID: " << employee.employeeID << endl; cout << "Name: " << employee.name << endl; cout << "Designation: " << employee.designation << endl; cout << "Salary: " << employee.salary << endl;
}
else
{
cout << "Employee not found!" << endl;
}
}

int main() {
    // Create files if they don't exist
    ifstream dataFile("employee_data.dat");
    ifstream indexFile("employee_index.dat");
    if (!dataFile || !indexFile) {
        cout << "Files do not exist. Creating them..." << endl;
        createFiles();
    }

    // Open files for reading and writing
    fstream dataFileStream("employee_data.dat", ios::in | ios::out | ios::binary);
    if (!dataFileStream) {
        cerr << "Error opening data file!" << endl;
        return 1;
    }

    // Continue with the rest of the program
    while (true) {
        cout << "\nEmployee Information System" << endl;
        cout << "1. Add Employee" << endl;
        cout << "2. Delete Employee" << endl;
        cout << "3. Display Employee" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        switch (choice) {
            case 1:
                addEmployee(dataFileStream);
                break;
            case 2:
                deleteEmployee(dataFileStream);
                break;
            case 3:
                displayEmployee(dataFileStream);
                break;
            case 4:
                dataFileStream.close();
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
