#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void login();
void registration();
void forgot();

int main()
{
    int c;
    cout<<"\t\t\t__________________________________________________\n\n\n";
    cout<<"\t\t\t            Welcome to the Login page    \n\n\n";
    cout<<"\t\t\t______________________ Menu _______________\n\n";
    cout<<"\t| Press 1 to LOGIN                        |"<<endl;
    cout<<"\t| Press 2 to REGISTER                     |"<<endl;
    cout<<"\t| Press 3 if you FORGOT your PASSWORD     |"<<endl;
    cout<<"\t| Press 4 to EXIT                         |"<<endl;
    cout<<"\n\t\t\t Please Enter your choice : ";
    cin>>c;
    cout<<endl;

    switch(c)
    {
        case 1: login(); break;
        case 2: registration(); break;
        case 3: forgot(); break;
        case 4:
            cout<<"\t\t\t Thankyou!! \n\n";
            break;
        default:
            system("cls");
            cout<<"\t\t\t Please select from the option given above \n"<<endl;
            main();
    }
}

// LOGIN FUNCTION
void login()
{
    int count=0;
    string userId,password,id,pass,aadhar,enteredAadhar;
    system("cls");
    cout<<"\t\t\t Please enter the username, password and Aadhaar number: "<<endl;
    cout<<"\t\t\t USERNAME: ";
    cin>>userId;
    cout<<"\t\t\t PASSWORD: ";
    cin>>password;
    cout<<"\t\t\t AADHAAR NO: ";
    cin>>enteredAadhar;

    ifstream input("records.txt");

    while(input>>id>>pass>>aadhar)
    {
        if(id==userId && pass==password && aadhar==enteredAadhar)
        {
            count=1;
            system("cls");
        }
    }
    input.close();

    if(count==1)
    {
        cout<<userId<<"\nYour login is successful \nThanks for logging in ! \n";
        main();
    }
    else{
        cout<<"\n LOGIN ERROR \n Please check Your username, password and Aadhaar number\n";
    }
}

// REGISTRATION FUNCTION
void registration()
{
    string ruserId,rpassword,raadhar;
    system("cls");
    cout<<"\t\t\t Enter the username : ";
    cin>>ruserId;
    cout<<"\t\t\t Enter the password : ";
    cin>>rpassword;
    cout<<"\t\t\t Enter your Aadhaar No : ";
    cin>>raadhar;

    ofstream f1("records.txt", ios::app);
    f1<<ruserId<<' '<<rpassword<<' '<<raadhar<<endl;
    system("cls");
    cout<<"\n\t\t\t Registration is successful ! \n";
    main();
}

// FORGOT PASSWORD FUNCTION
void forgot()
{
    int option;
    system("cls");
    cout<<"\t\t\t You forgot the password? No worries \n";
    cout<<"Press 1 to search your ID by username & Aadhaar"<<endl;
    cout<<"Press 2 to go back to the main menu"<<endl;
    cout<<"\t\t\t Enter your choice : ";
    cin>>option;

    switch(option)
    {
        case 1:
        {
            int count=0;
            string suserId,saadhar,sId,spass,saad;
            cout<<"\n\t\t\t Enter the username which you remembered: ";
            cin>>suserId;
            cout<<"\n\t\t\t Enter your Aadhaar No: ";
            cin>>saadhar;

            ifstream f2("records.txt");
            while(f2>>sId>>spass>>saad)
            {
                if(sId==suserId && saadhar==saad)
                {
                    count=1;
                    cout<<"\n\n Your account is found ! \n";
                    cout<<"\n\n Your password is : "<<spass<<endl;
                }
            }
            f2.close();
            if(count==0)
            {
                cout<<"\n\t Sorry! Your account not found!\n";
            }
            main();
            break;
        }
        case 2:
        {
            main();
            break;
        }
        default:
            cout<<"\t\t\t Wrong choice! Please try again"<<endl;
            forgot();
    }
}