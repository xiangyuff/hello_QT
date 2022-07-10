#ifndef CREDITSEXCHANGE_H
#define CREDITSEXCHANGE_H

#include <QWidget>
#include<QFile>
#include<QSoundEffect>
#include "picwid.h"

#include"interface.h"
#include"todolist.h"

#if defined(_MSC_VER) && (_MSC_VER >= 1600)
# pragma execution_character_set("utf-8")
#endif

class CreditsExchange : public QWidget
{
    Q_OBJECT

public:
    CreditsExchange(QWidget *parent = nullptr);
    ~CreditsExchange();
private:
    static QFile usedCredit_File;
    void paintEvent (QPaintEvent *);
    void showPicMusic();
    void initpic();
    PicWid* WidgetsPointer[12];

    QSoundEffect * startSound;
    void playsound(int ran);
public slots:
    void exchange_click();
    void stopmusic();
};
#endif // CREDITSEXCHANGE_H
