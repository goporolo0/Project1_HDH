#include "syscall.h"
#include "copyright.h"
#define MAX_LENGTH 32

int main()
{		
	char str[MAX_LENGTH];
	PrintString("Nhap chuoi: ");
while(1){
ReadString(str, MAX_LENGTH);
PrintString("echo: ");
PrintString(str);
PrintString("\n");
}
	

	
	

	return 0;
}
