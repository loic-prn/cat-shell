#include "entries.h"

void list(char **str){
	DIR *dir;
	struct dirent *dent;
	dir = opendir(".");
	// if can open
	if(dir != NULL){
		// readdir while it's not NULL
		while((dent=readdir(dir)) != NULL){
			struct stat s;
			// create a stat struct of "dent"
			stat(dent->d_name, &s);
			if(S_ISDIR(s.st_mode)){
				// custom lib to color output
				printf("%s%s", HGREEN, dent->d_name);
			}
			else{
				printf("%s", dent->d_name);
			}
				printf("%s\n", RESET);
		}
	}
	closedir(dir);
}
