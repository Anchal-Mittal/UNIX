#include <signal.h> 
int main(){
register int i;
setpgrp();
for (i 0; i < 10; i++){
  if (fork()== 0)
     { if (i & 1) 
        setpgrp(); 
      printf("pid %d pgrp n•• %d\n", getpid(), getpgrp()); pause(); /* sys call to suspend execution */
     }
 }
kill(0,SIG1NT)
}
