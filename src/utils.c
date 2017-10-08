#include "utils.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
void mysh_parse_command(const char* command,
                        int *argc, char*** argv)
{
char* com_tmp=(char*)malloc(sizeof(char)*255);
char* tok;
int i =0;

strcpy(com_tmp,command);
int len=strlen(com_tmp);
for(int j=len+1;j>=0;j--)
{
if(*(com_tmp+j) == '\n')
{
*(com_tmp+j) = '\0';
break;
}
}

tok=strtok(com_tmp," \n\t");
*argv = (char**)malloc(sizeof(char)*255);

if(tok == NULL)
{
i++;
*argc=i;
*(*argv)=(char*)malloc(sizeof(char)*255);
strcpy(*(*argv),"");
return;
}
while(tok!=NULL)
{
*(*argv+i)=(char*)malloc(sizeof(char)*255);
strcpy(*(*argv+i),tok);
tok=strtok(NULL," \n\t");
i++;
*argc=i;
}
return;
}
