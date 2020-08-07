#include<iostream.h>
#include<string.h>
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
class lib
{
 public:
 char name[20],bname[20],bcode[20];
 int clas;
 double time,admno;
 void get()
 {
  book s;
  ifstream l;
  l.open("books.dat",ios::binary);
  cout<<"*******enter the details of the student:"<<endl;
  cout<<"enter the name                      :";
  gets(name);
  cout<<"admission number(4 digit no.)       :";
  cin>>admno;
  cout<<"enter the class                     :";
  cin>>clas;
  enteragain:
  cout<<"enter book name                     :";
  gets(bname);
  while(l.read((char*)&s,sizeof(s)))
  {
   if(strcmpi(s.bnamedisp,bname)==0)
   cout<<"book available";
   else
   {
    cout<<"Book not available.Enter another book"<<endl;
    goto enteragain;
   }
  }
  cout<<"enter book code             :";
  gets(bcode);
  cout<<"enter date of issue(ddmmyy) :";
  cin>>time;
  l.close();
 }
 void show()
 {
  cout<<"********DETAILS ARE***********:"<<endl;
  cout<<"name                   :"<<name<<endl;
  cout<<"admission no.          :"<<admno<<endl;
  cout<<"class                  :"<<clas<<endl;
  cout<<"book name              :"<<bname<<endl;
  cout<<"book code              :"<<bcode<<endl;
  cout<<"issuing date(ddmmyy)   :"<<time<<endl;
 }
};
class book
{
public:
char bnamedisp[20];
char bauthordisp[20];
char bcodedisp[20];
void get()
{
cout<<"enter name of the book:";
gets(bnamedisp);
cout<<"enter author:";
gets(bauthordisp);
cout<<"enter book code:";
gets(bcodedisp);
}
void show()
{
cout<<"book:"<<bnamedisp<<"    ";
cout<<"author:"<<bauthordisp<<"   ";
cout<<"book code:"<<bcodedisp<<"    ";
cout<<endl;
}
};

