// Copyright (c) 2019 The Veil developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef RECEIVEWIDGET_H
#define RECEIVEWIDGET_H

#include <QWidget>
#include <interfaces/wallet.h>

class WalletModel;
class ClientModel;
class WalletView;

namespace Ui {
class ReceiveWidget;
}

class ReceiveWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ReceiveWidget(QWidget *parent = nullptr, WalletView *mainWindow = nullptr);
    ~ReceiveWidget();

    virtual void showEvent(QShowEvent *event) override;
    virtual void hideEvent(QHideEvent *event) override;
    void setWalletModel(WalletModel *model);
    void setDisplayRcvAddress(CTxDestination *displayAddress);

    void refreshWalletStatus();

public Q_SLOTS:
    void onBtnCopyAddressClicked();
    void generateNewAddressClicked();

private:
    Ui::ReceiveWidget *ui;
    ClientModel *clientModel;
    WalletModel *walletModel;
    WalletView *mainWindow;

    CPubKey newKey;
    QString qAddress;

    bool generateNewAddress(bool isOnDemand = false);

    bool displayAddressSet = false;
    CTxDestination currentDisplayAddress;
};

#endif // RECEIVEWIDGET_H
