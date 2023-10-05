#include <unistd.h>
#include <stdio.h>

int main(void)
{
	int ppid;

	ppid = getppid();
	printf("PPID : %d\n", ppid);
	return (0);
}
