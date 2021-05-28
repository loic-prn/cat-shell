#include "entries.h"

//int pos = 0;

char* read_line(void){
	short unsigned int buffsize = SIZE;
	char *buffer = malloc(sizeof(char) * buffsize);
	int c = 0;
	unsigned int i = 0;
	while(1){
		c = getchar();
		if(c == EOF || c == '\n'){
			buffer[i] = '\0';
			return buffer;
		}
		else {
			buffer[i] = c;
		}

		++i;

		if(i >= SIZE){
			buffsize += SIZE;
			buffer = realloc(buffer, buffsize);
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
	char *tok;
	if(!tokens){
		printf("csh:Allocation Error\n");
		exit(EXIT_FAILURE);
	}

	tok = strtok(line,LIMITERS);
	while(tok != NULL){
		tokens[position] = tok;
		++position;

		if(position >= buffsize){
			buffsize += ARG_SIZE;
			tokens = realloc(tokens, buffsize + sizeof(char*));
			if(!tokens){
				printf("csh:Allocation Error\n");
				exit(EXIT_FAILURE);
			}
		}

		tok = strtok(NULL, LIMITERS);
	}
	for(size_t i = 0; i < position; ++i){
		printf("%s\n", tokens[i]);
	}
	tokens[position] = NULL;
	return tokens;
}
