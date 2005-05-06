#ifndef COMMON_UTILS_H
#define COMMON_UTILS_H

#include "base.h"


int config_switch(const char *str);
bool e_mail_check(const char *email);
bool remove_control_chars(char *str);

void dump(unsigned char *buffer, size_t num);

char* checkpath(char *path, const char* src);
void findfile(const char *p, const char *pat, void (func)(const char*) );

extern inline FILE* savefopen(const char*name, const char*option)
{	// windows MAXPATH is 260, unix is longer
	char	 namebuf[2048];
	checkpath(namebuf,name);
	return fopen( namebuf, option);
}



struct StringBuf {
	char *buf_;
	char *ptr_;
	unsigned int max_;
};

struct StringBuf * StringBuf_Malloc();
void StringBuf_Init(struct StringBuf *);
int StringBuf_Printf(struct StringBuf *,const char *,...);
int StringBuf_Append(struct StringBuf *,const struct StringBuf *);
char * StringBuf_Value(struct StringBuf *);
void StringBuf_Destroy(struct StringBuf *);
void StringBuf_Free(struct StringBuf *);




#endif//COMMON_UTILS_H
