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
void aliniat(char mat[41][71],char sir[100],int lungime,int linie)
{
    int i;
    for(i=8;i<8+lungime;i++)
        mat[linie][i]=sir[i-8];
}
void meniu(char mat[41][71])
{
    system("COLOR 2A");
    char convertor[]="Convertor magic";
    centrare(mat,convertor,15,6);
    char alege[]="Alege convertor:";
    centrare(mat,alege,16,8);
    char lungime[]="1. Lungime";
    centrare(mat,lungime,10,13);
    char arie[]="2. Arie";
    centrare(mat,arie,7,15);
    char volum[]="3. Volum";
    centrare(mat,volum,8,17);
    char viteza[]="4. Viteza";
    centrare(mat,viteza,9,19);
    char temp[]="5. Temperatura";
    centrare(mat,temp,14,21);
    char masa[]="6. Masa";
    centrare(mat,masa,7,23);
    char energie[]="7. Energie";
    centrare(mat,energie,10,25);
    char presiune[]="8. Presiune";
    centrare(mat,presiune,11,27);
    char densitate[]="9. Densitate";
    centrare(mat,densitate,12,29);
    char consum[]="10. Consum combustibil";
    centrare(mat,consum,22,29);
}
void clear_screen(char fill = ' ')
{
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
    centrare(mat,din1,20,11);
    char din2[]="2. Centimetri patrati";
    centrare(mat,din2,21,13);
    char din3[]="3. Metri patrati";
    centrare(mat,din3,16,15);
    char din4[]="4. Kilometri patrati";
    centrare(mat,din4,20,17);
    char din6[]="5. Ari";
    centrare(mat,din6,6,19);
    char din7[]="6. Hectare";
    centrare(mat,din7,10,21);
    char din8[]="7. Yard patrat";
    centrare(mat,din8,15,23);
    char din9[]="8. Feet patrat";
    centrare(mat,din9,15,25);
}
void lungime(char mat[41][71],char sir[],int dim)
{
    centrare(mat,sir,dim,7);
    char din1[]="1. Milimetri";
    centrare(mat,din1,12,11);
    char din2[]="2. Centimetri";
    centrare(mat,din2,13,13);
    char din3[]="3. Metri";
    centrare(mat,din3,8,15);
    char din4[]="4. Kilometri";
    centrare(mat,din4,12,17);
    char din6[]="5. Inch";
    centrare(mat,din6,7,19);
    char din7[]="6. Yard";
    centrare(mat,din7,7,21);
    char din8[]="7. Mila";
    centrare(mat,din8,7,23);
    char din9[]="8. Feet";
    centrare(mat,din9,7,25);
}
void volum(char mat[41][71],char sir[],int dim)
{
    centrare(mat,sir,dim,7);
    char din1[]="1. Centimetri cubi";
    centrare(mat,din1,18,11);
    char din2[]="2. Metri cubi";
    centrare(mat,din2,13,13);
    char din3[]="3. Galon";
    centrare(mat,din3,8,15);
    char din4[]="4. Feet cub";
    centrare(mat,din4,11,17);
    char din6[]="5. Yard cub";
    centrare(mat,din6,11,19);
    char din8[]="6. Mililitri";
    centrare(mat,din8,12,21);
    char din9[]="7. Litri";
    centrare(mat,din9,8,23);
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
void convLungime(long double &v1,int y)
{
    if(y==1)
        v1=v1/1000;
    if(y==2)
        v1=v1/100;
    if(y==4)
        v1=v1*1000;
    if(y==5)
        v1=v1/39.370;
    if(y==6)
        v1=v1/1.0936;
    if(y==7)
        v1=v1/0.00062137;
    if(y==8)
        v1=v1/3.2808;
}
void convLungime2(long double &v1,int m)
{
    if(m==1)
        v1=v1*1000;
    if(m==2)
        v1=v1*100;
    if(m==4)
        v1=v1/1000;
    if(m==5)
        v1=v1*39.370;
    if(m==6)
        v1=v1*1.0936;
    if(m==7)
        v1=v1*0.00062137;
    if(m==8)
        v1=v1*3.2808;
}
void convVolum(long double &v1,int y)
{
    if(y==1)
        v1=v1/1000;
    if(y==2)
        v1=v1*1000;
    if(y==3)
        v1=v1/0.21997;
    if(y==4)
        v1=v1/0.035315;
    if(y==5)
        {
            v1=v1/1.3080;
            v1=v1*0.0010000;
        }
    if(y==6)
        v1=v1/1000;
}
void convVolum2(long double &v1,int m)
{
    if(m==1)
        v1=v1*1000;
    if(m==2)
        v1=v1/1000;
    if(m==3)
        v1=v1*0.21997;
    if(m==4)
        v1=v1*0.035315;
    if(m==5)
        {
            v1=v1/0.0010000;
            v1=v1*1.3080;
        }
    if(m==6)
        v1=v1*1000;
}
int main()
{


    int i,j,n,m,y,ok;
    char mat[41][71],c[]=" ";
    char sir[]="Converteste din:";
    long double v1,v2;
    system("MODE CON COLS=72 LINES=42");
    matrice(mat);
    meniu(mat);
    afisare(mat);
    SetCursorPosition(35, 11);
    cin>>n;
    clear_screen();
    matrice(mat);
    if(n==1)
    {
        lungime(mat,sir,16);
        afisare(mat);
        SetCursorPosition(44, 7);
        cin>>y;
        strcpy(sir,"In:");
        clear_screen();
        matrice(mat);
        lungime(mat,sir,3);
        afisare(mat);
        SetCursorPosition(37, 7);
        cin>>m;
        clear_screen();
        matrice(mat);
        aliniat(mat,"Valoare de convertit:",21,7);
        aliniat(mat,"Valoare convertita:",19,11);
        aliniat(mat,"Pentru a face alta convertire apasati 1 urmat de ENTER",54,30);
        aliniat(mat,"Pentru iesi din aplicatie apasati 2 urmat de ENTER",50,32);
        afisare(mat);
        SetCursorPosition(31, 7);
        cin>>v1;
        convLungime(v1,y);
        convLungime2(v1,m);
        SetCursorPosition(31, 11);
        cout<<v1;
        SetCursorPosition(8, 14);
        cin>>ok;
        while((ok!=1)&&(ok!=2))
        {
            clear_screen();
            matrice(mat);
            centrare(mat,"RASPUNS INVALID",15,7);
            centrare(mat,"Mai incearca",12,9);
            aliniat(mat,"Pentru a face alta convertire apasati 1 urmat de ENTER",54,30);
            aliniat(mat,"Pentru iesi din aplicatie apasati 2 urmat de ENTER",50,32);
            afisare(mat);
            SetCursorPosition(35, 11);
            cin>>ok;
        }
    }
    if(n==2)
    {
        arie(mat,sir,16);
        afisare(mat);
        SetCursorPosition(44, 7);
        cin>>y;
        strcpy(sir,"In:");
        clear_screen();
        matrice(mat);
        arie(mat,sir,3);
        afisare(mat);
        SetCursorPosition(37, 7);
        cin>>m;
        clear_screen();
        matrice(mat);
        aliniat(mat,"Valoare de convertit:",21,7);
        aliniat(mat,"Valoare convertita:",19,11);
        aliniat(mat,"Pentru a face alta convertire apasati 1 urmat de ENTER",54,30);
        aliniat(mat,"Pentru iesi din aplicatie apasati 2 urmat de ENTER",50,32);
        afisare(mat);
        SetCursorPosition(31, 7);
        cin>>v1;
        convM(v1,y);
        convD(v1,m);
        SetCursorPosition(31, 11);
        cout<<v1;
        SetCursorPosition(8, 14);
        cin>>ok;
        while((ok!=1)&&(ok!=2))
        {
            clear_screen();
            matrice(mat);
            centrare(mat,"RASPUNS INVALID",15,7);
            centrare(mat,"Mai incearca",12,9);
            aliniat(mat,"Pentru a face alta convertire apasati 1 urmat de ENTER",54,30);
            aliniat(mat,"Pentru iesi din aplicatie apasati 2 urmat de ENTER",50,32);
            afisare(mat);
            SetCursorPosition(35, 11);
            cin>>ok;
        }
    }
    if(n==3)
    {
        volum(mat,sir,16);
        afisare(mat);
        SetCursorPosition(44, 7);
        cin>>y;
        strcpy(sir,"In:");
        clear_screen();
        matrice(mat);
        volum(mat,sir,3);
        afisare(mat);
        SetCursorPosition(37, 7);
        cin>>m;
        clear_screen();
        matrice(mat);
        aliniat(mat,"Valoare de convertit:",21,7);
        aliniat(mat,"Valoare convertita:",19,11);
        aliniat(mat,"Pentru a face alta convertire apasati 1 urmat de ENTER",54,30);
        aliniat(mat,"Pentru iesi din aplicatie apasati 2 urmat de ENTER",50,32);
        afisare(mat);
        SetCursorPosition(31, 7);
        cin>>v1;
        convVolum(v1,y);
        convVolum2(v1,m);
        SetCursorPosition(31, 11);
        cout<<v1;
        SetCursorPosition(8, 14);
        cin>>ok;
        while((ok!=1)&&(ok!=2))
        {
            clear_screen();
            matrice(mat);
            centrare(mat,"RASPUNS INVALID",15,7);
            centrare(mat,"Mai incearca",12,9);
            aliniat(mat,"Pentru a face alta convertire apasati 1 urmat de ENTER",54,30);
            aliniat(mat,"Pentru iesi din aplicatie apasati 2 urmat de ENTER",50,32);
            afisare(mat);
            SetCursorPosition(35, 11);
            cin>>ok;
        }
    }
    return 0;
}
