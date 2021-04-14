#include<fstream>
#include<iostream>
#include<set>
#include<stdio.h>
#include<string>
#include<string.h>
#include <cstring>
#include<conio.h>



using namespace std;
fstream wrt,rd;

//Parent class that have all the basic details that contact of any type posses

class Contact{
protected:
    string f_name;
    string l_name;
    string mob_no;
    string tel_no;
    char adrs[50];
    string city;
    string email;
public:
    //string getFn(){return f_name;}
    //string getLn(){return l_name;}
    friend bool operator< (const Contact &left,const Contact &right);//A friend function that is used store objects in set
};

bool operator< (const Contact &left,const Contact &right)
{
    if(left.f_name != right.f_name) return left.f_name < right.f_name; //sort the objects in order of there first name
    else return left.l_name < right.l_name;                            //and if first name of two objects are same then sort according to their last name
}


class Fam_Cont:public Contact{ //A child class of Contact class
private:
    string relation;
    string dob; //date of birth
public:
    static int FamObj;
    Fam_Cont(){
    FamObj++;
    cout<<"Enter '-' to leave a field blank.\n\n";
    lab1:                       //For applying constraints on this field
    cout<<"First name : ";
    cin>>f_name;
    if(f_name=="-"){
    cout<<"This field cannot be left blank.\n\a";
    goto lab1;
    }
    lab2:                        //For applying constraints on this field
    cout<<"\nLast name : ";
    cin>>l_name;
    if(l_name=="-"){
    cout<<"This field cannot be left blank.\n\a";
    goto lab2;
    }
    lab3:                        //For applying constraints on this field
    cout<<"\nMobile number : ";
    cin>>mob_no;
    if(mob_no=="-"||mob_no.length()!=10){
    if(mob_no=="-")cout<<"This field cannot be left blank.\n\a";
    else cout<<"Enter a valid mobile number\n\a";
    goto lab3;
    }
    cout<<"\nRelation : ";
    cin>>relation;
    cout<<"\nDate of birth : ";
    cin>>dob;
    cout<<"\nTelephone number : ";
    cin>>tel_no;
    cin.ignore();
    cout<<"\nAddress : ";
    gets(adrs);
    cout<<"\nCity : ";
    cin>>city;
    cout<<"\nE-mail : ";
    cin>>email;
    }
    void Write(){
    wrt.open("C:\\Users\\adminn\\Desktop\\Project\\Final Cpp\\Family\\"+f_name+" "+l_name+".txt",ios::app); //open a file at needed location and having name as required
    wrt<<"First-name : ";      //writing on the file
    wrt<<f_name<<"=";
    wrt<<"\nLast-name : ";
    wrt<<l_name<<"=";
    wrt<<"\nMobile-number : ";
    wrt<<mob_no<<"=";
    wrt<<"\nRelation : ";
    wrt<<relation<<"=";
    wrt<<"\nDate_of_birth : ";
    wrt<<dob<<"=";
    wrt<<"\nTelephone-number : ";
    wrt<<tel_no<<"=";
    wrt<<"\nAddress : ";
    wrt<<adrs<<"=";
    wrt<<"\nCity : ";
    wrt<<city<<"=";
    wrt<<"\nE-mail : ";
    wrt<<email<<"=";
    wrt.close();
    }
    static int TotalCont(){return FamObj;}
};
int Fam_Cont::FamObj=0;

