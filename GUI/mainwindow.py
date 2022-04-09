
import os
import sys
from PyQt5.QtWidgets import *
from PyQt5.QtWidgets import QApplication, QPushButton, QWidget, QListView, QVBoxLayout, QMainWindow, QMessageBox, QLabel,QFileDialog,QComboBox
from PyQt5.QtGui import QIcon,QTextCursor,QTextCharFormat,QColor
import Ui_kwic_ui
import Ui_childwindow
from qt_material import apply_stylesheet
from qt_material import list_themes
import PyAPI

class MainWindow(QMainWindow): #主窗口

    def __init__(self,):
        super().__init__()
        self.ui = Ui_kwic_ui.Ui_MainWindow()
        self.keyword = ''
        self.filename = "D:\learn\\2021-2022-2\software industy\KWIC_BIT\LICENSE"
        self.childWindows = ChildWindow()
        self.childWindows.ui.setupUi(self.childWindows)
        self.childWindows.window_init()

    def window_init(self):
        #设置基本参数
        self.setWindowTitle('KWIC')
        self.resize(1200, 900)
        
        #按钮功能
        self.ui.origin_Button.clicked.connect(self.origin_Button_Output)
        self.ui.sortRow_Button.clicked.connect(self.sortRow_Button_Output)
        self.ui.sortRow_Button2.clicked.connect(self.sortRow_Button2_Output)
        self.ui.shift_Button.clicked.connect(self.shift_Button_Output)
        self.ui.find_Button.clicked.connect(self.find_Button_Output)
        self.ui.file_Button.clicked.connect(self.file_Button_Open)



    def origin_Button_Output(self):
        strs = PyAPI.readFile(self.filename) 
        self.connect_childwindow(strs,self.ui.origin_Button)


    def sortRow_Button_Output(self):
        PyAPI.readFile(self.filename)
        PyAPI.sort('Sortor1')
        strs = PyAPI.getPassage()
        self.connect_childwindow(strs,self.ui.sortRow_Button)

    def sortRow_Button2_Output(self):
        PyAPI.readFile(self.filename)
        PyAPI.sort('Sortor2')
        strs = PyAPI.getPassage()
        self.connect_childwindow(strs,self.ui.sortRow_Button2)

    def shift_Button_Output(self):
        PyAPI.readFile(self.filename)
        strs = PyAPI.getPassage()
        self.connect_childwindow(strs,self.ui.shift_Button)

    def find_Button_Output(self):
        PyAPI.readFile(self.filename)
        self.get_input()
        PyAPI.findWords(self.keyword)
        strs = PyAPI.getPassage()
        self.connect_childwindow(strs,self.ui.find_Button)
        self.childWindows.HighLight(self.keyword,strs)

    def connect_childwindow(self,str,contact):
        self.childWindows.ui.wordlist.setFontPointSize(20)
        self.childWindows.ui.wordlist.setText(str)
        contact.clicked.connect(self.childWindows.show)

    def get_input(self): #获得要查找的单词
        self.keyword = self.ui.word_LineEdit.text()

    def file_Button_Open(self):
        fileName,fileType = QFileDialog.getOpenFileName(self, "选取文件", os.getcwd(), "All Files(*);;Text Files(*.txt)")
        self.filename = fileName
        self.ui.file_browser.setText(fileName)


class ChildWindow(QDialog): #子窗口

    def __init__(self):
        super().__init__()
        self.ui = Ui_childwindow.Ui_Dialog()

    def window_init(self):
        #设置窗体基本参数
        self.setWindowTitle('结果')
        self.resize(1500, 1200)

    def HighLight(self,keyword,txt):

        keyword_lists = keyword.split(' ')
        keyword_lists = ['*' + keyword_lists[i] + '*' for i in range(len(keyword_lists))]

        document = self.ui.wordlist.document()
        cursor = QTextCursor(document)
        cursor.beginEditBlock()

        color = [0x65,0x65,0x65,0xFF,0xD5,0x4F,0x30,0x4F,0xFE]

        for i in range(len(keyword_lists)):

            highlight_cursor = QTextCursor(document)
            color_format = QTextCharFormat(highlight_cursor.charFormat())
            color_format.setBackground(QColor(color[3 * i % 9],color[(1 + 3 * i) % 9],color[(2 + 3 * i) % 9]))
            while (not highlight_cursor.isNull()) and (not highlight_cursor.atEnd()): 
                highlight_cursor = document.find(keyword_lists[i], highlight_cursor)
                if not highlight_cursor.isNull():
                    highlight_cursor.mergeCharFormat(color_format)
        
        cursor.endEditBlock()    

if __name__ == '__main__':
    #变量设置及初始化
    app = QApplication(sys.argv)
    MainWindows = MainWindow()
    MainWindows.ui.setupUi(MainWindows)
    apply_stylesheet(app, theme='dark_teal.xml')
    list_themes()
    MainWindows.window_init()
    MainWindows.show()
    sys.exit(app.exec())