#pragma once

/*-----------------------------------------------------------------------------------------------
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
-----------------------------------------------------------------------------------------------*/
#ifndef CPPCORE_HASH_H_INC
#define CPPCORE_HASH_H_INC

#include <cppcore/CPPCoreCommon.h>

namespace CPPCore {

//-------------------------------------------------------------------------------------------------
///	@class		Hash
///	@ingroup	CPPCore
///
///	@brief  This class is used to calculate the hash value for a given integer or character buffer.
//-------------------------------------------------------------------------------------------------
class Hash {
public:
    /// @brief  The default class constructor.
    Hash();

    /// @brief  The class constructor with a given hash value.
    /// @param  hash    [in] An integer value to compute the hash from.
    explicit Hash( unsigned int hash );

    /// @brief  The class constructor with a given value.
    /// @param  value   [in] A character buffer to compute the hash from.
    /// @param  base    [in] the table base.
    explicit Hash( const char *buffer, unsigned int base );
    
    ///
    explicit Hash( unsigned int value, unsigned int base );

    /// @brief  The class destructor.
    ~Hash();

    /// @brief  Computes the hash value for a given character buffer.
    /// @param  buffer  [in] The buffer.
    /// @param  base    [in] The table base.
    /// @return The hash value.
    static unsigned int toHash( const char *buffer, unsigned int base );
    static unsigned int toHash( unsigned int value, unsigned int base );

    /// brief    Returns the stored hash value.
    /// @return The hash value.
    unsigned int hashValue() const;

private:
    unsigned int m_hash;
};

//-------------------------------------------------------------------------------------------------
inline
Hash::Hash() 
: m_hash( 0 ){
    // empty
}

//-------------------------------------------------------------------------------------------------
inline
Hash::Hash( unsigned int hash )
: m_hash( hash ) {
    // empty
}

//-------------------------------------------------------------------------------------------------
inline
Hash::Hash( const char *buffer, unsigned int base )
: m_hash( toHash( buffer, base ) ) {
    // empty
}

//-------------------------------------------------------------------------------------------------
inline
Hash::Hash( unsigned int value, unsigned int base )
: m_hash( toHash( value, base ) ) {
    // empty
}

//-------------------------------------------------------------------------------------------------
inline
Hash::~Hash() {
    // empty
}

//-------------------------------------------------------------------------------------------------
inline
unsigned int Hash::toHash( const char *buffer, unsigned int base ) {
    unsigned int hash( 0 );
    if( !buffer ) {
        return hash;
    }
    
    // using division-rest method
    // see http://de.wikipedia.org/wiki/Divisionsrestmethode
    for( size_t i = 0; i < strlen( buffer ); ++i ) {
        hash = ( hash * 128 + buffer[ i ] ) % base;
    }
    
    return hash;
}

//-------------------------------------------------------------------------------------------------
inline
unsigned int Hash::toHash( unsigned int value, unsigned int base ) {
    const unsigned int hash( value%base );
    return hash;
}

//-------------------------------------------------------------------------------------------------
inline
unsigned int Hash::hashValue() const {
    return m_hash;
}

//-------------------------------------------------------------------------------------------------

} // Namespace CPPCore

#endif // CPPCORE_HASH_H_INC
