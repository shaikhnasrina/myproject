#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <stdlib.h>

using namespace std;

class Student
{
private:
    string subjects[6][4];
    int Roll_number;
    string name;
    int currnt_sem;
    string degree = "B.C.A";

public:
    void office();
    void addmition();
    void getDetailofStudent();
    void setMarks();
    void setSubjects();
    void subjectsNameStore();
    void getDetailofStudentAllStudent();

    Student()
    {
        subjectsNameStore();
        office();
    }
};

void Student::subjectsNameStore()
{
    subjects[0][0] = "TECHNICAL COMMUNICATION SKILL";
    subjects[0][1] = "PROBLEM SOLVING METHODOLOGIS AND PROGRAMMING IN C";
    subjects[0][2] = "COMPUTER FUNDAMENTALS AND EMERGING TECHNOLOGY";
    subjects[0][3] = "NETWORKING & INTERNET ENVIRONMENT";

    subjects[1][0] = "DATA STRUCTURE USING C LANGUAGE";
    subjects[1][1] = "WEB PROGRAMMING";
    subjects[1][2] = "COMPUTER ORGANIZATION & ARCHITECTURE";
    subjects[1][3] = "MATHEMATICAL AND STATISTICAL FOUNDATION OF COMPUTER SCIENCE";

    subjects[2][0] = "SAD, Software Quality Assurance and Testing";
    subjects[2][1] = "C++ and Object Oriented Programming";
    subjects[2][2] = "RDBMS Using Oracl";
    subjects[2][3] = "Content Management System using Word Press";

    subjects[3][0] = "Programming with JAVA";
    subjects[3][1] = "Programming with C#";
    subjects[3][2] = "Network Technology and Administration";
    subjects[3][3] = "Operating Systems Concepts With Unix / Linux";

    subjects[4][0] = "Advance Java Programming (J2EE)";
    subjects[4][1] = "Programming with ASP.NET";
    subjects[4][2] = "Web Searching Technology and Search Engine Optimization";
    subjects[4][3] = "Project Viva";

    subjects[5][0] = "Mobile Application Development in Android using Kotlin";
    subjects[5][1] = "Data Warehousing with SQL Server 2012";
    subjects[5][2] = "Programming in Python";
    subjects[5][3] = "Project Viva";
}

void Student::setSubjects()
{
    fstream data;

    data.open("Sem_1_Subjects.txt", ios::app | ios::out);
    for (int i = 0; i <= 3; i++)
    {
        data << subjects[0][i] << endl;
    }
    data.close();
    data.open("Sem_2_Subjects.txt", ios::app | ios::out);
    for (int i = 0; i <= 3; i++)
    {
        data << subjects[1][i] << endl;
    }
    data.close();
    data.open("Sem_3_Subjects.txt", ios::app | ios::out);
    for (int i = 0; i <= 3; i++)
    {
        data << subjects[2][i] << endl;
    }
    data.close();
    data.open("Sem_4_Subjects.txt", ios::app | ios::out);
    for (int i = 0; i <= 3; i++)
    {
        data << subjects[3][i] << endl;
    }
    data.close();
    data.open("Sem_5_Subjects.txt", ios::app | ios::out);
    for (int i = 0; i <= 3; i++)
    {
        data << subjects[4][i] << endl;
    }
    data.close();
    data.open("Sem_6_Subjects.txt", ios::app | ios::out);
    for (int i = 0; i <= 3; i++)
    {
        data << subjects[5][i] << endl;
    }
    data.close();
}

string give_inName(string name)
{
    for (int i = 0; i < sizeof(name); i++)
    {
        if (name[i] == ' ')
        {
            name[i] = '_';
        }
    }
    return name;
}

