#include "userface.h"

UserFace::UserFace(QWidget *parent) : QDialog(parent) {
  layout = new QGridLayout(this);
  btnScreen = new QPushButton("Screen", this);
  layout->addWidget(btnScreen, 1, 1);
  cmbScreen = new QComboBox(this);
  layout->addWidget(cmbScreen, 1, 2);
  lblResolution = new QLabel("Resolution", this);
  layout->addWidget(lblResolution, 2, 1);
  cmbResolution = new QComboBox(this);
  layout->addWidget(cmbResolution, 2, 2);
  lblSensitivity = new QLabel("Sensitivity", this);
  layout->addWidget(lblSensitivity, 3, 1);
  edtSensitivity = new QLineEdit(this);
  layout->addWidget(edtSensitivity, 3, 2);
  lblResilience = new QLabel("Resilience", this);
  layout->addWidget(lblResilience, 4, 1);
  edtResilience = new QLineEdit(this);
  layout->addWidget(edtResilience, 4, 2);
  btnDestiny = new QPushButton("Destiny", this);
  layout->addWidget(btnDestiny, 5, 1);
  edtDestiny = new QLineEdit(this);
  layout->addWidget(edtDestiny, 5, 2);
  lblStatus = new QLabel("Status", this);
  layout->addWidget(lblStatus, 6, 1, 1, 2);
  btnAbout = new QPushButton("About", this);
  layout->addWidget(btnAbout, 7, 1);
  btnAction = new QPushButton("Start", this);
  layout->addWidget(btnAction, 7, 2);
  setLayout(layout);
  setWindowTitle(tr("SkMotion"));
}

void UserFace::start() { qDebug() << "called action"; }
