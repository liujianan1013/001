#include "Mainhelpothers.h"


 Mainhelpothers::Mainhelpothers(QWidget* parent)
        :DWidget (parent)
    {
     mainVLayout = new QVBoxLayout;
     one_suggestButton = new DSuggestButton;
     one_suggestButton->setText(tr("cancel"));
     one_suggestButton->setFixedSize(135,35);

     create_stackwidget =new QStackedWidget();
     needinputnumber();
     linkwait();
     linkok();
     linkdefault();

     create_stackwidget->addWidget(two_widget);
     create_stackwidget->addWidget(one_widget);
     create_stackwidget->addWidget(three_widget);
     create_stackwidget->addWidget(four_widget);

     create_stackwidget->setCurrentWidget(two_widget);
     mainVLayout->addWidget(create_stackwidget);
     mainVLayout->addWidget(one_suggestButton, 0, Qt::AlignCenter);
     mainVLayout->setContentsMargins(0, 0, 0, 30);
     setLayout(mainVLayout);

    QString text1;

     connect(one_suggestButton,&DSuggestButton::pressed,this,&Mainhelpothers::td_sendslots);
     m_pTimer = new QTimer;
     connect(m_pTimer,SIGNAL(timeout()),this,SLOT(timeoutFunc()));
    }


 void Mainhelpothers::td_sendslots()
{
     if((one_suggestButton->text().compare("cancel") == 0) || (one_suggestButton->text().compare("disconnect") == 0 )|| (one_suggestButton->text().compare("back")) == 0){
         if(m_pTimer->isActive())
             m_pTimer->stop();
          show_number->setText("");
          one_suggestButton->setText("cancel");
          create_stackwidget->setCurrentWidget(two_widget);
           emit td_signal();

     }
     if((one_suggestButton->text().compare("tryagain") == 0))
     {
             show_number->setText("");
             one_suggestButton->setText("cancel");
             create_stackwidget->setCurrentWidget(two_widget);
     }
    if(one_suggestButton->text().compare("link") == 0)
    {
        one_suggestButton->setText("cancel");
        if(inputCode.compare(m_valifyCode) == 0)
        {
            m_pTimer->start(3000);
            create_stackwidget->setCurrentWidget(one_widget);
            one_suggestButton->setText("back");
        }
        else {
           one_suggestButton->setText(tr("tryagain"));
            create_stackwidget->setCurrentWidget(four_widget);
        }
    }
 }

 QWidget *Mainhelpothers::needinputnumber()
 {
     two_widget = new QWidget;
     two_grind = new QGridLayout(this);
     show_number = new QLineEdit(this);
     show_number->setFixedSize(300,100);

     show_number->setAlignment( Qt::AlignHCenter);;
     QRegExp rx("[0-9]{6}");
     show_number->setValidator(new QRegExpValidator(rx, this));
     show_number->setFixedSize(330,70);
     QFont ft1;
     ft1.setPointSize(24);
     ft1.setLetterSpacing(QFont::AbsoluteSpacing,18);
     show_number->setFont(ft1);
     connect(show_number,&QLineEdit::textChanged,[=](const QString &text){
         if(text.size() == 6)
         {
             inputCode=text;qDebug()<<text;
             one_suggestButton->setText("link");
         }
         });
     t_text = new DLabel;
     QString sstr = "In the above input you want to help people give you authentication code, \n"
                    "after the completion of the click on the links to assist each other\n";
     QFont o_font;
     o_font.setPointSize(7);
     t_text->setAlignment(Qt::AlignCenter);
     t_text->setFont(o_font);
     t_text->setText(sstr);
     t_text->setEnabled(false);
     two_grind->addWidget(show_number,0,0,1,1,Qt::AlignCenter);
     two_grind->addWidget(t_text,1,0,1,1,Qt::AlignCenter);
     two_widget->setLayout(two_grind);
     return two_widget;
 }

 QWidget *Mainhelpothers::linkwait()
 {
     one_widget = new QWidget;
     one_grind = new QGridLayout(this);
     s_text = new DLabel;
     spinner = new DSpinner(this);
     spinner->setFixedSize(32,32);
     spinner->start();
     s_text = new DLabel;
     QString str = "linking.......\n "
                   "please later...";
     s_text->setText(str);
     s_text->setAlignment(Qt::AlignCenter);
     s_text->setEnabled(false);
     QFont font;
     font.setPointSize(9);
     s_text->setFont(font);
     one_grind->addWidget(spinner,0,0,1,1,Qt::AlignCenter);
     one_grind->addWidget(s_text,1,0,1,1,Qt::AlignCenter);
     one_widget->setLayout(one_grind);
     return one_widget;
 }

 QWidget *Mainhelpothers::linkok()
 {
     three_widget = new QWidget;
     three_grind = new QGridLayout(this);
     show_text = new DLabel;
     h_text = new DLabel;
     show_text->setText(tr("You are for remote assistance"));
     show_text->setAlignment(Qt::AlignCenter);
     show_text->setEnabled(false);
     QFont ft1;
     ft1.setPointSize(15);
     show_text->setFont(ft1);
     show_text->setFixedSize(300,100);
     QString ssstr = "Currently there is a connection session\n"
                     "If you want to create a new connection, please disconnect";
     h_text->setText(ssstr);
     h_text->setAlignment(Qt::AlignCenter);
     h_text->setEnabled(false);
     QFont h_font;
     h_font.setPointSize(9);
     h_text->setFont(h_font);

     three_grind->addWidget(show_text,0,0,1,1,Qt::AlignCenter);
     three_grind->addWidget(h_text,1,0,1,1,Qt::AlignCenter);
     three_widget->setLayout(three_grind);
     return three_widget;
 }

 QWidget *Mainhelpothers::linkdefault()
 {
     four_widget = new QWidget;
          four_grind = new QGridLayout(this);
          linkshow = new DLabel;
          linktext = new DLabel;
          linkshow->setText(tr("The connection fails"));
          linkshow->setAlignment(Qt::AlignCenter);
          linkshow->setEnabled(false);
          QFont ft1;
          ft1.setPointSize(24);
          linkshow->setFont(ft1);
          linkshow->setFixedSize(300,100);
          QString str = "Network connection state is not very stable"
                        "Click the retry button to try to connect again";
          linktext->setText(str);
          linktext->setAlignment(Qt::AlignCenter);
          linktext->setEnabled(false);
          QFont h_font;
          h_font.setPointSize(9);
          linktext->setFont(h_font);
          four_grind->addWidget(linkshow,0,0,1,1,Qt::AlignCenter);
          four_grind->addWidget(linktext,1,0,1,1,Qt::AlignCenter);
          four_widget->setLayout(four_grind);
          return four_widget;
 }


 void Mainhelpothers::inittimer()
 {
         int nCount = create_stackwidget->count();
         int nIndex = create_stackwidget->currentIndex();
             ++nIndex;
         if (nIndex >= nCount)
           nIndex = 0;
         create_stackwidget->setCurrentIndex(nIndex);
        if(dw_timer->isActive())
             dw_timer->stop();

 }

 void Mainhelpothers::jump_tocopysuccessed()
 {
     if(one_suggestButton->text().compare(QString::fromLocal8Bit("copy") ) == 0)
     {
         int nCount = create_stackwidget->count();
         int nIndex = create_stackwidget->currentIndex();
             ++nIndex;
         if (nIndex >= nCount)
           nIndex = 0;
         create_stackwidget->setCurrentIndex(nIndex);
         if(dw_timer->isActive())
             dw_timer->stop();
         connect(one_suggestButton, &DSuggestButton::pressed, this, &Mainhelpothers::td_sendslots);
     }
 }

 void Mainhelpothers::getinputnumber()
 {}

 void Mainhelpothers::numberbattle()
 {}

 void Mainhelpothers::inputokconnect()
 {}

 void Mainhelpothers::timeoutFunc()
 {
     if(inputCode.compare(m_valifyCode) == 0)
     create_stackwidget->setCurrentWidget(three_widget);
     else {
          create_stackwidget->setCurrentWidget(four_widget);
     }
          if(m_pTimer->isActive())
         m_pTimer->stop();
 }

 void Mainhelpothers::getValifyCode(QString strValifyCode)
 {
    m_valifyCode = strValifyCode;
 }







