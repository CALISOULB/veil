// Copyright (c) 2019 The Veil developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <qt/veil/sendcontroldialog.h>
#include <qt/veil/forms/ui_sendcontroldialog.h>

SendControlDialog::SendControlDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SendControlDialog)
{
    ui->setupUi(this);
    connect(ui->btnEsc,SIGNAL(clicked()),this, SLOT(onEscapeClicked()));
    connect(ui->btnCancel,SIGNAL(clicked()),this, SLOT(onEscapeClicked()));

    ui->labelTitle->setProperty("cssClass" , "title-dialog");
    ui->btnSave->setProperty("cssClass" , "btn-text-primary");
    ui->btnCancel->setProperty("cssClass" , "btn-text-primary-inactive");
}

void SendControlDialog::onEscapeClicked(){
    close();
}

SendControlDialog::~SendControlDialog()
{
    delete ui;
}
