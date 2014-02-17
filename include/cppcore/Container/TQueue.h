/*
-------------------------------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2014 Kim Kulling

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
-------------------------------------------------------------------------------------------------
*/
#pragma once
#ifndef CPPCORE_TQUEUE_H_INC
#define CPPCORE_TQUEUE_H_INC

#include <cppcore/Container/TList.h>

namespace CPPCore {

//-------------------------------------------------------------------------------------------------
///	@class		TQueue
///	@ingroup	CPPCore
///
///	@brief	This template class implements a simple queue ( works FIFO ).
//-------------------------------------------------------------------------------------------------
template<class T>
class TQueue {
public:
	///	@brief	The default class constructor.
	TQueue();

	///	@brief	The class copy constructor.
	///	@param	rhs 	[in] The instance to copy from.
	TQueue( const TQueue<T> &rhs );

	///	@brief	The destructor.
	~TQueue();

	///	@brief	A new item will be enqueued.
	///	@param	item	[in] The item to enqueue.
	void enqueue( const T &item );

	///	@brief	Tries to dequeue the next item from the queue. If no more items are there, false 
	///			will be returned. If the queue is empty, this will fail.
	///	@param	item	[ out ] The next item, if true was returned.
	///	@return	true, if an item was dequeued correctly, false if the queue was already empty.
	bool dequeue( T &item );

	///	@brief	Returns the first item of the queue.
	///	@return	The first item.
	T front();

	///	@brief	Returns true, if the queue is empty.
	///	@return	true, if the queue is empty, false if not.
	bool isEmpty() const;
	
	///	@brief	The number of enqueued items will be returned.
	///	@return	The number of enqueued items.
	ui32 size();
	
	///	@brief	The queue will be cleared.
	void clear();

	///	@brief	The assignment operator.
	TQueue<T> &operator = ( const TQueue<T> &rhs );

	///	@brief	The compare operator.
	bool operator == ( const TQueue<T> &rhs ) const;

private:
	TList<T> m_QueueData;
};

//-------------------------------------------------------------------------------------------------
template<class T>
inline
TQueue<T>::TQueue() 
: m_QueueData() {
	// empty
}

//-------------------------------------------------------------------------------------------------
template<class T>
inline
TQueue<T>::TQueue( const TQueue<T> &rhs ) 
: m_QueueData( rhs.m_QueueData ) {
	// empty
}

//-------------------------------------------------------------------------------------------------
template<class T>
inline
TQueue<T>::~TQueue() {
	clear();
}

//-------------------------------------------------------------------------------------------------
template<class T>
inline
void TQueue<T>::enqueue( const T &item ) {
	m_QueueData.addBack( item );
}

//-------------------------------------------------------------------------------------------------
template<class T>
inline
bool TQueue<T>::dequeue( T &item ) {
	item = m_QueueData.front();
	m_QueueData.removeFront();
	if ( isEmpty() ) {
		return false;
    } else {
        return true;
    }
}

//-------------------------------------------------------------------------------------------------
template<class T>
inline
T TQueue<T>::front() {
	return m_QueueData.front();
}

//-------------------------------------------------------------------------------------------------
template<class T>
inline
bool TQueue<T>::isEmpty() const {
	return m_QueueData.isEmpty();
}

//-------------------------------------------------------------------------------------------------
template<class T>
inline
ui32 TQueue<T>::size() {
	return m_QueueData.size();
}

//-------------------------------------------------------------------------------------------------
template<class T>
inline
void TQueue<T>::clear() {
	m_QueueData.clear();
}

//-------------------------------------------------------------------------------------------------
template<class T>
inline
TQueue<T> &TQueue<T>::operator = ( const TQueue<T> &rhs ) {
	if ( *this == rhs ) {
		return *this;
    }

	m_QueueData = rhs.m_QueueData;

	return *this;
}

//-------------------------------------------------------------------------------------------------
template<class T>
inline
bool TQueue<T>::operator == ( const TQueue<T> &rhs ) const {
	return m_QueueData == rhs.m_QueueData;
}

//-------------------------------------------------------------------------------------------------

} // Namespace CPPCore

#endif // CPPCORE_TQUEUE_H_INC