//
//  main.cpp
//  Project2.cpp
// Name: Jerron Spraggins
// User ID: jas0157@auburn.edu
// Filename: Project2.cpp
// How to compile: I used Visual Studio Code on my Mac computer and ran it with the terminal.
//
#include <windows.h>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ostream>
#include <array>

using namespace std;

class menu;
class member;
class admin;
class client;
class account;
int const dbsize = 100;

class menu {
public: 
    menu();
    void memberMenu();
    void showMain();
    void showLogin();
    void showmanage();
    bool authenticate(string, string, vector <member>);
    member returnmember(string, string, vector <member>);
};

class admin {
public: 
    admin();

    string name;
    string password;
    string getadminname(string);
    string getadminpass(string);
    int verify;
    void setadminname(string);
    void setadminpass(string);
    void setverify(int);
    int getverify();
    void addnewmember(vector <member>&);
    void deletemember(vector <member>&);
    void displaybranch(vector <member>);
    void changepassword(member, vector <member>&);
};

class member {
public: 
    member();

    string name;
    string password;
    void setMemberName(string);
    void setpassword(string);
    void addclient(string, string, int, string, int, vector <client>);
    void changepass(member, vector <member>&);
    string getmembername();
    string getpass();
    int getverify();
    void setverify(int);

    int verify = 0;
};


class account {
public: 
    
    account();

    int acnum;
    string name;
    string actype;
    int balance;
    void setacname(string);
    void setactype(string);
    void setbalance(int);
    void setacnum(int);
    string getacname();
    string getactype();
    int getbalance();
    int getacnum();
    int getverify();
    void setverify();
    void deposit(int);
    void withdraw(int);

    int verify = 0;
};

class client {
public: 
    client();
    account clientacct;
    class account;

    string clientname;
    string addy;
    int ssn;
    string boss;
    int income;
    void setclientname(string);
    void setaddy(string);
    void setssn(int);
    void setboss();
    void setincome(int);
    string getclientname();
    string getaddy();
    string getboss();
    int getssn();
    int getincome();
    int getverify();
    void setverify();

    int verify = 0;

};

menu::menu() {
}

member::member() {
    string name = "NA";
    string password = "NA";

    int verify = 0;
}

admin::admin() {
    string name = "NA";
    string password = "NA";

    int verify = 0;
}

client::client() {
    string clientname = "NA";
    string addy = "NA";
    int ssn = 0;
    string bosss = "NA";
    int income = 0;

    int verify = 0;
}

account::account() {
    int actnum = 0;
    string name = "NA";
    string actype = "NA";
    int balance = 0;

    int verify = 0;
}

void menu::showMain() {
    cout << "\t===========================================================\n";
    cout << "\t| Welcome to the Auburn Branch of Tiger Bank!    |\n";
    cout << "\t===========================================================\n";
    cout << "1) Login\n";
    cout << "2) Quit\n";
}

bool menu::authenticate(string nameIn, string passIn, vector <member> database) {
    bool valid = false;
    int index;
    for (index = 0; index < dbsize; index++) {
        if (database[index].getmembername() == nameIn && database[index].getpass() == passIn) {
            valid = true;
            break;
        }
        else {
            valid = false;
        }
    }
    return valid;
}

void menu::showlogin() {
    cout << "\t===========================================================\n";
    cout << "\t| Login to Access the Teller Terminal System         |\n";
    cout << "\t===========================================================\n";
}

member menu::returnmember(string nameIn, string passIn, vector <member> database) {
    member retrieve;
    for (int index = 0; index < dbsize; index++) {
        if (database[index].getmembername() == nameIn && database[index].getpass() == passIn) {
            retrieve.setverify(database[index].getverify());
            retrieve.setpassword(database[index].getpass());
            retrieve.setMemberName(database[index].getmembername());
            break;
        }
    }
    return retrieve;
}

int main(){
    return 0;   
}
