#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <windows.h>
#define ll long long
#define con 1180254
#define line cout<<"------------------------------------------------------------------------------------------------------------------\n";
#define sline cout<<"---\n";

using namespace std;

class bank
    {
    private :
        ll amount=0.000;
        string name="DEFAULT";
        string ads="DEFAULT";
        ll acn=000000000000;

    public :







        int amount_display()
        {
            return amount;
        }
        int acn_display()
        {
            return acn;
        }
        string ads_d()
        {
            return ads;
        }
        string name_d()
        {
            return name;
        }



        void update_amount(ll a,int b)
        {
            if(b>0)
            amount=amount +a;

            if(b<0)
                amount-=a;

        }
        int enterdata(int i);
        void display();
        void editdeatils(ll am,ll acn,string n,string add);





    }a[1000];





    int bank ::enterdata(int j)
    {
        cout<<"j = "<<j<<endl;

        cout<<"NAME -: ";
            getline(cin,name);
            getline(cin,name);

            cout<<"\nADDRESS -:";
            getline(cin,ads);

            cout<<"\nINITIAL AMOUNT (must be greater than 1000 rs) -:";
            cin>>amount;
            if(amount<1000)
            {
                cout<<"\nAMOUNT ENTERED NOT SUFFICIENT !";
                return -1;
            }
            else
                cout<<"\nAMOUNT UPDATED SUCCESSFULLY \n";

            acn=con+j+1;
            j++;
            cout<<"\nPLEASE NOTE DOWN THE ACCOUNT NO :\n";
            cout<<"\nACCOUNT NO -: "<<acn<<endl;
            return 1;

    }

    void bank :: display()
    {
        cout<<"\nNAME    : "<<name<<endl;
        cout<<"ADDRESS : "<<ads<<endl;
        cout<<"AMOUNT  : "<<amount<<endl;

    }

    void bank:: editdeatils(ll am,ll acn1,string n,string add)
    {
        amount=am;
        acn=acn1;
        name=n;
        ads=add;


    }


   ll index(ll a)
   {


       a=a-con;
       if(a>0)
       return a;

       else
        return -1;

   }
   void heading()
   {
       system("cls");
       Sleep(500);
       cout<<"----------------------------------------------------------------\n";
       cout<<"|                |  WELCOME TO YOSHIMITSU BANK !   |            |\n";
       cout<<"----------------------------------------------------------------\n";


   }

   void menu()
   {

       cout<<"CHOOSE FROM BELOW(ENTER 0 TO QUIT)-:\n\n";Sleep(500);
       cout<<"1.Open an Account.\n";Sleep(500);
       cout<<"2.Deposit money.\n";Sleep(500);
       cout<<"3.Transfer money to other Account.\n";Sleep(500);
       cout<<"4.Withdraw Money.\n";Sleep(500);
       cout<<"5.Display personal account details.\n";Sleep(500);
       cout<<"6.Display all accounts(administrator password required)\n";Sleep(500);

   }

   void displayall(int k)
   {
        line
        cout<<"|  S.NO  |  ACCOUNT.NO  |          NAME        |                 ADDRESS               |       AMOUNT(Rs)    |"<<endl;
        line
        for(int i=0;i<k;i++)
       {
           cout<<"|   "<<i+1<<"    |  "<<a[i].acn_display()<<"     |"<<setw(20)<<a[i].name_d()<<"  |  "<<setw(35)<<a[i].ads_d()<<"  |  "<<setw(15)<<a[i].amount_display()<<"  |"<<endl;
           Sleep(200);
       }
        line

   }

   int working(int j)
   {
       ll s,k,b,r,r2,k2; int d=0;
       string l,p="aj4745";


       sline
       cin>>s;
       sline
       //system("cls");
       line
       switch(s)
       {

           case 1:d=a[j].enterdata(j);
                  if(d>0)
                  j++;
           break;

           case 2:cout<<"Enter Account No -: "; cin>>r;
                  k=index(r);
                  //cout<<"k = "<<k<<endl;
                  if((k==-1)||(k>j))
                  {
                      line
                      cout<<"Account invalid !\n";
                      line
                  }
                  cout<<"Enter the Amount to be deposited --: ";cin>>b;
                  a[k-1].update_amount(b,1);
                  cout<<"UPDATED AMOUNT --: "<<a[k-1].amount_display()<<"\n";
                  Sleep(10000);
           break;

           case 3:cout<<"ENTER SOURCE BANK ACCOUNT NO --: ";
                  cin>>r;
                  k=index(r);
                  //cout<<"k = "<<k<<endl;
                  if((k==-1)||(k>j))
                  {
                      line
                      cout<<"Account invalid !\n";
                      line
                      break;
                  }
                  cout<<"ENTER DESTINATION BANK ACCOUNT --: ";
                  cin>>r2;
                  k2=index(r2);
                  //cout<<"k = "<<k<<endl;
                  if((k2==-1)||(k2>j))
                  {
                      line
                      cout<<"Account invalid !\n";
                      line
                      break;
                  }
                  cout<<"ENTER AMOUNT TO BE TRANSFERRED --: ";
                  cin>>b;
                  if(b<1)
                  {
                      cout<<"\nAMOUNT INVALID !\n"<<endl;
                      break;
                  }
                  else
                  {
                      a[k-1].update_amount(b,-1);
                      a[k2-1].update_amount(b,+1);
                      cout<<"\nTRANSFER SUCCESSFULL!\n";
                  }
                  Sleep(10000);



            break;

           case 4:cout<<"Enter Account No -: "; cin>>r;
                  k=index(r);
                  //cout<<"k = "<<k<<endl;
                  if((k==-1)||(k>j))
                  {
                      line
                      cout<<"Account invalid !\n";
                      line
                  }
                  cout<<"Enter the Amount to be withdrawn --: ";cin>>b;

                  a[k-1].update_amount(b,-1);
                  cout<<"UPDATED AMOUNT --: "<<a[k-1].amount_display()<<"\n";
                  Sleep(10000);
            break;

           case 5:cout<<"Enter Account No -: "; cin>>r;
                  k=index(r);
                  //cout<<"k = "<<k<<endl;
                  if((k==-1)||(k>j))
                  {
                      line
                      cout<<"Account invalid !\n";
                      line
                  }
                  else
                  {

                      a[k-1].display();
                  }
                  Sleep(10000);
            break;

           case 6:cout<<"ENTER ACCESSING PASSWORD --: ";
                  cin>>l;cout<<"\n";
                  if(l==p)
                  {
                      system("cls");
                      displayall(j);

                  }
                  else
                    cout<<"ACESS DENIED!\n";

                    Sleep(10000);
            break;

           case 0:cout<<"\n";Sleep(300);cout<<"T";Sleep(300);cout<<"h";Sleep(300);cout<<"a";Sleep(300);cout<<"n";Sleep(300);cout<<"k";Sleep(300);cout<<"s";Sleep(300);cout<<" ";Sleep(300);cout<<"f";Sleep(300);cout<<"o";Sleep(300);cout<<"r";Sleep(300);cout<<" ";Sleep(300);cout<<"u";Sleep(300);cout<<"s";Sleep(300);cout<<"i";Sleep(300);cout<<"n";Sleep(300);cout<<"g";Sleep(300);cout<<"!";Sleep(300);cout<<"\n"<<endl;
                  cout<<"                                                           ";Sleep(300);cout<<"p";Sleep(300);cout<<"r";Sleep(300);cout<<"o";Sleep(300);cout<<"d";Sleep(300);cout<<"u";Sleep(300);cout<<"c";Sleep(300);cout<<"e";Sleep(300);cout<<"d";Sleep(300);cout<<" ";Sleep(300);cout<<"b";Sleep(300);cout<<"y";Sleep(300);cout<<" ";Sleep(300);cout<<"@";Sleep(300);cout<<" ";Sleep(300);cout<<"Y";Sleep(300);cout<<"O";Sleep(300);cout<<"S";Sleep(300);cout<<"H";Sleep(300);cout<<"I";Sleep(300);cout<<"M";Sleep(300);cout<<"I";Sleep(300);cout<<"T";Sleep(300);cout<<"S";Sleep(300);cout<<"U";Sleep(300);cout<<"4";Sleep(300);cout<<"7";Sleep(300);cout<<"4";Sleep(300);cout<<"5";Sleep(300);cout<<endl;
                  Sleep(10000);
                  return -1;
            break;





       }
       return j;

   }

   void spacelag()
   {
       ll t=10,n=5;
       while(t--)
       {
           for(int i=0;i<n;i++)
           {
               for(int k=0;k<n-i;k++)
               {
                   cout<<"      ";
               }

               for(int j=0;j<(2*i)+1;j++)
               {
                   cout<<"YOSHIMITSU ";
               }
               cout<<endl;
           }
           n++;
           Sleep(100);
       }
       system("cls");

   }

