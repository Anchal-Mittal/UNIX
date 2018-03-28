#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#define MSGKEY  75

struct msgfrom{
long mtype;
char mtext[256];

};

void main(){
struct msgfrom msg;
int msgid,pid,*pint;
msgid=msgget(MSGKEY,0777);
pid=getpid();
pint=(int*)msg.mtext;
*pint=pid*5677677;
msg.mtype=1;
msgsnd(msgid,&msg,sizeof(int),0);
printf("%d",sizeof(int));
msgrcv(msgid,&msg,256,pid,0);
printf("client,receive from pid %d",*pint);


}
