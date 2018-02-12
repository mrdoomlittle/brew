# include "brew.h"
# include <malloc.h>
# include <stdio.h>
void parse(bucketp *__p) {
	while(!at_eof()) {
		bucketp tok = lex();
		if (tok->sort == _ident) {
			printf("ident: %s\n", (char*)tok->p);
			free(tok->p);
		}
	}
}
