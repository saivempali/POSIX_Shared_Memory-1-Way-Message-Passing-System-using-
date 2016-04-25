 
#define BUF_SIZE 10

int readptr = 0;
int writeptr = 0;

struct msg
{
	char mesg[1000];
	int flag;
};

typedef struct msg message_t;

struct buffer
{
	message_t buf[BUF_SIZE];
};

typedef struct buffer buffer_t;

