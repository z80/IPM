// **********************************************************************
//
// Copyright (c) 2003-2008 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************

#ifndef TEST_ICE
#define TEST_ICE

module Test
{

exception InvalidInputException
{
    string message;
};

local exception RetryException
{
};

interface MyObject
{
    //
    // A simple addition
    //
    int add(int x, int y);

    //
    // Will throw RetryException until current.ctx["retry"] is "no"
    //
    int addWithRetry(int x, int y);

    //
    // Raise user exception
    //
    int badAdd(int x, int y) throws InvalidInputException;

    //
    // Raise ONE
    //
    int notExistAdd(int x, int y);

    //
    // Raise system exception
    //
    int badSystemAdd(int x, int y);
};


};

#endif
