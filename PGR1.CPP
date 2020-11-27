#include<iostream.h>
#include<conio.h>
inline void maxi(int a,int b)
     {   cout<<(a>b?a:b);
     }
void main()
{  clrscr();
   int x,y;
   cin>>x>>y;
   maxi(x,y);
   getch();
}