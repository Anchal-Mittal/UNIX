#include<stdio.h>
#include<signal.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>

#define SHMKEY 75
#define K 1024
int shmid;
main(){
	int i,*pint;
	char *addr;
	extern char *shmat();
	shmid=shmget(SHMKEY,64*K,0777);
	addr=shmat(shmid,0,0);
	pint=(int*)addr;
	while(*pint==0);
	for (i=0;i<256;i++)
	printf("%d\n",*pint++);

}
