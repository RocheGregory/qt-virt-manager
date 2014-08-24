#ifndef PCI_ADDR_H
#define PCI_ADDR_H

#include "_addr.h"
#include <QSpinBox>

class PciAddr : public _Addr
{
    Q_OBJECT
public:
    explicit PciAddr(QWidget *parent = 0);

private:
    QLabel          *domainLabel;
    QLabel          *busLabel;
    QLabel          *slotLabel;
    QLabel          *functLabel;
    QLineEdit       *domain;
    QLineEdit       *bus;
    QLineEdit       *slot;
    QSpinBox        *function;
    QGridLayout     *commonlayout;

public slots:
    AttrList getAttrList() const;
};

#endif // PCI_ADDR_H