#ifndef WIDGET_H
#define WIDGET_H

#include <QContextMenuEvent>
#include <QWidget>
#include <QMenu>
#include <QAction>


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void contextMenuEvent(QContextMenuEvent* event)override;

    //003初始化菜单
    void initMenu();

    //008菜单项的槽函数
    void slot_menu_1_openFile();
    void slot_menu_2_open();
    void slot_menu_3_newFile();
    void slot_menu_5_close();
    void slot_menu_4_new();
    void slot_menu_6_save();

private:
    Ui::Widget *ui;

    //001新建QMenu对象, 这个对象用来做菜单输出
    QMenu* m_Menu;

};
#endif // WIDGET_H