void Student::office()
{

    int choice;
    string email, password;
    cout << "\n\n\n\t\t\t\t----------------------------B.C.A. OFFICE---------------------------\n";
    cout << "\t\t\t\t|                                                                  |\n";
    cout << "\t\t\t\t|                          1)ADDMITION                             |\n";
    cout << "\t\t\t\t|                                                                  |\n";
    cout << "\t\t\t\t|                          2)List of Student                       |\n";
    cout << "\t\t\t\t|                                                                  |\n";
    cout << "\t\t\t\t|                          3)Get details of Student                |\n";
    cout << "\t\t\t\t|                                                                  |\n";
    cout << "\t\t\t\t|                          4)Set Marks in Each Subject             |\n";
    cout << "\t\t\t\t|                                                                  |\n";
    cout << "\t\t\t\t|                          5)EXIT                                  |\n";
    cout << "\t\t\t\t|                                                                  |\n";
    cout << "\t\t\t\t--------------------------------------------------------------------\n";
up:
    cout << "\n\n \tEnter what you want to do : ";
    cin >> choice;

    switch (choice)
    {
    case 1:
    {

        cout << "\n Email : ";
        cin >> email;
        cin.ignore();
        cout << " Password : ";
        getline(cin, password);
        if (email == "aaftab@gmail.com" && password == "aaftab shekh")
            addmition();
        else
        {
            cout << " Email or Password is incorect plz try agian" << endl;
            cout << " -----------Press any key-----------";
            getch();
            system("cls");
            office();
        }
        break;
    }

    case 2:
    {
        getDetailofStudentAllStudent();
        office();
        break;
    }

    case 3:
    {
        getDetailofStudent();
        office();
        break;
    }

    case 4:
    {

        cout << "\n Email : ";
        cin >> email;
        cin.ignore();
        cout << " Password : ";
        getline(cin, password);
        if (email == "aaftab@gmail.com" && password == "aaftab shekh")
            setMarks();
        else
        {
            cout << " Email or Password is incorect plz try agian" << endl;
            cout << " -----------Press any key-----------";
            getch();
            system("cls");
            office();
        }

        break;
    }

    case 5:
    {
        exit(1);
    }

    default:
    {
        cout << " Invelid choice plz try agian" << endl;
        goto up;
    }
    }
}

void Student::addmition()
{
    int Copy_Rno;
    string Copy_name;
    int Copy_cs;
    string Copy_degree;
up:
    int check = 0;
    cout << "\n\n Enter Roll number : ";
    cin >> Roll_number;
    fstream data, data1, dataTmp;
    data.open("studentDetail.txt", ios::in);

    if (!data)
    {
        dataTmp.open("studentDetail.txt", ios::out | ios::app);
        dataTmp.close();
    }
    else
    {
        do
        {
            data >> Copy_Rno >> Copy_name >> Copy_cs >> Copy_degree;

            if (Roll_number == Copy_Rno)
            {
                cout << " This Roll number alrady exist Re_enter Roll number " << endl;
                data.close();
                check++;
                goto up;
            }
        } while (!data.eof());
        data.close();
    }

    data1.open("studentDetail.txt", ios::app | ios::out);

    cin.ignore();

    cout << " Enter stduent name : ";
    getline(cin, name);
    name = give_inName(name);
go:
    cout << " Enter student sem : ";
    cin >> currnt_sem;

    if (currnt_sem > 7 || currnt_sem < 0)
    {
        cout << " Invelid Sem plz enter 1 to 6 only : " << endl;
        goto go;
    }

    data1 << Roll_number << " " << name << " " << currnt_sem << " " << degree << "\n";
    data1.close();
    cout << "\n\n Data Enter succsefully !!!" << endl;

    cout << " -----------Press any key-----------";
    getch();
    system("cls");
    office();
}

void Student::getDetailofStudentAllStudent()
{
    int Copy_Rno = 0;
    string Copy_name;
    int Copy_cs;
    string Copy_degree;
    fstream data;
    int counter = 0;

    data.open("studentDetail.txt", ios::in);
    data >> Copy_Rno >> Copy_name >> Copy_cs >> Copy_degree;

    cout << "\n\n";
    if (!data)
    {
        cout << " DATA BASE EMPTY !!!!" << endl;
        cout << "-----> Plz take few Addmition <-----";
        office();
    }
    while (!data.eof())
    {

        cout << "ID " << Copy_Rno
             << " " << Copy_name << endl;
        data >> Copy_Rno >> Copy_name >> Copy_cs >> Copy_degree;
        counter++;
    }
    data.close();
    cout << "\n\n--------------------------\n";
    cout << "|                         |\n";
    if (counter < 10)
        cout << "| Totle Student is : 00" << counter << "  |" << endl;
    else if (counter < 100)
        cout << "| Totle Student is : 0" << counter << "  |" << endl;
    else
        cout << "| Totle Student is : " << counter << "  |" << endl;
    cout << "|                         |\n";
    cout << "--------------------------\n";

    if (counter == 0)
    {
        cout << " No any Student  availabe plz take few addmition first " << endl;
        cout << "*****************Press any key*****************";
        getch();
        system("cls");
        office();
    }

    cout << " -----------Press any key-----------";
    getch();
    system("cls");
}

