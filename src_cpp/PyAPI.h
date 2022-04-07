/*@brief:给python的接口供其调用
 */

#ifndef __PyAPI_h__
#define __PyAPI_h__

#include <Python.h>

#include <iostream>
#include <string>

#include "passage.h"

class PyAPI {
   public:
    virtual ~PyAPI() {}
    static PyAPI& Singleton();

    std::string getPassage();
    void findWords(std::string words);
    void sortPassage(std::string strategy);
    std::string readFile(std::string filePath);

   private:
    PyAPI() : _passage(new Passage) {}
    Passage* _passage;
    inline static PyAPI* _singletonPtr;
};

#endif