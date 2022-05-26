#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

/* QMainWindow 和 QDialog 都继承自 QWidget
 * 但前者可以有菜单栏、工具栏等， QDialog 不行
*/
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /* 每个 QObject 都可以设置一个 parent。
    * parent 在析构之前，会将所有子对象析构。
    */
    MainWindow(QWidget *parent = nullptr); // 主窗口为什么要有 parent？
    ~MainWindow();

    QPushButton *test_btn;
};
#endif // MAINWINDOW_H
