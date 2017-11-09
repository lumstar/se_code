
/**************************************************************************************************/
/* @USTC      YiYu                                                                                */
/*  FILE NAME             :  menu.c                                                               */
/*  PRINCIPAL AUTHOR      :  wjiany                                                               */            
/*  DESCRIPTION           :  This is a menu program                                               */
/**************************************************************************************************/




#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "linktable.h"
#include "menu.h"

tLinkTable * head = NULL;

#define CMD_MAX_LEN 128
#define DESC_LEN    1024
#define CMD_NUM     13
#define CMD_MAX_ARGV_NUM 10


/* data struct and its operations */

typedef struct DataNode
{
    tLinkTableNode * pNext;
    char*   cmd;
    char*   desc;
    int     (*handler)(int argc,char * argv[]);
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


/* menu program */



/*add cmd to menu*/
int MenuConfig(char *cmd, char *desc,int (*handler)(int argc,char *argv[]))
{
    tDataNode* pNode = NULL;
    if(head == NULL)
    {
        head = CreateLinkTable();
        pNode = (tDataNode*)malloc(sizeof(tDataNode));
        pNode->cmd = "help";
        pNode->desc = "Menu List:";
        pNode->handler = Help;
        AddLinkTableNode(head,(tLinkTableNode *)pNode);
    }
    pNode = (tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd = cmd;
    pNode->desc = desc;
    pNode->handler = handler;
    AddLinkTableNode(head,(tLinkTableNode *)pNode);
    return 0;
}

/*Exucete Menu*/
int ExecuteMenu()
{
   /* cmd line begins */
    while(1)
    {
        int argc = 0;
        char *argv[CMD_MAX_ARGV_NUM];
	char cmd[CMD_MAX_LEN];
        char *pcmd=NULL;
        printf("Input a cmd number > ");
        //scanf("%s", cmd);
        pcmd = fgets(cmd,CMD_MAX_LEN,stdin); 
        //tDataNode *p = FindCmd(head, cmd);
        if( pcmd == NULL)
        {
            continue;
        }
        pcmd = strtok(pcmd," ");
        while(pcmd!=NULL&&argc<CMD_MAX_ARGV_NUM)
	{
	    argv[argc] = pcmd;
            argc++;
            pcmd = strtok(NULL," ");
	}
        if(argc == 1)
        {
            int len = strlen(argv[0]);
            * (argv[0] + len - 1) = '\0';  
        }
        tDataNode * p = (tDataNode *)SearchLinkTableNode(head,SearchCondition,(void*)argv[0]);
         if( p == NULL)
        {
            printf("This is a wrong cmd!\n ");
            continue;
        }
        if(p->handler != NULL) 
        { 
            p->handler(argc,argv);
        }
   
    }
}

int Help(int argc,char *argv[])
{
    ShowAllCmd(head);
    return 0; 
}

int Quit(int argc,char * argv[])
{
    exit(0);
}
int Add(int argc,char * argv[])
{
    int c = argv[1][0]+argv[2][0]-96;
    printf("Result:a+b= %d\n",c);
    return 0;
}
int Sub(int argc,char * argv[])
{
    int c = argv[1][0]-argv[2][0];
    printf("Result:a-b= %d\n",c);
    return 0;
}
int Mult(int argc,char * argv[])
{
    int a,b;
    printf("please input two numbers:\n");
    scanf("%d %d",&a,&b);
    int c = a*b;
    printf("Result:a*b= %d\n",c);
    return 0;
}
int Divi(int argc,char * argv[])
{
    float a,b;
    printf("please input two numbers:\n");
    scanf("%f %f",&a,&b);
    float c = a/b;
    printf("Result:a/b= %lf\n",a/b);
    return 0;
}
int Compare(int argc,char * argv[])
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
int Gettm(int argc,char * argv[])
{
    time_t rawtime;
    struct tm *t;
    time(&rawtime);
    t = localtime(&rawtime);
    printf("The local time : %s\n",asctime(t));
    return 0;
}
