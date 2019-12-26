#ifndef MAINNEEDHELP_H
#define MAINNEEDHELP_H


#include <QMainWindow>
#include <QObject>
#include <DWidget>
#include<QWidget>
#include<DMainWindow>
#include<DPushButton>
#include<QGridLayout>
#include<DLabel>
#include<DSuggestButton>
#include<QFont>
#include<QPixmap>
#include<QImage>
#include<QTimer>
#include<DSpinner>
#include<QTime>
#include<QDebug>
#include<QStackedWidget>
#include<DLineEdit>
#include<DSpinner>
#include<QClipboard>
#include<DTitlebar>
#include<QIcon>
#include<QString>
#include<DApplication>
#include<DTitlebar>
#include<QHBoxLayout>

DWIDGET_USE_NAMESPACE


class Mainneedhelp : public DWidget
{
    Q_OBJECT
public:
    Mainneedhelp(QWidget * parent = nullptr);
    ~Mainneedhelp(){}
private slots:
    void t_sendslot();
    void inittimer();
    void jump_tocopysuccessed();
signals:
    void mysignal();
    void sendsignalpram();
    void c_timer();
    void jump_copyok();
public:

private:

    QStackedWidget* create_stackwidget;

    QVBoxLayout *mainVLayout;

    QGridLayout* one_grind;
    QGridLayout* two_grind;
    QGridLayout* three_grind;
    //
    QWidget* one_widget;
    QWidget* two_widget;
    QWidget* three_widget;

    DLabel* s_text;
    DSuggestButton *m_suggestButton;

    QTime time;
    DSpinner* spinner;

    DLineEdit* show_verification;
    DLabel* show_number;
    DLabel* t_text;


    DLabel* show_text;
    DLabel* h_text;
    QClipboard *clipboard;

    QString *data;




private:
    QWidget *generateVarifyCodeWidget();
    QWidget *generatesuccessed();
    QWidget *copysuccessde();


public:
    QTimer* dw_timer;
    QString setValifyCode();
    QString getRandomNumber();

};
#endif // MAINNEEDHELP_H
