#include <fstream>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;
int input(){
int i;
do{
int is;      
fflush(stdin);
i=scanf("%d",&is);
if(i<1)
{
    printf("please enter a valid value...\nEnter again :");
}
else
{
    return is;
}
}while(i==0);
   return 0;
}


int main()
{
    fstream f;
     int x;
    // travel t;
do{
//clrscr();
printf("**********************Welcome**********************\n");
printf("Enter your type...\n");
printf("1)ADMIN\n ");
printf("2)LAUNDRY BOY\n");
printf("3)CUSTOMER\n");
printf("4)EXIT\n");
x=input();
switch(x){
    case 1: //ADMIN
    case 2: //Laundry BOY
    case 3: //CUSTOMER
    default: printf("Thanks for visiting");


}//switch
}while(x!=4);//do


}
