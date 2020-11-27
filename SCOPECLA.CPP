#include<iostream.h>
#include<conio.h>
int a=1;
void main()
{clrscr();
int a=2;
cout<<"a="<<a<<"\n";
cout<<"::a="<<::a<<"\n";
{int a=3;
cout<<"inner block"<<"\n";
cout<<"a="<<a<<"\n";
cout<<"::a="<<::a<<"\n";
}
cout<<"a="<<a<<"\n";
cout<<"::a="<<::a;
getch();
}