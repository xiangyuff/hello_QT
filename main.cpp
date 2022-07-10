#include"mainwidget.h"
#include <QApplication>
#include "dataclass.h"
#include "dataclasswidget.h"
#include "creditswidget.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
 //   welcome_Widget w;
 //   to_do_widget w_2;
    mainWidget *w = new mainWidget;
    //DataClass *w = new DataClass;
  //  mainWidget w;
   // dataClassWidget * w = new dataClassWidget;
   //w->show();
 //   w->deleteLater();
    w->setAttribute(Qt::WA_DeleteOnClose);
  //  creditsWidget *w = new creditsWidget;
        w->show();

    return a.exec();
}
