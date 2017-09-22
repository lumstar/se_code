#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
void help()
{
    printf("This is a simple command line!\n");
    printf("You can use the following commands for help:\n");
    printf("----help-----for some help you want\n");
    printf("----hello----An interface of my command menu\n");
    printf("----add------help you to add two numbers\n");
    printf("----sub------help you to make a subtraction of two numbers\n");
    printf("----mult-----help you to make a multiplication of two numbers\n");
    printf("----divi-----help you to make a division of two numbers\n");
    printf("----compare--help you to make a comparation of two numbers\n");
    printf("----time-----help you to know the immediate time\n");
    printf("----quit-----help you quit the menu of command\n");
}
void hello()
{
    printf("Welcome to my command of menu,huve fun! ^_^\n");    
}
void add()
{
    int a,b;
    printf("please input two numbers:\n");
    scanf("%d %d",&a,&b);
    int c = a+b;
    printf("Result:a+b= %d\n",c);
}
void sub()
{
    int a,b;
    printf("Please input two numbers:\n");
    scanf("%d %d",&a,&b);
    int c=a-b;
    printf("Result:a-b= %d",c);
}
void mult()
{
    int a,b;
    printf("please input two numbers:\n");
    scanf("%d %d",&a,&b);
    int c = a*b;
    printf("Result:a*b= %d\n",c);
}
void divi()
{
    float a,b;
    printf("please input two numbers:\n");
    scanf("%f %f",&a,&b);
    float c = a/b;
    printf("Result:a/b= %lf\n",a/b);
}
void compare()
{
    int a,b;
    printf("Please input two numbers:\n");
	scanf("%d %d",&a,&b);
    float c = a-b;
    if(c>0)
    {
        printf("Result:%d>%d\n",a,b);
    }
    else if(c<0)
    {
        printf("Result:%d<%d\n",a,b);
    }
    else
    {
         printf("Result:%d=%d\n",a,b);
    }
}
void gettm()
{
    time_t rawtime;
    struct tm *t;
    time(&rawtime);
    t = localtime(&rawtime);
    printf("The local time : %s\n",asctime(t));
}
void quit()
{
    exit(0);
}
int main()
{
    char cmd[20];
	printf("Welcome to the menu,you can input help for help\n");
    while(1)
    {
		scanf("%s",&cmd);
        if(strcmp(cmd,"help") == 0)
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
		else
		{
		    printf("There is no such command,please try again!\n");
		}
    }
    return 0;
}
