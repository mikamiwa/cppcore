/*
-------------------------------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2014-2016 Kim Kulling

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
#include <cppcore/Container/TStaticArray.h>

#include "gtest/gtest.h"

using namespace CPPCore;

//-------------------------------------------------------------------------------------------------
///	@class		TStaticArrayTest
///	@ingroup	UnitTest
///
///	@brief	The queue tests.
//-------------------------------------------------------------------------------------------------
class TStaticArrayTest : public testing::Test {
    // empty
};

TEST_F(TStaticArrayTest, constructTest) {
    TStaticArray<int, 4> arr;
    EXPECT_EQ(4u, arr.size());
    EXPECT_EQ(0, arr[0]);
    EXPECT_EQ(0, arr[3]);
}

TEST_F(TStaticArrayTest, access_items_Test) {
    TStaticArray<int, 4> arr;
    for (int i = 0; i < 4; ++i) {
        arr[i] = i;
    }
    for (int i = 0; i < 4; ++i) {
        EXPECT_EQ(i, arr[i]);
    }
}

TEST_F(TStaticArrayTest, clear_Test) {
    TStaticArray<int, 4> arr;
    for (size_t i = 0; i < 4; ++i) {
        arr[i] = i;
    }
    arr.clear();
    for (size_t i = 0; i < 4; ++i) {
        EXPECT_EQ(0, arr[i]);
    }
}

TEST_F(TStaticArrayTest, access_strin_Test) {
    TStaticArray < std::string, 4> arr;
    arr[0] = std::string("bla");
    arr[1] = std::string("bla");
    arr[2] = std::string("bla");
    arr[3] = std::string("huhu");
}
