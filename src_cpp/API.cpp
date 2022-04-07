#include "PyAPI.h"

static PyObject *_readFile(PyObject *self, PyObject *args) {
    const char *filePath;
    if (!PyArg_ParseTuple(args, "s", &filePath)) {
        return NULL;
    }
    return PyUnicode_FromString(PyAPI::Singleton().readFile(filePath).c_str());
}

static PyObject *_getPassage(PyObject *self, PyObject *args) {
    return PyUnicode_FromString(PyAPI::Singleton().getPassage().c_str());
}

static PyObject *_findWords(PyObject *self, PyObject *args) {
    const char *_words;
    if (!PyArg_ParseTuple(args, "s", &_words)) {
        return NULL;
    }
    PyAPI::Singleton().findWords(_words);
    // 不能无返回值，可以返回Py_None
    return Py_None;
}

static PyObject *_sort(PyObject *self, PyObject *args) {
    const char *_strategy;
    if (!PyArg_ParseTuple(args, "s", &_strategy)) {
        return NULL;
    }
    PyAPI::Singleton().sortPassage(std::string(_strategy));
    return Py_None;
}

static PyMethodDef ModuleMethods[] = {
    /*{
        "great_function",  // 对python的函数名
        _great_function,   // 本文件上方定义的包裹函数名
        METH_VARARGS,      // 固定
        ""                 // 说明文字
    },*/
    {"getPassage", _getPassage, METH_VARARGS, "获取passage"},
    {"findWords", _findWords, METH_VARARGS, "查找word并标记之"},
    {"sort", _sort, METH_VARARGS, "对各row排序"},
    {"readFile", _readFile, METH_VARARGS, "读入文件"},
    {NULL, NULL, 0, NULL}};

static struct PyModuleDef cModPyDem = {
    PyModuleDef_HEAD_INIT, /* 固定 */
    "PyAPI",               /* name of module */
    "",                    /* module documentation, may be NULL */
    -1, /* size of per-interpreter state of the module, or -1 if the module
           keeps state in global variables. */
    ModuleMethods};

// 函数名必须是:PyInit_{模块名}
PyMODINIT_FUNC PyInit_PyAPI(void) { return PyModule_Create(&cModPyDem); }