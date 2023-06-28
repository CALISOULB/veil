// Copyright (c) 2019 The Veil developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef ADDRESSRECEIVE_H
#define ADDRESSRECEIVE_H

#include <QWidget>
#include <QDialog>
#include <interfaces/wallet.h>

// TODO: Save address label.

class WalletModel;

namespace Ui {
class AddressReceive;
}

class AddressReceive : public QDialog
{
    Q_OBJECT

public:
    explicit AddressReceive(QWidget *parent = nullptr, WalletModel* _walletModel = nullptr, bool isMinerAddress = false);
    ~AddressReceive();
private Q_SLOTS:
    void onEscapeClicked();
    void onBtnCopyAddressClicked();
    void onBtnSaveClicked();
private:
    Ui::AddressReceive *ui;
    WalletModel *walletModel;
    bool isMiner;

    CPubKey newKey;
    QString qAddress;
    CTxDestination dest;

    void generateNewAddress(bool isMinerAddress);
};

#endif // ADDRESSRECEIVE_H
