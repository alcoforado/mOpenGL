#include "MainWindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
  
    ui->setupUi(this);
    //this->setCentralWidget()

}





MainWindow::~MainWindow()
{
    delete ui;
}
