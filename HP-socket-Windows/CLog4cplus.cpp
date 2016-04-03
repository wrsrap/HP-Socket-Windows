
#include "CLog4cplus.h"

#ifdef _DEBUG
	#pragma comment(lib,"log4cplusD.lib")
#else
	#pragma comment(lib,"log4cplus.lib")
#endif


using namespace Log4cplus;

CLog4cplus* CLog4cplus::m_pInstance=new CLog4cplus();

CLog4cplus::CLog4cplus(void)
{

}


CLog4cplus::~CLog4cplus(void)
{		
	//m_logger.shutdown();
}

CLog4cplus* CLog4cplus::GetLoggerInstance()
{
	//if(m_pInstance!=NULL)
	if(m_pInstance==NULL)
	{
		m_pInstance=new CLog4cplus();
		return m_pInstance;
	}

	return m_pInstance;
}

void CLog4cplus::Debug(const char* msg)    
{
	LOG4CPLUS_DEBUG(m_logger, msg);
}

void CLog4cplus::Info(const char* msg)    
{
	LOG4CPLUS_INFO(m_logger, msg);
}

void CLog4cplus::Trace(const char* msg)
{
	LOG4CPLUS_TRACE(m_logger, msg);
}

void CLog4cplus::Warn(const char* msg)    
{
	LOG4CPLUS_WARN(m_logger, msg);
}

void CLog4cplus::Error(const char* msg)    
{
	LOG4CPLUS_ERROR(m_logger, msg);
}

void CLog4cplus::Fatal(const char* msg)
{
	LOG4CPLUS_FATAL(m_logger, msg);
}

bool CLog4cplus::LoadConfigure(const char* filename)
{
	try
	{
		PropertyConfigurator::doConfigure(LOG4CPLUS_TEXT(filename));
		m_logger = Logger::getRoot();		
	}
	catch(...)
	{
		return false;
	}

	return true;

}
