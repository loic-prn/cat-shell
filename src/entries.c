#include "entries.h"

char* read_line(void){
	short unsigned int buffsize = SIZE;
	char *buffer = malloc(sizeof(char) * buffsize);
	if(!buffer){
		printf("csh:Allocation Error\n");
		exit(EXIT_FAILURE);
	}
	int c = 0;
	unsigned int i = 0;
	while(1){
		c = getchar();
		// check if end
		if(c == EOF || c == '\n'){
			// end the string
			buffer[i] = '\0';
			return buffer;
		}
		else {
			buffer[i] = c;
		}

		++i;

		// if about to overflow
		if(i >= SIZE){
			buffsize += SIZE;
			// realloc = add space
			buffer = realloc(buffer, buffsize);
			// realloc fail
			if(!buffer){
				printf("csh:Allocation Error\n");
				exit(EXIT_FAILURE);
			}
		}
	}
	return buffer;
}


char **parse_line(char *line){
	short unsigned int buffsize = ARG_SIZE;
	size_t position = 0;
	char **tokens = (char**) malloc(sizeof(char*) * buffsize);
	if(!tokens){
		printf("csh:Allocation Erroe\n");
		exit(EXIT_FAILURE);
	}
	char *tok;
	// if fail malloc
	if(!tokens){
		printf("csh:Allocation Error\n");
		exit(EXIT_FAILURE);
	}
	// parse token
	tok = strtok(line,LIMITERS);
	// go through the tab until the end
	while(tok != NULL){
		tokens[position] = tok;
		++position;

		// if about to overflow
		if(position >= buffsize){
			buffsize += ARG_SIZE;
			tokens = realloc(tokens, buffsize + sizeof(char*));
			// if realloc fail
			if(!tokens){
				printf("csh:Allocation Error\n");
				exit(EXIT_FAILURE);
			}
		}
		// parse token
		tok = strtok(NULL, LIMITERS);
	}
	// put a NULL at the end to delimit
	tokens[position] = NULL;
	return tokens;
}


void printer(char **pptr){
	size_t i = 0;
	while(pptr[i] != NULL){
		if(i == 0){
			printf("%s\n", pptr[i]);
		}
		// tab if not first
		else{
			printf("\t%s\n", pptr[i]);
		}
		++i;
	}
}
