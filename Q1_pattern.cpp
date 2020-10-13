#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

void pattern(int);

int main()

{int n;

    cout<<"enter no of interation:";

    cin>>n;

    pattern(n);

    getch();
    return (0);
}
void pattern(int n)
{
    int a=1,i=1;

    while(a<(2*n))

    {for(int k=1;k<i;k++)

           cout<<" ";

        for(int j=i;j<=n;j++)
        {
            cout<<j<<" ";
        }
    cout<<"\n";

    if(a>=n)  //for lower pattern

        i--;

     else

        {i++;}

    a++;
    }
}
