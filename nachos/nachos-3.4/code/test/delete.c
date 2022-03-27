#include "syscall.h"
#include "copyright.h"
#define MAX_LENGTH 32

int main()
{
	char fileName[MAX_LENGTH];
	PrintString("Nhap ten file can xoa\n");
	ReadString(fileName, MAX_LENGTH);

PrintString("Open file aa for testing\n");
Open("aa",0);


		if (!Delete(fileName)) 
	{
		PrintString("--- Xoa file thanh cong ---\n");

	}
	else
	{
		PrintString("--- Xoa file that bai ---\n");
	}

	return 0;
}
