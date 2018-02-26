/** @class Logger
	@version 1.0 
	@date 2008-11-24
	@author Robert Malmstrom
*/

#ifndef LOGGER_H
#define LOGGER_H

#include "stdafx.h"
#include <fstream>
#include <String>
#include <cctype>       // Includes the function std::tolower
#include "Thread.h"

/// Logger is a class that is used to create and write to a log file.
/**
    This class is used to create a log-file with the name Log.txt.
	Logger is a singleton class where you call the GetInstance
	function to receive the Logger instance. The constructor tries to
	find the file LoggingSettings.ini in the working directory to get
	information about what log level code (LOG_INFO, LOG_WARNING,
	LOG_ERROR, LOG_DEBUG) that is written to the Log-file.
	The function Write is used to write information to the log-file
	and it is thread safe. The write function adds date, time, log
	level code and changes row in the logging text.

	One example of how the LoggingSettings.ini file could look:

	LOG_INFO		true
	LOG_WARNING		false
	LOG_ERROR		true
	LOG_DEBUG		false
*/

using namespace std;

class Logger : public Thread
{
public:
	enum LogLevel
	{
		LOG_INFO,
		LOG_WARNING,
		LOG_ERROR,
		LOG_DEBUG
	};

private:
	static Logger*		m_pInstance;
	std::fstream		m_logFile;
	std::fstream		m_loggingSetupFile;
	bool				m_bLogNothing;
	bool				m_bLogInfo;
	bool				m_bLogWarning;
	bool				m_bLogError;
	bool				m_bLogDebug;
	bool				m_bLogErrorWritten;

public:
	virtual ~Logger( void );
	/// Function to get the instance of the logger class.
	/** This function first checks to see if an instance of this Logger
		class already has been created. if not it creates one instance of
		the class and returns it. If an instance already has been created
		then it returns that instance.
	*/
	static Logger* GetInstance( void );
	/// Function to write text rows to the Log.txt file.
	/** This function is used to write one row of information to the
		Log.txt file. The logLevel parameter shows which type of 
		information that one wants to write to the Log-file (LOG_INFO, LOG_WARNING,
		LOG_ERROR, LOG_DEBUG). The function checks to see if the type of data
		is supposed to be written to the file. The settings for which type of
		information that is to be written to the file is loaded in the constructor
		from the file LoggingSettings.ini. The function is thread safe and adds
		date, time, log level code and changes row at the end of the text.
	*/
	void Write( const LogLevel logLevel, const string& logString );
	void Write( const LogLevel logLevel, const string& logString, int iValue );
	void Write( const LogLevel logLevel, const string& logString, unsigned int iValue );
	void Write( const LogLevel logLevel, const string& logString, float fValue );
	void Write( const LogLevel logLevel, const string& logString, double dValue );
	/// This function returns true if an error has been logged.
	bool HasErrorBeenLogged();

protected:
	/// The constructor that opens the log.txt file.
	/** The constructor opens the log.txt file or creates a new
		file with that name if none exsits. Then it calls the function
		LoadLoggingSetup to load the settings for which type of
		information (LOG_INFO, LOG_WARNING, LOG_ERROR, LOG_DEBUG)
		that is to be written to the log.txt file from the file
		LoggingSettings.ini in the working directory. If the
		LoggingSettings.ini is not found then all logging is stopped.
	*/
	Logger( void );
private:
	/// Function that loads the logging settings from the file LoggingSettings.ini
	/** This function loads the settings for which type of
		information (LOG_INFO, LOG_WARNING, LOG_ERROR, LOG_DEBUG)
		that is to be written to the log.txt file from the file
		LoggingSettings.ini in the working directory. The reading
		of the word true/false is not key sensitive.
	*/
	void LoadLoggingSetup( void );
	/// Function that takes a string and makes it lower case.
	/** This function takes a string and returns the lower
		case version of the string.
	*/
	std::string MakeLowerCase( string str );
};

#endif