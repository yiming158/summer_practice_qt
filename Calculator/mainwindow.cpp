#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore/QCoreApplication>
#include <cmath>
#include <QString>
QString value="",total="";
float num1,num2;
bool add_bool=false,subtract_bool=false,multiply_bool=false,divide_bool=false,square_bool=false,sqroot_bool=false;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)

{
label =new QLabel("0",this);
label->setGeometry(QRect(QPoint(25,115),QSize(250,50)));

clear_button=new QPushButton("C",this);
clear_button->setGeometry(QRect(QPoint(175,175),QSize(100,50)));
connect(clear_button,SIGNAL(released()),this,SLOT(clear()));

add_button=new QPushButton("+",this);
add_button->setGeometry(QRect(QPoint(125,225),QSize(50,50)));
connect(add_button,SIGNAL(released()),this,SLOT(add()));

subtract_button=new QPushButton("-",this);
subtract_button->setGeometry(QRect(QPoint(175,225),QSize(50,50)));
connect(subtract_button,SIGNAL(released()),this,SLOT(subtract()));

multiply_button=new QPushButton("x",this);
multiply_button->setGeometry(QRect(QPoint(125,275),QSize(50,50)));
connect(multiply_button,SIGNAL(released()),this,SLOT(multiply()));

divide_button=new QPushButton("÷",this);
divide_button->setGeometry(QRect(QPoint(175,275),QSize(50,50)));
connect(divide_button,SIGNAL(released()),this,SLOT(divide()));

square_button=new QPushButton("x²",this);
square_button->setGeometry(QRect(QPoint(225,225),QSize(50,50)));
connect(square_button,SIGNAL(released()),this,SLOT(square()));

sqroot_button=new QPushButton("√x",this);
sqroot_button->setGeometry(QRect(QPoint(225,275),QSize(50,50)));
connect(sqroot_button,SIGNAL(released()),this,SLOT(sqroot()));


equal_button=new QPushButton("=",this);
equal_button->setGeometry(QRect(QPoint(175,325),QSize(100,50)));
connect(equal_button,SIGNAL(released()),this,SLOT(equal()));

zero_button=new QPushButton("0",this);
zero_button->setGeometry(QRect(QPoint(25,325),QSize(50,50)));
connect(zero_button,SIGNAL(released()),this,SLOT(zero()));

one_button=new QPushButton("1",this);
one_button->setGeometry(QRect(QPoint(75,325),QSize(50,50)));
connect(one_button,SIGNAL(released()),this,SLOT(one()));

two_button=new QPushButton("2",this);
two_button->setGeometry(QRect(QPoint(125,325),QSize(50,50)));
connect(two_button,SIGNAL(released()),this,SLOT(two()));

three_button=new QPushButton("3",this);
three_button->setGeometry(QRect(QPoint(25,275),QSize(50,50)));
connect(three_button,SIGNAL(released()),this,SLOT(three()));

four_button=new QPushButton("4",this);
four_button->setGeometry(QRect(QPoint(75,275),QSize(50,50)));
connect(four_button,SIGNAL(released()),this,SLOT(four()));

five_button=new QPushButton("5",this);
five_button->setGeometry(QRect(QPoint(25,225),QSize(50,50)));
connect(five_button,SIGNAL(released()),this,SLOT(five()));

six_button=new QPushButton("6",this);
six_button->setGeometry(QRect(QPoint(75,225),QSize(50,50)));
connect(six_button,SIGNAL(released()),this,SLOT(six()));

seven_button=new QPushButton("7",this);
seven_button->setGeometry(QRect(QPoint(25,175),QSize(50,50)));
connect(seven_button,SIGNAL(released()),this,SLOT(seven()));

eight_button=new QPushButton("8",this);
eight_button->setGeometry(QRect(QPoint(75,175),QSize(50,50)));
connect(eight_button,SIGNAL(released()),this,SLOT(eight()));

nine_button=new QPushButton("9",this);
nine_button->setGeometry(QRect(QPoint(125,175),QSize(50,50)));
connect(nine_button,SIGNAL(released()),this,SLOT(nine()));




}

void MainWindow::clear(){
   value="";
   total = "";
   label->setText(value);


}
void MainWindow::add(){
    num1=value.toFloat();
value+="+";
label->setText(value);
add_bool=true;
}
void MainWindow::subtract(){
    num1=value.toFloat();
    value+="-";
    label->setText(value);
    subtract_bool=true;
}
void MainWindow::multiply(){
    num1=value.toFloat();
    value+="x";
    label->setText(value);
    multiply_bool=true;

}
void MainWindow::divide(){
    num1=value.toFloat();
    value+="/";
    label->setText(value);
    divide_bool=true;

}
void MainWindow::square(){
    num1=value.toFloat();
    value="";
    label->setText(value);
    total=QString::number(pow(num1,2));
    label->setText(total);
    //square_bool=true;

}
void MainWindow::sqroot(){
    num1=value.toFloat();
    value="";
    label->setText(value);
    total=QString::number(pow(num1,0.5));
    label->setText(total);


   // sqroot_bool=true;

}
void MainWindow::equal(){


    QString qstr=value;

     total+=(value+"=");

    if(add_bool){
        QStringList strSplitted=qstr.split('+');
        num2=strSplitted.at(1).toFloat();
        total+=QString::number(num1+num2);
        label->setText(total);

    }

    if(subtract_bool){
        QStringList strSplitted=qstr.split('-');
        num2=strSplitted.at(1).toFloat();
        total+=QString::number(num1-num2);
    label->setText(total);

    }
    if(multiply_bool){
       QStringList strSplitted=qstr.split('x');
        num2=strSplitted.at(1).toFloat();
        total+=QString::number(num1*num2);
    label->setText(total);



    }
    if(divide_bool){
         QStringList strSplitted=qstr.split('/');
        num2=strSplitted.at(1).toFloat();
        total+=QString::number(num1/num2);
    label->setText(total);

    }

    num1=0;
    num2=0;
}

void MainWindow::zero(){
    value+="0";
    label->setText(value);


}
void MainWindow::one(){

    value+="1";
    label->setText(value);
}
void MainWindow::two(){
    value+="2";
    label->setText(value);
}
void MainWindow::three(){
    value+="3";
    label->setText(value);
}
void MainWindow::four(){
    value+="4";
    label->setText(value);

}
void MainWindow::five(){
    value+="5";
    label->setText(value);
}
void MainWindow::six(){
    value+="6";
    label->setText(value);
}
void MainWindow::seven(){
    value+="7";
    label->setText(value);
}
void MainWindow::eight(){
    value+="8";
    label->setText(value);
}
void MainWindow::nine(){
    value+="9";
    label->setText(value);
}





MainWindow::~MainWindow()
{

}

