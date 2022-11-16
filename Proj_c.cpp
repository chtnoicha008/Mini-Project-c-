#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
string Id_ar[1000], Name_ar[1000], price_ar[1000];
string com[100][3];

void clear_display();

int Menu();
void Report();
void reset_com();
void AddMenu(string FN);
void DisplayMenu(string FN);
void DisplayMenu_arry(string FN);
void order_menu();
void Total_pay();
void clear_display()
{
    #ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
int ma;
int main()
{
    const string Filename = "menuTest.txt";
    ifstream InFile;
    ofstream OutFile;
    int c;
    do
    {
        DisplayMenu_arry(Filename);
        clear_display(); // call external command
        c = Menu();
        switch (c)
        {
        case 1:
            AddMenu(Filename);
            break;
        case 2:
            DisplayMenu(Filename);
            break;
        case 3:
            order_menu();
            break;
        case 4:
            Report();
            break;
        }
    } while (c != 0);
    cout << "Exit program." << endl;
    return (0);
}
int Menu()
{
    int Choose;
    cout << "-------------------------------------------------------" << endl;
    cout << "               Welcome to KMUTNB Restaurant            " << endl;
    cout << "-------------------------------------------------------" << endl;
    cout << "                       [0]EXIT                         " << endl;
    cout << "                       [1]ADD MENU                     " << endl;
    cout << "                       [2]MENU                         " << endl;
    cout << "                       [3]ORDER                        " << endl;
    cout << "                       [4]REPORT                       " << endl;
    cout << "-------------------------------------------------------" << endl;
    cout << " Enter choose : ";
    cin >> Choose;
    system("clear");
    return (Choose);
}
void AddMenu(string FN)
{
    ofstream OutFile(FN.c_str(), ios_base::out | ios_base::app);
    if (OutFile.is_open())
    {
        string Id, Name,price;
        cout << "-------------------------------------------------------" << endl;
        cout << "               Welcome to KMUTNB Restaurant            " << endl;
        cout << "-------------------------------------------------------" << endl;
        cout << "                      ADD MENU                         " << endl;
        cout << "-------------------------------------------------------" << endl;
        cout << "Enter number : ";
        cin >> Id;
        cout << "Enter Menu : ";
        cin >> Name;
        cout <<"Enter price :";
        cin>> price;
        OutFile << Id << " " << Name << " "<<price<< endl;
        OutFile.close();
        char Wait;
        cin.get(Wait);
        cout << "\nSaved already ,Press Enter to continue";
        cin.get(Wait);
    }
    else
        cout << "File could not opened." << endl;
}
void DisplayMenu(string FN)
{
    ifstream InFile(FN.c_str(), ios_base::in);
    if (InFile.is_open())
    {
        string Id, Name,Price;
        cout << "---------------------------------------------------------------------" << endl;
        cout << "                            Welcome to KMUTNB Restaurant             " << endl;
        cout << "---------------------------------------------------------------------" << endl;
        cout << "                                   Display MENU                      " << endl;
        cout << "---------------------------------------------------------------------" << endl;
        cout << "           Id            |            Menu             |     Price   " << endl;
        cout << "---------------------------------------------------------------------" << endl;
        InFile >> Id >> Name >> Price ;
        while (!InFile.eof())
        {
            cout << "           " << Id;
            cout << "                       " << Name;
            cout << "                       " << Price << endl;
            InFile >> Id >> Name >> Price;
        }
        cout << "---------------------------------------------------------------------" << endl;
        InFile.close();
        char Wait;
        cin.get(Wait);
        cout << "\nPress Enter to continue";
        cin.get(Wait);
    }
    else
        cout << "File could not opened." << endl;
}
void DisplayMenu_arry(string FN)
{
    ifstream InFile(FN.c_str(), ios_base::in); 
    if (InFile.is_open())
    {
        int loop = 0;
        while (!InFile.eof())
        {
            InFile >> Id_ar[loop] >> Name_ar[loop] >> price_ar[loop];
            loop++;
        }
        InFile.close();
    }
    else
        cout << "File could not opened." << endl;
}
void order_menu() 
{
    char se;
    char sh;
    char py;
    clear_display();
    cout << "---------------------------------------------------------------------" << endl;
    cout << "                             Welcome to KMUTNB Restaurant            " << endl;
    cout << "---------------------------------------------------------------------" << endl;
    cout << "                                    Display MENU                     " << endl;
    cout << "---------------------------------------------------------------------" << endl;
    cout << "           Id           |             Menu           |     price     " << endl;
    cout << "---------------------------------------------------------------------" << endl;
    cout << com[0][0]<<"  |  " << com[0][1] <<"  |  "  << com[0][2]<< endl;
    cout << com[1][0]<<"  |  " << com[1][1] <<"  |  "  << com[1][2]<< endl;
    cout << com[2][0]<<"  |  " << com[2][1] <<"  |  "  << com[2][2]<< endl;
    cout << com[3][0]<<"  |  " << com[3][1] <<"  |  "  << com[3][2]<< endl;
    cout << com[4][0]<<"  |  " << com[4][1] <<"  |  "  << com[4][2]<< endl;
    cout << com[5][0]<<"  |  " << com[5][1] <<"  |  "  << com[5][2]<< endl;
    cout << com[6][0]<<"  |  " << com[6][1] <<"  |  "  << com[6][2]<< endl;
    cout << com[7][0]<<"  |  " << com[7][1] <<"  |  "  << com[7][2]<< endl;
    cout << com[8][0]<<"  |  " << com[8][1] <<"  |  "  << com[8][2]<< endl;
    cout << com[9][0]<<"  |  " << com[9][1] <<"  |  "  << com[9][2]<< endl;
    cout << com[10][0]<<"  |  " << com[10][1] <<"  |  "  << com[10][2]<< endl;
    cout<<"Enter no. manu : ";
    cin>>ma;
    cout << " Want to continue? [Y] or [N] :  ";
    cin>>se;
    cin.get();
    {
        if(se == 'n')
        {
            cout<<"Want to eat at a [r]restaurant or [h]home? : ";
            cin>>sh;
            if(sh == 'r')
            {
                clear_display();
                cout << "------------------------------------------------------ " << endl;
                cout << "           Picking up food at the RESTAURANT         | " << endl;
                cout << "   Food cost 25 baht, if adding food +5 baht each    | " << endl;
                cout << "------------------------------------------------------ " << endl;
                cout << "                       Display MENU                  | " << endl;
                cout << "------------------------------------------------------ " << endl;
                cout << "       Id      |                      Menu           | " << endl;
                cout << "------------------------------------------------------"  << endl;
                cout << com[0][0]<<"  |  " << com[0][1] <<"  |  "  << com[0][2]<< endl;
                cout << com[1][0]<<"  |  " << com[1][1] <<"  |  "  << com[1][2]<< endl;                            
                cout << com[2][0]<<"  |  " << com[2][1] <<"  |  "  << com[2][2]<< endl;
                cout << com[3][0]<<"  |  " << com[3][1] <<"  |  "  << com[3][2]<< endl;
                cout << com[4][0]<<"  |  " << com[4][1] <<"  |  "  << com[4][2]<< endl;
                cout << com[5][0]<<"  |  " << com[5][1] <<"  |  "  << com[5][2]<< endl;
                cout << com[6][0]<<"  |  " << com[6][1] <<"  |  "  << com[6][2]<< endl;
                cout << com[7][0]<<"  |  " << com[7][1] <<"  |  "  << com[7][2]<< endl;
                cout << com[8][0]<<"  |  " << com[8][1] <<"  |  "  << com[8][2]<< endl;
                cout << com[9][0]<<"  |  " << com[9][1] <<"  |  "  << com[9][2]<< endl;
                cout << com[10][0]<<"  |  " << com[10][1] <<"  |  "  << com[10][2]<< endl;
                cout << "------------------------------------------------------"<<endl;
                int loop_chack = 0;
                while(com[loop_chack][0] != com[100][0])
                {
                    loop_chack++;
                }
                com[loop_chack][0] = Id_ar[ma];
                com[loop_chack][1] = Name_ar[ma];
                cin.ignore();
                cout<<"\nPress Enter to continue";
                cin.get();
                cout<<"Do you want to pay now? [Y]yes or [N]no : ";
                cin>> py;
                {
                    if (py == 'y')
                    {
                        Total_pay();
                    }
                    else if (py == 'n')
                    {
                        order_menu();
                    }
                }
            }
            else if (sh == 'h')
            {
                clear_display();
                cout << "------------------------------------------------------ " << endl;
                cout << "                 To eat at home                      | " << endl;
                cout << "                Food cost 50 baht                    | " << endl;
                cout << "------------------------------------------------------ " << endl;
                cout << "                       Display MENU                  | " << endl;
                cout << "------------------------------------------------------ " << endl;
                cout << "       Id      |                      Menu           | " << endl;
                cout << "------------------------------------------------------"  << endl;
                cout << com[0][0]<<"  |  " << com[0][1] <<"  |  "  << com[0][2]<< endl;
                cout << com[1][0]<<"  |  " << com[1][1] <<"  |  "  << com[1][2]<< endl;
                cout << com[2][0]<<"  |  " << com[2][1] <<"  |  "  << com[2][2]<< endl;
                cout << com[3][0]<<"  |  " << com[3][1] <<"  |  "  << com[3][2]<< endl;
                cout << com[4][0]<<"  |  " << com[4][1] <<"  |  "  << com[4][2]<< endl;
                cout << com[5][0]<<"  |  " << com[5][1] <<"  |  "  << com[5][2]<< endl;
                cout << com[6][0]<<"  |  " << com[6][1] <<"  |  "  << com[6][2]<< endl;
                cout << com[7][0]<<"  |  " << com[7][1] <<"  |  "  << com[7][2]<< endl;
                cout << com[8][0]<<"  |  " << com[8][1] <<"  |  "  << com[8][2]<< endl;
                cout << com[9][0]<<"  |  " << com[9][1] <<"  |  "  << com[9][2]<< endl;
                cout << com[10][0]<<"  |  " << com[10][1] <<"  |  "  << com[10][2]<< endl;
                int loop_chack = 0;
                while(com[loop_chack][0] != com[100][0])
                {
                    loop_chack++;
                }
                com[loop_chack][0] = Id_ar[ma];
                com[loop_chack][1] = Name_ar[ma];
                cin.ignore();
                cout<<"\nPress Enter to continue";
                cin.get();
                cout<<"Do you want to pay now? [Y]yes or [N]no : ";
                cin>> py;
                {
                    if (py == 'y')
                    {
                        Total_pay();
                    }
                    else if (py == 'n')
                    {
                        order_menu();
                    }
                }
                Report();
            }

        }
    
    int loop_chack = 0;
    while(com[loop_chack][0] != com[100][0])
    {
        loop_chack++;
    }
    com[loop_chack][0] = Id_ar[ma];
    com[loop_chack][1] = Name_ar[ma];
    com[loop_chack][2] = price_ar[ma];


    order_menu();
    }
}
void Report()                                                                   //รายงานการขายไม่ออก
{
    cin.ignore();
    clear_display();
    cout << "------------------------------------------------------ " << endl;
    cout << "                       REPORT                        | " << endl;
    cout << "                  To eat at home                     | " << endl;
    cout << "------------------------------------------------------ " << endl;
    cout << "                       Display MENU                  | " << endl;
    cout << "------------------------------------------------------ " << endl;
    cout << "       Id      |                      Menu           | " << endl;
    cout << "------------------------------------------------------"  << endl;
    cout << com[0][0]<<"  |  " << com[0][1] <<"  |  "  << com[0][2]<< endl;
    cout << com[1][0]<<"  |  " << com[1][1] <<"  |  "  << com[1][2]<< endl;
    cout << com[2][0]<<"  |  " << com[2][1] <<"  |  "  << com[2][2]<< endl;
    cout << com[3][0]<<"  |  " << com[3][1] <<"  |  "  << com[3][2]<< endl;
    cout << com[4][0]<<"  |  " << com[4][1] <<"  |  "  << com[4][2]<< endl;
    cout << com[5][0]<<"  |  " << com[5][1] <<"  |  "  << com[5][2]<< endl;
    cout << com[6][0]<<"  |  " << com[6][1] <<"  |  "  << com[6][2]<< endl;
    cout << com[7][0]<<"  |  " << com[7][1] <<"  |  "  << com[7][2]<< endl;
    cout << com[8][0]<<"  |  " << com[8][1] <<"  |  "  << com[8][2]<< endl;
    cout << com[9][0]<<"  |  " << com[9][1] <<"  |  "  << com[9][2]<< endl;
    cout << com[10][0]<<"  |  " << com[10][1] <<"  |  "  << com[10][2]<< endl;
    int loop_chack = 0;
    while(com[loop_chack][0] != com[100][0])
        {
            loop_chack++;
        }
            com[loop_chack][0] = Id_ar[ma];
            com[loop_chack][1] = Name_ar[ma];
            cin.ignore();
}
void Total_pay()                                                                    //คิดเงินไม่ได้
{
    char Ex;
    cin.ignore();
    cout<<"------------------------------------------------------"<<endl;
    cout<<"Total Pay :        ";
    cout<<"Exit : [E] : ";
    cin>>Ex;
    if(Ex == 'E' || 'e')
    {
        Menu();
    }
    cin.ignore();
}
void reset_com()
{
    for(int i = 0; i < 99; i++)
    {
        com[i][0] = com[100][0];
        com[i][1] = com[100][1];
    }
}
