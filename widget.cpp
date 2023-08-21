#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->server = new QTcpServer;

    this->server->listen(QHostAddress::AnyIPv4, 8000);

    //客户端发起连接， server发出信号
    connect(this->server, &QTcpServer::newConnection, this, &Widget::newClentHandler);
}

void Widget::newClentHandler()
{
    //建立tcp连接
   QTcpSocket *socket = this->server->nextPendingConnection();

//   //获取客户端地址
//   socket->peerAddress();

//   //获取端口号
//   socket->peerPort();

   ui->ipLineEdit->setText(socket->peerAddress().toString());
   ui->portLineEdit_2->setText(QString::number(socket->peerPort()));

   //服务器收到客户发送的信息， socket发出readyread信号
   //connect(socket, &QTcpSocket::readyRead, this, &Widget::clientInfoSlot);


}

void Widget::clientInfoSlot()
{
    QTcpSocket *s = (QTcpSocket*)sender();

    ui->lineEdit->setText(QString(s->readAll()));

}

Widget::~Widget()
{
    delete ui;
}

