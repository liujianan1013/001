#ifndef MAINHELPOTHERS_H
#define MAINHELPOTHERS_H
#include<QPalette>
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
#include<QString>
#include<DApplication>
DWIDGET_USE_NAMESPACE
#include <QLineEdit>
class Mainhelpothers : public DWidget
{
    Q_OBJECT
public:
    Mainhelpothers(QWidget* parent = nullptr );
    ~Mainhelpothers(){}
private slots:
    void td_sendslots();
    void inittimer();
    void jump_tocopysuccessed();
    void getinputnumber();
    void numberbattle();
    void inputokconnect();

    void timeoutFunc();

signals:
    void td_signal();

private:

    QStackedWidget* create_stackwidget;
    QVBoxLayout *mainVLayout;
    DSuggestButton *one_suggestButton;

    QWidget* one_widget;
    QWidget* two_widget;
    QWidget* three_widget;
    QWidget* four_widget;

    QGridLayout* two_grind;
    QGridLayout* one_grind;
    QGridLayout* three_grind;
    QGridLayout* four_grind;

    DSpinner* spinner;
    DLabel* s_data;
    DLabel* s_text;
    QTimer* dw_timer;
    QTime time;

    QTimer *m_pTimer;


    QLineEdit* show_number;
    DLabel* t_text;

    DLabel* show_text;
    DLabel* h_text;
    QClipboard *clipboard;

    DLabel* linkshow;
    DLabel* linktext;
    QString inputCode;


private:
    QWidget *needinputnumber();
    QWidget *linkwait();
    QWidget *linkok();
    QWidget* linkdefault();

public:
    void getValifyCode( QString strValifyCode);
private:
    QString m_valifyCode;

};
#endif // MAINHELPOTHERS_H