class Fri_Cont:public Contact{  //Another child class
private:
    string type;
    string dob;
    string since;
public:
    static int FriObj;
    Fri_Cont(){
    FriObj++;
    cout<<"Enter '-' to leave a field blank.\n\n";
    lab1:
    cout<<"First name : ";
    cin>>f_name;
    if(f_name=="-"){
    cout<<"\nThis field cannot be left blank.\n\a";
    goto lab1;
    }
    lab2:
    cout<<"\nLast name : ";
    cin>>l_name;
    if(l_name=="-"){
    cout<<"This field cannot be left blank.\n\a";
    goto lab2;
    }
    lab3:
    cout<<"\nMobile number : ";
    cin>>mob_no;
    if(mob_no=="-"||mob_no.length()!=10){
    if(mob_no=="-")cout<<"This field cannot be left blank.\n\a";
    else cout<<"Enter a valid mobile number\n\a";
    goto lab3;
    }
    cout<<"\nKnown since : ";
    cin>>since;
    cout<<"\nDescription : ";
    cin>>type;
    cout<<"\nDate of birth : ";
    cin>>dob;
    cout<<"\nTelephone number : ";
    cin>>tel_no;
    cin.ignore();
    cout<<"\nAddress : ";
    gets(adrs);
    cout<<"\nCity : ";
    cin>>city;
    cout<<"\nE-mail : ";
    cin>>email;
    }
    void Write(){
    wrt.open("C:\\Users\\adminn\\Desktop\\Project\\Final Cpp\\Friends\\"+f_name+" "+l_name+".txt",ios::app);
    wrt<<"First-name : ";
    wrt<<f_name<<"=";
    wrt<<"\nLast-name : ";
    wrt<<l_name<<"=";
    wrt<<"\nMobile number : ";
    wrt<<mob_no<<"=";
    wrt<<"\nKnown_since : ";
    wrt<<since<<"=";
    wrt<<"\nDescription : ";
    wrt<<type<<"=";
    wrt<<"\nDate_of_birth : ";
    wrt<<dob<<"=";
    wrt<<"\nTelephone-number : ";
    wrt<<tel_no<<"=";
    wrt<<"\nAddress : ";
    wrt<<adrs<<"=";
    wrt<<"\nCity : ";
    wrt<<city<<"=";
    wrt<<"\nE-mail : ";
    wrt<<email<<"=";
    wrt.close();
    }
    static int TotalCont(){return FriObj;}
};
int Fri_Cont::FriObj=0;
class SerPro_Cont:public Contact{
private:
    string service;
public:
    static int SerObj;
    SerPro_Cont(){
    SerObj++;
    cout<<"Enter '-' to leave a field blank.\n\n";
    lab1:
    cout<<"First name : ";
    cin>>f_name;
    if(f_name=="-"){
    cout<<"\nThis field cannot be left blank.\n\a";
    goto lab1;
    }
    lab2:
    cout<<"\nLast name : ";
    cin>>l_name;
    if(l_name=="-"){
    cout<<"This field cannot be left blank.\n\a";
    goto lab2;
    }
    lab3:
    cout<<"\nMobile number : ";
    cin>>mob_no;
    if(mob_no=="-"||mob_no.length()!=10){
    if(mob_no=="-")cout<<"This field cannot be left blank.\n\a";
    else cout<<"Enter a valid mobile number\n\a";
    goto lab3;
    }
    cout<<"\nService : ";
    cin>>service;
    cout<<"\nTelephone number : ";
    cin>>tel_no;
    cin.ignore();
    cout<<"\nAddress : ";
    gets(adrs);
    cout<<"\nCity : ";
    cin>>city;
    cout<<"\nE-mail : ";
    cin>>email;
    }
    void Write(){
    wrt.open("C:\\Users\\adminn\\Desktop\\Project\\Final Cpp\\Other\\"+f_name+" "+l_name+".txt",ios::app);
    wrt<<"First-name : ";
    wrt<<f_name<<"=";
    wrt<<"\nLast-name : ";
    wrt<<l_name<<"=";
    wrt<<"\nMobile-number : ";
    wrt<<mob_no<<"=";
    wrt<<"\nService : ";
    wrt<<service<<"=";
    wrt<<"\nTelephone_number : ";
    wrt<<tel_no<<"=";
    wrt<<"\nAddress : ";
    wrt<<adrs<<"=";
    wrt<<"\nCity : ";
    wrt<<city<<"=";
    wrt<<"\nE-mail : ";
    wrt<<email<<"=";
    wrt.close();
    }
    static int TotalCont(){return SerObj;}
};
int SerPro_Cont::SerObj=0;

