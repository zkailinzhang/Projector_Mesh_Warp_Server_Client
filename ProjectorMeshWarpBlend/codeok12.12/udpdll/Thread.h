/** @class Thread
	@version 1.0 
	@date 2008-11-24
	@author Robert Malmstrom
*/

#ifndef THREAD_H
#define THREAD_H

#include "stdafx.h"

/// This class is used to create threads and/or thread locking
/** This class is inherited to create threads and/or to create
	thread lockings to make data and functions thread safe.
	If a class inherits from this class it should have a function
	like this class virtual function ThreadWork. The ThreadWork
	function is called in a eternal loop. To start the thread you
	call the function StartThread. To stop the thread you call the
	function StopThread. If you wont to thread safe a function you
	call the function Lock in the beginning of the function and
	then Unlock at the end of the function.
*/

class Thread
{
public:
	Thread(void);
	virtual ~Thread(void);

protected:
	/** This function starts a thread which calls the function ThreadWork
		until you call the function StopThread.
	*/
	bool			StartThread();
	/** This function terminates the thread which means that the function
		ThreadWork is no longer called.
	*/
	bool			StopThread();
	/** This virtual function should be implemented by the class that
		inherits from this class. It is this function that performes
		the thread work and is called in a eternal loop.
	*/
	virtual void	ThreadWork();
	/** This function is called at the beginning of a thread safe function
		and must be followed by a call to Unlock at the end of the function.
	*/
	void			Lock();
	/** This function is called after a call to the function Lock to end
		the thread safe scoope.
	*/
	void			Unlock();

private:
	/** This function is the real thread function that calls the function
		ThreadWork in a eternal loop until you call the function
		StopThread.
	*/
	static DWORD _stdcall ThreadWorkLoop( void* pParam );

    HANDLE				m_handleThread;
	DWORD				m_dThreadId;
	static bool			m_bThreadWorking;
	CRITICAL_SECTION	m_pCriticalSection;
};

#endif