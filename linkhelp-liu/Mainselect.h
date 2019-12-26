#ifndef MAINSELECT_H
#define MAINSELECT_H
#include"Mainneedhelp.h"
#include"Mainhelpothers.h"

#include <DMainWindow>
#include<DApplication>
#include <QObject>
#include <QWidget>
#include<DLineEdit>
#include<DPushButton>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QDebug>
#include<DLabel>
#include<DToolButton>
#include <QStackedWidget>
#include<QStackedWidget>
#include<QTimer>
#include<QString>
#include<DApplication>
#include<DTitlebar>
#include<QSpacerItem>

DWIDGET_USE_NAMESPACE

class Mainselect : public DMainWindow
{
    Q_OBJECT
public:
    Mainselect(QWidget * parent = nullptr);
    ~Mainselect(){}
private slots:
    void retuen_main();
    void send_needhelpslots();
    void return_demotwo();
    void setheadtitle(const QString &Lefticon,const QString &Righticon);

signals:
    void mainslots();
    void t_slots();
private:
    QStackedWidget* m_stackcontrol;
    QGridLayout* grind;
    DToolButton* b_needhelp;
    DToolButton* b_hellpothers;
    DLineEdit* line1;
    DLabel *headpicture;
    DLabel *readtext;
    QImage* img;
    QWidget* widget;
    Mainneedhelp* m_needhelp;
    Mainhelpothers* h_others;
    QTimer* timer;

    QImage *image;
    DTitlebar *tit;
    DWidget *headtitle;
    DLabel * lefticon;
    DLabel * righticon;

};



#endif // MAINSELECT_H