void Search(string type,string f_name,string l_name){
rd.open("C:\\Users\\adminn\\Desktop\\Project\\Final Cpp\\"+type+"\\"+f_name+" "+l_name+".txt",ios::in); //open a file at this specified location and having this given name
char c,y;
if(!rd.is_open()){
    cout<<"Sorry, contact not found !\n\a";
    cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t...Press any key to continue ";cin>>c;
    return;
}
cout<<"\n***************************\n\n"; //printing the contents of the file
while(rd>>c){
    if(c==':') cout<<" : ";
    else if(c=='=') cout<<"\n\n";    //for changing the line
    else cout<<c;
}
rd.close();//closing the opened file for future operations
cout<<"\n***************************\n";
cout<<"\n\n1.Delete                     2.Modify                        [Any key].Continue\n\n";
cout<<"Enter your choice ::   ";cin>>c;
switch(c){
case '1':
    cout<<"Delete this contact? [Y/N] :: ";cin>>y;
    if(y=='Y'||y=='y'){
    string dl="C:\\Users\\adminn\\Desktop\\Project\\Final Cpp\\"+type+"\\"+f_name+" "+l_name+".txt";
    char del[dl.length()+1];
    strcpy(del, dl.c_str());
    const int res=remove(del);
    if( ( res!= 0 ))
    cout<<"\nError deleting Contact\n\n";
    else
    cout<<"\nContact successfully deleted\n\n";
    }
    break;
    /*
    Modification is done as follows :

    First open the target file in read mode

    Create a second file named temp in the same location

    Here only three top field can be modified

    If user wish to change the any of these field the new content will be written in the temp file
    else the old contents will be copied from target file to temp file.

    While making changes we store the First name and last name in some new variables

    After making all the required modification we copy paste all the remaining contents from target file to temp file

    After this we delete the target file and and we rename the temp file using the first name and last name variable.

    */
case '2':{
    string fn,ln,old,nw;
    char x;
    int n=4;
    rd.open("C:\\Users\\adminn\\Desktop\\Project\\Final Cpp\\"+type+"\\"+f_name+" "+l_name+".txt",ios::in);
    wrt.open("C:\\Users\\adminn\\Desktop\\Project\\Final Cpp\\"+type+"\\temp.txt",ios::app);
    cout<<"\nChange first name? \n";
    cout<<"\n[Y/N] :: ";cin>>x;
    while(n--){rd>>old;}
    if(x=='y'||x=='Y'){
        l1:
        cout<<"\nEnter new first name : ";
        cin>>nw;
        if(nw=="-"){
            cout<<"\nThis field cannot be left blank.\n\a";
            goto l1;
        }
        fn=nw;
        wrt<<"First name : ";
        wrt<<nw<<"=";
    }
    else{
        fn=f_name;
        wrt<<"First name : ";
        wrt<<fn<<"=";
    }

    cout<<"\nChange last name? \n";
    cout<<"\n[Y/N] :: ";cin>>x;
    n=4;
    while(n--){rd>>old;}
    if(x=='y'||x=='Y'){
        l2:
        cout<<"\nEnter new last name : ";
        cin>>nw;
        if(nw=="-"){
            cout<<"\nThis field cannot be left blank.\n\a";
            goto l2;
        }
        ln=nw;
        wrt<<"\nLast name : ";
        wrt<<nw<<"=";
    }
    else{
        ln=l_name;
        wrt<<"\nLast name : ";
        wrt<<ln<<"=";
    }

    cout<<"\nChange Mobile number? \n";
    cout<<"\n[Y/N] :: ";cin>>x;

   n=4;
    while(n--){rd>>old;}
    if(x=='y'||x=='Y'){
        l3:
        cout<<"\nEnter new mobile number : ";
        cin>>nw;
        if(nw=="-"){
            cout<<"\nThis field cannot be left blank.\n\a";
            goto l3;
        }
        wrt<<"\nMobile number : ";
        wrt<<nw<<"=\n";
    }
    else{
        wrt<<"\nMobile number : ";
        wrt<<old<<"="<<"\n";
    }
    while(rd>>x){
        wrt<<x;
        if(x=='=') wrt<<"\n";
    }

    wrt.close();
    rd.close();
    string d2="C:\\Users\\adminn\\Desktop\\Project\\Final Cpp\\"+type+"\\"+f_name+" "+l_name+".txt";
    char del1[d2.length()+1];
    strcpy(del1, d2.c_str());
    const int dx=remove(del1);
    if( ( dx!= 0 ))
    cout<<"\nError updating Contact\n\n";
    else
    cout<<"Contact successfully updated\n\n";
    string nn="C:\\Users\\adminn\\Desktop\\Project\\Final Cpp\\"+type+"\\"+fn+" "+ln+".txt";
    char arr[nn.length()+1];
    strcpy(arr,nn.c_str());
    string on="C:\\Users\\adminn\\Desktop\\Project\\Final Cpp\\"+type+"\\temp.txt";
    char arr2[on.length()+1];
    strcpy(arr2,on.c_str());
    rename(arr2,arr);
    break;
    }
default:
    getch();
}
system("cls");
return;
}

