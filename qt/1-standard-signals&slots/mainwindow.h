#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

class MainWindow : public QMainWindow
{
    // F1 可以在官方文档中快速查询某个量

    // 若想使用信号和槽函数，你必须添加这个宏
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QPushButton *test_btn;
};
#endif // MAINWINDOW_H
