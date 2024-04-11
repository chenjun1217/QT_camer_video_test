#include <stdio.h> // 包含标准输入输出头文件
#include <iostream> // 包含输入输出流头文件
#include "mainwindow.h" // 包含主窗口头文件
#include "ui_mainwindow.h" // 包含主窗口UI头文件
using namespace std; // 使用标准命名空间

MainWindow::MainWindow(QWidget *parent) // 主窗口构造函数
    : QMainWindow(parent) // 调用父类构造函数
    , ui(new Ui::MainWindow) // 初始化UI指针
{
    ui->setupUi(this); // 设置UI
    timer = new QTimer(this); // 创建定时器
    connect(timer, SIGNAL(timeout()), this, SLOT(OpenVideoOrCarme())); // 连接定时器信号与槽函数
}

MainWindow::~MainWindow() // 主窗口析构函数
{
    delete ui; // 释放UI指针
}

void MainWindow::on_pushButton_clicked() // 按钮点击事件处理函数
{
    //视频播放按钮
    if (isCameraOpen) // 如果相机已打开
    {
        capture.open(0); // 打开相机
    }
    else
    {
        capture.open("01.mp4"); // 打开视频文件
    }
    timer->start(33); // 启动定时器
}

void MainWindow::on_pushButton_2_clicked() // 停止按钮点击事件处理函数
{
    //视频停止播放按钮
    timer->stop(); // 停止定时器
    capture.release(); // 释放视频捕获
}

void MainWindow::on_label_linkActivated(const QString &link) // 标签链接激活事件处理函数
{
    //视频播放
}

void MainWindow::OpenVideoOrCarme() // 打开视频或相机函数
{
    capture >> frame; // 从捕获中读取帧
    //cvtColor(frame, frame, CV_BGR2RGB);//only RGB of Qt
    QImage srcQImage = QImage((uchar*)(frame.data), frame.cols, frame.rows, QImage::Format_RGB888); // 创建Qt格式的图像
    ui->label->setPixmap(QPixmap::fromImage(srcQImage)); // 在标签上显示图像
    ui->label->resize(srcQImage.size()); // 调整标签大小
    ui->label->show(); // 显示标签
}

void MainWindow::on_comboBox_activated(const QString &arg1) // 下拉框激活事件处理函数
{
    if(ui->comboBox) // 如果下拉框存在
        isCameraOpen = 1; // 设置相机打开标志为1
    else
        isCameraOpen = 0; // 设置相机打开标志为0
}