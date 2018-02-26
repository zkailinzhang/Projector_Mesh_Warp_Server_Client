#pragma once

#include "XMLParser.h"
#include <string>
#include <vector>
#include <cctype>       // Includes the function std::tolower

using namespace std;

class Config
{

private:
	struct Parameter
	{
		string name;
		string value;
	};

public:
	~Config( void );

	static Config* GetInstance(void);
	bool GetBoolVariable( string name );
	float GetFloatVariable( string name );
	double GetDoubleVariable( string name );
	int GetIntVariable( string name );
	string GetStringVariable( string name );

protected:
	Config( void );

private:
	void LoadConfig( string fileName );
	string MakeLowerCase( string str );

	static Config*		m_pInstance;
	XMLParser			m_XMLParser;
	vector<Parameter>	m_parameterVector;

};
