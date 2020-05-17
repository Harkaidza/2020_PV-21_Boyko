#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtMath"

double num_first;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(digits_numbers()));

    connect(ui->pushButton_plus_min,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_procent,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_sqrt,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_modul,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_factor,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_x2,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_x3,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_10x,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_log,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_ln,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_sin,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_cos,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_tg,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_ctg,SIGNAL(clicked()),this,SLOT(operations()));

    connect(ui->pushButton_pi,SIGNAL(clicked()),this,SLOT(constants()));
    connect(ui->pushButton_e,SIGNAL(clicked()),this,SLOT(constants()));

    connect(ui->pushButton_del,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_mult,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_plus,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_minus,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_xy,SIGNAL(clicked()),this,SLOT(math_operations()));
    ui->pushButton_del->setCheckable(true);
    ui->pushButton_mult->setCheckable(true);
    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_xy->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers()
{
    QPushButton *button = (QPushButton *)sender();

    double all_numbers;
    QString new_label;

    if(ui->result_show->text().contains(".") && button->text() == "0")
        new_label = ui->result_show->text() + button->text();
    else
    {
        all_numbers = (ui->result_show->text()+button->text()).toDouble();
        new_label = QString::number(all_numbers,'g',15);
    }

    ui->result_show->setText(new_label);
}

void MainWindow::on_pushButton_dot_clicked()
{
    if (!(ui->result_show->text().contains('.')))
        ui->result_show->setText(ui->result_show->text() + ".");
}

void MainWindow::constants()
{
    QPushButton *button = (QPushButton *)sender();
    QString new_label;
    if (button->text() == "pi")
    {
        new_label = QString::number(M_PI,'g',15);
        ui->result_show->setText(new_label);
    }
    else if (button->text() == "e")
    {
        new_label = QString::number(M_E,'g',15);
        ui->result_show->setText(new_label);
    }
}

void MainWindow::operations()
{
    //помещаем в указатель кнопку, которая была нажата
    QPushButton *button = (QPushButton *)sender();
    double all_numbers;
    QString new_label;

    if (button->text() == "+/-")
    {
        all_numbers = (ui->result_show->text()).toDouble();
        all_numbers = all_numbers * -1;
        new_label = QString::number(all_numbers,'g',15);

        ui->result_show->setText(new_label);
    }
    else if (button->text() == "%")
    {
        all_numbers = (ui->result_show->text()).toDouble();
        all_numbers = all_numbers * 0.01;
        new_label = QString::number(all_numbers,'g',15);

        ui->result_show->setText(new_label);
    }
    else if (button->text() == "sqrt")
    {
        all_numbers = (ui->result_show->text()).toDouble();
        all_numbers = sqrt(all_numbers);
        new_label = QString::number(all_numbers,'g',15);

        ui->result_show->setText(new_label);
    }
    else if (button->text() == "|x|")
    {
        all_numbers = (ui->result_show->text()).toDouble();
        all_numbers = abs(all_numbers);
        new_label = QString::number(all_numbers,'g',15);

        ui->result_show->setText(new_label);
    }
    else if (button->text() == "x^2")
    {
        all_numbers = (ui->result_show->text()).toDouble();
        all_numbers = pow(all_numbers,2);
        new_label = QString::number(all_numbers,'g',15);

        ui->result_show->setText(new_label);
    }
    else if (button->text() == "x^3")
    {
        all_numbers = (ui->result_show->text()).toDouble();
        all_numbers = pow(all_numbers,3);
        new_label = QString::number(all_numbers,'g',15);

        ui->result_show->setText(new_label);
    }
    else if (button->text() == "10^x")
    {
        all_numbers = (ui->result_show->text()).toDouble();
        all_numbers = pow(10,all_numbers);
        new_label = QString::number(all_numbers,'g',15);

        ui->result_show->setText(new_label);
    }
    else if (button->text() == "Log")
    {
        all_numbers = (ui->result_show->text()).toDouble();
        all_numbers = log10(all_numbers);
        new_label = QString::number(all_numbers,'g',15);

        ui->result_show->setText(new_label);
    }
    else if (button->text() == "Ln")
    {
        all_numbers = (ui->result_show->text()).toDouble();
        all_numbers = log(all_numbers);
        new_label = QString::number(all_numbers,'g',15);

        ui->result_show->setText(new_label);
    }
    else if (button->text() == "sin")
    {
        all_numbers = (ui->result_show->text()).toDouble();
        all_numbers = sin(all_numbers*M_PI/180);
        new_label = QString::number(all_numbers,'g',15);

        ui->result_show->setText(new_label);
    }
    else if (button->text() == "cos")
    {
        all_numbers = (ui->result_show->text()).toDouble();
        all_numbers = cos(all_numbers*M_PI/180);
        new_label = QString::number(all_numbers,'g',15);

        ui->result_show->setText(new_label);
    }
    else if (button->text() == "tg")
    {
        all_numbers = (ui->result_show->text()).toDouble();
        all_numbers = sin(all_numbers*M_PI/180)/cos(all_numbers*M_PI/180);
        new_label = QString::number(all_numbers,'g',15);

        ui->result_show->setText(new_label);
    }
    else if (button->text() == "ctg")
    {
        all_numbers = (ui->result_show->text()).toDouble();
        all_numbers = cos(all_numbers*M_PI/180)/sin(all_numbers*M_PI/180*M_PI/180);
        new_label = QString::number(all_numbers,'g',15);

        ui->result_show->setText(new_label);
    }
    else if (button->text() == "n!")
    {
        all_numbers = (ui->result_show->text()).toDouble();
        if (all_numbers == (int)all_numbers)
        {
            int res = 1;
            for (int i = 1; i <= (int)all_numbers; i++)
              res = res * i;
            new_label = QString::number(res,'g',15);
            ui->result_show->setText(new_label);
        }
        else ui->result_show->setText("error");
    }
}

