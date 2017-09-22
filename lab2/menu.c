#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void help()
{
    printf("This is a simple command line!");
    printf("You can use the following commands for help:");
    printf("----help-----for some help you want");
    printf("----hello----An interface of my command menu");
    printf("----add------help you to add two numbers");
    printf("----sub------help you to make a subtraction of two numbers");
    printf("----mult-----help you to make a multiplication of two numbers");
    printf("----divi-----help you to make a division of two numbers");
    printf("----compare--help you to make a comparation of two numbers");
    printf("----time-----help you to know the immediate time");
    printf("----quit-----help you quit the menu of command");
}
void hello()
{
    printf("Welcome to my command of menu,huve fun! ^_^");    
}
void add()
{
    double a,b;
    printf("please input two numbers:");
    scanf("%lf %lf",&a,&b);
    double c = a+b;
    printf("Result:a+b= %lf\n",c);
}
void sub()
{
    double a,b;
    printf("Please input two numbers:");
    scanf("%lf %lf",&a,&b);
    double c=a-b;
    printf("Result:a-b= %lf",c);
}
void mult()
{
    double a,b;
    printf("please input two numbers:");
    scanf("%lf %lf",&a,&b);
    double c = a*b;
    printf("Result:a*b= %lf\n",c);
}
void divi()
{
    double a,b;
    printf("please input two numbers:");
    scanf("%lf %lf",&a,&b);
    double c = a/b;
    printf("Result:a/b= %lf\n",a/b);
}
void compare()
{
    double a,b;
    printf("Please input two numbers:");
    double c = a-b;
    if(c>0)
    {
        printf("Result:a>b");
    }
    else if(a<0)
    {
        printf("Result:a<b");
    }
    else
    {
        printf("Result:a=b");
    }
}
void gettm()
{
    time_t rawtime;
    struct tm *t;
    time(&rawtime);
    t = localtime(&rawtime);
    printf("The local time : %s",asctime(t));
}
void quit()
{
    exit(0);
}
int main()
{
    char cmd[20];
    while(1)
    {
        if(strcmp(cmd,"help" == 0))
        {
            help();
        }
        else if(strcmp(cmd,"hello") == 0)
        {
            hello();
        }
        else if(strcmp(cmd,"add") == 0)
        {
            add();
        }
        else if(strcmp(cmd,"sub") == 0)
        {
            sub();
        }
        else if(strcmp(cmd,"mult") == 0)
        {
            mult();
        }
        else if(strcmp(cmd,"divi") == 0)
        {
            divi();
        }
        else if(strcmp(cmd,"compare") == 0)
        {
            compare();
        }
        else if(strcmp(cmd,"time") == 0)
        {
            gettm();
        }
        else if(strcmp(cmd,"quit") == 0)
        {
            quit();
        }
    }
    return 0;
}
