#include <stdio.h>
#include<stdlib.h>
#include<string.h>	
#include<pthread.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/mman.h>
#include<sys/types.h>
#include<fcntl.h>
#include "data.h"

#define MSG_READ 1
#define MSG_UNREAD 0

pthread_mutexattr_t buffersharedm;

pthread_cond_t writer = PTHREAD_COND_INITIALIZER;

char *name = "buffer";

void foo(void)
{
    puts("Hello, I'm a shared library");
}

void buffer_create()
{

	int i;
	
	buffer_t *bufmap;

	int fd = open(name,O_RDWR|O_CREAT|O_EXCL,0666);
	ftruncate(fd,sizeof(buffer_t));

	pthread_mutexattr_init(&buffersharedm);
	pthread_mutexattr_setpshared(&buffersharedm, PTHREAD_PROCESS_SHARED);

	bufmap = (buffer_t*)mmap(NULL,sizeof(buffer_t),PROT_READ|PROT_WRITE, MAP_SHARED,fd,0);

	close(fd);

	for(i=0; i<10; i++)
	{
		bufmap->buf[i].flag = MSG_READ;
	}
}

buffer_t* buffer_open()
{
	buffer_t* bufmap;
	int fd = open(name,O_RDWR,0666);

	if(fd < 0)
	{
		puts("Unable to open buffer\n");
		printf("fd = %d\n",fd);
		return NULL;
	}

	bufmap = (buffer_t*)mmap(NULL,sizeof(buffer_t),PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);

	close(fd);

	return bufmap;
}

int Read()
{
	readptr = readptr % 10;

	buffer_t* bufmap = buffer_open();

	if(bufmap == NULL)
	{
		puts("ERROR:NULL");
		return 1;
	}

	while(bufmap->buf[readptr].flag == MSG_READ)
	{
		//DOES NOTHING
		//puts("does nothing");
	}

	if(strcmp(bufmap->buf[readptr].mesg, "quit") == 0)
		return 1;
	
	int tempptr = readptr;

	printf("%s\n",bufmap->buf[readptr].mesg);

	readptr = (readptr + 1) % 10;

	return 0;
}

void Write(char *message, int msglen)
{
	writeptr = writeptr % 10;
	buffer_t* bufmap = buffer_open();
	
	while(bufmap->buf[writeptr].flag == MSG_UNREAD)
	{
		//DOES NOTHING
		//puts("does nothing\n");
	}
	
	int i;
	for( i=0; i<msglen; i++)
	{
		bufmap->buf[writeptr].mesg[i] = message[i];
	}
	bufmap->buf[writeptr].mesg[i] = '\0';
	
	bufmap->buf[writeptr].flag = MSG_UNREAD;


	writeptr = (writeptr + 1) % 10;
}

