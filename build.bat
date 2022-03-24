set pythonPath=C:\Users\AuYang\AppData\Local\Programs\Python\Python36\
g++ src_cpp/* -I%pythonPath%include -L%pythonPath%libs -lpython36 -L%pythonPath% -lpython36 -o GUI/PyAPI.pyd -shared -std=c++20
