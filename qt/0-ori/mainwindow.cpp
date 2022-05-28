#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
{
    // 设置窗口大小
    this->setFixedSize(800, 600);

    // 为窗口添加按钮
    this->test_btn = new QPushButton();
    this->test_btn->setParent(this);
    this->test_btn->setText("Test succeeded");
    this->test_btn->setFixedSize(200, 400); //先为横坐标，后为纵坐标
    this->test_btn->move(300, 100);
    this->test_btn->setEnabled(false);// 我故意的
}

MainWindow::~MainWindow()
{
}

