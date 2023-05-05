QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admin.cpp \
    adminpage.cpp \
    course.cpp \
    main.cpp \
    loginpage.cpp \
    student.cpp \
    studentpage.cpp \
    user.cpp

HEADERS += \
    admin.h \
    adminpage.h \
    course.h \
    loginpage.h \
    student.h \
    studentpage.h \
    user.h

FORMS += \
    adminpage.ui \
    loginpage.ui \
    studentpage.ui

TRANSLATIONS += \
    Qt_en_GB.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Courses.txt
