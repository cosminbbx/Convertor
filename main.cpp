#include <iostream>
#include <string.h>
#include <windows.h>
#include <stdio.h>
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
    char convertor[]="Convertor magic";
    centrare(mat,convertor,15,6);
    char alege[]="Alege convertor:";
    centrare(mat,alege,16,8);
    char lungime[]="1. Lungime";
    centrare(mat,lungime,10,9);
    char arie[]="2. Arie";
    centrare(mat,arie,7,10);
    char volum[]="3. Volum";
    centrare(mat,volum,8,11);
    char viteza[]="4. Viteza";
    centrare(mat,viteza,9,12);
    char temp[]="5. Temperatura";
    centrare(mat,temp,14,13);
    char masa[]="6. Masa";
    centrare(mat,masa,7,14);
    char energie[]="7. Energie";
    centrare(mat,energie,10,15);
    char presiune[]="8. Presiune";
    centrare(mat,presiune,11,16);
    char densitate[]="9. Densitate";
    centrare(mat,densitate,12,17);
    char consum[]="10. Consum combustibil";
    centrare(mat,consum,22,18);
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
int main()
{


    int i,j,n;
    char mat[41][71],c[]=" ";
    char sir[]="Chestie";
    matrice(mat);
    meniu(mat);
    afisare(mat);
    SetCursorPosition(20, 30);
    cin>>n;
    clear_screen();
    matrice(mat);
    if(n==1)
        centrare(mat,sir,7,20);
    afisare(mat);
    return 0;
}
