
/**************************************************************************************************/
/* @USTC      YiYu                                                                  */
/*  FILE NAME             :  menu.c                                                               */
/*  PRINCIPAL AUTHOR      :  wjiany                                                               */            
/*  DESCRIPTION           :  This is a menu program                                               */
/**************************************************************************************************/




#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "linktable.h"

int Help();
int Quit();
int Add();
int Sub();
int Mult();
int Divi();
int Compare();
int Gettm();
#define CMD_MAX_LEN 128
#define DESC_LEN    1024
#define CMD_NUM     10



/* data struct and its operations */

typedef struct DataNode
{
    tLinkTableNode * pNext;
    char*   cmd;
    char*   desc;
    int     (*handler)();
} tDataNode;

int SearchCondition(tLinkTableNode * pLinkTableNode,void  *args)
{
	char * cmd = (char *) args;
    tDataNode * pNode = (tDataNode *)pLinkTableNode;
    if(strcmp(pNode->cmd, cmd) == 0)
    {
        return  SUCCESS;  
    }
    return FAILURE;	       
}

/* find a cmd in the linklist and return the datanode pointer */
tDataNode* FindCmd(tLinkTable * head, char * cmd)
{
    return  (tDataNode*)SearchLinkTableNode(head,SearchCondition,(void *) cmd);
}

/* show all cmd in listlist */
int ShowAllCmd(tLinkTable * head)
{
    tDataNode * pNode = (tDataNode*)GetLinkTableHead(head);
    while(pNode != NULL)
    {
        printf("%s - %s\n", pNode->cmd, pNode->desc);
        pNode = (tDataNode*)GetNextLinkTableNode(head,(tLinkTableNode *)pNode);
    }
    return 0;
}

int InitMenuData(tLinkTable ** ppLinktable)
{
    *ppLinktable = CreateLinkTable();
    tDataNode* pNode = (tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd = "help";
    pNode->desc = "Menu List:";
    pNode->handler = Help;
    AddLinkTableNode(*ppLinktable,(tLinkTableNode *)pNode);
    pNode = (tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd = "version";
    pNode->desc = "Menu Program V1.0";
    pNode->handler = NULL; 
    AddLinkTableNode(*ppLinktable,(tLinkTableNode *)pNode);
    pNode = (tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd = "quit";
    pNode->desc = "Quit from Menu Program V1.0";
    pNode->handler = Quit; 
    AddLinkTableNode(*ppLinktable,(tLinkTableNode *)pNode);
    pNode=(tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd="add";
    pNode->desc="add two numbers";
    pNode->handler=Add;
    AddLinkTableNode(*ppLinktable,(tLinkTableNode*)pNode);
    pNode=(tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd="sub";
    pNode->desc="make a sub of two numbers";
    pNode->handler=Sub;
    AddLinkTableNode(*ppLinktable,(tLinkTableNode*)pNode);
    pNode=(tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd="mult";
    pNode->desc="make a multiplication of two numbers";
    pNode->handler=Mult;
    AddLinkTableNode(*ppLinktable,(tLinkTableNode*)pNode);
    pNode=(tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd="divi";
    pNode->desc="make a division of two numbers";
    pNode->handler=Divi;
    AddLinkTableNode(*ppLinktable,(tLinkTableNode*)pNode);
    pNode=(tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd="compare";
    pNode->desc="make a comparation  of two numbers";
    pNode->handler=Compare;
    AddLinkTableNode(*ppLinktable,(tLinkTableNode*)pNode);
    pNode=(tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd="time";
    pNode->desc=" know the immediate time";
    pNode->handler=Gettm;
    AddLinkTableNode(*ppLinktable,(tLinkTableNode*)pNode);
	
    return 0; 
}

/* menu program */

tLinkTable * head = NULL;

int main()
{
    InitMenuData(&head); 
   /* cmd line begins */
    while(1)
    {
		char cmd[CMD_MAX_LEN];
        printf("Input a cmd number > ");
        scanf("%s", cmd);
        tDataNode *p = FindCmd(head, cmd);
        if( p == NULL)
        {
            printf("This is a wrong cmd!\n ");
            continue;
        }
        printf("%s - %s\n", p->cmd, p->desc); 
        if(p->handler != NULL) 
        { 
            p->handler();
        }
   
    }
}

int Help()
{
    ShowAllCmd(head);
    return 0; 
}

int Quit()
{
    exit(0);
}
int Add()
{
    int a,b;
    printf("please input two numbers:\n");
    scanf("%d %d",&a,&b);
    int c = a+b;
    printf("Result:a+b= %d\n",c);
    return 0;
}
int Sub()
{
    int a,b;
    printf("Please input two numbers:\n");
    scanf("%d %d",&a,&b);
    int c=a-b;
    printf("Result:a-b= %d\n",c);
    return 0;
}
int Mult()
{
    int a,b;
    printf("please input two numbers:\n");
    scanf("%d %d",&a,&b);
    int c = a*b;
    printf("Result:a*b= %d\n",c);
    return 0;
}
int Divi()
{
    float a,b;
    printf("please input two numbers:\n");
    scanf("%f %f",&a,&b);
    float c = a/b;
    printf("Result:a/b= %lf\n",a/b);
    return 0;
}
int Compare()
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
int Gettm()
{
    time_t rawtime;
    struct tm *t;
    time(&rawtime);
    t = localtime(&rawtime);
    printf("The local time : %s\n",asctime(t));
    return 0;
}
