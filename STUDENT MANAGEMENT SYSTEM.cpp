//student management System.
//all header files
#include<iostream>
#include<conio.h>
#include<string.h>
#include<iomanip>
#include<windows.h>
#include<fstream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
class student
{
    char name[30];
    int Roll_no;
    int age;
    char Pname[30];
    char stdn[10];
    int busno;
    string convert(string s)
    {
        for(int i=0;i<s.length();i++)
        {
            s[i]=toupper(s[i]);
        }
        return s;
    }
public:
    void intro(void);   // introduction of project.
    void ccolor(int); //display colorful contain.
    void loadingbar(void);   //simple loading bar.
    void login(void); //simple login contain.
    void getdata(void);   //Get all data from user.
    void showdata(void);   //display all data .
    void viewAlldata();     //display all data from files.
    int storedata();        //store all data in a file
    void searchData(char *);    //search a perticuler data.
    void showsearch(void);      //display search.
    void deleteData(char *);    //delete a data.
    void updateData(char *);    //use to update a data.
    student()
    {
        Roll_no=0;
        age=0;
        busno=0;
        strcpy(name,"no name");
        strcpy(Pname,"no name");
        strcpy(stdn,"not found");
    }

};
void student::ccolor(int clr){
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, clr);

//the above code displays colorful background.
}
void student::loadingbar()
{
    for (int i=15;i<=100;i+=5)//increasing by  5 and start with 15
        {
        system("cls");
        ccolor(14);
		cout<<"\n\n\n\n\n\n\n\t\t\t";
		cout<<i<<" %% Loading...\n\n\t\t";
		cout<<" ";
		for (int j=0; j<i;j+=2){
			cout<<" ";
		}
		Sleep(50);  //sleep for 50 mile second
		if(i==90 || i==50 || i==96 || i==83){
			Sleep(50);
		}
	}
	system("cls");// clear the terminal
}
void student::intro()
{
    ccolor(433);
    cout<<"*****************************************************************"<<endl
        <<"*****************************************************************"<<endl
        <<"*************      STUDENT MONITORING SYSTEM       **************"<<endl
        <<"*************             MADE BY MR.ASHFAQUE ALI      **********"<<endl
        <<"*****************************************************************"<<endl
        <<"*****************************************************************"<<endl
        <<"_________________________________________________________________\n";
        //simple introduction
        getch();
}
void student::login()
{
    ccolor(14); // simple login with user_id and password
    char ui[]="ASHFAQUE";
    char psw[]="3535";
    char gui[10],gpsw[10];
    cout<<"\n\t\t______________________________"<<endl
        <<"\t\t|ENTER USER ID:-|";
    cin>>gui;
    cout<<"\n\t\t______________________________"<<endl
        <<"\t\t|ENTER PASSWORD:-|";
    cin>>gpsw;
    if(strcmp(ui,gui)!=0 && strcmp(psw,gpsw)==0)
       {
           ccolor(12);
        cout<<"\t\tINVALID UI AND PASSWORD:";
        getch();
        exit(0);
    }
    else
    {
        cout<<"\t\tLOGIN SUCSESSFULLY:-\n";
    }
}
void student::getdata()
{

    fflush(stdin);
   cout<<"\t**************************************************"<<endl;
   cout<<"\t* ENTER STUDENT NAME :";cin.getline(name,29);fflush(stdin);
   cout<<"\t**************************************************"<<endl;
   cout<<"\t* ENTER STUDENT ROLL.NO :";cin>>Roll_no;fflush(stdin);
   cout<<"\t**************************************************"<<endl;
   cout<<"\t* ENTER STUDENT BUS NO :";cin>>busno;fflush(stdin);
   cout<<"\t**************************************************"<<endl;
   cout<<"\t* ENTER STUDENT AGE :";cin>>age;fflush(stdin);
   cout<<"\t**************************************************"<<endl;fflush(stdin);
   cout<<"\t* ENTER STUDENT FATHER NAME :";cin.getline(Pname,29);fflush(stdin);
   cout<<"\t**************************************************"<<endl;
   cout<<"\t* ENTER STUDENT STANDARD :";cin.getline(stdn,9);fflush(stdin);
   cout<<"\t**************************************************"<<endl;fflush(stdin);

}
void student::showdata()
{
            cout<<"\t***************************************************"<<endl;
            cout<<"\t|                             |                   "<<endl;
            cout<<"\t|NAME of the student is       |->    "<<name<<"   "<<endl;
            cout<<"\t|                             |                   "<<endl;
            cout<<"\t|Roll.NO of the student is    |->       "<<Roll_no<<"          "<<endl;
            cout<<"\t|                             |                   "<<endl;
            cout<<"\t|BUS.NO of the student is     |->       "<<busno<<"         "<<endl;
            cout<<"\t|                             |                   "<<endl;
            cout<<"\t|Age of the student is        |->        "<<age<<"         "<<endl;
            cout<<"\t|                             |                   "<<endl;
            cout<<"\t|Father name of the student is|->     "<<Pname<<"  "<<endl;
            cout<<"\t|                             |                   "<<endl;
            cout<<"\t|Class of the student is      |->    "<<stdn<<"     "<<endl;
            cout<<"\t|                             |                   "<<endl;
            cout<<"\t***************************************************"<<endl;
}
int student::storedata()
{
    if(age==0 && Roll_no==0)
    {
        cout<<"\n Student data not initialized : ";
        return(0);
    }
    else
    {
        ofstream fout;
        fout.open("file.dat",ios::app|ios::binary);
        fout.write((char*)this,sizeof(*this));
        fout.close();
        return(1);

    }
}
void student::viewAlldata()
{
    ifstream fin;
    fin.open("file.dat",ios::in|ios::binary);
    if(!fin)
        cout<<"error file not found:";
    else{
        fin.read((char*)this,sizeof(*this));
        while(!fin.eof()){
            showdata();
           fin.read((char*)this,sizeof(*this));
        }
        fin.close();
    }
}
void student::searchData(char *t)
{
    int count=0;
    ifstream fin;
    fin.open("file.dat",ios::in|ios::binary);
    if(!fin)
        cout<<"error file not found:";
    else{
        fin.read((char*)this,sizeof(*this));
        while(!fin.eof()){
            if(!strcmp(t,name)){
                showdata();
                count++;
            }
           fin.read((char*)this,sizeof(*this));
        }
        if(count==0)
            cout<<"\n record not found:";
        fin.close();
    }
}
void student::showsearch()
{
    cout<<"\t\t*************************************"<<"\n";
    cout<<"\t\t*                                   *"<<"\n";
    cout<<"\t\t*      STUDENT SEARCH OPTION        *"<<"\n";
    cout<<"\t\t*                                   *"<<"\n";
    cout<<"\t\t*************************************"<<"\n";
    char ser[30];
    cout<<"\t\t Enter Name of the student:";
    fflush(stdin);
    cin.getline(ser,29);
    searchData(ser);
}
void student::deleteData(char *t)
{
     ifstream fin;
    ofstream fout;
    fin.open("file.dat",ios::in|ios::binary);
    if(!fin)
    {
        ccolor(12);
        cout<<"Error file not found:";
    }

    else{
        fout.open("temp.dat",ios::out|ios::binary);
        fin.read((char*)this,sizeof(*this));
        while(!fin.eof())
        {
            if(strcmp(name,t))
                fout.write((char*)this,sizeof(*this));
            fin.read((char*)this,sizeof(*this));
        }
        fin.close();
        fout.close();
        remove("file.dat");
        rename("temp.dat","file.dat");
    }
}
void student::updateData(char *t)
{
    fstream file;
    file.open("file.dat",ios::in|ios::out|ios::ate|ios::binary);
    file.seekg(0);
    file.read((char*)this,sizeof(*this));
    while(!file.eof())
    {
        if(!strcmp(t,name)){
            getdata();
            file.seekp(file.tellp()-sizeof(*this));
            file.write((char*)this,sizeof(*this));
        }
        file.read((char*)this,sizeof(*this));
    }
}

