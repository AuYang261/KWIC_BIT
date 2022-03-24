#include "PyAPI.h"

static PyObject *_getPassage(PyObject *self, PyObject *args) {
    std::string s = "hello python!";
    // return PyAPI::Singleton().getPassage();
    return PyUnicode_FromString(s.c_str());
}

static PyObject *_findWord(PyObject *self, PyObject *args) {
    const char *_word;
    if (!PyArg_ParseTuple(args, "s", &_word)) {
        return NULL;
    }
    std::cout << _word << std::endl;
    // 好像不能无返回值
    return PyUnicode_FromString("Got it!");
}

static PyMethodDef ModuleMethods[] = {
    /*{
        "great_function",  // 对python的函数名
        _great_function,   // 本文件上方定义的包裹函数名
        METH_VARARGS,      // 固定
        ""                 // 说明文字
    },*/
    {"getPassage", _getPassage, METH_VARARGS, "注册一个客户端"},
    {"findWord", _findWord, METH_VARARGS, "注销一个客户端"},
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