void Student::getDetailofStudent()
{

    getDetailofStudentAllStudent();

    int Copy_Rno = 0;
    string Copy_name;
    int Copy_cs;
    string Copy_degree;
    int key;
    int cheker = 0;
    char yes_no;
    cout << "Enter ID for serch : ";
    cin >> key;
    system("cls");

    fstream data;
    data.open("studentDetail.txt", ios::in);
    data >> Copy_Rno >> Copy_name >> Copy_cs >> Copy_degree;

    while (!data.eof())
    {
        if (key == Copy_Rno)
        {
            Roll_number = Copy_Rno;
            name = Copy_name;
            currnt_sem = Copy_cs;
            degree = Copy_degree;

            cout << " Name : " << name << endl
                 << " Roll number :" << Roll_number << endl
                 << " Currnt same : " << currnt_sem << endl
                 << " Pursuing degree : " << degree << endl;
            cheker++;
        }
        data >> Copy_Rno >> Copy_name >> Copy_cs >> Copy_degree;
    }
    data.close();
    if (cheker == 0)
    {
        cout << " Data not found plz check Roll number !!!" << endl;
        getDetailofStudentAllStudent();
        getDetailofStudent();
    }

    // cout << "  if you go to office press (yes=y) other wise (no=n)";
    // cin >> yes_no;
    cout << " -----------Press any key-----------";
    getch();
    system("cls");

    // if (yes_no == 'y')
    // {
    //     office();
    // }
}

