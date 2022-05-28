#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    // 应用程序对象
    QApplication a(argc, argv);

    // 主窗口对象
    MainWindow *w = new MainWindow(nullptr);

    // 默认隐藏，需要展示
    w->show();

    // 注意，是 QApplication::exec()，和 QMainWindow 无关！
    return a.exec();
}
