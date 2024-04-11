#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv2/dnn.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_label_linkActivated(const QString &link);
    void OpenVideoOrCarme();

    void on_comboBox_activated(const QString &arg1);

private:
    Ui::MainWindow *ui;
    cv::VideoCapture capture;
    QTimer *timer;
    cv::Mat frame;
    bool isCameraOpen=0;

};
#endif // MAINWINDOW_H
