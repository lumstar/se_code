#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "linklist.h"
int help();
int hello();
int quit();
int add();
int sub();
int mult();
int compare();
int gettm();
#define CMD_MAX_LEN	128
#define DESC_LEN	1024
#define CMD_NUM		10
static tDataNode head[] =
{
    {"help","this is help cmd!",help,&head[1]},
    {"hello","Welcome interface",hello,&head[2]},
    {"version","menu program v1.0",NULL,&head[3]},
    {"add","add two numbers",add,&head[4]},
    {"sub","make a subtraction of two numbers",sub,&head[5]},
    {"mult","make a multiplication of two numbers",mult,&head[6]},
    {"compare","compare two numbers",compare,&head[7]},
    {"time","show the local time",gettm,&head[8]},
    {"quit","exit the menu program",quit,NULL}
};
int main()
{
    while(1)
    {
        char cmd[CMD_MAX_LEN];
	printf("input a cmd->");
	scanf("%s",cmd);
	tDataNode *p = FindCmd(head, cmd);
	if(p == NULL)
	{
	    printf("this is a wrong cmd!\n");
	    continue;
	}
	printf("%s - %s\n", p->cmd, p->desc);
	if(p->handler != NULL)
	{
	    p->handler();
	}	
    }
}
int help()
{
    ShowAllCmd(head);
    return 0;
}
int quit()
{
    exit(0);
    return 0;
}
int add()
{
    int a,b;
    printf("please input two numbers:\n");
    scanf("%d %d",&a,&b);
    int c = a+b;
    printf("Result:a+b= %d\n",c);
    return 0;
}
int sub()
{
    int a,b;
    printf("Please input two numbers:\n");
    scanf("%d %d",&a,&b);
    int c=a-b;
    printf("Result:a-b= %d\n",c);
    return 0;
}
int mult()
{
    int a,b;
    printf("please input two numbers:\n");
    scanf("%d %d",&a,&b);
    int c = a*b;
    printf("Result:a*b= %d\n",c);
    return 0;
}
int compare()
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
    return 0;
}
int hello()
{
    printf("Welcome to my command of menu,huve fun! ^_^\n");
    return 0;    
}
int gettm()
{
    time_t rawtime;
    struct tm *t;
    time(&rawtime);
    t = localtime(&rawtime);
    printf("The local time : %s\n",asctime(t));
    return 0;
}
