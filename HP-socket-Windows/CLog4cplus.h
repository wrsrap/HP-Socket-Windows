#ifndef CLOG4CPLUS_H__
#define CLOG4CPLUS_H__

#include <cstdlib>
#include <log4cplus/logger.h>
#include <log4cplus/configurator.h>
#include <log4cplus/helpers/loglog.h>
#include <log4cplus/helpers/stringhelper.h>
#include <log4cplus/loggingmacros.h>

using namespace std;
using namespace log4cplus;
using namespace log4cplus::helpers;

namespace Log4cplus{

class CLog4cplus
{
private:
	CLog4cplus(void);
	static CLog4cplus* m_pInstance;

public:
	virtual ~CLog4cplus(void);
	static CLog4cplus* GetLoggerInstance();

public:
	void Debug(const char* msg);
    void Info(const char* msg);
    void Trace(const char* msg);
    void Warn(const char* msg);
    void Error(const char* msg);
    void Fatal(const char* msg);
    
    bool LoadConfigure(const char* filename = nullptr);	

private:  
	 Logger m_logger;
};
}

#endif