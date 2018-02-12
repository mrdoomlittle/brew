# ifndef __brew__h
# define __brew__h
# include <mdlint.h>
extern mdl_u8_t *p;
# define incrp p++
# define decrp p--
typedef struct bucket {
	struct bucket *next;
	mdl_u8_t sort;
	void *p;
	mdl_u16_t len;
} *bucketp;

enum {
	_unknown,
	_ident,
	_colon
};

bucketp lex();
void ulex(bucketp);
void parse(bucketp*);
mdl_u8_t at_eof();
void lexer_cleanup();
# endif /*__brew__h*/
