QT       += core gui
QT       += multimedia
QT       += charts
RC_ICONS = icon.ico

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    creditsexchange.cpp \
    creditswidget.cpp \
    dailyclockin.cpp \
    dataclass.cpp \
    dataclasswidget.cpp \
    dayclockin.cpp \
    encouragement.cpp \
    interface.cpp \
    main.cpp \
    mainwidget.cpp \
    mypushbutton.cpp \
    picwid.cpp \
    provide_eyes.cpp \
    qcustomcalendarwidget.cpp \
    to_do_widget.cpp \
    todolist.cpp \
    tomatoclock.cpp \
    welcome_widget.cpp

HEADERS += \
    creditsexchange.h \
    creditswidget.h \
    dailyclockin.h \
    dataclass.h \
    dataclasswidget.h \
    dayclockin.h \
    encouragement.h \
    interface.h \
    mainwidget.h \
    mypushbutton.h \
    picwid.h \
    provide_eyes.h \
    qcustomcalendarwidget.h \
    to_do_widget.h \
    todolist.h \
    tomatoclock.h \
    welcome_widget.h

FORMS += \
    dataclass.ui \
    dataclasswidget.ui \
    dayclockin.ui \
    mainwidget.ui \
    to_do_widget.ui \
    welcome_widget.ui \


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
