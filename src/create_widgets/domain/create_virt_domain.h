#ifndef CREATE_VIRT_DOMAIN_H
#define CREATE_VIRT_DOMAIN_H

#include <QMainWindow>
#include <QMap>
#include <QSettings>
#include <QDir>
#include <QTemporaryFile>
#include <QTabWidget>
#include <QPushButton>
#include <QThread>
#include "domain_widgets.h"
#include "common_widgets/devices.h"
#include <QDebug>

class HelperThread : public QThread
{
    Q_OBJECT
public:
    explicit HelperThread(
            QObject     *parent = NULL,
            virConnect  *_conn  = NULL);
    void             run();
signals:
    void             result(QString&);
private:
    virConnect      *currWorkConnection = NULL;
};

typedef QMap<QString, _QWidget*> WidgetList;

class CreateVirtDomain : public QMainWindow
{
    Q_OBJECT
public:
    explicit CreateVirtDomain(
            QWidget *parent = NULL,
            TASK     _task  = TASK());
    ~CreateVirtDomain();

signals:
    void             errorMsg(QString&);
    void             readyRead(bool);
    void             finished(QString&);
    void             addNewTask(TASK);

private:
    QSettings        settings;
    virConnect      *currWorkConnection = NULL;
    QString          xmlFileName, xmlDesc;
    virErrorPtr      virtErrors;
    QString          capabilities;
    QString          type;
    QTabWidget      *tabWidget = NULL;
    QCheckBox       *showDescription;
    QLabel          *about;
    QPushButton     *ok;
    QPushButton     *restore;
    QPushButton     *cancel;
    QWidget         *buttons;
    QHBoxLayout     *buttonLayout;
    QVBoxLayout     *commonLayout;

    QTemporaryFile  *xml = NULL;
    WidgetList       wdgList;
    bool             ready = false;
    TASK             task;

    HelperThread    *helperThread;
    QWidget         *baseWdg = NULL;

public slots:
    void             closeEvent(QCloseEvent*);

private slots:
    void             setCapabilities(QString&);
    void             readCapabilities();
    void             readyDataLists();
    void             buildXMLDescription();
    void             set_Result();
    void             create_specified_widgets();
    void             set_specified_Tabs();
    void             restoreParameters();
    void             setBootOrder(QDomElement*);
    void             sendMsg(QString&);
};

#endif // CREATE_VIRT_DOMAIN_H
