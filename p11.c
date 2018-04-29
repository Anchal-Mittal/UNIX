int global; 
main(){
int local;
local =1;
if (vfork==0){
  global =2; /* write parent data space */ 
  local a=3; /* write parent stack */ 
  exit();
 }
  printf("global %d local %d\n", global, local);
}
