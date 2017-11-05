
/********************************************************************/
/*  USTC   YiYu                                                     */
/*  FILE NAME             :  menu.h                                 */
/*  PRINCIPAL AUTHOR      :  wjiany                                 */
/*  DESCRIPTION           :  interface of menu                      */
/********************************************************************/


/*functions of cmd*/
int Help(int argc,char * argv[]);
int Quit(int argc,char * argv[]);
int Add(int argc,char * argv[]);
int Sub(int argc,char * argv[]);
int Mult(int argc,char * argv[]);
int Divi(int argc,char * argv[]);
int Compare(int argc,char * argv[]);
int Gettm(int argc,char * argv[]);

/*add cmd to menu*/

int MenuConfig(char *cmd,char *desc,int(*handler)(int argc,char *argv[]));

/*execute menu*/

int ExecuteMenu();
