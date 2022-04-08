import PyAPI

(PyAPI.readFile("../LICENSE"))
# print(PyAPI.getPassage())
PyAPI.findWords("MIT")
PyAPI.sort("Sortor1")
print(PyAPI.getPassage())
PyAPI.findWords("") # 清空前面查找的词标记
print(PyAPI.getPassage())