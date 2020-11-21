#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include<windows.h>
#define null -32
#include <iostream>
#include <conio.h>
#include <string.h>
int Size;
int push_value;
int i;
int n;
int code;
int v;
int number;
int index;
int *p=&index;
using namespace std;

class Stack
{
private:
    int tos;
    int Size;
    int *st;
    static int counter;

public:

    Stack(int n=10)
    {
        tos=0;
        Size=n;
        st=new int [Size];
        counter++;
        cout <<"this is constructor of stack with size"<<endl;

    }
    ~Stack()
    {
        delete[] st;
        counter--;
        cout<< "this is  destructor of stack  with size"<<endl;
    }


    static int getcounter()
{
    return counter;
}

    void push (int);
    int pop ();
    void print();



};

int  Stack::counter=0;
void Stack:: push (int n)
{
    if( tos==Size)
    {
        cout<<"stack is full"<<endl;
    }
    else
    {
        st[tos]=n;
        tos++;
    }

}

int Stack :: pop()
{
    int retval;

    if (tos==0)
    {
        cout<<"stack is empty"<<endl;
        retval=-1;
    }
    else
    {
        tos--;
        retval=st[tos];
    }
    return retval;
}

void Stack::print()
{
    if(tos== 0)
    {
        cout<<"the stack is empty"<<endl;
    }
    else
    {
        for(i=0;i<tos;i++)
        {
            cout<<st[i]<<endl;
        }
    }
}


 void gotoxy(int x,int y)
 {
   COORD coord={0,0};
   coord.X=x;
   coord.Y=y;
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }

 void textattr(int i)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);

}

int main()
{
int c=1;
char f;
int k=0;

    char arr[3][10]={"push","pop","print"};
    int i,j,row;
     printf("enter the size  of stack\n");
     scanf("%d",&Size);
      Stack s1(Size);

    system("cls");
     printf("\t\t\main menu\n");
   printf("\t\t\------------");


   while(c>0)
   {


   for(i=0;i<3;i++)
   {
      gotoxy(20,i+5);
      textattr( 15);
      printf("%s\n",arr[i]);
   }
        gotoxy(20,k+5);
      textattr( 1);
      printf("%s\n",arr[k]);

  char d;
   d=getch();
if(d==27)break;
if(d==9)
{
    gotoxy(20,k+5);
      textattr( 15);
      printf("%s\n",arr[k]);
           if(k==2)
            {
            k=0;
            gotoxy(20,k+5);
      textattr( 1);
      printf("%s\n",arr[k]);
            }
           else
           {
               k=k+1;
               gotoxy(20,k+5);
      textattr( 1);
      printf("%s\n",arr[k]);
           }
}
   if(d == -32)
   {
       d=getch();
       if(d==80)
       {
           gotoxy(20,k+5);
      textattr( 15);
      printf("%s\n",arr[k]);
           if(k==2)
            {
            k=0;
            gotoxy(20,k+5);
      textattr( 1);
      printf("%s\n",arr[k]);
            }
           else
           {
               k=k+1;
               gotoxy(20,k+5);
      textattr( 1);
      printf("%s\n",arr[k]);
           }
       }
       else if (d==72)
       {
           gotoxy(20,k+5);
      textattr( 15);
      printf("%s\n",arr[k]);
         if(k==0)
         {
             k=2;
             gotoxy(20,k+5);
      textattr( 1);
      printf("%s\n",arr[k]);
         }
         else{
                k=k-1;
                gotoxy(20,k+5);
      textattr( 1);
      printf("%s\n",arr[k]);
         }


       }
       else if (d==27)
       {

    break;
       }


}
      else if ( d==13)
{
    if (k==0)
    {
          system("cls");
          textattr( 15);
          printf("enter the value\n");
          scanf("%d",&push_value);
         s1.push(push_value);
         getch();


            system("cls");
             textattr( 15);
         printf("\t\t\main menu\n");
   printf("\t\t\------------");


    }
    else if(k==1)
    {
         system("cls");
         s1.pop();
         getchar();
           system("cls");
            textattr( 15);
                printf("\t\t\main menu\n");
   printf("\t\t\------------");

    }
    else if (k==2)
    {
         system("cls");
            textattr( 15);
      s1.print();
      getchar();
       system("cls");
            textattr( 15);
                printf("\t\t\main menu\n");
   printf("\t\t\------------");
    }

   }


    }
    return 0;
   }


