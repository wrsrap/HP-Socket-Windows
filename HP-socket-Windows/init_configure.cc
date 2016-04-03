/*
 * Init_log4cxx.cc
 *
 *  Created on: 2012-9-12
 *      Author: yaowei
 */

#include "init_configure.h"
#include "config_file.h"
#include "utils.h"

#define LOG_CON_FILE        "\\conf\\log.properties"
#define CONF_FILE        	"\\conf\\config.ini"


CLog4cplus *g_pLogger;


CInitConfig::CInitConfig()
{
}

CInitConfig::~CInitConfig()
{
}

void CInitConfig::InitLog4cplus(std::string log_config_file)
{
	g_pLogger = CLog4cplus::GetLoggerInstance();
	/*PropertyConfigurator::configure(config_file_path_ + LOG_CON_FILE);
	g_logger = Logger::getLogger(project_name);
	LOG4CXX_INFO(g_logger, "Run...");*/
}

bool CInitConfig::LoadConfiguration()
{	
	string name = config_file_path_ + LOG_CON_FILE;
	if (!g_pLogger->LoadConfigure(name.c_str()))
	{
		cout << "日志初始化失败" << endl;
		return false;
	}
		

	std::locale old_locale = std::locale::global(std::locale(""));
	std::string file_path = config_file_path_ + CONF_FILE;
	std::ifstream conf_file(file_path.c_str());
	std::locale::global(old_locale);
	if (!conf_file)
	{
		g_pLogger->Error("Load config error!");
		return false;
	}
	conf_file >> utils::G<ConfigFile>();
	return true;
}


