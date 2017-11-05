#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "menu.h"

int main(int argc,char * argv[])
{
    MenuConfig("version","Menu Program V1.0",NULL);
    MenuConfig("quit","Quit from Menu Program V1.0",Quit);
    MenuConfig("add","add two numbers",Add);
    MenuConfig("sub","make a sub of two numbers",Sub);
    MenuConfig("mult","make a multiplication of two numbers",Mult);
    MenuConfig("divi","make a division of two numbers",Divi);
    MenuConfig("compare","make a comparation  of two numbers",Compare);
    MenuConfig("time","know the immediate time",Gettm);
    ExecuteMenu();
}

   
   
    
