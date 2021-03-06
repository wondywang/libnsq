/*************************************************************************
	> File Name: main.cpp
	> Author: EastQ 
	> Mail: log2013@163.com 
	> Created Time: 2015年10月19日 星期一 22时11分49秒
 ************************************************************************/

#include<iostream>
#include <string.h>
#include "net_thread.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "http_server.h"
#include <stdlib.h>
using namespace std;
using namespace NSQTOOL;

void ConsumerCallBack(int iProtocolId, const string &strMsgId, const string &strMsgBody)
{
    printf("iProtocolId = %d, msg body = %s\n", iProtocolId, strMsgBody.c_str());
}

void NsqLogCallBack(int iLogLevel, const char *pLogMsg)
{
    printf("%s\n", pLogMsg);
}

int main()
{
    //线程个数，每个nsqd连接个数，日志级别，日志回调函数
    CHttpServer::InitSuperServer(1, LOG_DEBUG, NsqLogCallBack);

    CHttpServer::StartSuperServer();

	while (1)
	{
        sleep(20); 
        break;
	}

  CHttpServer::StopSuperServer();
}

