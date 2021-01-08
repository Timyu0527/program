#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define lineTotal 4
char *myStrtok(char str[], char brk[])
{
	static char *nextp = NULL;
	char *token = NULL;
	if(str != NULL) nextp = str;
	while(*nextp != '\0')
	{
		int flag = 0;
		for(int i = 0; i < strlen(brk); ++i)
		{
			if(*nextp == brk[i])
			{
				flag = 1;
				break;
			}
		}
		if(flag) nextp++;
        else break;
	}
	if(*nextp != '\0') token = nextp;
	while(*nextp != '\0')
	{
		for(int i = 0; i < strlen(brk); ++i)
		{
			if(*nextp == brk[i])
			{
				*nextp = '\0';
				nextp++;
				return token;
			}
		}
		nextp++;
	}
	return token;
}

int main() {
    char testline[lineTotal][100] = {
        "... Yes you got it!!! \\^^/",
        ".,?!///\\\\!!? ..",
        "",
        "A normal test. Hope it works!"
    };
    char brk[] = "., \\/?!";
    int i; char line[100], *token;
    for (i = 0; i < lineTotal; i++) {
        printf("Testing [%s] by strtok:\n", testline[i]);
        strcpy(line, testline[i]);
        token = strtok(line, brk);
        while (token != NULL) {
            printf("\t[%s]\n", token);
            token = strtok(NULL, brk);
        }
        printf("Testing [%s] by mystrtok:\n", testline[i]);
        strcpy(line, testline[i]);
        token = myStrtok(line, brk);
        while (token != NULL) {
            printf("\t[%s]\n", token);
            token = myStrtok(NULL, brk);
        }
    }
    return 0;
}
