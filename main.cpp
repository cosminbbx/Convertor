#include <iostream>
#include <string.h>
#include <windows.h>
#include <stdio.h>
#include <cstdlib>
#include <stdlib.h>
using namespace std;
void matrice(char mat[41][71])
{
    int i,j;
    for(i=0;i<=40;i++)
        for(j=0;j<=70;j++)
            mat[i][j]=32;
    mat[0][0]=201;
    mat[0][70]=187;
    mat[40][0]=200;
    mat[40][70]=188;
    for(i=1;i<40;i++)
    {
        mat[i][0]=186;
        mat[i][70]=186;
    }

    for(i=1;i<70;i++)
    {
        mat[0][i]=205;
        mat[40][i]=205;
    }
    for(i=2;i<40;i++)
    {
        mat[i][2]=221;
        mat[i][68]=222;
    }

    for(i=2;i<69;i++)
    {
        mat[1][i]=220;
        mat[39][i]=223;
    }
}
void centrare(char mat[41][71],char sir[100],int lungime,int linie)
{
    int pozitie,index,k;
    pozitie=(70-lungime)/2;
    k=0;
    for(index=pozitie;index<pozitie+lungime;index++)
    {
        mat[linie][index]=sir[k];
        k++;
    }
}
void meniu(char mat[41][71])
{
    system("COLOR 2A");
    char convertor[]="Convertor magic";
    centrare(mat,convertor,15,6);
    char alege[]="Alege convertor:";
    centrare(mat,alege,16,8);
    char lungime[]="1. Lungime";
    centrare(mat,lungime,10,11);
    char arie[]="2. Arie";
    centrare(mat,arie,7,13);
    char volum[]="3. Volum";
    centrare(mat,volum,8,15);
    char viteza[]="4. Viteza";
    centrare(mat,viteza,9,17);
    char temp[]="5. Temperatura";
    centrare(mat,temp,14,19);
    char masa[]="6. Masa";
    centrare(mat,masa,7,21);
    char energie[]="7. Energie";
    centrare(mat,energie,10,23);
    char presiune[]="8. Presiune";
    centrare(mat,presiune,11,25);
    char densitate[]="9. Densitate";
    centrare(mat,densitate,12,27);
    char consum[]="10. Consum combustibil";
    centrare(mat,consum,22,29);
}
void clear_screen(char fill = ' ') {
    COORD tl = {0,0};
    CONSOLE_SCREEN_BUFFER_INFO s;
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(console, &s);
    DWORD written, cells = s.dwSize.X * s.dwSize.Y;
    FillConsoleOutputCharacter(console, fill, cells, tl, &written);
    FillConsoleOutputAttribute(console, s.wAttributes, cells, tl, &written);
    SetConsoleCursorPosition(console, tl);
}
void afisare(char mat[41][71])
{
    int i,j;
    for(i=0;i<=40;i++)
    {
        for(j=0;j<=70;j++)
            cout<<mat[i][j];
        cout<<'\n';
    }
}
void SetCursorPosition(int x, int y)
{
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {x ,y };
    SetConsoleCursorPosition(output, pos);
}
void arie(char mat[41][71],char sir[],int dim)
{
    centrare(mat,sir,dim,7);
    char din1[]="1. Milimetri patrati";
    centrare(mat,din1,20,10);
    char din2[]="2. Centimetri patrati";
    centrare(mat,din2,21,12);
    char din3[]="3. Metri patrati";
    centrare(mat,din3,16,14);
    char din4[]="4. Kilometri patrati";
    centrare(mat,din4,20,16);
    char din6[]="5. Ari";
    centrare(mat,din6,6,18);
    char din7[]="6. Hectare";
    centrare(mat,din7,10,20);
    char din8[]="7. Yard patrat";
    centrare(mat,din8,15,22);
    char din9[]="8. Feet patrat";
    centrare(mat,din9,15,24);
}
void convM(long double &v1,int y)
{
    if(y==1)
        v1=v1/1000000;
    if(y==2)
        v1=v1/10000;
    if(y==4)
        v1=v1*1000000;
    if(y==5)
        v1=v1*100;
    if(y==6)
        v1=v1*10000;
    if(y==7)
        v1=v1/1.1960;
    if(y==8)
        v1=v1/10.764;
}
void convD(long double &v1,int m)
{
    if(m==1)
        v1=v1*1000000;
    if(m==2)
        v1=v1*10000;
    if(m==4)
        v1=v1/1000000;
    if(m==5)
        v1=v1/100;
    if(m==6)
        v1=v1/10000;
    if(m==7)
        v1=v1*1.1960;
    if(m==8)
        v1=v1*10.764;
}
int main()
{


    int i,j,n,m,y;
    char mat[41][71],c[]=" ";
    char sir[]="Conversteste din:";
    long double v1,v2;
    system("MODE CON COLS=72 LINES=42");
    matrice(mat);
    meniu(mat);
    afisare(mat);
    SetCursorPosition(20, 30);
    cin>>n;
    clear_screen();
    matrice(mat);
    if(n==2)
    {
        arie(mat,sir,17);
        afisare(mat);
        cin>>y;
        strcpy(sir,"In:");
        clear_screen();
        matrice(mat);
        arie(mat,sir,3);
        afisare(mat);
        cin>>m;
        clear_screen();
        matrice(mat);
        centrare(mat,"Valoarea de convertit:",22,7);
        centrare(mat,"Valoare convertita:",19,11);
        afisare(mat);
        SetCursorPosition(33, 9);
        cin>>v1;
        convM(v1,y);
        convD(v1,m);

        SetCursorPosition(33, 13);
        cout<<v1;
    }
    return 0;
}
