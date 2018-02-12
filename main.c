# include "brew.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <malloc.h>
mdl_u8_t *p = NULL;
mdl_u8_t static *eof;
mdl_u8_t at_eof() {
	return (p >= eof || *p == '\0');
}
int main(int __argc, char const *__argv[]) {
	char const *file;
	if (__argc < 2) {
		fprintf(stderr, "please provide file.\n");
		return -1;
	}

	file = __argv[1];
	int fd;
	if ((fd = open(file, O_RDONLY)) == -1) {
		fprintf(stderr, "failed to open file.\n");
		return -1;
	}

	struct stat st;
	if (fstat(fd, &st) == -1) {
		fprintf(stderr, "failed to stat file.\n");
		goto _falt;	
	}

	if ((p = (mdl_u8_t*)malloc(st.st_size)) == NULL) {
		fprintf(stderr, "failed to allocate memory.\n");
		goto _falt;
	}
	
	read(fd, p, st.st_size);
	eof = p+st.st_size;
	bucketp p;
	parse(&p);

	lexer_cleanup();

	_falt:
	close(fd);
	if (p != NULL)
		free(p);
	return 0;
}
