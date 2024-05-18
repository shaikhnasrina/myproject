#include <iostream>
#include <conio.h>
#include <fstream>
#include <stdlib.h>
using namespace std;

class Shope
{
private:
    int product_code;
    int product_parice;
    float product_discount;
    string product_name;

public:
    void menu();
    void shopKeper();
    void buyer();
    void add_Product();
    void edit_Product();
    void remove_Product();
    void display_Product();
    void buy_Product();
    void invoic(int(*), int(*), int);
};

void Shope::menu()
{
    system("clear");
    int choice;
    string email, password;

    cout << "________________________Login________________________\n";
    cout << "                                                     \n";
    cout << "              1)Shopkeper                            \n";
    cout << "                                                     \n";
    cout << "              2)Sells                                \n";
    cout << "                                                     \n";
    cout << "              3)Exit                                 \n";
    cout << "_____________________________________________________\n";
m:
    cout << " Enter code For login : ";
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
        cout << "                  Email : ";
        cin >> email;
        cout << "               Password : ";
        cin >> password;
        if (email == "aaftab@gmail.com" && password == "aaftab_shekh")
        {
            shopKeper();
        }
        else
        {
            cout << "ERROR Email Or Password is incorect ";
            menu();
        }
        break;
    }

    case 2:
    {
        buyer();
        break;
    }

    case 3:
    {
        exit(0);
        break;
    }
    default:
    {
        cout << " Wrong choice plz try again \n";
        goto m;
    }
    }
}

void Shope::shopKeper()
{

    int choice;

    cout << "________________________GODOWN________________________\n";
    cout << "                                                      \n";
    cout << "|                 1. Add new stock                  | \n";
    cout << "|                                                   | \n";
    cout << "|                 2. Modify old stock               | \n";
    cout << "|                                                   | \n";
    cout << "|                 3. Remove any old stock           | \n";
    cout << "|                                                   | \n";
    cout << "|                 4. Display All Products           | \n";
    cout << "|                                                   | \n";
    cout << "|                 5. Back to login page             | \n";
    cout << "|                                                   | \n";
    cout << "|___________________________________________________|_\n";
m:
    cout << " What you want to do : ";
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        add_Product();
        break;
    }
    case 2:
    {
        edit_Product();
        break;
    }
    case 3:
    {
        remove_Product();
        break;
    }
    case 4:
    {
        display_Product();
        shopKeper();
        break;
    }
    case 5:
    {
        menu();
        break;
    }
    default:
    {
        cout << " ERROR SOME MISTACK HEAR PL TRY AGAIN \n";
        goto m;
    }
    }
}

void Shope::add_Product()
{
    fstream data;

    int pCode;
    int pPrice;
    float pDis;
    string pName;

m:
    int checker = 0;
    cout << " Enter ID of Product : ";
    cin >> product_code;
    cout << " Enter price of Product : ";
    cin >> product_parice;
    cout << " Enter name of Product : ";
    cin >> product_name;
    cout << " Enter discount on " << product_name << " : ";
    cin >> product_discount;

    data.open("godown.txt", ios::in);
    if (!data)
    {
        data.open("godown.txt", ios::app | ios::out);
        data << product_code << " " << product_parice << " " << product_name << " " << product_discount << "\n";
        data.close();
    }
    else
    {
        data >> pCode >> pPrice >> pName >> pDis;
        while (!data.eof())
        {
            if (pCode == product_code)
            {
                checker++;
            }
            data >> pCode >> pPrice >> pName >> pDis;
        }
        data.close();
        if (checker == 1)
        {
            cout << product_name << " This Product alrday exits in our Godown \n";
            data.close();
            goto m;
        }
        else
        {
            data.open("godown.txt", ios::app | ios::out);
            data << product_code << " " << product_parice << " " << product_name << " " << product_discount << "\n";
            data.close();
        }
    }
    shopKeper();
}

void Shope::edit_Product()
{
    display_Product();

    fstream data, dataTmp;

    int pCode;
    int pPrice;
    float pDis;
    string pName;
    int pkey;

    int checker = 0;

    cout << " Enter product id which you want to \"Modifay\" \n ";
    cin >> pkey;

    data.open("godown.txt", ios::in);
    if (!data)
    {
        cout << "  Stock is Empty \n";
    }
    else
    {
        dataTmp.open("godown1.txt", ios::app | ios::out);

        data >> pCode >> pPrice >> pName >> pDis;
        while (!data.eof())
        {
            if (pCode == pkey)
            {
                cout << " Enter ID of Product : ";
                cin >> product_code;
                cout << "Enter price of Product : ";
                cin >> product_parice;
                cout << " Enter name of Product : ";
                cin >> product_name;
                cout << " Enter discount on " << product_name << " : ";
                cin >> product_discount;

                dataTmp << product_code << " " << product_parice << " " << product_name << " " << product_discount << "\n";
                cout << " Record Modify succsefully \n";
                checker++;
            }
            else
            {
                dataTmp << " " << pCode << " " << pPrice << " " << pName << " " << pDis << "\n";
            }
            data >> pCode >> pPrice >> pName >> pDis;
        }
    }
    data.close();
    dataTmp.close();
    if (checker == 1)
    {
        cout << " Modifay product succefully \n\n";
        remove("godown.txt");
        rename("godown1.txt", "godown.txt");
    }
    else
    {
        cout << " ERROR Product not found ";
        rename("godown1.txt", "godown.txt");
    }

    shopKeper();
}

