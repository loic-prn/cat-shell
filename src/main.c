#include "entries.h"

int main(int argc, char* argv[]){
	printf("$ ");
	char *ptr = read_line(); // alloc
	char **pptr = parse_line(ptr); // alloc
	if(strcmp(pptr[0], "ls") == 0){
		list();
	}
	printer(pptr);

	// some github fixes 2.0
	free(ptr); // free
	free(pptr);

	//list();
	return 0;
}
