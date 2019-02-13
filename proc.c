#include <stdio.h>
#include <strings.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
	int fd_in,fd_out;
	char buf[1024];
	
	memset(buf,0,1024);
	fd_in= open("/tmp/infile", O_RDONLY);
	fd_out = open("/tmp/outfile", O_WRONLY|O_CREAT);
	fork();
	while (read(fd_in, buf, 2) > 0) { /* Loop through the infile */
                printf("%d: %s", getpid(), buf);
                /* Write a line */
                sprintf(buf, "%d Hello, world!\n\r", getpid());
                write(fd_out, buf, strlen(buf));
                sleep(1);
                memset(buf, 0, 1024); /* clear buffer*/
        }
        sleep(10);
}
