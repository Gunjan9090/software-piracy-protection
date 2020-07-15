#include<string.h>
#include<fstream>
#include<iostream>
#include<conio.h>
using namespace std;
char c[50];
class User
{ private:
    char id[50];
    char pwd[50];
  public:
  User(){}
    User(char *id,char *pwd)
    {
     strcpy(this->id,id);
     strcpy(this->pwd,pwd);
    }

    int check(char *id,char *pwd)
    {if(strcmpi(this->id,id)==0 && strcmpi(this->pwd,pwd)==0)
      return(1);
      else
      return(0);
    }
};
void setpassword()
{ fstream H;
  H.open("h:/pwd.txt",ios::out|ios::binary);
  
  User U("100","INDIA");
  H.write((char *)&U,sizeof(U));
  H.close();
}
int readpassword(char *id,char *pwd)
{fstream H;
  H.open("h:/pwd.txt",ios::in|ios::binary);
  User U;
  H.read((char *)&U,sizeof(U));
  int i=U.check(id,pwd);
  H.close();
  return i;
}
char *password()
{ char ch;
  int i=0;
  while(1)
  {
   ch=getch();
   cout<<"*";
  c[i++]=ch;
  if(ch=='\r')
  break;
   }
  c[i-1]=0;
}
int main()
{char id[30] ;
 setpassword();
  cout<<"\t\t\tEnter Id:";
 cin>>id;
 cout<<"\t\t\tEnter Password:";
 password();
 int i=readpassword(id,c);
 cout<<endl<<endl;
 if(i)
 {cout<<"Tested";}
 else
 {cout<<"Not Authenticated to Access this Software";
 }
 return 0;
}
