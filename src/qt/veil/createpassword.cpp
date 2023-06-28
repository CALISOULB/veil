// Copyright (c) 2019 The Veil developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <qt/veil/createpassword.h>
#include <qt/veil/forms/ui_createpassword.h>

CreatePassword::CreatePassword(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreatePassword)
{
    ui->setupUi(this);
    ui->editPassword->setAttribute(Qt::WA_MacShowFocusRect, 0);
    ui->editPasswordRepeat->setAttribute(Qt::WA_MacShowFocusRect, 0);


    // Error Message
    ui->errorMessage->setVisible(false);
}

QString CreatePassword::getPassword(){
    return ui->editPassword->text();
}

QString CreatePassword::getPasswordRepeat(){
    return ui->editPasswordRepeat->text();
}

bool CreatePassword::isValid(){
    QString text1 = ui->editPassword->text();
    QString text2 = ui->editPasswordRepeat->text();
    // TODO: Is empty password ok?
    bool pass1 =  true;//text1.size() > 0 || (!text1.isEmpty());
    bool pass2 = true; //text2.size() > 0 || (!text2.isEmpty());

    if(text1 != text2){
        pass2 = false;
    }

    if(!pass1 || !pass2){
        ui->errorMessage->setVisible(true);
        if(!pass1){
            ui->separatorPassword->setStyleSheet("background-color:#fd1337");
        }
        if(!pass2){
            ui->separatorPasswordRepeat->setStyleSheet("background-color:#fd1337");
        }
    }

    return pass1 && pass2;
}


CreatePassword::~CreatePassword()
{
    delete ui;
}
