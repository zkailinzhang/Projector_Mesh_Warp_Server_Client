#include "Thread.h"

// Static variables.
bool Thread::m_bThreadWorking = false;

Thread::Thread(void)
{
	InitializeCriticalSection( &m_pCriticalSection );
}

Thread::~Thread(void)
{
	DeleteCriticalSection( &m_pCriticalSection );
}

bool Thread::StartThread()
{
	m_bThreadWorking = true;
	m_handleThread = CreateThread(	NULL,
									0,
									ThreadWorkLoop,
									(void *)this,
									0,
									&( static_cast<DWORD>( m_dThreadId ) ) );

	if ( m_handleThread == NULL )
		return false;
	else
		return true;
}

bool Thread::StopThread()
{
	DWORD dExitCode = STILL_ACTIVE;

	m_bThreadWorking = false;
	while ( dExitCode == STILL_ACTIVE )
	{
		Sleep(1);
		if ( !GetExitCodeThread( m_handleThread, &dExitCode ) )
			dExitCode = STILL_ACTIVE;
	}
	CloseHandle( m_handleThread );

	return true;
}

void Thread::ThreadWork()
{
}

void Thread::Lock()
{
    EnterCriticalSection( &m_pCriticalSection );
}

void Thread::Unlock()
{
    LeaveCriticalSection( &m_pCriticalSection );
}

DWORD _stdcall Thread::ThreadWorkLoop( void* pParam )
{
	Thread* pThread = ( Thread* )pParam;
	while ( m_bThreadWorking )
		pThread->ThreadWork();

	return 0;
}