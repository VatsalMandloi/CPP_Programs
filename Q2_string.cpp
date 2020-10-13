#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

void subString(string s, int len1,string str2,int len2)
{
    int flag,tlen,a;

string temp;
   // to store substring
    for (int i = 0; i < len1; i++)

           {flag=0;

               temp=s.substr(i,len2);

               tlen=temp.length();

             a=0;
             for(int m=0;m<tlen;m++)  //to check redudancy in substring

               { for(int n=0 ; n<tlen;n++)

             {   {if(m!=n)

                 {if(temp[m]==temp[n])
                   {a++;}

             }}}}

              if(a<2)

              {for( int j=0;j<tlen;j++) //to find substring with different character

               {for(int k=0 ; k<len2;k++)
                 {
                     if(str2[k]==temp[j])
                     {
                         flag++;
                     }
                 }
                   } if(flag==len2)

                         cout<<"substring ' "<<temp<<"' found at index "<<i<<endl;

                   }}
}
int main()
{
    string s = "xyyzxzyzxxyz",str2="xyz";

    subString(s,s.length(),str2,str2.length());
   getch();
    return 0;

}
