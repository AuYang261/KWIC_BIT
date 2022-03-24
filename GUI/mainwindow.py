import sys
from PyQt5.QtWidgets import *
from PyQt5.QtWidgets import QApplication, QPushButton, QWidget, QListView, QVBoxLayout, QMainWindow, QMessageBox, QLabel
from PyQt5.QtGui import QIcon,QTextCursor,QTextCharFormat,QColor
import Ui_kwic_ui
import Ui_childwindow
from functools import partial

class MainWindow(QMainWindow): #主窗口

    def __init__(self,):
        super().__init__()
        self.ui = Ui_kwic_ui.Ui_MainWindow()

    def window_init(self):
        #设置窗体基本参数
        self.setWindowTitle('KWIC')
        self.resize(1500, 1200)

        #按钮功能
        self.ui.origin_Button.clicked.connect(partial(self.fun, self.ui))
        self.ui.sortRow_Button.clicked.connect(partial(self.fun, self.ui))
        self.ui.shift_Button.clicked.connect(partial(self.fun, self.ui))
        self.ui.find_Button.clicked.connect(partial(self.fun, self.ui))

    def fun(self,ui):#对应各功能
        print('1')

    def get_input(self): #获得要查找的单词
        keyword = str(self.ui.word_LineEdit.text())
        #这里要传回去

class ChildWindow(QDialog): #子窗口

    def __init__(self):
        super().__init__()
        self.ui = Ui_childwindow.Ui_Dialog()

    def window_init(self):
        #设置窗体基本参数
        self.setWindowTitle('查找结果')
        self.resize(1200, 900)

    def HighLight(self):
        document = self.ui.wordlist.document()
        highlight_cursor = QTextCursor(document)
        cursor = QTextCursor(document)
        cursor.beginEditBlock()

        color_format = QTextCharFormat(highlight_cursor.charFormat())
        color_format.setBackground(QColor(255,211,6))

        while((not highlight_cursor.isNull()) and (not highlight_cursor.atEnd())):
            highlight_cursor = document.find('apple',highlight_cursor)
            if not highlight_cursor.isNull():
                highlight_cursor.mergeCharFormat(color_format)
        cursor.endEditBlock()    

    

if __name__ == '__main__':
    #变量设置及初始化
    app = QApplication(sys.argv)
    MainWindows = MainWindow()
    ChildWindows = ChildWindow()
    MainWindows.ui.setupUi(MainWindows)
    ChildWindows.ui.setupUi(ChildWindows)
    MainWindows.window_init()
    ChildWindows.window_init()

    #关联窗口
    contact = MainWindows.ui.find_Button
    contact.clicked.connect(ChildWindows.show)

    MainWindows.get_input()
    ChildWindows.HighLight()
    MainWindows.show()
    sys.exit(app.exec())