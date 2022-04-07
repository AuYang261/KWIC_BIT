
import sys
from PyQt5.QtWidgets import *
from PyQt5.QtWidgets import QApplication, QPushButton, QWidget, QListView, QVBoxLayout, QMainWindow, QMessageBox, QLabel
from PyQt5.QtGui import QIcon,QTextCursor,QTextCharFormat,QColor
import Ui_kwic_ui
import Ui_childwindow
from functools import partial
import PyAPI

class MainWindow(QMainWindow): #主窗口

    def __init__(self,):
        super().__init__()
        self.ui = Ui_kwic_ui.Ui_MainWindow()
        self.childWindows = ChildWindow()
        self.childWindows.ui.setupUi(self.childWindows)
        self.childWindows.window_init()

    def window_init(self):
        #设置窗体基本参数
        self.setWindowTitle('KWIC')
        self.resize(1500, 1200)

        #按钮功能
        self.ui.origin_Button.clicked.connect(partial(self.origin_Button_Output, self.ui))
        self.ui.sortRow_Button.clicked.connect(partial(self.sortRow_Button_Output, self.ui))
        self.ui.shift_Button.clicked.connect(partial(self.shift_Button_Output, self.ui))
        self.ui.find_Button.clicked.connect(partial(self.find_Button_Output, self.ui))

    def origin_Button_Output(self,ui):
        #str = PyAPI.resdFile()
        self.connect_childwindow('abc',self.ui.origin_Button)

    def sortRow_Button_Output(self,ui):
        #PyAPI.sort()
        #str = PyAPI.getPassage()
        self.connect_childwindow('def',self.ui.sortRow_Button)

    def shift_Button_Output(self,ui):
        #str = PyAPI.getPassage()
        self.connect_childwindow('hjh',self.ui.shift_Button)

    def find_Button_Output(self,ui):
        #PyAPI.findWords()
        #str = PyAPI.getPassage()
        txt = 'abc*apple*skdjah*apple*banana*apple*'
        self.get_input()
        self.connect_childwindow(txt,self.ui.find_Button)
        self.childWindows.HighLight(self.keyword,txt)
        #self.childWindows.HighLight()

    def connect_childwindow(self,str,contact):
        self.childWindows.ui.wordlist.setText(str)
        contact.clicked.connect(self.childWindows.show)

    def get_input(self): #获得要查找的单词
        self.keyword = self.ui.word_LineEdit.text()
        #这里要传回去

class ChildWindow(QDialog): #子窗口

    def __init__(self):
        super().__init__()
        self.ui = Ui_childwindow.Ui_Dialog()

    def window_init(self):
        #设置窗体基本参数
        self.setWindowTitle('查找结果')
        self.resize(1200, 900)

    def HighLight(self,keyword,txt):

        keyword_lists = keyword.split(',')
        txt_lists = txt.split('*')

        document = self.ui.wordlist.document()
        highlight_cursor = QTextCursor()
        cursor = QTextCursor()
        cursor.beginEditBlock()

        color_format = QTextCharFormat(highlight_cursor.charFormat())
        color_format.setBackground(QColor(255,211,6))

        for ch in txt_lists:

            if ch in keyword_lists:
                highlight_cursor = document.find(ch,highlight_cursor)
                highlight_cursor.mergeCharFormat(color_format)
        
        cursor.endEditBlock()    

if __name__ == '__main__':
    #变量设置及初始化
    app = QApplication(sys.argv)
    MainWindows = MainWindow()
    MainWindows.ui.setupUi(MainWindows)
    MainWindows.window_init()

    # #关联窗口
    # contact = MainWindows.ui.find_Button
    # contact.clicked.connect(MainWindows.childWindows.show)

    MainWindows.get_input()
    MainWindows.show()
    sys.exit(app.exec())