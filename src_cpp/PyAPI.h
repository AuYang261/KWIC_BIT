/*@brief:给python的接口供其调用
 */

#ifndef __PyAPI_h__
#define __PyAPI_h__

#include <Python.h>

#include <iostream>
#include <string>

class Passage;

class PyAPI {
   public:
    virtual ~PyAPI() {}
    static PyAPI& Singleton();

    std::string getPassage();
    void findWord(std::string s);
    void sortPassage();

   private:
    PyAPI() : _passage() {}
    Passage* _passage;
    inline static PyAPI* _singletonPtr;
};

#endif