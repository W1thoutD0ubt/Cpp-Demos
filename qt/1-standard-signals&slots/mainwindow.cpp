#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
{
    // 设置窗口大小
    this->setFixedSize(800, 600);

    // 为窗口添加按钮
    this->test_btn = new QPushButton();
    this->test_btn->setParent(this);
    this->test_btn->setText("点我");
    this->test_btn->setFixedSize(100, 100);
    this->test_btn->move(350, 250);

    /* 连接信号和槽函数
     * 参数依次为：信号源、信号名称、接收者、触发的槽函数
     * clicked() 为信号，click() 为槽函数，注意区分！
     * 槽函数可以像普通函数一样使用
     * 信号和槽函数都可以继承
    */
    QObject::connect(this->test_btn, &QPushButton::clicked, this, &QMainWindow::close);
    // 这怎么看都像是添加回调函数……
}

MainWindow::~MainWindow()
{
}
