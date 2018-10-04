#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <fstream>
using namespace std;

void deposit();
void withdraw();
void after_with();
void animation();
void PIN();
void after_deposit();
void checkbalance();
void readcurPIN();
void changePIN();
//void verifyPINchange();

float balance,withdrawal;
float bal_aft_with;
int choice,pin;
float bal_aft_dep;
float deposit_val;
int currentPIN;
int newPIN;

fstream file;



int main()
{

    //animation();
    readcurPIN();
    PIN();
    system("cls");
    system("color 2");
    cout<<"Logged in successfully.Please wait a moment."<<endl;
    Sleep(1000);
    system("cls");
    system("color 0f");
     while(true)
  {   Sleep(1500);
      system("cls");
                cout<<"============================="<<endl;
                cout<<"===========\\MENU//=========="<<endl;
                cout<<"============================="<<endl;
                cout<<"1-withdraw money"<<endl;
                cout<<"2-deposit money"<<endl;
                cout<<"3-change your PIN number"<<endl;
                cout<<"4-check your balance"<<endl;
                cout<<"5-log out"<<endl;
    cin>>choice;
    switch(choice)
    {
    case 1:
        {
            withdraw();
            if(withdrawal<=balance)
            {after_with();}
             else if(withdrawal>balance)
                 {
                Sleep(1000);
                system("cls");
                cout<<"insufficient funds...Try again!"<<endl;
                Sleep(1500);
                 }
        }break;
    case 2:
        {
          deposit();
          after_deposit();
        }break;
    case 3:
       {
         //verifyPINchange();
         changePIN();
       }break;
    case 4:
        {
           checkbalance();
        }break;
    case 5:
        {
          system("cls");
          cout<<"Thank you for using our ATM! Have a nice day!";
          Sleep(3000);
          exit(0);
        }break;
    default:
        {
            cout<<"There is no such option as '"<<choice<<"'... try again"<<endl;
            Sleep(1500);
        }break;
    }

  }
    return 0;
}

void withdraw()
{
    bal_aft_with=balance-withdrawal;
    file.open("balance.txt",ios::in);
    string line;
    int line_nr=1;
    while(getline(file,line))
    {
       if(line_nr==1)  balance=atoi(line.c_str());
    }
       file.close();
    cout<<"how much do you want to withdraw? "<<endl;
    cout<<"You have "<<balance<<" on your account ";
    cin>>withdrawal;
    if(withdrawal<=balance)
    {
        after_with();
    }
    else if(withdrawal>balance)
    {
        Sleep(1000);
        system("cls");
        cout<<"insufficient funds...Try again!"<<endl;
        Sleep(1500);
    }

}

void after_with()
{
    bal_aft_with=balance-withdrawal;
    file.open("balance.txt", ios::out);
    file<<bal_aft_with;
    file.close();
    cout<<"you now have: "<<bal_aft_with<<" on your account  "<<endl;
    system("pause");
}

void animation()
{
       cout << "Welcome to the ATM!!!" << endl;
    Sleep(2000);
    system("cls");
    cout << "Please wait a moment..." << endl;
    Sleep(1000);
    system("cls");
    for(int i=1;i<=10;i++)
  {
    system("cls");
    for(int i=1;i<=3;i++)
    {
        cout<<".";
        Sleep(100);
    }
}
}
void PIN()
{
    Sleep(500);
    system("cls");
    cout<<"enter the PIN number ";
    cin>>pin;
    while(pin!=currentPIN)
    {
        system("color 4");
        cout<<"Invalid PIN. Try again."<<endl;
        Sleep(1000);
        system("cls");
        system("color 0f");
        cout<<"enter the PIN number: ";
        cin>>pin;
    }

}
void deposit()
{
    file.open("balance.txt",ios::in);
    string line;
    int line_nr=1;
    while(getline(file,line))
    {
        if(line_nr==1) balance=atoi(line.c_str());
    }
    file.close();
    cout<<"You now have "<<balance<<" on your account"<<endl;
    cout<<"How much do you want to deposit? ";
    cin>>deposit_val;


}
void after_deposit()
{
    file.open("balance.txt",ios::out);
    bal_aft_dep=balance+deposit_val;
    file<<bal_aft_dep;
    file.close();
    cout<<"success! You now have "<<bal_aft_dep<<" on your account  ";
    system("pause");
}
void checkbalance()
{
            file.open("balance.txt", ios::in);
            string line;
            int line_nr=1;
            while(getline(file,line))
            {
                if(line_nr==1) balance=atoi(line.c_str());
            }
            system("cls");
            cout<<"your balance is "<<balance<<endl;
            system("pause");
            file.close();
}
void readcurPIN()
{
     file.open("pin.txt", ios::in);
    string line;
    int line_nr=1;
    while(getline(file,line))
    {
        if(line_nr==1) currentPIN=atoi(line.c_str());
    }
    cout<<currentPIN;
    system("pause");
    file.close();
}
void changePIN()
{
    file.open("pin.txt", ios::out);
    cout<<"Please enter your new PIN number"<<endl;
    cin>>newPIN;
    file<<newPIN;
    cout<<"operation successful.PIN changed to'"<<newPIN<<"'"<<endl;
    Sleep(1500);
    file.close();
}

//void  int verifyPINchangeATT;
      ////  cin>>verifyPINchangeATT;
    ////while(verifyPINchangeATT!=currentPIN)
    //{
      //  cout<<"enter your old PIN number: ";
      //  int verifyPINchangeATT;
      //  cin>>verifyPINchangeATT;
       // cout<<"pin incorrect, try again..."<<endl;
        //Sleep(900);
   // }
    //if(verifyPINchangeATT=currentPIN)
    //{
       // cout<<"pin correct, proceeding..."<<endl;
       // Sleep(900);
    //}
//}
