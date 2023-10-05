#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	long max_pid;
	int fd;
	char buffer[100];
	int flag;

	fd = open("/proc/sys/kernel/pid_max", O_RDONLY);
	flag = read(fd, buffer, sizeof(buffer));
	buffer[flag] = '\0';
	printf("max_pid: %s", buffer);



	/*max_pid = sysconf(_SC_AIO_MAX);*/



	return (0);
}
