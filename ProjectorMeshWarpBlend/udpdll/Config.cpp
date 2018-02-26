#include "Config.h"

// Static variable
Config* Config::m_pInstance = NULL;

Config::Config( void )
{
}

Config::~Config( void )
{
}

Config* Config::GetInstance( void )
{
	if (m_pInstance == NULL)
	{
		m_pInstance = new Config();
		m_pInstance->LoadConfig( "config.xml" );
	}

	return m_pInstance;
}

void Config::LoadConfig( std::string fileName )
{
	Parameter parameter;
	string tagString;
	string parameterString;

	m_XMLParser.LoadFile( fileName );

    while ( m_XMLParser.GetNextTag( tagString ) )
    {
        if ( tagString.compare( "VIEW" ) == 0 )
        {
			while ( m_XMLParser.GetNextTag( tagString ) && tagString.compare( "/VIEW" ) )
            {
				parameter.name = MakeLowerCase( tagString );
				if ( m_XMLParser.GetTagParam( parameterString ) )
				{
					parameter.value = parameterString;
					m_parameterVector.push_back ( parameter );
				}
				m_XMLParser.GetNextTag( tagString );
            }
        }
    }
	int kalle = 0;
}

bool Config::GetBoolVariable( string name )
{
	string parameterValue;

	for( vector< Config::Parameter >::iterator parameterIterator = m_parameterVector.begin(); parameterIterator != m_parameterVector.end(); parameterIterator++ )
	{
		if ( parameterIterator->name.compare( MakeLowerCase( name ) ) == 0 )
		{
			parameterValue = parameterIterator->value;
			if ( parameterValue.compare( "true" ) == 0 )
				return true;
		}
	}

	return false;
}

float Config::GetFloatVariable( string name )
{
	for( vector< Config::Parameter >::iterator parameterIterator = m_parameterVector.begin(); parameterIterator != m_parameterVector.end(); parameterIterator++ )
	{
		if ( parameterIterator->name.compare( MakeLowerCase( name ) ) == 0 )
		{
			return static_cast< float >( atof( parameterIterator->value.c_str() ) );
		}
	}

	return 0.0f;
}

double Config::GetDoubleVariable( string name )
{
	for( vector< Config::Parameter >::iterator parameterIterator = m_parameterVector.begin(); parameterIterator != m_parameterVector.end(); parameterIterator++ )
	{
		if ( parameterIterator->name.compare( MakeLowerCase( name ) ) == 0 )
		{
			return atof( parameterIterator->value.c_str() );
		}
	}

	return 0.0f;
}

int Config::GetIntVariable( string name )
{
	for( vector< Config::Parameter >::iterator parameterIterator = m_parameterVector.begin(); parameterIterator != m_parameterVector.end(); parameterIterator++ )
	{
		if ( parameterIterator->name.compare( MakeLowerCase( name ) ) == 0 )
		{
			return atoi( parameterIterator->value.c_str() );
		}
	}

	return 0;
}

string Config::GetStringVariable( string name )
{
	bool bState = false;

	for( vector< Config::Parameter >::iterator parameterIterator = m_parameterVector.begin(); parameterIterator != m_parameterVector.end(); parameterIterator++ )
	{
		if ( parameterIterator->name.compare( MakeLowerCase( name ) ) == 0 )
		{
			return parameterIterator->value;
		}
	}

	return "";
}

string Config::MakeLowerCase( string str )
{
	const int iStringLength = static_cast<int>(str.length());

	for(int iIndex = 0; iIndex != iStringLength; ++iIndex)
		str[iIndex] = std::tolower(str[iIndex]);

	return str;
}

