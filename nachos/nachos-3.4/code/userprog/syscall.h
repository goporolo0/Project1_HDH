/* syscalls.h 
 * 	Nachos system call interface.  These are Nachos kernel operations
 * 	that can be invoked from user programs, by trapping to the kernel
 *	via the "syscall" instruction.
 *
 *	This file is included by user programs and by the Nachos kernel. 
 *
 * Copyright (c) 1992-1993 The Regents of the University of California.
 * All rights reserved.  See copyright.h for copyright notice and limitation 
 * of liability and disclaimer of warranty provisions.
 */

#ifndef SYSCALLS_H
#define SYSCALLS_H

#include "copyright.h"

/* system call codes -- used by the stubs to tell the kernel which system call
 * is being asked for
 */
#define SC_Halt		0
#define SC_Exit		1
#define SC_Exec		2
#define SC_Join		3
//
#define SC_CreateFile	4
#define SC_Open		5
#define SC_Read		6
#define SC_Write	7
#define SC_Close	8

#define SC_Fork		9
#define SC_Yield	10

//Syscall co ban
#define SC_ReadInt	11
#define SC_PrintInt	12
#define SC_ReadChar	13
#define SC_PrintChar	14
#define SC_ReadString	15
#define SC_PrintString	16

#define SC_Seek		17
#define SC_Delete	18


#ifndef IN_ASM


void Halt();

int ReadInt();

void PrintInt(int number);

char ReadChar();

void PrintChar(char character);

void ReadString(char buffer[], int length);

void PrintString(char buffer[]);

void Exit(int status);	

typedef int SpaceId;	
 
SpaceId Exec(char *name);

int Join(SpaceId id); 	
 

typedef int OpenFileId;	


#define ConsoleInput	0  
#define ConsoleOutput	1  

int CreateFile(char* name);


OpenFileId Open(char *name, int type);

void Close(OpenFileId id);

/* Read "size" bytes from the open file into "buffer".  
 * Return the number of bytes actually read -- if the open file isn't
 * long enough, or if it is an I/O device, and there aren't enough 
 * characters to read, return whatever is available (for I/O devices, 
 * you should always wait until you can return at least one character).
 */
int Read(char *buffer, int charcount, OpenFileId id);

// Write "size" bytes from "buffer" to the open file.
int Write(char *buffer, int charcount, OpenFileId id);

int Seek(int pos, OpenFileId id);


int Delete(char*name);


/* User-level thread operations: Fork and Yield.  To allow multiple
 * threads to run within a user program. 
 */
void Fork(void (*func)());

void Yield();		

#endif /* IN_ASM */

#endif /* SYSCALL_H */




