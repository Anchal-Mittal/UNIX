#include<fcntl.h>
#include<stdio.h>
int fdrd,fdwt;
char c;
int main(argc , argv)
int argc;
char *argv[];
{
if(argc!=3) 
  exit(1);

if((fdrd=open(argv[1],O_RDONLY))==-1)
  exit(1);
if((fdwt=creat(argv[2],0666))==-1)
  exit(1);
fork();
rdwt();
exit(0);
}

rdwt(){
for(; ;){
 if(read(fdrd, &c,1)!=1)
   return ;
 write(fdwt,&c,1);
 }
}
