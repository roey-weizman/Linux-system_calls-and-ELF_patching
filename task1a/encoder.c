#define SYS_READ     3
#define SYS_WRITE    4
#define STDIN 0
#define STDOUT 1
#define STDERR 2
#include <stdio.h>
#include <stdlib.h>
#include "lab4_util.h"
#include <string.h>
int main(int argc,char **argv){
   
    char buffer[1];int pos=0; int k=0; int p=0;
    int debugMode=0;
    
    for(;pos<argc;pos++){
        if(strcmp(argv[pos],"-d")==0){
            debugMode=1;
        }
    }
    
   
        while(k=(system_call(SYS_READ,STDIN, buffer,1))>0){
            if(debugMode==1){
                printDebug(itoa(SYS_READ),itoa(k));}
            char c=buffer[0];
            if(c>=65 && c<=90){
            c=c+32;}
            buffer[0]=c;
            k=system_call(SYS_WRITE,STDOUT, buffer,1);
            if(debugMode==1)
                printDebug(itoa(SYS_WRITE),itoa(p));
        
        
    
            }}            


 void printDebug(char* id ,char* retCode){
        char newLine[]={"\n"};
        system_call(SYS_WRITE,STDERR,"Debug Details:",14);
        system_call(SYS_WRITE,STDERR,newLine,1);
        system_call(SYS_WRITE,STDERR,id,strlen(id));
        system_call(SYS_WRITE,STDERR,newLine,1);
        system_call(SYS_WRITE,STDERR,retCode,strlen(retCode));
        system_call(SYS_WRITE,STDERR,newLine,1);
        system_call(SYS_WRITE,STDERR,newLine,1);
}
