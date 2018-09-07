//#include "shell.h"
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <time.h>
#include <curses.h>

int main()
{
	pid_t child;
	DIR * d;
	struct dirent * de;
	int i, c, k;
	char s[256], cmd[256], o[256], n[256];
	time_t t;

	while (1)
	{
		t = time(NULL);
		printf("Time: %s\n", ctime(&t));

		getcwd(s, 200);
		printf("\nCurrent Directory: %s \n", s);

		/* F I L E S */
		d = opendir(".");
		c = 0;
		printf("\nFiles:\n-------------------------------------------\n");
		while ((de = readdir(d)))
		{
			if (((de->d_type) & DT_REG))
				printf("\t%d. %s\n", c++, de->d_name);
			if ((c%8)==0)
			{
				printf("Hit N for Next\n");
				k = getchar();
			}
		}
		closedir(d);

		/* D I R E C T O R I E S */
		d = opendir(".");
		c = 0;
		printf("\nDirectories:\n-------------------------------------------\n");
		while ((de = readdir(d)))
		{
			if ((de->d_type) & DT_DIR)
				printf("\t%d. %s\n", c++, de->d_name);
		}
		closedir(d);

		/* O P E R A T I O N   M E N U */
		printf("\nOperations:\n-------------------------------------------\n");
		printf("\tD  Display\n");
		printf("\tE  Edit\n");
		printf("\tR  Run\n");
		printf("\tC  Change Directory\n");
		printf("\tS  Sort Directory Listing\n");
		printf("\tM  Move to Directory\n");
		printf("\tX  Remove File\n");
		printf("\tQ  Quit\n");
		
		printf("-------------------------------------------\n");
		c = getchar(); getchar();
		switch (c)
		{
			case 'D': printf("Display Operation\n");
				break;
			case 'E': printf("Edit Operation\n");
				scanf("%s", s);
				strcpy(cmd, "pico ");
				strcat(cmd, s);
				system(cmd);
				break;
			case 'R': printf("Run Operation\n");
				scanf("%s", s);
				system(cmd);
				break;
			case 'C': printf("Change Directory Operation\n");
				scanf("%s", s);
				chdir(cmd);
				break;
			case 'S': printf("Sort Directory Listing Operation\n");
				break;
			case 'M': printf("Move to Directory\n");
				getcwd(o, 200);
				printf("\nOriginal Directory: %s\n", o);
				getcwd(n, 200);
				printf("\nNew Directory: %s\n", n);
				break;
			case 'X': printf("Remove File Operation\n");
				break;
			case 'Q': printf("Quit Operation\n");
				exit(0);
				break;
			default: printf("Please select an option from the menu\n");
		}
	}
}