void MainWindow::math_operations()
{
    QPushButton *button = (QPushButton *)sender();

    num_first = ui->result_show->text().toDouble();
    ui->result_show->setText("");
    button->setChecked(true);
}

void MainWindow::on_pushButton_AC_clicked()
{
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_mult->setChecked(false);
    ui->pushButton_del->setChecked(false);
    ui->pushButton_xy->setChecked(false);

    ui->result_show->setText("0");
}

void MainWindow::on_pushButton_equal_clicked()
{
    double lableNumber, num_second;
    QString new_label;

    num_second = ui->result_show->text().toDouble();

    if (ui->pushButton_plus->isChecked()) {
      lableNumber = num_first + num_second;
      new_label = QString::number(lableNumber,'g',15);
      ui->result_show->setText(new_label);
      ui->pushButton_plus->setChecked(false);

    } else if (ui->pushButton_minus->isChecked()) {
        lableNumber = num_first - num_second;
        new_label = QString::number(lableNumber,'g',15);
        ui->result_show->setText(new_label);
        ui->pushButton_minus->setChecked(false);

    } else if (ui->pushButton_mult->isChecked()){
        lableNumber = num_first * num_second;
        new_label = QString::number(lableNumber,'g',15);
        ui->result_show->setText(new_label);
        ui->pushButton_mult->setChecked(false);

    } else if (ui->pushButton_del->isChecked()){
        if (num_second == 0)
            ui->result_show->setText("error!");
        else
        {
        lableNumber = num_first / num_second;
        new_label = QString::number(lableNumber,'g',15);
        ui->result_show->setText(new_label);
        }
        ui->pushButton_del->setChecked(false);

    } else if (ui->pushButton_xy->isChecked()){
        lableNumber = pow(num_first,num_second);
        new_label = QString::number(lableNumber,'g',15);
        ui->result_show->setText(new_label);
        ui->pushButton_xy->setChecked(false);
    }
}
