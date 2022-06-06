#include "userface.h"

UserFace::UserFace(QWidget *parent) : QDialog(parent) {
  layout = new QGridLayout();
  btnScreen = new QPushButton("Screen");
  layout->addWidget(btnScreen, 1, 1);
  cmbScreen = new QComboBox();
  layout->addWidget(cmbScreen, 1, 2);
  lblResolution = new QLabel("Resolution");
  layout->addWidget(lblResolution, 2, 1);
  cmbResolution = new QComboBox();
  layout->addWidget(cmbResolution, 2, 2);
  lblSensitivity = new QLabel("Sensitivity");
  layout->addWidget(lblSensitivity, 3, 1);
  edtSensitivity = new QLineEdit();
  layout->addWidget(edtSensitivity, 3, 2);
  lblResilience = new QLabel("Resilience");
  layout->addWidget(lblResilience, 4, 1);
  edtResilience = new QLineEdit();
  layout->addWidget(edtResilience, 4, 2);
  btnDestiny = new QPushButton("Destiny");
  layout->addWidget(btnDestiny, 5, 1);
  edtDestiny = new QLineEdit();
  layout->addWidget(edtDestiny, 5, 2);
  lblStatus = new QLabel("Status");
  layout->addWidget(lblStatus, 6, 1, 1, 2);
  btnAbout = new QPushButton("About");
  layout->addWidget(btnAbout, 7, 1);
  btnAction = new QPushButton("Start");
  layout->addWidget(btnAction, 7, 2);
  setLayout(layout);
  setWindowTitle(tr("SkMotion"));
}

void UserFace::start() { qDebug() << "called action"; }
