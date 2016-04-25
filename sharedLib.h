
#include "data.h"

#ifndef foo_h__
#define foo_h__
 
/*extern int readptr;
extern int writeptr;

extern struct msg
{
	char *mesg;
	int flag;
};

extern typedef struct msg message_t;

extern message_t buffer[BUF_SIZE];
*/

extern "C"{

//message_t buffer[BUF_SIZE];

void buffer_create();

message_t* buffer_open();

void foo(void);

int Read();

void Write(char*,int);

void print();

}
 
#endif  // foo_h__
