#include "Mainneedhelp.h"

Mainneedhelp::Mainneedhelp(QWidget *parent)
   :DWidget(parent)
{
    mainVLayout = new QVBoxLayout;
    m_suggestButton = new DSuggestButton;
    m_suggestButton->setFixedSize(135,35);
    create_stackwidget =new QStackedWidget();
    generateVarifyCodeWidget();
    generatesuccessed();
    copysuccessde();
    create_stackwidget->addWidget(one_widget);
    create_stackwidget->addWidget(two_widget);
    create_stackwidget->addWidget(three_widget);

    create_stackwidget->setCurrentWidget(one_widget);
    mainVLayout->addWidget(create_stackwidget);
    mainVLayout->addWidget(m_suggestButton, 0, Qt::AlignCenter);
    mainVLayout->setContentsMargins(0, 0, 0, 30);
    setLayout(mainVLayout);
    mainVLayout->setSpacing(30);

    connect(m_suggestButton,&DSuggestButton::clicked,this,&Mainneedhelp::t_sendslot);
    dw_timer = new QTimer(this);
     connect(dw_timer,&QTimer::timeout,this,
             [=]() {
         if(dw_timer->isActive())
             dw_timer->stop();
         m_suggestButton->setText(tr("copy"));
         create_stackwidget->setCurrentWidget(two_widget);
         QString str = getRandomNumber();
         qDebug()<<"****************"<<str;
         show_number->setText(str);

     });
}


QWidget *Mainneedhelp::generateVarifyCodeWidget()
{
    one_widget = new QWidget;
    one_grind = new QGridLayout(this);
    s_text = new DLabel;
    spinner = new DSpinner(this);
    spinner->setFixedSize(32,32);
    spinner->start();
    s_text = new DLabel;
    QString str = "is requesting authentication code.......\n please later...";
    s_text->setText(str);
    s_text->setAlignment(Qt::AlignCenter);
    s_text->setEnabled(false);
    QFont font;
    font.setPointSize(9);
    s_text->setFont(font);
    m_suggestButton->setText(tr("cancel"));
    one_grind->addWidget(spinner,0,0,1,1,Qt::AlignCenter);
    one_grind->addWidget(s_text,1,0,1,1,Qt::AlignCenter);
    one_widget->setLayout(one_grind);
    return one_widget;
}

QWidget *Mainneedhelp::generatesuccessed()
{
    two_widget = new QWidget;
    two_grind = new QGridLayout(this);
    show_number = new DLabel;
    t_text = new DLabel;
    show_number->setFixedSize(300,100);
    QString sstr = "to start sharing your desktop,please be sure to provide the able\n"
                    "verification code to be help your staff,they enter the authentication code\n"
                    "your shared session verfication code verfication code will be started immediately\n";
    QFont o_font;
    o_font.setPointSize(7);
    t_text->setFont(o_font);
    t_text->setText(sstr);
    t_text->setAlignment(Qt::AlignCenter);
    t_text->setEnabled(false);
    show_number->setAlignment(Qt::AlignCenter);
    show_number->setEnabled(false);
    QFont ft1;
    ft1.setPointSize(24);
    ft1.setLetterSpacing(QFont::AbsoluteSpacing,18);
    show_number->setFont(ft1);
    two_grind->addWidget(show_number,0,0,1,1,Qt::AlignCenter);
    two_grind->addWidget(t_text,1,0,1,1,Qt::AlignCenter);
    two_widget->setLayout(two_grind);
    return two_widget;
}

QWidget *Mainneedhelp::copysuccessde()
{
    three_widget = new QWidget;
    three_grind = new QGridLayout(this);
    show_text = new DLabel;
    h_text = new DLabel;
    show_text->setAlignment(Qt::AlignCenter);
    show_text->setEnabled(false);
    show_text->setFixedSize(300,100);
    QString ssstr = "link.....\n"
                    "please  wait ";
    h_text->setText(ssstr);
    h_text->setAlignment(Qt::AlignCenter);
    h_text->setEnabled(false);
    QFont h_font;
    h_font.setPointSize(9);
    h_text->setFont(h_font);
    QFont ft1;
    ft1.setPointSize(24);
    show_text->setFont(ft1);
    show_text->setText(tr("copy successed"));
    three_grind->addWidget(show_text,0,0,1,1,Qt::AlignCenter);
    three_grind->addWidget(h_text,1,0,1,1,Qt::AlignCenter);
    three_widget->setLayout(three_grind);
    return three_widget;
}


void Mainneedhelp::t_sendslot()
{
     if((m_suggestButton->text().compare("back") == 0) || (m_suggestButton->text().compare("cancel") == 0))
     {
          create_stackwidget->setCurrentWidget(one_widget);
           emit sendsignalpram();
     }
    if(m_suggestButton->text().compare("copy") == 0)
    {
        connect(m_suggestButton,&DSuggestButton::clicked,[=](){
        QClipboard *board = QApplication::clipboard();
        board->setText(show_number->text());
                });
        m_suggestButton->setText("back");
        create_stackwidget->setCurrentWidget(three_widget);
    }
}

void Mainneedhelp::inittimer()
{
        m_suggestButton->setText(tr("copy"));
        int nCount = create_stackwidget->count();
        int nIndex = create_stackwidget->currentIndex();
            // 获取下一个需要显示的页面索引
            ++nIndex;
            // 当需要显示的页面索引大于等于总页面时，切换至首页
        if (nIndex >= nCount)
          nIndex = 0;
          ;
        create_stackwidget->setCurrentIndex(nIndex);
        if(dw_timer->isActive())
            dw_timer->stop();
}

void Mainneedhelp::jump_tocopysuccessed()
{
    if(m_suggestButton->text().compare(QString::fromLocal8Bit("copy") ) == 0)
    {
        int nCount = create_stackwidget->count();
        int nIndex = create_stackwidget->currentIndex();
            ++nIndex;
        if (nIndex >= nCount)
          nIndex = 0;
        create_stackwidget->setCurrentIndex(nIndex);
        connect(m_suggestButton, &DSuggestButton::pressed, this, &Mainneedhelp::t_sendslot);
    }
}



QString Mainneedhelp::setValifyCode()
{
    return show_number->text();
}

QString Mainneedhelp::getRandomNumber()
{
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime())); //设置随机数种子
    int rand = qrand() % 900000 + 100000;             //产生十以内的随机数(0-9)
    return QString::number(rand);
}

