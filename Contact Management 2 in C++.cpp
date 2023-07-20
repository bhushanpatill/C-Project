#include<iostream>
// #include<bits/stdc++.h>
#include<fstream>
#include<conio.h>
using namespace std;

void addContact();
void searchContact();
void help();
void self_exit();
bool check_digits(string);
bool check_numbers(string);

string first_name, last_name, phone_number;

int main(){
    short int choice;
    system("cls");
    system("color 0A");
    
    cout<<"\t\t\t\tCONTACT MANAGEMENT"<<endl<<endl;
    cout<<"\t\t1. ADD CONTACT"<<endl;
    cout<<"\t\t2. SEARCH CONTACT"<<endl;
    cout<<"\t\t3. HELP"<<endl;
    cout<<"\t\t4. EXIT"<<endl;
    cin>>choice;

    switch(choice){
        case 1:
            addContact();
            break;
        case 2:
            searchContact();
            break;
        case 3:
            help();
            break;
        case 4:
            self_exit();
            break;

        default:
            cout<<"\n\n INVALID INPUT"<<endl;
            cout<<"\n\n PRESS ANY KEY TO CONTINUE"<<endl;
            getch();
            main();
    }
    return 0;
}

void self_exit()
{
    system("cls");
    cout<<"\n\t\t Thank you for using !"<<endl;
    exit(1);
}

void help()
{
    cout<<"This displays help";
}

void addContact()
{
    ofstream o1("Contacts.txt", ios::app);
    system("cls");
    cout<<"\n\n\t Enter your first name : "<<endl;
    cin>>first_name;
    cout<<"\t Enter your last name : "<<endl;
    cin>>last_name;
    cout<<"\t Enter your 10 digit phone number : "<<endl;
    cin>>phone_number;

    if(check_digits(phone_number) == true)
    {
        if(check_numbers(phone_number) == true)
        {
            if(o1.is_open())
            {
                o1<<first_name<<" "<<last_name<<" "<<phone_number<<endl;
                cout<<"\n\t Contact saved successfully"<<endl;
            }
            else{
                cout<<"\n\t Error opening file !";
            }
        }
        else
        {
            cout<<"\n\t\t A phone number must contain numbers only "<<endl;
        }
    }
    else
    {
        cout<<"\n\t\t A phone number contains 10 digits";
    }
    o1.close();
}
void searchContact()
{
    bool found = false;
    ifstream myfile("Contacts.txt");
    string keyword;
    cout<<"Enter name to search : "<<endl;
    cin>>keyword;
    while(myfile>>first_name>>last_name>>phone_number)
    {
        if(keyword == first_name || keyword == last_name)
        {
            system("cls");
            cout<<"Contact details....."<<endl;
            cout<<"First name : "<<first_name<<endl;
            cout<<"Last name : "<<last_name<<endl;
            cout<<"Phone number : "<<phone_number<<endl;
            found = true;
            break;
        }
    }
    if(found == false){
        cout<<"No user found sorry..!"<<endl;
    }

}

bool check_digits(string x)
{
    if(x.length() == 10)
    {
        return true;
    }
    else{
        return false;
    }
}

bool check_numbers(string x)
{
    bool check = true;

    for(int i = 0;i<x.length();i++)
    {
        if(!(int(x[i])>=48 && int(x[i])<=57))
        {
            check = false;
            break;
        }
    }

    if(check == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}