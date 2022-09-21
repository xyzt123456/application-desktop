//en c++
#include <iostream>
#include <string>

//en c
#include <stdio.h>

using namespace std;

int somme(int a , int b, int c=1)
{
    return a+b+c;
}

int main()
{
    int x=1,y=2,z=3,w;

    w=somme(x,y);

    cout<<"la somme: "<<w;













    /*const int a=10;
    int b;
    float c;
    string ch1="hello";
    string ch2="2a37",ch3;

    //cout<<ch1+" "+ch2<<endl;
    ch3=ch1+" "+ch2;
    cout<<ch3<<endl;

    cout<<"saisir une phrase"<<endl;
    cin>>ch3;
    cout<<ch3<<endl;
    ch3="";

    //pour prendre en consideration l'espace
    cout<<"saisir une phrase"<<endl;
    getline(cin,ch3);
    cout<<ch3<<endl;
    //enc
    scanf("%d %f",&b,&c);
    //en c++
    cin>>b>>c;


    //en c
    printf("b=%d\n",b);
    //en c++
    cout <<"b="<<b<<" c="<<c<<endl;
    cout << "Hello world!" << endl;
*/

    return 0;
}
