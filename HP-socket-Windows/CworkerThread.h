#ifndef WORKER_THREAD__H__
#define WORKER_THREAD__H__

#include <vector>
#include <thread>
#include "defines.h"
#include "threadSafe_container.h"

#define DATA_BUFFER_SIZE 2048

typedef struct
{
	char buf[DATA_BUFFER_SIZE];
	unsigned int len;
	int  sfd;
}LOCAL_REV_DATA;

typedef struct {
	int sfd;
}CONN_INFO;

typedef struct {
	DWORD 			thread_id;        	/* unique ID of this thread */
	struct event_base 	*base;    			/* libevent handle this thread uses */
	struct event		*notify_event;  		/* listen event for notify pipe */
	struct event		*timeout_event;
	DWORD	msg_count;
//	struct event notify_event;
	HANDLE	notify_receive_fd;  /* receiving end of notify pipe */
	HANDLE 	notify_send_fd;     /* sending end of notify pipe */
	CThreadSafeList<CONN_INFO> 	list_conn;	/* queue of new connections to handle */
} LIBEVENT_THREAD;

typedef struct{
	int    sfd;
	char*  rBuf;
	int    rlen;
	char*  wBuf;
	int    wlen;
	bool   isVerify;
	LIBEVENT_THREAD *thread; 				/* Pointer to the thread object serving this connection */
}CONN;


class CWorkerThread
{
public:
	CWorkerThread();
	virtual ~CWorkerThread();

public:

	bool InitThreads(struct event_base* main_base);

	void DispatchSfdToWorker(int sfd);

private:

	bool SetupThread(LIBEVENT_THREAD* me);

	static void RegisterThreadInitialized(void);
	static void WaitForThreadRegistration(int nthreads);

	//static void ReadPipeCb(int fd, short event, void* arg);
	static CONN*InitNewConn(const CONN_INFO& conn_info, LIBEVENT_THREAD* libevent_thread_ptr);

	static void CreateWorker(void (*func)(void *), void *arg);
	static void WorkerLibevent(void *arg);
	static void TimeOutCb(evutil_socket_t none_use, short flags, void * parm);

	static void ClientTcpReadCb(struct bufferevent *bev, void *arg);
	static void ClientTcpErrorCb(struct bufferevent *bev, short event, void *arg);

	/* 为了重复利用连接内存资源 */
	static void InitFreeConns();
	static CONN *GetConnFromFreelist();
	static bool AddConnToFreelist(CONN *conn);
	static void FreeConn(CONN *conn);
	static void CloseConn(CONN *conn, struct bufferevent *bev);

private:

	std::vector<LIBEVENT_THREAD*> vec_libevent_thread_;
	int last_thread_;

	static int init_count_;

	static std::mutex mutex_;
	static HANDLE h_InitFinish;
	static std::vector<CONN*> vec_freeconn_;
	static int freetotal_;
	static int freecurr_;

};

#endif