int main()
{
    student s1;
    s1.loadingbar();
    s1.intro();
    s1.login();
    s1.ccolor(929);
    int choice;
    while(choice!=6)
    {
        s1.ccolor(929);
        system("cls");
    cout<<"*****************************************************************"<<"\n";
    cout<<"***                                                           ***"<<"\n";
    cout<<"***              1. Insert Student record.                    ***"<<"\n";
    cout<<"***              2. View All Student record.                  ***"<<"\n";
    cout<<"***              3. Search Student record.                    ***"<<"\n";
    cout<<"***              4. Delete Student record.                    ***"<<"\n";
    cout<<"***              5. Update Student record.                    ***"<<"\n";
    cout<<"***              6. For Exit The Program.                     ***"<<"\n";
    cout<<"***                                                           ***"<<"\n";
    cout<<"*****************************************************************"<<"\n";
    cout<<"\n        Enter Your choice:";
    cin>>choice;
    switch(choice)
    {
    case 1:
        s1.getdata();
        s1.storedata();
        cout<<"\n\t\t Data is Successfully Stored:";
        getch();
        break;
    case 2:
        s1.viewAlldata();
        getch();
        break;
    case 3:
        s1.showsearch();
        getch();
        break;
    case 4:
        cout<<"\n\n Enter Student Name to delete a record:";
        char name[30];fflush(stdin);
        cin.getline(name,29);
        s1.deleteData(name);
        cout<<"\n\t\t Data is Successfully Deleted:";
        getch();
        break;
    case 5:
        cout<<"\n\n Enter Student Name to Update a record:";fflush(stdin);
        cin.getline(name,29);
        s1.updateData(name);
        cout<<"\n\t\t Data is Successfully Updated:";
        getch();
        break;
    case 6:
        s1.ccolor(558);
        cout<<"\n\t\t Thank You For using This Application:";
        cout<<"\n\t\t Enter Any Key To Exit:-";
        getch();
        exit(0);
        break;
    default:
        s1.ccolor(12);
        cout<<"Invalid Input Try Again:";
        getch();
        }
    }
    getch();
}
