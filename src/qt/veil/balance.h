// Copyright (c) 2019 The Veil developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BALANCE_H
#define BALANCE_H

#include <interfaces/wallet.h>

#include <qt/veil/tooltipbalance.h>
#include <QWidget>
#include <QString>
#include <memory>

class ClientModel;
//class PlatformStyle;
class WalletModel;
class BitcoinGUI;


namespace Ui {
class Balance;
}

class Balance : public QWidget
{
    Q_OBJECT

public:
    explicit Balance(QWidget *parent = 0, BitcoinGUI *gui = 0);
    ~Balance();

    void setClientModel(ClientModel *clientModel);
    void setWalletModel(WalletModel *walletModel);
    void refreshWalletStatus();
    bool eventFilter(QObject *obj, QEvent *event);
    void setDisplayRcvAddress(CTxDestination *displayAddress);

public Q_SLOTS:
    void setBalance(const interfaces::WalletBalances& balances);
    void updateDisplayUnit();
    void onBtnBalanceClicked();
    void onBtnUnconfirmedClicked();
    void onBtnImmatureClicked();
    void onBtnCopyAddressClicked();

private:
    Ui::Balance *ui;
    BitcoinGUI* mainWindow;
    ClientModel *clientModel;
    WalletModel *walletModel;
    interfaces::WalletBalances m_balances;

    CPubKey newKey;
    QString qAddress;

    bool isWalletLocked = false;

    TooltipBalance *tooltip = nullptr;

    void onBtnBalanceClicked(int type);

    bool displayAddressSet = false;
    CTxDestination currentDisplayAddress;
};

#endif // BALANCE_H