void Student::setMarks()
{
    fstream dataTmp;
    dataTmp.open("Sem_1_Subjects.txt", ios::in);
    if (!dataTmp)
    {
        setSubjects();
    }
    dataTmp.close();

    int totle = 0;
    int keySem;
    int i;
    int Marks[7][4];
    int faill = 0;
    int pr1, pr2;

    string Subjects[4];
    fstream Markshit;

    getDetailofStudent();
o:
    cout << " Enter sam for creat result : ";
    cin >> keySem;

    if (keySem > currnt_sem || keySem < 0)
    {
        cout << " This Student in sem : " << currnt_sem << " plz Enter valid sam ";
        goto o;
    }
    switch (keySem)
    {
    case 1:
    {
        Markshit.open("Sem_1_Markshit.txt", ios::app | ios::out);
        break;
    }
    case 2:
    {
        Markshit.open("Sem_2_Markshit.txt", ios::app | ios::out);
        break;
    }
    case 3:
    {
        Markshit.open("Sem_3_Markshit.txt", ios::app | ios::out);
        break;
    }

    case 4:
    {
        Markshit.open("Sem_4_Markshit.txt", ios::app | ios::out);
        break;
    }

    case 5:
    {
        Markshit.open("Sem_5_Markshit.txt", ios::app | ios::out);
        break;
    }

    case 6:
    {
        Markshit.open("Sem_6_Markshit.txt", ios::app | ios::out);
        break;
    }

    default:
        cout << "\n\n 404 ERROR \n\n";
    }

    for (i = 0; i <= 3; i++)
    {
        Subjects[i] = subjects[keySem - 1][i];
    }

    Markshit << " Name : " << name << "\n";
    cout << " Name : " << name << "\n";
    Markshit << " Roll number : " << Roll_number << "\n";
    cout << " Roll number : " << Roll_number << "\n";
    Markshit << " Sem : " << currnt_sem << "\n";
    cout << " Sem : " << currnt_sem << "\n";
    Markshit << " Degree : " << degree << "\n";
    cout << " Degree : " << degree << "\n";
mm:
    for (i = 0; i < 4; i++)
    {
        cout << endl
             << " Enter marks of ->" << Subjects[i] << " : ";
        cin >> Marks[keySem][i];
    }

    cout << endl
         << " Enter marks of ->LOCAL Prectical : ";
    cin >> pr1;

    cout << endl
         << " Enter marks of ->LOCAL Viva : ";
    cin >> pr2;

    if ((Marks[keySem][0] < 0) || (Marks[keySem][0] > 101) || (Marks[keySem][1] < 0) || (Marks[keySem][1] > 101) || (Marks[keySem][2] < 0) || (Marks[keySem][2] > 101) || (Marks[keySem][3] < 0) || (Marks[keySem][3] > 101) || (pr1 < 0) || (pr1 > 101) || (pr2 < 0) || (pr2 > 101))
    {
        cout << " given marks is Wrong plz give marks 1 to 100 only " << endl;
        goto mm;
    }

    system("cls");

    Markshit << endl
             << " Result Of Sem - " << keySem << endl;
    cout << endl
         << " Result Of Sem - " << keySem << endl;
    Markshit << endl
             << "**************************************************************************" << endl;
    cout << endl
         << "**************************************************************************" << endl;
    for (i = 0; i < 4; i++)
    {
        Markshit << endl
                 << Subjects[i] << " Marks : ";
        Markshit << Marks[keySem][i] << endl;
        totle += Marks[keySem][i];
        Markshit << endl;
        cout << endl
             << Subjects[i] << " Marks : ";
        cout << Marks[keySem][i] << endl;
        cout << endl
             << "--------------------------------------------------------------------" << endl;
    }
    Markshit << endl
             << "LOCAL Prectical"
             << " Marks : ";
    Markshit << pr1 << endl;
    Markshit << endl
             << "--------------------------------------------------------------------" << endl;
    totle += pr1;
    Markshit << endl
             << "LOCAL Viva"
             << " Marks : ";
    Markshit << pr2 << endl;
    totle += pr2;
    cout << endl
         << "LOCAL Prectical"
         << " Marks : ";
    cout << pr1 << endl;
    cout << endl
         << "--------------------------------------------------------------------" << endl;
    cout << endl
         << "LOCAL Viva"
         << " Marks : ";
    cout << pr2 << endl;

    Markshit << endl
             << "**************************************************************************" << endl;
    cout << endl
         << "**************************************************************************" << endl;

    Markshit << " Totle : " << totle << "/600" << endl;
    Markshit << " Percentage : " << float(totle / 6.0) << endl;
    cout << " Totle : " << totle << "/600" << endl;
    cout << " Percentage : " << float(totle / 6.0) << endl;
    if (Marks[keySem][0] < 28)
    {
        Markshit << " " << Subjects[0] << " : Faill" << endl;
        cout << " " << Subjects[0] << " : Faill" << endl;
        faill++;
    }
    if (Marks[keySem][1] < 28)
    {
        Markshit << " " << Subjects[1] << " : Faill" << endl;
        cout << " " << Subjects[1] << " : Faill" << endl;
        faill++;
    }
    if (Marks[keySem][2] < 28)
    {
        Markshit << " " << Subjects[2] << " : Faill" << endl;
        cout << " " << Subjects[2] << " : Faill" << endl;
        faill++;
    }
    if (Marks[keySem][3] < 28)
    {
        Markshit << " " << Subjects[3] << " : Faill" << endl;
        cout << " " << Subjects[3] << " : Faill" << endl;
        faill++;
    }
    if (pr1 < 28)
    {
        Markshit << " "
                 << "LOCAL Prectical"
                 << " : Faill" << endl;
        cout << " "
             << "LOCAL Prectical"
             << " : Faill" << endl;
        faill++;
    }
    if (pr2 < 28)
    {
        Markshit << " "
                 << "LOCAL Viva"
                 << " : Faill" << endl;
        cout << " "
             << "LOCAL Viva"
             << " : Faill" << endl;
        faill++;
    }

    if ((totle / 6.0) < 40)
    {
        Markshit << " minimum percentage is 40 or above Your percentage is " << (float)totle / 6.0 << " : Faill" << endl;
        cout << " minimum percentage is 40 or above Your percentage is " << (float)totle / 6.0 << " : Faill" << endl;
        faill++;
    }
    else if (faill != 1)
    {
        Markshit << " PASS  " << endl;
        cout << " PASS " << endl;
    }

    if(faill==1)
    {
    cout<<" FAILL "<<endl;
    }

    Markshit << " SGPA : " << (totle / 6.0) / 10.0;
    cout << " SGPA : " << (totle / 6.0) / 10.0;

    faill = 0;

    Markshit << endl
             << "=====================================================================================" << endl;
    cout << endl
         << "=====================================================================================" << endl;

    Markshit.close();
    cout << "\n\n\n ---->Mark shit available on this path file derectory<----\n\n\n";
    cout << " -----------Press any key-----------";
    getch();
    system("cls");
    office();
}

int main()
{
    Student s1;
    return 0;
}