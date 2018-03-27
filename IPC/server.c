#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#define MSGKEY  75

struct msgfrom{
long mtype;
char mtext[256];

}msg;

int msgid;
void main(){

int i,pid,*pint;
extern cleanup();
for(i=0;i<20;i++)
   signal(i,cleanup);

msgid=msgget(MSGKEY,0777|IPC_CREAT);
 
for(;;){
msgrcv(msgid,&msg,256,1,0);
pint=(int*)msg.mtext;
pid=*pint;
printf("server :receive from pid %dn",pid);
msg.mtype=pid;
*pint=getpid();
msgsnd(msgid,&msg,sizeof(int),0);
kill(0,0);
}


}
cleanup(){
msgctl(msgid,IPC_RMID,0);
}

