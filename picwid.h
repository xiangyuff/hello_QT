#ifndef PICWID_H
#define PICWID_H

#include <QWidget>

class PicWid : public QWidget
{
    Q_OBJECT
public:
    explicit PicWid(const QString picAddress,QWidget *parent = nullptr);
    explicit PicWid(QWidget *parent = nullptr);
    void playsound();
    void stopsound();
private:
    const QString picAd;
    void paintEvent (QPaintEvent *);

signals:

};

#endif // PICWID_H
