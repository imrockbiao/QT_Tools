#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->setWindowTitle("显示右击窗口菜单");

    //002实例化菜单
    m_Menu = new QMenu(this);

    //004对菜单进行初始化
    initMenu();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::contextMenuEvent(QContextMenuEvent *event)
{
    Q_UNUSED(event)

    //007把菜单的事件循环加入
    m_Menu->exec(QCursor::pos());

}

void Widget::initMenu()
{
    //005菜单项初始化
    QAction *menu_1_openFile = new QAction("打开文件");
    QAction *menu_2_open = new QAction("打开");
    QAction *menu_3_newFile = new QAction("新建文件");
    QAction *menu_4_new = new QAction("新建");
    QAction *menu_5_close = new QAction("关闭");
    QAction *menu_6_save = new QAction("保存");

    //006把菜单项加入到菜单中
    m_Menu->addAction(menu_1_openFile);
    m_Menu->addAction(menu_2_open);
    m_Menu->addAction(menu_3_newFile);
    m_Menu->addAction(menu_4_new);
    m_Menu->addAction(menu_5_close);
    m_Menu->addAction(menu_6_save);

    //007连接菜单项对应的槽函数
    connect(menu_1_openFile, &QAction::triggered, this, &Widget::slot_menu_1_openFile);
    connect(menu_2_open, &QAction::triggered, this, &Widget::slot_menu_2_open);
    connect(menu_3_newFile, &QAction::triggered, this, &Widget::slot_menu_3_newFile);
    connect(menu_4_new, &QAction::triggered, this, &Widget::slot_menu_4_new);
    connect(menu_5_close, &QAction::triggered, this, &Widget::slot_menu_5_close);
    connect(menu_6_save, &QAction::triggered, this, &Widget::slot_menu_6_save);

}

void Widget::slot_menu_1_openFile()
{
    ui->label->setStyleSheet("background-color: #00FF00;");
    ui->label->setText("打开文件");
}

void Widget::slot_menu_2_open()
{
    ui->label->setStyleSheet("background-color: #FFFF00;");
    ui->label->setText("打开");
}

void Widget::slot_menu_3_newFile()
{
    ui->label->setStyleSheet("background-color: #00FFFF;");
    ui->label->setText("新建文件");
}

void Widget::slot_menu_5_close()
{
    ui->label->setStyleSheet("background-color: #FF0F0F;");
    ui->label->setText("关闭");
}

void Widget::slot_menu_4_new()
{
    ui->label->setStyleSheet("background-color: #BFDDD0;");
    ui->label->setText("新建");
}

void Widget::slot_menu_6_save()
{
    ui->label->setStyleSheet("background-color: #F0A055;");
    ui->label->setText("保存");
}