void M1(){
cout<<"\n\n\n\n\n\n\n";
cout<<"\t\t\t        1. Create\n\n";
cout<<"\t\t\t        2. Search\n\n";
cout<<"\t\t\t        3. Exit\n";
}
void M2(){
cout<<"\n\n\n";
cout<<"\t\t        1. Family      :Total contact present : "<<Fam_Cont::TotalCont()<<"\n\n";
cout<<"\t\t        2. Friend      :Total contact present : "<<Fri_Cont::TotalCont()<<"\n\n";;
cout<<"\t\t        3. Other       :Total contact present : "<<SerPro_Cont::TotalCont()<<"\n\n";;
}
void Welcome(){
cout<<"\n\n\n\n\n\n\n";
cout<<"\t\t\t+************************************+\n";
cout<<"\t\t      --|   Address and Phonebook System     |-- \n";
cout<<"\t\t\t+************************************+\n";
cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t...Press any key to continue ";
}

int main(){
char out,in,ans='y';
string fn,ln;
set<Fam_Cont> fam_con;
set<Fri_Cont> fri_con;
set<SerPro_Cont> ser_con;

Welcome();
cin>>out;
system("cls");
do{
M1();
cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tEnter your choice : ";
cin>>out;
system("cls");
switch(out){
case '1':
    M2();
    cout<<"\n\nCategory of contact : ";
    cin>>in;
    system("cls");
    switch(in){
        case '1':
            while(ans=='Y'||ans=='y'){  //looping until user enter n/N
            Fam_Cont obj;
            fam_con.insert(obj);
            cout<<"\nEnter more contact in this category?\n[Y/N] :: ";
            cin>>ans;
            system("cls");
            }
            for(auto i:fam_con){
                i.Write();
            }
            ans='y';
            break;
        case '2':
            while(ans=='Y'||ans=='y'){
            Fri_Cont obj1;
            fri_con.insert(obj1);
            cout<<"\nEnter more contact in this category?\n[Y/N] :: ";
            cin>>ans;
            system("cls");
            }
            for(auto i:fri_con){
                i.Write();
            }
            ans='y';

            break;
        case '3':
            while(ans=='Y'||ans=='y'){
            SerPro_Cont obj2;
            ser_con.insert(obj2);
            cout<<"\nEnter more contact in this category?\n[Y/N] :: ";
            cin>>ans;
            system("cls");
            }
            for(auto i:ser_con){
                i.Write();
            }
            ans='y';
            break;
        default:
            cout<<"INVALID INPUT!\n\a";
            getch();
            system("cls");
            break;
    }
break;

case '2':
    M2();
    cout<<"Enter category to look into : ";
    cin>>in;
    system("cls");
    cout<<"\nEnter first name of the contact : ";
    cin>>fn;
    cout<<"\nEnter last name of the contact : ";
    cin>>ln;
    system("cls");
    switch(in){
        case '1':
            Search("Family",fn,ln);
            break;
        case '2':
            Search("Friends",fn,ln);
            break;
        case '3':
            Search("Other",fn,ln);
            break;
        default:
            cout<<"INVALID INPUT!\n\a";
            getch();
            break;
    }
    break;

case '3':
    cout<<"\n\n\n\n\n\n\n";
    cout<<"\t\t\t\t+*************+";
    cout<<"\n\t\t\t\t|  Thank you! |\n";
    cout<<"\t\t\t\t+*************+\n\n\n\n\n";
    break;
default:
    cout<<"INVALID INPUT!\n\a";
    getch();
    break;
}
}while(out!='3');
return 0;
}





