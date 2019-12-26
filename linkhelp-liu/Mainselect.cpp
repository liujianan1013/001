#include "Mainselect.h"
#include<QString>
#include<DApplication>


#define TIME (2*1000)

Mainselect::Mainselect(QWidget *parent)
    :DMainWindow(parent)
{
    m_stackcontrol =new QStackedWidget();
    widget = new QWidget;
    m_needhelp = new Mainneedhelp;
    h_others = new Mainhelpothers;
    m_stackcontrol->addWidget(widget);
    m_stackcontrol->addWidget(m_needhelp);
    m_stackcontrol->addWidget(h_others);
    grind = new QGridLayout(this);
    headpicture = new DLabel;
    img = new QImage;
    img->load(":/images/test1.svg");
    headpicture->setPixmap(QPixmap::fromImage(*img));
    headpicture->setScaledContents(true);
    headpicture->setFixedSize(100,100);
    readtext = new DLabel;
    QString str = "\nThis is the deepin remote assistance application of team development.\n"
                  "If you have difficulties in the process of use, or someone turn to you,\n"
                  "please click below I want to ask for help or help others";
    readtext->setText(str);
    readtext->setAlignment(Qt::AlignCenter);
    readtext->setEnabled(false);
    QFont font;
    font.setPointSize(7);
    readtext->setFont(font);
    b_needhelp = new DToolButton(this);
    b_needhelp->setFixedSize(130,35);
    b_needhelp->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    b_needhelp->setText(tr("i need help"));
    b_needhelp->setIcon(QPixmap(":/images/test3.svg"));
    b_hellpothers = new DToolButton(this);
    b_hellpothers->setFixedSize(130,35);
    b_hellpothers->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    b_hellpothers->setText(tr("help others"));
    b_hellpothers->setIcon(QPixmap(":/images/test2.svg"));
    grind->addWidget(headpicture,0,0,Qt::AlignCenter);
    grind->addWidget(readtext,1,0,1,1,Qt::AlignCenter);
    grind->addWidget(b_needhelp, 2, 0, 1, 1,Qt::AlignCenter);
    grind->addWidget(b_hellpothers, 3, 0, 1, 1,Qt::AlignCenter);
    widget->setLayout(grind);
    grind->setSpacing(15);
    setCentralWidget(m_stackcontrol);

    connect(b_needhelp,&DToolButton::pressed,this,&Mainselect::send_needhelpslots);
    connect(b_hellpothers,&DToolButton::pressed,this,&Mainselect::return_demotwo);
    connect(m_needhelp,&Mainneedhelp::sendsignalpram,this,&Mainselect::retuen_main);
    connect(h_others,&Mainhelpothers::td_signal,this,&Mainselect::retuen_main);
    connect(m_needhelp,&Mainneedhelp::c_timer,this,&Mainselect::retuen_main);
}

void Mainselect::retuen_main()
{
    m_stackcontrol->setCurrentWidget(widget);
}

void Mainselect::send_needhelpslots()
{
    setheadtitle(":/images/test3.svg",tr("need help"));
    m_stackcontrol->setCurrentWidget(m_needhelp);
    m_needhelp->dw_timer->start(TIME);

}

void Mainselect::return_demotwo()
{
    setheadtitle(":/images/test2.svg",tr("help others"));
    m_stackcontrol->setCurrentWidget(h_others);
    //add by
    h_others->getValifyCode(m_needhelp->setValifyCode());
}


void Mainselect::setheadtitle(const QString &Lefticon, const QString &Righticon)
{
    tit = this->titlebar();
    image = new QImage;
    lefticon = new DLabel(this);
    lefticon->setPixmap(QPixmap::fromImage(*image));
    lefticon->setScaledContents(true);
    lefticon->setFixedSize(18,18);
    righticon = new DLabel(this);
    QHBoxLayout* mylayout = new QHBoxLayout();
    mylayout->addSpacing(250);
    mylayout->addWidget(lefticon,0,Qt::AlignCenter);
    mylayout->addWidget(righticon,0,Qt::AlignCenter);
    headtitle = new DWidget(this);
    headtitle->setLayout(mylayout);
    tit->setCustomWidget(headtitle);
    lefticon->setPixmap(QPixmap(Lefticon));
    righticon->setText(Righticon);
}
