%define newline 10

section .data
HELLO_format:
	db "Hello, Infected File", newline, 0
section .text
global _start
global system_call
global code_start
global code_end
global infection
global infector
extern main
_start:
    pop    dword ecx    ; ecx = argc
    mov    esi,esp      ; esi = argv
    ;; lea eax, [esi+4*ecx+4] ; eax = envp = (4*ecx)+esi+4
    mov     eax,ecx     ; put the number of arguments into eax
    shl     eax,2       ; compute the size of argv in bytes
    add     eax,esi     ; add the size to the address of argv 
    add     eax,4       ; skip NULL at the end of argv
    push    dword eax   ; char *envp[]
    push    dword esi   ; char* argv[]
    push    dword ecx   ; int argc

    call    main        ; int main( int argc, char *argv[], char *envp[] )

    mov     ebx,eax
    mov     eax,1
    int     0x80
    nop
        

system_call:
    push    ebp             ; Save caller state
    mov     ebp, esp
    sub     esp, 4          ; Leave space for local var on stack
    pushad                  ; Save some more caller state

    mov     eax, [ebp+8]    ; Copy function args to registers: leftmost...        
    mov     ebx, [ebp+12]   ; Next argument...
    mov     ecx, [ebp+16]   ; Next argument...
    mov     edx, [ebp+20]   ; Next argument...
    int     0x80            ; Transfer control to operating system
    mov     [ebp-4], eax    ; Save returned value...
    popad                   ; Restore caller state (registers)
    mov     eax, [ebp-4]    ; place returned value where caller can see it
    add     esp, 4          ; Restore caller state
    pop     ebp             ; Restore caller state
    ret                     ; Back to caller
    
code_start:
    
infection:
    push    ebp             ; Save caller state
    mov     ebp, esp
    pushad 
    push 21
    push HELLO_format
    push 1
    push 4
    call system_call
    add esp,16
    popad			; Restore registers
    mov	esp, ebp	           ; Function exit code
    pop	ebp
    
    ret


infector:
    push    ebp             ; Save caller state
    mov     ebp, esp
    pushad 
    
    mov edx,dword [ebp+8]  ;pointer to file
    mov eax,code_start    ;label address
    mov ebx,code_end      ;label address
    mov ecx,eax  
    ;open file for write to
    sub ecx,ebx ;num of bytes to write
    push 00700 ; mode 
    push 1025 ; append code
    push edx ; file
    push 5 ; open
    call system_call 
    add esp,16
    
    
    push ecx ;num of bytes to write
    push edx ;file
    push eax ; file descriptor from open
    push 4 ;write 
    call system_call
    add esp,16

    popad			; Restore registers
    mov	esp, ebp	        ; Function exit code
    pop	ebp
    
    ret       

code_end: