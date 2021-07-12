#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
int main(int argc,char **argv)
{
	int fd1;
	int fd2;
	fd1 = open(argv[1],O_RDWR);
	fd2 = open(argv[2],O_RDWR|O_CREAT,0664);
	char buffer[8192] ;
	bzero(buffer,sizeof(buffer));
	//确定是第几个进程
	int Pro = atoi(argv[4]);
	//进程数量
	int  ProcNum = atoi(argv[3]);
	//源文件中总字节数
	int rSize = lseek(fd1,0,SEEK_END);
	//每个进程拷贝的字节数(防止少拷贝)
	int eVeBytesNum = rSize%ProcNum == 0?rSize/ProcNum:rSize/ProcNum+1;
	//偏移读写指针
	lseek(fd1,Pro*eVeBytesNum,SEEK_SET);
	//读内容
	read(fd1,buffer,eVeBytesNum);
	//偏移读写指针
	lseek(fd2,Pro*eVeBytesNum,SEEK_SET);
	//写内容
	write(fd2,buffer,strlen(buffer));
	close(fd1);
	close(fd2);
	return 0;
}
