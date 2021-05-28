#include "entries.h"

int main(int argc, char* argv[]){
	printf("$ ");
	char *ptr = read_line(); // alloc
	char **pptr = parse_line(ptr);
	free(ptr); // free
	free(pptr);
	return 0;
}
