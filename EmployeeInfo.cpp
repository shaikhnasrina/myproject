#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Employee
{
private:
    int id;
    string name;
    short age;
    int salary;
    string department;

public:
    Employee()
    {
        id = 0;
        name = '\0';
        age = 0;
        salary = 0;
        department = '\0';
        cout << " Employee of";
    }

    void setId(void);
    void setName(void);
    void setAge(void);
    void setSalary(void);
    void setDprt(void);

    void getId(void);
    void getName(void);
    void getAge(void);
    void getSalary(void);
    void getDprt(void);

    void setDetail(void);
    void getDetail(void);
};

void Employee ::setId(void)

{
    cout << endl
         << " Enter Employee id : ";
    cin >> id;
}

void Employee ::setName(void)
{
    cout << " Enter Employee name : ";
    cin >> name;
}

void Employee ::setAge(void)
{
    cout << " Enter Employee Age : ";
    cin >> age;
}

void Employee ::setSalary(void)
{
    cout << " Enter Employee salary : ";
    cin >> salary;
}

void Employee ::setDprt(void)
{
    cout << " Enter Employee department : ";
    cin >> department;
}

void Employee ::getId(void)
{
    cout << "<--- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --->" << endl
         << " Employee Id is : " << id << endl;
}

void Employee ::getName(void)
{
    cout << " Employee name is : " << name << endl;
}

void Employee ::getAge(void)
{
    cout << " Employee Age is : " << age << endl;
}

void Employee ::getSalary(void)
{
    cout << " Employee Salary is : " << salary << endl;
}

void Employee ::getDprt(void)
{
    cout << " Employee Department is : " << department << endl;
}

void Employee ::setDetail()
{
    setId();
    setName();
    setAge();
    setSalary();
    setDprt();
}

void Employee ::getDetail()
{
    getId();
    getName();
    getAge();
    getSalary();
    getDprt();
}

class Programmer : public Employee
{
private:
    int lanhuage_code;
    string language;

public:
    Programmer()
    {
        cout << " Programer ";
    }
    void setLanguage(void);
    void getLanguage(void);

    void setDetail()
    {
        Employee ::setDetail();
        setLanguage();
    }
    void getDetail()
    {
        Employee ::getDetail();
        getLanguage();
    }
};

void Programmer ::setLanguage()
{
    cout << " ******************************************** " << endl;
    cout << " 1.C language" << endl;
    cout << " 2.C puls puls" << endl;
    cout << " 3.Java" << endl;
    cout << " 4.Paython" << endl;
    cout << " 5.Fluter" << endl;
    cout << " ******************************************** " << endl;
    int i = 1;
    while (i == 1)
    {
        cout << " Enter code of language : ";
        cin >> lanhuage_code;

        switch (lanhuage_code)
        {
        case 1:
        {
            language = "C language";
            i++;
            break;
        }
        case 2:
        {
            language = "C puls puls";
            i++;
            break;
        }
        case 3:
        {
            language = "Java";
            i++;
            break;
        }
        case 4:
        {
            language = "Paython";
            i++;
            break;
        }
        case 5:
        {
            language = "Fluter";
            i++;
            break;
        }
        default:
        {
            cout << " invelid Code " << endl;
            int i = 1;
        }
        }
    }
}

void Programmer ::getLanguage()
{
    cout << " Programmer language is : " << language << endl;
}

class FullStack : public Programmer
{
private:
    string dataBase;

public:
    FullStack()
    {
        cout << " With full stack devloper ";
    }
    void setDB(void);
    void getDB(void);

    void setDetail(void)
    {
        Programmer ::setDetail();
        setDB();
    }

    void getDetail()
    {
        Programmer ::getDetail();
        getDB();
    }
};

void FullStack ::setDB(void)
{
    int DB_Code;
    cout << " ------------------------------------------- " << endl;
    cout << " 1.MySql" << endl;
    cout << " 2.NoSql" << endl;
    cout << " 3.Oracle" << endl;
    cout << " 4.MongoDB" << endl;
    cout << " 5.SqlLite" << endl;
    cout << " ------------------------------------------- " << endl;
    int i = 1;
    while (i == 1)
    {
        cout << " Enter code of DataBase : ";
        cin >> DB_Code;

        switch (DB_Code)
        {
        case 1:
        {
            dataBase = "MySql";
            i++;
            break;
        }
        case 2:
        {
            dataBase = "NoSql";
            i++;
            break;
        }
        case 3:
        {
            dataBase = "Oracle";
            i++;
            break;
        }
        case 4:
        {
            dataBase = "MongoDB";
            i++;
            break;
        }
        case 5:
        {
            dataBase = "SqlLite";
            i++;
            break;
        }
        default:
        {
            cout << " invelid Code " << endl;
            int i = 1;
        }
        }
    }
}

void FullStack ::getDB(void)
{
    cout << " Currnt using data base is : " << dataBase;
}

class Compnay{
    public:
    Compnay(){
    Employee e1;
    Programmer p1;
    FullStack f1;

    int choice;
    cout << "Enter Postion of Employee \n 1.Fresher \n 2.Programmer \n 3.FullStack \n";
    cin >> choice;
    switch (choice)
    {
    case 1:

        e1.setDetail();
        e1.getDetail();
        break;

    case 2:
        p1.setDetail();
        p1.getDetail();
        break;

    case 3:
        f1.setDetail();
        f1.getDetail();
        break;

    default:
        cout << "Invelid choice";
    }
    }
};

int main()
{
    Compnay c1;


    return 0;
}