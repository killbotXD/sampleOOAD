#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
int input(){
int i;
do{
int is;      fflush(stdin);
i=scanf("%d",&is);
if(i<1){cout<<"please enter a valid value...\nEnter again :";}else{return is;}
               }while(i==0);
   return 0;
}

class travel{
int passlength,adults,child,dist,t_code;
float fare;
char name1[30],surname[30],pass[120];
public:
int code(){return t_code;}

void enter(int);
void assignfare(int,int,int);
void show();
void del();
void editdist(){cout<<"enter new distance : ";
                                   dist=input();assignfare(adults,child,dist);}
void editadults(){cout<<"enter new number of adults : ";
                                   adults=input();assignfare(adults,child,dist);}
void editchild(){cout<<"enter new childern numbers : ";
                                   child=input();assignfare(adults,child,dist);}
void editname1(){cout<<"Enter the new first name : ";
scanf("%s",name1);}
void editsurname(){cout<<"Enter new surname : ";scanf("%s",surname);}
int access(char *p){if(strcmp(p,pass)==0){ return 1;}else{return 0;}}
char *enterpass();
void changepass();
};
char *travel::enterpass(){
     cout<<"Enter your password : ";   int n=0;
             char *p=new char[203];char ch;
while(n<passlength){
ch=getch();
cout<<"*";
p[n]=ch;
n++;
}
fflush(stdin);
return p;}
void travel::assignfare(int x,int y,int z){
if(z>=1000){fare=(x*500)+(y*250);}
if(z<1000&&z>=500){fare=(x*300)+(y*150);}
if(z<500){fare=(x*200)+(y*100);}
}
void travel::changepass(){
cout<<"Enter new password : ";scanf("%s",pass);
passlength=strlen(pass);
}
  void travel::enter(int c){
                           char an;
                       clrscr();
                       t_code=c;
                 gotoxy(15,7);   cout<<"Enter bookers first name : ";        scanf("%s",name1);
                 gotoxy(15,8);   cout<<"enter bokers surname: ";             scanf("%s",surname);
                 gotoxy(15,9);   cout<<"enter number of adults : ";          adults=input();
                 gotoxy(15,10);   cout<<"enter no. of children : ";           child=input();
                 gotoxy(15,11);   cout<<"enter distance : ";                  dist=input();
                 gotoxy(15,12);   cout<<"do you want to enter a password?";
                 gotoxy(15,18);cout<<"note: your booking will automatically set your first name as your";
                 gotoxy(15,19);cout<<"password....";
                  gotoxy(15,13);  cin>>an;
                    if(an=='n'||an=='N'){strcpy(pass,name1);passlength=strlen(pass);}else{gotoxy(15,15);cout<<"set password : ";scanf("%s",pass);passlength=strlen(pass);}
        assignfare(adults,child,dist);

}
void travel::show(){
     clrscr();
        gotoxy(15,7);      cout<<"your travel code is : "<<t_code<<endl;
        gotoxy(15,8);      cout<<"This booking was made by : "<<name1<<" "<<surname;
        gotoxy(15,9);               cout<<"your number of adults is : "<<adults;
        gotoxy(15,10);               cout<<"your no of children is : "<<child;
        gotoxy(15,11);               cout<<"total distance is : "<<dist;
        gotoxy(15,12);               cout<<"your total fare is : "<<fare;
        //gotoxy(15,13);               cout<<pass;
        gotoxy(15,14);               cout<<"Press Enter....";
                       getch();
}
void main(){fstream f;
     int x;
     travel t;
do{
clrscr();
gotoxy(15,4);/*textbackground(12);*/textcolor(3);cprintf("**********************Welcome**********************");
gotoxy(15,6);cprintf("Enter any one of your choices...");
gotoxy(15,7);textcolor(26);cprintf("1)Enter details and assign fare. ");
gotoxy(15,8);cprintf("2)Show details and fare.");
gotoxy(15,9);cprintf("3)Cancel booking");
gotoxy(15,10);cprintf("4)Edit");
gotoxy(15,11);cprintf("5)Exit");
gotoxy(15,13);x=input();
switch(x){
case 1: int coode;f.open("n.dat",ios::out|ios::app);f.close();
      gotoxy(15,15);cout<<"enter travel code : ";
      int i=scanf("%d",&coode);//tthis
      if(i<1){cout<<"please enter a proper input..";getch();break;}
                   f.open("n.dat",ios::in);
                    f.seekg(0);        int chk=0;
                     while(!f.eof()){
                      f.read((char*)&t,sizeof(t));
                      if(t.code()==coode){cout<<"The Booking already exists ..please use another code..\npress enter...";getch();chk++;}     if(chk==1)break; } f.close();
     if(chk==0){   f.open("n.dat",ios::out|ios::app);
        t.enter(coode);
        f.write((char*)&t,sizeof(t));
        f.close();}
 break;
 case 2:int code=0;
     gotoxy(15,15); cout<<"enter travel code : "; cin>>code;
                   f.open("n.dat",ios::in);
                    f.seekg(0);        int chk1=0;
                     while(!f.eof()){
                      f.read((char*)&t,sizeof(t));
                      if(t.code()==code){ t.show();chk1++;}     if(chk1==1)break; }if(chk1==0){cout<<"record not found..";getch();} f.close();
 break;
 case 3: ifstream inp;
 char ans;
 inp.open("n.dat",ios::in);
 ofstream temp("temp.dat",ios::out);
int tcode,chk3=0;
gotoxy(15,15);cout<<"Enter travel code of the booking which is to be deleted : ";
tcode=input();
while(!inp.eof())
{
inp.read((char*)&t,sizeof(t));
if(tcode==t.code())
{chk3++;if(chk3>1)break;
t.show();
cout<<endl<<"Are you sure if you want to delete booking(Y/N)?";
cin>>ans;
if(ans=='n'||ans=='N'){temp.write((char*)&t,sizeof(t));}else{}
}
else{
temp.write((char*)&t,sizeof(t));}
}//wile
temp.close();
inp.close();
remove("n.dat");
rename("temp.dat","n.dat");if(ans=='y'||ans=='Y'){cout<<"deletion succesfull..press enter...";getch();}
break;
case 4:
int c=0;
gotoxy(15,15);
cout<<"Enter the teavel code which u want to edit : ";
c=input(); int access;

f.open("n.dat",ios::in);
                    f.seekg(0);        int chk11=0;
                     while(!f.eof()){
                      f.read((char*)&t,sizeof(t));
                      if(t.code()==c){ t.show();chk11++;
                      cout<<"Enter your password to proceed!!!!"<<endl;

                     gotoxy(15,15); access=t.access(t.enterpass());cout<<" ";
                      }     if(chk11==1)break; }if(chk11==0){cout<<"record not found..";getch();} f.close();
if(access==1){
int reply=0;
ifstream inp2;
inp2.open("n.dat",ios::in);
ofstream tmp("tmp.dat",ios::out|ios::app);
inp.seekg(0);
while(!inp2.eof()){
inp2.read((char*)&t,sizeof(t));
if(t.code()==c){x:
  clrscr();reply=0;
gotoxy(15,7);cout<<"****************EDIT MENU*****************";
gotoxy(15,8);cout<<"what do you want to edit ?"<<endl;
gotoxy(15,9);cout<<"1)First name."<<endl;
gotoxy(15,10);cout<<"2)last name."<<endl;
gotoxy(15,11);cout<<"3)No. of adults."<<endl;
gotoxy(15,12);cout<<"4)No. of childern."<<endl;
gotoxy(15,13);cout<<"5)Distance"<<endl;
gotoxy(15,14);cout<<"6)Change password"<<endl;
gotoxy(15,15);cout<<"7)nothing take me out of here!!!"<<endl;
reply=0;
gotoxy(15,16);cin>>reply;

switch(reply){
case 1:gotoxy(15,17);t.editname1();break;
case 2:gotoxy(15,17); t.editsurname();break;
case 3:gotoxy(15,17);t.editadults();                      break;
case 4:gotoxy(15,17); t.editchild();
                                   break;
case 5:gotoxy(15,17);t.editdist();break;
  case 6: gotoxy(15,17);  char *pa=new char[203];    int access2;

                      pa=t.enterpass();
                      access2=t.access(pa);
                      if(access2==1){gotoxy(15,18);cout<<"access granted.....press enter..... ";getch();
gotoxy(15,19);        t.changepass();}
else{gotoxy(15,18);cout<<"Access denied.....Press Enter....";getch();}
                      break;
case 7:c=c-1;break;//edit on 3/2/18

}//switch

if(reply!=7){gotoxy(15,20);cout<<"Press Enter.....";getch();goto x;}

tmp.write((char*)&t,sizeof(t));
}//if
else{tmp.write((char*)&t,sizeof(t));}
}//while
tmp.close();
inp.close();
remove("n.dat");
rename("tmp.dat","n.dat");}else{cout<<"Access denied.... press enter... ";getch();}//ifaccesswala

break;
}//switch

}while(x!=5);//do


}//main