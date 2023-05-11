QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adminpage.cpp \
    adminwelcome.cpp \
    course.cpp \
    data.cpp \
    editCourse.cpp \
    debuging.cpp \
    frame.cpp \
    framewelcome.cpp \
    main.cpp \
    loginpage.cpp \
    newcourse.cpp \
    newstudent.cpp \
    registerform.cpp \
    student.cpp \
    studentpage.cpp \
    viewcourses.cpp \
    viewstudent.cpp \
    adminviewcourse.cpp

HEADERS += \
    adminpage.h \
    adminwelcome.h \
    course.h \
    data.h \
    editCourse.h \
    debuging.h \
    frame.h \
    framewelcome.h \
    loginpage.h \
    newcourse.h \
    newstudent.h \
    registerform.h \
    student.h \
    studentpage.h \
    viewcourses.h \
    viewstudent.h \
    adminviewcourse.h

FORMS += \
    adminpage.ui \
    adminwelcome.ui \
    editcourse.ui \
    debuging.ui \
    frame.ui \
    framewelcome.ui \
    loginpage.ui \
    newcourse.ui \
    newstudent.ui \
    registerform.ui \
    studentpage.ui \
    viewcourses.ui \
    viewstudent.ui \
    adminviewcourse.ui
TRANSLATIONS += \
    Qt_en_GB.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=
