QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    controllers/manager_controller.cpp \
    controllers/specialist_controller.cpp \
    controllers/user_controller.cpp \
    database.cpp \
    entities/bank.cpp \
    entities/bank_account.cpp \
    entities/company.cpp \
    entities/credit.cpp \
    entities/credit_request.cpp \
    entities/deposit.cpp \
    entities/join_salary_project_request.cpp \
    entities/salary_project.cpp \
    entities/salary_project_request.cpp \
    entities/sign_up_request.cpp \
    entities/transfer.cpp \
    entities/user.cpp \
    interface/deposit_credit_menu.cpp \
    interface/log_in_menu.cpp \
    interface/mainwindow.cpp \
    interface/manager_menu.cpp \
    interface/manager_salary_project.cpp \
    interface/operator_menu.cpp \
    interface/sign_up_menu.cpp \
    interface/specialist_menu.cpp \
    interface/user_menu.cpp \
    interface/user_salary_project_menu.cpp \
    main.cpp \
    parser.cpp

HEADERS += \
    controllers/manager_controller.h \
    controllers/specialist_controller.h \
    controllers/user_controller.h \
    database.h \
    entities/bank.h \
    entities/bank_account.h \
    entities/company.h \
    entities/credit.h \
    entities/credit_request.h \
    entities/deposit.h \
    entities/join_salary_project_request.h \
    entities/salary_project.h \
    entities/salary_project_request.h \
    entities/sign_up_request.h \
    entities/transfer.h \
    entities/user.h \
    interface/deposit_credit_menu.h \
    interface/log_in_menu.h \
    interface/mainwindow.h \
    interface/manager_menu.h \
    interface/manager_salary_project.h \
    interface/operator_menu.h \
    interface/sign_up_menu.h \
    interface/specialist_menu.h \
    interface/user_menu.h \
    interface/user_salary_project_menu.h \
    parser.h

FORMS += \
    interface/deposit_credit_menu.ui \
    interface/log_in_menu.ui \
    interface/mainwindow.ui \
    interface/manager_menu.ui \
    interface/manager_salary_project.ui \
    interface/operator_menu.ui \
    interface/sign_up_menu.ui \
    interface/specialist_menu.ui \
    interface/user_menu.ui \
    interface/user_salary_project_menu.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
