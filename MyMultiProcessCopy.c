#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
//修改
int main(int argc ,char **argv)
{
	//参数检测
	if(argc < 3||argc > 4)
	{
		printf("参数异常！！！\n");
		exit(0);
	}
	//源文件字节数
	int fd1 = open(argv[1],O_RDWR);
	int lSize = lseek(fd1,0,SEEK_END);
	//确定进程数量
	int ProcNum;
	//无进程数量
	//有进程数量
	//yywxzuishuai
	
	else if(argc == 4)
	{
		ProcNum = atoi(argv[3]);
		//判断是否规范
		if(ProcNum<0||ProcNum>100)
		{
			printf("进程数不符合规范..\n");
			exit(0);
		}
	}
	//如果进程数量大于源文件字节数
	if(ProcNum > SrcByteNum)
	{
		while(ProcNum > SrcByteNum)
		ProcNum = ProcNum/2;
	}
	//todo
	char str1[6];
	char str2[6];
	bzero(str1,sizeof(str1));
	bzero(str2,sizeof(str2));
	sprintf(str1,"%d",ProcNum);
	pid_t pid;
	int i;
	//创建进程
	for(i = 0;i < ProcNum;i++)
	{
		pid = fork();
		//为字符数组赋值
		sprintf(str2,"%d",i);
		if(pid == 0)
			break;
	}
	//父进程
	if(pid > 0)
	{
		printf("线程数量为%d\n",ProcNum);
		printf("拷贝中，请稍等!\n");
		sleep(10);
	}
	//子进程
	else if(pid == 0)
	{	
		sleep(1);
		if((execl("/home/colin/colin5阶段/ZuoYe/Mycopy","Mycopy",argv[1],argv[2],str1,str2,NULL))==-1)
		{
			perror("error..\n");
			exit(0);
		}
	}
	//错误
	else
	{
		perror("error\n");
		exit(0);
	}
	//非阻塞回收
	while(waitpid(-1, NULL,WNOHANG)!=-1)
	{
		printf("Recycle my Children ing...\n");
	 	sleep(1);
	}
	close(fd1);
	return 0;
}