void main()
{


 int abc,mchoice;
 int x;

 mainpage:
 clrscr();
 cout<<"**************************D.A.V MODEL SCHOOL,KHARAGPUR(W.B)*********************"<<endl;
 cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^Library Management System^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
 gotoxy(25,8);
 cout<<"Enter your choice";
 gotoxy(25,13);
 cout<<"1-Administrator Account";
 gotoxy(25,16);
 cout<<"2-Student Account";
 gotoxy(25,19);
 cout<<"3-Enter and delete books(authorised persons only)"<<endl;
 gotoxy(25,22);
 cout<<"4-exit"<<endl;
 cin>>mchoice;
 if(mchoice==1)
 {
 start:
 clrscr();
 cout<<endl<<endl<<"enter your choice"<<endl;
 cout<<"1-enter new Record(issue book)"<<endl;
 cout<<"2-view Record list"<<endl;
 cout<<"3-Change the Record"<<endl;
 cout<<"4-search for a record"<<endl;
 cout<<"5-delete a record(deposit book)"<<endl;
 cout<<"6-Exit the program"<<endl;
 cin>>x;
 if(x==1)
 {
  char ch='y';
  lib s ;
  ofstream b;
  b.open("library.dat",ios::binary|ios::app);
  while(ch=='y'||ch=='Y')
  {
   s.get();
   b.write((char*)&s,sizeof(s));
   cout<<"do you want to enter more(y/n)....:"<<endl;
   cin>>ch;
  }
  b.close();
  cout<<"return to main menu--press1"<<endl;
  cout<<"return to administrator menu---press2"<<endl;
  cout<<"exit the program----press3";
  cin>>abc;
  if(abc==1)
  goto mainpage;
  else if(abc==2)
  goto start;
  else
  exit(0);
 }
 if(x==2)
 {
  lib s;
  ifstream a;
  a.open("library.dat",ios::binary);
  while(a.read((char*)&s,sizeof(s)))
  {
   s.show();
  }
  a.close();
  cout<<"return to main menu--press1"<<endl;
  cout<<"return to administrator menu---press2"<<endl;
  cout<<"exit the program----press3";
  cin>>abc;
  if(abc==1)
  goto mainpage;
  else if(abc==2)
  goto start;
  else
  exit(0);
 }
 if(x==3)
 {
  double admnosearch;
  int classsearch;
  cout<<"Enter the class                          :"<<endl;
  cin>>classsearch;
  cout<<"Enter the admission number               :"<<endl;
  cin>>admnosearch;
  lib s;
  ifstream fp1;
  ofstream fp2;
  fp1.open("library.dat",ios::binary);
  fp2.open("temp.dat",ios::out|ios::binary|ios::cur);
  while(fp1.read((char*)&s,sizeof(s)))
  {
   if(s.admno==admnosearch&&s.clas==classsearch)
   {
    fp2.seekp(-1*sizeof(s),ios::cur);
    s.get();
   }
   fp2.write((char*)&s,sizeof(s));
  }
  fp1.close();
  fp2.close();
  remove("library.dat");
  rename("temp.dat","library.dat");
  cout<<"return to main menu--press1"<<endl;
  cout<<"return to administrator menu---press2"<<endl;
  cout<<"exit the program----press3";
  cin>>abc;
  if(abc==1)
  goto mainpage;
  else if(abc==2)
  goto start;
  else
  exit(0);
 }
 if(x==4)
 {
  int classsearch;
  double admnosearch;
  lib s;
  ifstream l;
  l.open("library.dat",ios::binary);
  cout<<"Enter the class of the student               :";
  cin>>classsearch;
  cout<<"Enter the admission no.                      :";
  cin>>admnosearch;
  int c=0;
  while(l.read((char*)&s,sizeof(s)))
  {
   if(s.admno==admnosearch&&s.clas==classsearch)
   {
   s.show();
   c=1;
   }
  }
  l.close();
  if(c!=1)
  cout<<"Record not found"<<endl;
  cout<<"return to main menu--press1"<<endl;
  cout<<"return to administrator menu---press2"<<endl;
  cout<<"exit the program----press3";
  cin>>abc;
  if(abc==1)
  goto mainpage;
  else if(abc==2)
  goto start;
  else
  exit(0);
 }
 if(x==5)
 {
  int classsearch;
  double admnosearch;
  lib s;
  ifstream fp1;
  ofstream fp2;
  cout<<"Enter the class of the student              :";
  cin>>classsearch;
  cout<<"Enter the admission no                     :";
  cin>>admnosearch;
  fp1.open("library.dat",ios::binary);
  fp2.open("temp.dat",ios::out|ios::binary);
  int m=0;
  while(fp1.read((char*)&s,sizeof(s)))
  {
   if(s.admno==admnosearch&&s.clas==classsearch)
   {
    m++;
    s.show();
    cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  CAUTION  !!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
    cout<<"check whether book is submitted late or not(compare with issuing date)"<<endl;
    cout<<"if submitted late or if book is lost, ask student to deposit fine in student account"<<endl;
    cout<<"Then only delete the record"<<endl;
    cout<<"checked??(click y/n)"<<endl;
    char tempchoice;
    cin>>tempchoice;
    if(tempchoice=='y'||tempchoice=='Y')
    {
     if(!(s.admno==admnosearch&&s.clas==classsearch))
     {
      fp2.write((char*)&s,sizeof(s));
     }
     cout<<"**record deleted**"<<endl;
    }
    else
    goto mainpage;
   }
  }
  if(m==0)
  cout<<"record not found"<<endl;

  fp1.close();
  fp2.close();
  remove("library.dat");
  rename("temp.dat","library.dat");
  cout<<"return to main menu--press1"<<endl;
  cout<<"return to administrator menu---press2"<<endl;
  cout<<"exit the program----press3";
  cin>>abc;
  if(abc==1)
  goto mainpage;
  else if(abc==2)
  goto start;
  else
  exit(0);
 }
 if(x==6)
 exit(0);
 }
 if(mchoice==2)
 {

  start1:
  clrscr();
  cout<<"enter your choice"<<endl;
  cout<<"1-see the books"<<endl;
  cout<<"2-see rules regulations and current fine system"<<endl;
  cout<<"3-Deposit fine"<<endl;
  cout<<"4-exit"<<endl;
  cin>>x;
  if(x==1)
  {
    cout<<"The books in stock are:"<<endl;
    cout<<"                              DAV LIBRARAY                   "<<endl;
    cout<<"______________________________________________________________________________"<<endl;
    book s;
    ifstream a;
    a.open("books.dat",ios::binary);
    while(a.read((char*)&s,sizeof(s)))
    {
      s.show();
    }
    a.close();
    cout<<endl<<endl<<"Books other than these can also be ordered from our central library";
    cout<<endl<<"contact details:"<<"centrallibrarydav@mail.com"<<endl<<"Ph.No.-43354354"<<endl;
    cout<<"return to main menu--press1"<<endl;
    cout<<"return to student menu---press2"<<endl;
    cout<<"exit the program----press3";
    cin>>abc;
    if(abc==1)
    goto mainpage;
    else if(abc==2)
    goto start1;
    else
    exit(0);
  }
  if(x==2)
  {
    cout<<"books must be handled with care"<<endl;
    cout<<"Book must be returned within 15 days of issuing"<<endl;
    cout<<"If time exceeds 15 days,the reader can still keep the book for a extended period of 15 days";
    cout<<"If the reader keeps the book for more than 15 days,fine is charged at 10% of the price per day"<<endl;
    cout<<"if the book is damaged or lost or stolen,the actual MRP of the book must be deposited within 15 days"<<endl<<endl<<endl;
    cout<<"return to main menu--press1"<<endl;
    cout<<"return to student menu---press2"<<endl;
    cout<<"exit the program----press3";
    cin>>abc;
    if(abc==1)
    goto mainpage;
    else if(abc==2)
    goto start1;
    else
    exit(0);
  }
  if(x==3)
  {
   int MRP,days,ch3;
   int classsearch;
   double admnosearch;
   lib s;
   ifstream l;
   char tempname[20];
   l.open("library.dat",ios::binary);
   cout<<"enter the class of the student                             :";
   cin>>classsearch;
   cout<<"enter the admission no. of the student                     :";
   cin>>admnosearch;
   while(l.read((char*)&s,sizeof(s)))
   {
    if(s.admno==admnosearch&&s.clas==classsearch)
    {
     cout<<"your record is found!!"<<endl;
     s.show();
     cout<<"1-late submission"<<endl;
     cout<<"2-lost book"<<endl;
     cin>>ch3;
     if(ch3==1)
     {
      cout<<"Fine is calulated as:-  1% of MRP x No.of days kept extra"<<endl;
      cout<<"Enter the number of days,the book has been kept extra:";
      cin>>days;
      cout<<"enter the MRP of the book                      :";
      cin>>MRP;
      cout<<"___________________________________________________________"<<endl;
      cout<<"The fine is:"<<days*MRP*0.01<<" rupees"<<endl;
      cout<<"Please deposit the money to your library incharge.Thank you"<<endl;
      cout<<"___________________________________________________________"<<endl;
     }
     if(ch3==2)
     {
     cout<<"You have to pay the MRP of the book and Rs 50 as additional charge"<<endl;
     cout<<"Be Carefull next time.Thankyou"<<endl;
     }
    }
   }
   l.close();
   cout<<"return to main menu--press1"<<endl;
   cout<<"return to student menu---press2"<<endl;
   cout<<"exit the program----press3";
   cin>>abc;
   if(abc==1)
   goto mainpage;
   else if(abc==2)
   goto start1;
   else
   exit(0);
  }
  if(x==4)
  exit(0);
 }
 if(mchoice==3)
 {
  clrscr();
  cout<<"Enter your choice"<<endl;
  cout<<"1-Add New Books"<<endl;
  cout<<"2-delete books"<<endl;
  cout<<"3-View books"<<endl;
  cin>>x;
  if(x==1)
  {
   char ch='y';
   book s ;
   ofstream b;
   b.open("books.dat",ios::binary|ios::app);
   while(ch=='y'||ch=='Y')
   {
   s.get();
   b.write((char*)&s,sizeof(s));
   cout<<"do you want to enter more(y/n)....:"<<endl;
   cin>>ch;
   }
   b.close();
   cout<<"return to main menu--press1"<<endl;
   cout<<"exit the program----press2";
   cin>>abc;
   if(abc==1)
   goto mainpage;
   else
   exit(0);
  }
  if(x==2)
  {
   char codesearch[20];
   book s;
   char tempname[20];
   ifstream fp1;
   ofstream fp2;
   cout<<"Enter the name of the book to be deleted"<<endl;
   gets(tempname);
   cout<<"Enter the code of the to be deleted:";
   gets(codesearch);
   fp1.open("books.dat",ios::binary);
   fp2.open("temp.dat",ios::out|ios::binary);
   while(fp1.read((char*)&s,sizeof(s)))
   {
    if(strcmpi(s.bcodedisp,codesearch)!=0)
    {
     fp2.write((char*)&s,sizeof(s));
    }
   }
   cout<<"record deleted!!"<<endl;
   fp1.close();
   fp2.close();
   remove("books.dat");
   rename("temp.dat","books.dat");
   cout<<"return to main menu--press1"<<endl;
   cout<<"exit the program----press2";
   cin>>abc;
   if(abc==1)
   goto mainpage;
   else
   exit(0);
  }
  if(x==3)
  {
    cout<<"The books in stock are:"<<endl;
    cout<<"                              DAV LIBRARAY                   "<<endl;
    cout<<"______________________________________________________________________________"<<endl;
    book s;
    ifstream a;
    a.open("books.dat",ios::binary);
    while(a.read((char*)&s,sizeof(s)))
    {
      s.show();
    }
    a.close();
    cout<<endl<<endl<<"Books other than these can also be ordered from our central library";
    cout<<endl<<"contact details:"<<"centrallibrarydav@mail.com"<<endl<<"Ph.No.-43354354"<<endl;
    cout<<"return to main menu--press1"<<endl;
    cout<<"exit the program----press2";
    cin>>abc;
    if(abc==1)
    goto mainpage;
    else
    exit(0);
  }
 }
 if(mchoice==4)
  exit(0);
  getch();
}

