#define SYS_OPEN 5
#include <string.h>
#define SYS_READ     3
#define SYS_WRITE    4
#define STDIN 0
#define STDOUT 1
#define STDERR 2
#define O_RDONLY 0
#define O_WRONLY 1
#define SYS_CLOSE 6
int main(int argc,char **argv){
    int open_file=0; int write_to_file=0; char* inFileName;
    char* outFileName; char buffer[1];int j=1;int p=0;int k=0;int s=0;
      int debugMode=0;

    for(;j<argc;j++){
        if(strcmp(argv[j],"-i")==0){
            open_file=1;
            inFileName=argv[j+1];
        }
        if(strcmp(argv[j],"-o")==0){
            write_to_file=1;
            outFileName=argv[j+1];
        }
        if(strcmp(argv[j],"-d")==0){
            debugMode=1;
        }
    }
    
    if(open_file==0&&write_to_file==0){
        while(k=system_call(SYS_READ,STDIN, buffer,1)>0){
            char c=buffer[0];
            if(c>=65 && c<=90){
            c=c+32;
            }
            buffer[0]=c;
            k=system_call(SYS_WRITE,STDOUT, buffer,1);
          
        }
    }
    
    if(open_file==1&&write_to_file==0){
        k= system_call(SYS_OPEN,inFileName, O_RDONLY,00700);
        
        while((p=system_call(SYS_READ,k, buffer,1))>0){
           
            char c=buffer[0];
            if(c>=65 && c<=90){
            c=c+32;
            }
            buffer[0]=c;
            system_call(SYS_WRITE,STDOUT, buffer,1);
          
    }
    }
    if(open_file==0&&write_to_file==1){
        
        p=system_call(SYS_OPEN,outFileName, O_WRONLY,00700);
       
         while(system_call(SYS_READ,STDIN, buffer,1)>0){
            
            char c=buffer[0];
            if(c>=65 && c<=90){
            c=c+32;
            }
            buffer[0]=c;
            system_call(SYS_WRITE,p,buffer,1);
           
        }
    }
    if(open_file==1&&write_to_file==1){
        k= system_call(SYS_OPEN,inFileName, O_RDONLY,00700);
        
        p=system_call(SYS_OPEN,outFileName, O_WRONLY,00700);
        
         while(system_call(SYS_READ,k, buffer,1)>0){
            
            char c=buffer[0];
            if(c>=65 && c<=90){
            c=c+32;
            }
            buffer[0]=c;
            system_call(SYS_WRITE,p, buffer,1);
        }
    }
    }    
    

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

