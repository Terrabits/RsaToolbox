

QT          += core gui widgets
HEADERS     += $$PWD/About/About.h \
               $$PWD/ConnectButton/ConnectButton.h \
               $$PWD/ConnectionTypeComboBox/ConnectionTypeComboBox.h \
               $$PWD/DecibelEdit/DecibelEdit.h \
               $$PWD/DoubleEdit/DoubleEdit.h \
               $$PWD/ErrorLabel/ErrorLabel.h \
               $$PWD/FrequencyEdit/FrequencyEdit.h \
               $$PWD/getSaveFileNameWidget/getSaveFileNameWidget.h \
               $$PWD/GetSnpFile/GetSnpFile.h \
               $$PWD/LastPath/LastPath.h \
               $$PWD/ListPanel/ListPanel.h \
               $$PWD/PointsEdit/PointsEdit.h \
               $$PWD/PortsLineEdit/PortsLineEdit.h \
               $$PWD/PowerEdit/PowerEdit.h \
               $$PWD/TimedProgressBar/TimedProgressBar.h \
               $$PWD/Update/Update.h \
               $$PWD/Wizard/Wizard.h \
               $$PWD/Wizard/WizardPage.h \
               $$PWD/Wizard/BreadCrumbs.h \
               $$PWD/Wizard/WizardButtons.h \
               $$PWD/Shake.h
INCLUDEPATH += $$PWD/ \
               $$PWD/About \
               $$PWD/ConnectButton \
               $$PWD/ConnectionTypeComboBox \
               $$PWD/DecibelEdit \
               $$PWD/DoubleEdit \
               $$PWD/ErrorLabel \
               $$PWD/FrequencyEdit \
               $$PWD/getSaveFileNameWidget \
               $$PWD/GetSnpFile \
               $$PWD/LastPath \
               $$PWD/ListPanel \
               $$PWD/PointsEdit \
               $$PWD/PortsLineEdit \
               $$PWD/PowerEdit \
               $$PWD/TimedProgressBar \
               $$PWD/Update \
               $$PWD/Wizard
SOURCES     += $$PWD/About/About.cpp \
               $$PWD/ConnectButton/ConnectButton.cpp \
               $$PWD/ConnectionTypeComboBox/ConnectionTypeComboBox.cpp \
               $$PWD/DecibelEdit/DecibelEdit.cpp \
               $$PWD/DoubleEdit/DoubleEdit.cpp \
               $$PWD/ErrorLabel/ErrorLabel.cpp \
               $$PWD/FrequencyEdit/FrequencyEdit.cpp \
               $$PWD/getSaveFileNameWidget/getSaveFileNameWidget.cpp \
               $$PWD/GetSnpFile/GetSnpFile.cpp \
               $$PWD/LastPath/LastPath.cpp \
               $$PWD/ListPanel/ListPanel.cpp \
               $$PWD/PointsEdit/PointsEdit.cpp \
               $$PWD/PortsLineEdit/PortsLineEdit.cpp \
               $$PWD/PowerEdit/PowerEdit.cpp \
               $$PWD/TimedProgressBar/TimedProgressBar.cpp \
               $$PWD/Update/Update.cpp \
               $$PWD/Wizard/Wizard.cpp \
               $$PWD/Wizard/WizardPage.cpp \
               $$PWD/Wizard/BreadCrumbs.cpp \
               $$PWD/Wizard/WizardButtons.cpp \
               $$PWD/Shake.cpp
FORMS       += $$PWD/About/About.ui \
               $$PWD/getSaveFileNameWidget/getSaveFileNameWidget.ui \
               $$PWD/GetSnpFile/GetSnpFile.ui \
               $$PWD/ListPanel/ListPanel.ui \
               $$PWD/TimedProgressBar/TimedProgressBar.ui \
               $$PWD/Update/Update.ui \
               $$PWD/Wizard/Wizard.ui \
               $$PWD/Wizard/BreadCrumbs.ui \
               $$PWD/Wizard/WizardButtons.ui
RESOURCES   += $$PWD/About/AboutResources.qrc \
               $$PWD/Wizard/WizardResources.qrc
