# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'd:\learn\2021-2022-2\software industy\KWIC_BIT\GUI\kwic_ui.ui'
#
# Created by: PyQt5 UI code generator 5.15.4
#
# WARNING: Any manual changes made to this file will be lost when pyuic5 is
# run again.  Do not edit this file unless you know what you are doing.


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(885, 646)
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.gridLayout = QtWidgets.QGridLayout(self.centralwidget)
        self.gridLayout.setObjectName("gridLayout")
        self.shift_Button = QtWidgets.QPushButton(self.centralwidget)
        self.shift_Button.setEnabled(True)
        self.shift_Button.setObjectName("shift_Button")
        self.gridLayout.addWidget(self.shift_Button, 7, 0, 1, 1)
        self.file_browser = QtWidgets.QTextBrowser(self.centralwidget)
        self.file_browser.setEnabled(False)
        self.file_browser.setObjectName("file_browser")
        self.gridLayout.addWidget(self.file_browser, 3, 0, 1, 1)
        self.label = QtWidgets.QLabel(self.centralwidget)
        self.label.setObjectName("label")
        self.gridLayout.addWidget(self.label, 8, 0, 1, 1)
        self.word_LineEdit = QtWidgets.QLineEdit(self.centralwidget)
        self.word_LineEdit.setObjectName("word_LineEdit")
        self.gridLayout.addWidget(self.word_LineEdit, 9, 0, 1, 1)
        self.textBrowser = QtWidgets.QTextBrowser(self.centralwidget)
        self.textBrowser.setEnabled(False)
        self.textBrowser.setObjectName("textBrowser")
        self.gridLayout.addWidget(self.textBrowser, 0, 0, 1, 1)
        self.origin_Button = QtWidgets.QPushButton(self.centralwidget)
        self.origin_Button.setEnabled(True)
        self.origin_Button.setObjectName("origin_Button")
        self.gridLayout.addWidget(self.origin_Button, 4, 0, 1, 1)
        self.textBrowser_2 = QtWidgets.QTextBrowser(self.centralwidget)
        self.textBrowser_2.setEnabled(False)
        self.textBrowser_2.setObjectName("textBrowser_2")
        self.gridLayout.addWidget(self.textBrowser_2, 1, 0, 1, 1)
        self.find_Button = QtWidgets.QPushButton(self.centralwidget)
        self.find_Button.setEnabled(True)
        self.find_Button.setObjectName("find_Button")
        self.gridLayout.addWidget(self.find_Button, 14, 0, 1, 1)
        self.sortRow_Button = QtWidgets.QPushButton(self.centralwidget)
        self.sortRow_Button.setEnabled(True)
        self.sortRow_Button.setObjectName("sortRow_Button")
        self.gridLayout.addWidget(self.sortRow_Button, 5, 0, 1, 1)
        self.file_Button = QtWidgets.QPushButton(self.centralwidget)
        self.file_Button.setObjectName("file_Button")
        self.gridLayout.addWidget(self.file_Button, 2, 0, 1, 1)
        self.sortRow_Button2 = QtWidgets.QPushButton(self.centralwidget)
        self.sortRow_Button2.setObjectName("sortRow_Button2")
        self.gridLayout.addWidget(self.sortRow_Button2, 6, 0, 1, 1)
        MainWindow.setCentralWidget(self.centralwidget)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow"))
        self.shift_Button.setText(_translate("MainWindow", "输出循环移位结果"))
        self.file_browser.setHtml(_translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:\'SimSun\'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:19px; background-color:#1e1e1e;\"><span style=\" font-family:\'Consolas\',\'Courier New\',\'monospace\'; font-size:14px; color:#ce9178;\">D:\\learn</span><span style=\" font-family:\'Consolas\',\'Courier New\',\'monospace\'; font-size:14px; color:#d7ba7d;\">\\\\</span><span style=\" font-family:\'Consolas\',\'Courier New\',\'monospace\'; font-size:14px; color:#ce9178;\">2021-2022-2\\software industy</span><span style=\" font-family:\'Consolas\',\'Courier New\',\'monospace\'; font-size:14px; color:#d7ba7d;\">\\\\</span><span style=\" font-family:\'Consolas\',\'Courier New\',\'monospace\'; font-size:14px; color:#ce9178;\">try.txt</span></p></body></html>"))
        self.label.setText(_translate("MainWindow", "输入查找词"))
        self.textBrowser.setHtml(_translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:\'SimSun\'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:72pt; font-weight:600; font-style:italic;\">K W I C</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:22pt; font-weight:600; font-style:italic;\">by 1,2,3,4</span></p></body></html>"))
        self.origin_Button.setText(_translate("MainWindow", "输出原文本"))
        self.textBrowser_2.setHtml(_translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:\'SimSun\'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">使用指南：</span></p></body></html>"))
        self.find_Button.setText(_translate("MainWindow", "输出查找结果"))
        self.sortRow_Button.setText(_translate("MainWindow", "STL排序产生结果"))
        self.file_Button.setText(_translate("MainWindow", "选择文件"))
        self.sortRow_Button2.setText(_translate("MainWindow", "堆排序产生结果"))
