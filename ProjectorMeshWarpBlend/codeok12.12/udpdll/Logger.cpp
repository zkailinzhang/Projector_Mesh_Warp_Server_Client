#include "Logger.h"
#include <sstream>

Logger* Logger::m_pInstance = NULL;

Logger::Logger( void )
: m_bLogNothing( false ), m_bLogInfo( false ), m_bLogWarning( false ), m_bLogError( false )
, m_bLogDebug( false ), m_bLogErrorWritten( false )
{
	m_logFile.open( "WarpLog.txt", std::ios::out | std::ios::trunc );
	LoadLoggingSetup();
}

Logger::~Logger( void )
{
	m_logFile.close();
}

void Logger::LoadLoggingSetup( void )
{
	std::string fileTextString;
	std::string loggingSetupStatusString;

	m_loggingSetupFile.open( "LoggingSetup.ini", std::ios::in );

	// If the file LoggingSetup.ini can't be found in the working directory then there
	// will be no logging.
	if ( m_loggingSetupFile.fail() )
	{
		Write( static_cast< const Logger::LogLevel >( -1 ), "Logger::LoadLoggingSetup, Couldn´t find the LoggingSetup.ini file in the working directory = No logging." );
		m_bLogNothing = true;
		return;
	}
	while ( !m_loggingSetupFile.eof() )
	{
		m_loggingSetupFile >> fileTextString;
		if ( fileTextString.compare( "LOG_INFO" ) == 0 )
		{
			m_loggingSetupFile >> fileTextString;
			fileTextString = MakeLowerCase( fileTextString );
			if (fileTextString.compare( "true" ) == 0)
				m_bLogInfo = true;
		}
		if ( fileTextString.compare( "LOG_WARNING" ) == 0 )
		{
			m_loggingSetupFile >> fileTextString;
			fileTextString = MakeLowerCase( fileTextString );
			if ( fileTextString.compare( "true" ) == 0 )
				m_bLogWarning = true;
		}
		if ( fileTextString.compare( "LOG_ERROR" ) == 0 )
		{
			m_loggingSetupFile >> fileTextString;
			fileTextString = MakeLowerCase(fileTextString);
			if (fileTextString.compare("true") == 0)
				m_bLogError = true;
		}
		if ( fileTextString.compare( "LOG_DEBUG" ) == 0 )
		{
			m_loggingSetupFile >> fileTextString;
			fileTextString = MakeLowerCase( fileTextString );
			if ( fileTextString.compare( "true" ) == 0 )
				m_bLogDebug = true;
		}
	}
	loggingSetupStatusString += "Log file opened with logging state: ";
	if ( m_bLogInfo )
		loggingSetupStatusString += "LOG_INFO = true, ";
	else
		loggingSetupStatusString += "LOG_INFO = false, ";
	if ( m_bLogWarning )
		loggingSetupStatusString += "LOG_WARNING = true, ";
	else
		loggingSetupStatusString += "LOG_WARNING = false, ";
	if ( m_bLogError )
		loggingSetupStatusString += "LOG_ERROR = true, ";
	else
		loggingSetupStatusString += "LOG_ERROR = false, ";
	if ( m_bLogDebug )
		loggingSetupStatusString += "LOG_DEBUG = true";
	else
		loggingSetupStatusString += "LOG_DEBUG = false";
	Write( Logger::LOG_INFO, loggingSetupStatusString );

	// If no of the logging levels are true then do no
	// logging at all.
	if ( !m_bLogInfo && !m_bLogWarning && !m_bLogError && !m_bLogDebug )
		m_bLogNothing = true;

	m_loggingSetupFile.close();
}

Logger* Logger::GetInstance( void )
{
	if ( m_pInstance == NULL )
		m_pInstance = new Logger();

	return m_pInstance;
}

void Logger::Write( const LogLevel logLevel, const string& logString )
{
	std::string logLevelString;
	std::string logRowString;
	bool		bLogging;
	char		timeAndDateCharArray[ 100 ];
	SYSTEMTIME	systemTime;

	if ( !m_bLogNothing )
	{
		Lock();
			bLogging = false;
			switch ( logLevel )
			{
			case LOG_INFO:
				if ( m_bLogInfo )
				{
					logLevelString = "LOG_INFO, ";
					bLogging = true;
				}
				break;
			case LOG_WARNING:
				if ( m_bLogWarning )
				{
					logLevelString = "LOG_WARNING, ";
					bLogging = true;
				}
				break;
			case LOG_ERROR:
				if ( m_bLogError )
				{
					logLevelString = "LOG_ERROR, ";
					bLogging = true;
					m_bLogErrorWritten = true;
				}
				break;
			case LOG_DEBUG:
				if ( m_bLogDebug )
				{
					logLevelString = "LOG_DEBUG, ";
					bLogging = true;
				}
				break;
			case -1:
				bLogging = true;
				break;
			}
			if (bLogging)
			{
				GetSystemTime( &systemTime );
				sprintf_s( timeAndDateCharArray, 100, "%d:%02d:%02d-%02d:%02d:%02d:%03d ", systemTime.wYear, systemTime.wMonth, systemTime.wDay, systemTime.wHour + 1, systemTime.wMinute, systemTime.wSecond, systemTime.wMilliseconds );
				logRowString = timeAndDateCharArray + logLevelString + logString + "\r\n";
				m_logFile.write( logRowString.c_str(), (std::streamsize)logRowString.length() );
				m_logFile.flush();
			}
		Unlock();
	}
}

void Logger::Write( const LogLevel logLevel, const string& logString, int iValue )
{
	stringstream ss;

	ss << logString << iValue;
	Write( logLevel, ss.str() );
}

void Logger::Write( const LogLevel logLevel, const string& logString, unsigned int iValue )
{
	stringstream ss;

	ss << logString << iValue;
	Write( logLevel, ss.str() );
}

void Logger::Write( const LogLevel logLevel, const string& logString, float fValue )
{
	stringstream ss;

	ss << logString << fValue;
	Write( logLevel, ss.str() );
}

void Logger::Write( const LogLevel logLevel, const string& logString, double dValue )
{
	stringstream ss;

	ss << logString << dValue;
	Write( logLevel, ss.str() );
}

std::string Logger::MakeLowerCase( string str )
{
	const int iStringLength = static_cast< int >( str.length() );

	for( int iIndex = 0; iIndex != iStringLength; ++iIndex )
		str[iIndex] = std::tolower( str[ iIndex ] );

	return str;
}

bool Logger::HasErrorBeenLogged()
{
	return m_bLogErrorWritten;
}
