#include "syscall.h"
#include "copyright.h"
#define MAX_LENGTH 32

int main()
{
	//OpenFileId cua file nguon va file dich
	int srcFileId;
	int destFileId;

	int fileSize;
	int i; 
	char c; 
	char source[MAX_LENGTH];
	char dest[MAX_LENGTH];
	
	PrintString(" - Nhap ten file nguon: ");
	ReadString(source, MAX_LENGTH); // Goi ham ReadString de doc vao ten file nguon	
	PrintString(" - Nhap ten file dich: ");
	ReadString(dest, MAX_LENGTH); 
	srcFileId = Open(source, 1); 
	
	if (srcFileId != -1) 
	{
		destFileId = CreateFile(dest);
		Close(destFileId);		
		destFileId = Open(dest, 0); // Goi ham Open de mo file dich
		if (destFileId != -1) //Kiem tra mo file thanh cong
		{			
			fileSize = Seek(-1, srcFileId);
			Seek(0, srcFileId); // Seek den dau file nguon
			Seek(0, destFileId); // Seek den dau file dich
			i = 0;
			
			for (; i < fileSize; i++) 
			{
				Read(&c, 1, srcFileId); 
				Write(&c, 1, destFileId); 
			}
			
			PrintString(" -> Copy thanh cong.\n\n");
			Close(destFileId); 
		}
		else
		{
			PrintString(" - Tao file dich khong thanh cong!!\n");
		}
		
		Close(srcFileId); 
	}
	else
	{
		PrintString("Loi khi mo file");
	}
	
	return 0;
}


