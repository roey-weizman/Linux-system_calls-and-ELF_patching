
#define SYS_WRITE 4
#define STDOUT 1
#define SYS_SEEK 19
#define SYS_OPEN 5
#define O_RDWR 2
#define SEEK_SET      0 /* Seek from beginning of file.  */
#define SEEK_CUR      1 /* Seek from current position.  */
#define SEEK_END      2  

int main (int argc , char* argv[], char* envp[])
{
    
    int file=0;
    file=open("greeting",O_RDWR);
    lseek(file,657,0);
    write(file,"Mira. ",6)  ;
                  

 /* int i;
  char * str;
  str = itoa(argc);
  system_call(SYS_WRITE,STDOUT, str,strlen(str));
  system_call(SYS_WRITE,STDOUT," arguments \n", 12);
  for (i = 0 ; i < argc ; i++)
    {
      system_call(SYS_WRITE,STDOUT,"argv[", 5);
	  str = itoa(i);
      system_call(SYS_WRITE,STDOUT,str,strlen(str));
      system_call(SYS_WRITE,STDOUT,"] = ",4);
      system_call(SYS_WRITE,STDOUT,argv[i],strlen(argv[i]));
      system_call(SYS_WRITE,STDOUT,"\n",1);
    }*/
  return 0;
}
