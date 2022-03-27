#include "syscall.h"
#include "copyright.h"
#define MAX_LENGTH 32

int main()
{

	int openFileId;
	int fileSize;
	char c; //Ky tu de in ra
	char fileName[MAX_LENGTH];
	int i; //Index for loop
	PrintString(" - Nhap vao ten file can doc: ");

	ReadString(fileName, MAX_LENGTH);
	
	openFileId = Open(fileName, 1); // Goi ham Open de mo file 
	
	if (openFileId != -1) 
	{
		//Seek den cuoi file de lay fileSize
		fileSize = Seek(-1, openFileId);
		i = 0;
		// Seek den dau tap tin de tien hanh Read
		
		Seek(0, openFileId);
		
		PrintString(" --- Noi dung file ---\n");
		for (; i < fileSize; i++) 
		{
			Read(&c, 1, openFileId); 
			PrintChar(c); 
		}
		Close(openFileId); 
	}
	else
	{
		PrintString(" Mo file khong thanh cong!!\n\n");
	}
	return 0;

}

