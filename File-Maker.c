#include<stdio.h>
#include<conio.h>
#include<math.h>
#include <stdlib.h>
#include <string.h>
#define M 100
int main()
{
int a;
printf("\n How many states you want to enter for the DFA:-");
scanf("%d",&a);
FILE *fp;
char s[a][M],X[M],Y[M],T[M],f[M][M],O[M][M],G[M];
int i,j,b,c,d=1,e,k,p,g,u,v,o,l;

for(i=0;i<a;i++)
{
    E:printf("\n Enter a state:-");
    fflush(stdin);
    gets(s[i]);
    d=1;
    for(j=0;j<i;j++)
    {
        if(strcmp(s[j],s[i])==0)
        {
            d=0;
            break;
        }
    }
    if(d==0)
    {
        printf("\n you have entered same state.please enter a valid state.");
        goto E;
    }
}
/*
for(i=0;i<a;i++)
{
    printf("%s ",s[i]);
}
*/
printf("\n How many alphabet you want to enter for the DFA:-");
scanf("%d",&b);
char z[b][M];
for(j=0;j<b;j++)
{
    D:printf("\n Enter an alphabet:-");
    fflush(stdin);
    gets(z[j]);
    d=1;o=-1;
    for(i=0;i<j;i++)
    {
        if(strcmp(z[j],z[i])==0)
        {
            d=0;
            break;
        }
    }
    if(d==0)
    {
        printf("\n you have entered same alphabet.please enter a valid alphabet.");
        goto D;
    }
    d=1;
}
int Q[a][a][b];
/*
for(i=0;i<b;i++)
{
    printf("%s ",z[i]);
}
*/
A:printf("\n Enter your starting state for the DFA:-");
fflush(stdin);
gets(G);
printf("%s",O[0]);
int k1=0;
for(i=0;i<a;i++)
{
    if(strcmp(s[i],G)==0)
    {
        d=0;
        k1=i;
        break;
    }
}
if(d!=0)
{
    printf("\n It is not a valid starting state please enter valid state.");
    goto A;
}
B:printf("\n How many final states you want to enter for the DFA:-");
scanf("%d",&c);
if(c>a)
{
    printf("\n Number of final states can't be greater than card(Q). please enter a valid number. ");
    goto B;
}
for(j=0;j<c;j++)
{
    C:printf("\n Enter a state:-");
    fflush(stdin);
    gets(f[j]);
    d=1;
    for(i=0;i<j;i++)
    {
        if(strcmp(f[j],f[i])==0)
        {
            d=0;
            break;
        }
    }
    if(d==0)
    {
        printf("\n you have entered same final state.please enter a valid final state.");
        goto C;
    }
    d=1;
    for(i=0;i<a;i++)
    {
        if(strcmp(s[i],f[j])==0)
        {
            d=0;
            break;
        }
    }
    if(d!=0)
    {
        printf("\n It is not a valid final state please enter valid final state.");
        goto C;
    }
}
/*
for(i=0;i<c;i++)
{
    printf("%s ",f[i]);
}
*/
for(k=0;k<a;k++)
{
    for(j=0;j<a;j++)
    {
        for(i=0;i<b;i++)
        {
            Q[k][j][i]=0;
        }
    }
}
fp=fopen("Wanted_DFA.txt","w");
fprintf(fp,"%s","States:-{");
for(i=0;i<a;i++)
{
    fprintf(fp,"%s",s[i]);
    if(i!=a-1)
    {
        fprintf(fp,"%s",",");
    }
}
fprintf(fp,"%s","}");
fprintf(fp,"\n%s","Alphabets:-{");
for(i=0;i<b;i++)
{
    fprintf(fp,"%s",z[i]);
    if(i!=b-1)
    {
        fprintf(fp,"%s",",");
    }
}
fprintf(fp,"%s","}");
fprintf(fp,"\n%s","Final States:-{");
for(i=0;i<c;i++)
{
    fprintf(fp,"%s",f[i]);
    if(i!=c-1)
    {
        fprintf(fp,"%s",",");
    }
}
fprintf(fp,"%s","}");
fprintf(fp,"\n%s%s","Starting State:-",G);
fprintf(fp,"\n%s","Transition Functions are:-");
for(k=0;k<M;k++)
{
    for(j=0;j<M;j++)
    {
        F:printf("\n Enter the values of transition function [d(q,a)=q'] as (state alphabet state) for your DFA [If you want to end your input enter (@ @ @)]:-");
        scanf("%s %s %s",&T,&X,&Y);
        if (strcmp(T,X)==0 && strcmp(X,Y)==0 && strcmp(T,"@")==0)
        {
            k=M;
            j=M;
            break;
        }
        d=1;
        for(i=0;i<a;i++)
        {
            if(strcmp(s[i],T)==0)
            {
                d=0;
                u=i;
                break;
            }
        }
        if(d!=0)
        {
            printf("\n Not a valid state please enter a valid state.");
            goto F;
        }
        d=1;
        for(i=0;i<a;i++)
        {
            if(strcmp(s[i],Y)==0)
            {
                d=0;
                v=i;
                break;
            }
        }
        if(d!=0)
        {
            printf("\n Not a valid state please enter a valid state.");
            goto F;
        }
        d=1;
        for(i=0;i<b;i++)
        {
            if(strcmp(z[i],X)==0)
            {
                d=0;
                Q[u][v][i]=1;
                fprintf(fp,"\n%s%s%s%s%s%s","del(",s[u],",",z[i],")=",s[v]);
                break;
            }
        }
        if(d!=0)
        {
            printf("\n Not a valid alphabet please enter a valid alphabet.");
            goto F;
        }
    }
}/*
for(k=0;k<a;k++)
{
    for(j=0;j<a;j++)
    {printf("{");
        for(i=0;i<b;i++)
        {
            printf("%d,",Q[k][j][i]);
        }
        printf("}    ");
    }
    printf("\n");
}*/
fclose(fp);
}

