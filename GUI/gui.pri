

QT          += widgets
HEADERS     += $$PWD/ErrorLabel/ErrorLabel.h \
               $$PWD/GetSnpFile/GetSnpFile.h \
               $$PWD/ListPanel/ListPanel.h \
               $$PWD/PortsLineEdit/PortsLineEdit.h \
               $$PWD/ConnectButton/ConnectButton.h \
               $$PWD/ConnectionTypeComboBox/ConnectionTypeComboBox.h \
               $$PWD/Wizard/Wizard.h \
               $$PWD/Wizard/WizardPage.h \
               $$PWD/Wizard/BreadCrumbs.h \
               $$PWD/Wizard/WizardButtons.h
INCLUDEPATH += $$PWD/ErrorLabel \
               $$PWD/GetSnpFile \
               $$PWD/ListPanel \
               $$PWD/PortsLineEdit \
               $$PWD/ConnectButton \
               $$PWD/ConnectionTypeComboBox \
               $$PWD/Wizard
SOURCES     += $$PWD/ErrorLabel/ErrorLabel.cpp \
               $$PWD/GetSnpFile/GetSnpFile.cpp \
               $$PWD/ListPanel/ListPanel.cpp \
               $$PWD/PortsLineEdit/PortsLineEdit.cpp \
               $$PWD/ConnectButton/ConnectButton.cpp \
               $$PWD/ConnectionTypeComboBox/ConnectionTypeComboBox.cpp \
               $$PWD/Wizard/Wizard.cpp \
               $$PWD/Wizard/WizardPage.cpp \
               $$PWD/Wizard/BreadCrumbs.cpp \
               $$PWD/Wizard/WizardButtons.cpp
FORMS       += $$PWD/GetSnpFile/GetSnpFile.ui \
               $$PWD/ListPanel/ListPanel.ui \
               $$PWD/Wizard/Wizard.ui \
               $$PWD/Wizard/BreadCrumbs.ui \
               $$PWD/Wizard/WizardButtons.ui
RESOURCES   += $$PWD/Wizard/WizardResources.qrc