int main()
{

    int j=0,t=10000,k,p=0,l;
    ifstream fin;
    fin.open("num.txt");

    fin>>j; k=j;

    cout<<j<<endl;
    fin.close();
    ifstream fin2;
    fin2.open("xyz.txt");
    while(k--)
    {
        system("cls");
        int i; string str1,str2;
        ll acn,am;


        cout<<"Recieving details for acc "<<i<<endl;
        fin2>>i>>acn;
        getline(fin2,str1,'|');
        fin2>>am;
        getline(fin2,str2,'|');
        cout<<i<<" "<<acn<<" "<<str1<<" "<<am<<" "<<str2<<"  j = "<<j<<endl;
        a[i-1].editdeatils(am,acn,str1,str2);
        Sleep(150);



    }

    fin.close();






    while(t--)
    {


    spacelag();
    heading();
    line
    menu();

    l=j;
    j=working(j);
    if(j==-1)
        goto end1;

    cout<<"j = "<<j<<endl;


    Sleep(300);

    }
    end1:
    //cout<<"Reached end"<<endl;
    cout<<"j="<<j<<endl;
    ofstream fout;
    fout.open("xyz.txt");

    while(p<l)
    {

    cout<<"saving data for p = "<<p<<endl;
    fout<<p+1<<" "<<a[p].acn_display()<<a[p].name_d()<<"|"<<a[p].amount_display()<<a[p].ads_d()<<"|"<<endl;

     p++;
    }
    fout.close();
    ofstream fout2;
    fout2.open("num.txt");
    fout2<<l;
    Sleep(300);

    return 0;
}
