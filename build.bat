@echo off
chcp 65001
set pythonPath=C:\Users\AuYang\AppData\Local\Programs\Python\Python36\
g++ src_cpp/*.cpp -Isrc_cpp/include -I%pythonPath%include -L%pythonPath%libs -lpython36 -L%pythonPath% -lpython36 -o GUI/PyAPI.pyd -shared -std=c++20 -static > BuildOutput.log 2>&1
echo 编译信息在BuildOutput.log里
