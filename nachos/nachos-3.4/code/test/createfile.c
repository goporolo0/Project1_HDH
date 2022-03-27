#include "syscall.h"
#include "copyright.h"
#define MAX_LENGTH 32

int main()
{
	int stdin;
	char fileName[MAX_LENGTH];	
	
	PrintString("Nhap ten file\n");
	ReadString(fileName, MAX_LENGTH);
	
	if (CreateFile(fileName) == 0) 
	{
		PrintString("--- Tao file thanh cong---");

	}
	else
	{
		PrintString("--- Tao file that bai ---");
	}
	
	return 0;
}