void Shope::remove_Product()
{
    display_Product();
    fstream data, dataTmp;

    int pkey;
    int checker = 0;

    cout << " Enter ID of Product which you want to Remove : ";
    cin >> pkey;

    data.open("godown.txt", ios::in);

    if (!data)
    {
        cout << " Godown is empty \n";
    }
    else
    {
        dataTmp.open("godown1.txt", ios::app | ios::out);

        data >> product_code >> product_parice >> product_name >> product_discount;
        while (!data.eof())
        {
            if (product_code == pkey)
            {
                checker++;
            }
            else
            {
                dataTmp << " " << product_code << " " << product_parice << " " << product_name << " " << product_discount << "\n";
            }
            data >> product_code >> product_parice >> product_name >> product_discount;
        }
        data.close();
        dataTmp.close();
    }

    if (checker == 1)
    {
        cout << " Remove from Godown product succefully \n";
        remove("godown.txt");
        rename("godown1.txt", "godown.txt");
    }
    else
    {
        cout << " ERROR Product not found ";
        remove("godown1.txt");
    }
    shopKeper();
}

void Shope::display_Product()
{
    fstream data;
    int pCode;
    int pPrice;
    float pDis;
    data.open("godown.txt", ios::in);
    string pName;

    if (!data)
    {
        cout << " Godwpn is empty \n";
    }
    else
    {
        cout << "------------------------------List of items ------------------------------\n\n\n\n";
        cout << "| ID "
             << "| Price "
             << "| Name"
             << "\n";
        data >> pCode >> pPrice >> pName >> pDis;
        cout << "\n___________________________________________________________________________\n";
        while (!data.eof())
        {
            cout << "| " << pCode << " | " << pPrice << " | " << pName << "\n";
            data >> pCode >> pPrice >> pName >> pDis;
        }
        cout << "\n\n\n\n";
        data.close();
    }
}

void Shope::buyer()
{

    int choice;
    cout << "\n\n*********************************WellCome to our shope**********************************\n";
    cout << "|                                                                                          |\n";
    cout << "|               1)Clicl 1 to buy products                                                 |\n";
    cout << "|                                                                                          |\n";
    cout << "|               2)Back to main menu                                                        |\n";
    cout << "|                                                                                          |\n";
    cout << "********************************************************************************************\n";
m:
    cout << "Enter Your choice : ";
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        buy_Product();
        break;
    }
    case 2:
    {
        menu();
        break;
    }
    default:
    {
        cout << "Invelid choice \n";
        goto m;
    }
    }
}

void Shope::buy_Product()
{
    int arrProductCode[100];
    int arrQuntityOfProduct[100];
    string name, Mobile_number, date;
    char yes_no;
    int counter = 0;

    cout << "Enter coustmor name : ";
    cin >> name;
    cin.clear();
    cout << "Enter Mobile number : ";
    cin >> Mobile_number;
    cout << " Enter date :";
    cin >> date;

    fstream bill;
    bill.open("BILL.txt", ios::app | ios::out);

    bill << "\n name : " << name << "\n";

    bill << " mobile NO:" << Mobile_number << "\n";

    bill << " date: " << date << "\n\n\n";

    bill.close();
    fstream data;
    display_Product();
m:
    do
    {
        cout << "\n Enter product code: ";
        cin >> arrProductCode[counter];
        cout << "\n Enter product quntity: ";
        cin >> arrQuntityOfProduct[counter];

        // for (int i = 0; i < counter; i++)
        // {
        //     if (arrProductCode[counter] == arrProductCode[i])
        //     {
        //         cout << " Duplicate order plz try agian \n";
        //         goto m;
        //     }
        // }
        counter++;
        cout << " Do you want to buy another product : yes = y AND no = n ";
        cin >> yes_no;
    } while (yes_no == 'y');

    invoic(&arrProductCode[0], &arrQuntityOfProduct[0], counter);
    buyer();
}

void Shope::invoic(int *arrProductCode, int *arrQuntityOfProduct, int counter)
{

    int pCode;
    int pPrice;
    float pDis;
    string pName;

    int amount = 0;
    float total = 0;
    fstream data;
    fstream bill;
    bill.open("BILL.txt", ios::app | ios::out);
    cout << "____________________________________________________BILL____________________________________________________\n";
    cout << "\tID\t\t\tNAME\t\tQuntity\t\tPricet\t\tAmount\t\tTotle-(With discount)\n";
    bill << "____________________________________________________BILL____________________________________________________\n";
    bill << "\tID\t\t\tNAME\t\tQuntity\t\tPricet\t\tAmount\t\tTotle-(With discount)\n";

    for (int i = 0; i <= counter; i++)
    {
        data.open("godown.txt", ios::in);
        data >> product_code >> product_parice >> product_name >> product_discount;

        while (!data.eof())
        {
            if (product_code == arrProductCode[i])
            {
                amount = product_parice * arrQuntityOfProduct[i];
                product_discount = amount - (amount * (product_discount / 100));
                total = total + product_discount;
                bill << "\t" << product_code << "\t\t" << product_name << "\t\t" << arrQuntityOfProduct[i] << "\t\t" << product_parice << "\t\t" << amount << "\t\t\t" << product_discount << "\n";
                cout << "\t" << product_code << "\t\t\t" << product_name << "\t\t" << arrQuntityOfProduct[i] << "\t\t" << product_parice << "\t\t" << amount << "\t\t\t" << product_discount << "\n";
            }
            data >> product_code >> product_parice >> product_name >> product_discount;
        }
        data.close();
    }
    cout << "-----------------------------------------------------------------------------------------------------------\n";
    cout << "\n Totle bill is :" << total;
    bill << "-----------------------------------------------------------------------------------------------------------\n";
    bill << "\n Totle bill is :" << total;
    bill.close();
}

int main()
{
    Shope s1;
    s1.menu();
}