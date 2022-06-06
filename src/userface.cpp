#include <QDir>
#include <QDoubleValidator>
#include <QGuiApplication>
#include <QIntValidator>
#include <QPushButton>
#include <QScreen>
#include <QStandardPaths>

#include "recorder.h"
#include "userface.h"

UserFace::UserFace(QWidget *parent) : QDialog(parent) {
  setWindowTitle(tr("SkMotion"));
  settings = new QSettings("Pointel", "SkMotion");
  layout = new QGridLayout(this);
  setLayout(layout);
  btnScreen = new QPushButton("Screen", this);
  layout->addWidget(btnScreen, 1, 1);
  cmbScreen = new QComboBox(this);
  layout->addWidget(cmbScreen, 1, 2);
  lblResolution = new QLabel("Resolution:", this);
  layout->addWidget(lblResolution, 2, 1);
  cmbResolution = new QComboBox(this);
  layout->addWidget(cmbResolution, 2, 2);
  lblSensitivity = new QLabel("Sensitivity:", this);
  layout->addWidget(lblSensitivity, 3, 1);
  edtSensitivity = new QLineEdit(this);
  layout->addWidget(edtSensitivity, 3, 2);
  lblResilience = new QLabel("Resilience:", this);
  layout->addWidget(lblResilience, 4, 1);
  edtResilience = new QLineEdit(this);
  layout->addWidget(edtResilience, 4, 2);
  btnDestiny = new QPushButton("Destiny", this);
  layout->addWidget(btnDestiny, 5, 1);
  edtDestiny = new QLineEdit(this);
  layout->addWidget(edtDestiny, 5, 2);
  btnAbout = new QPushButton("About", this);
  layout->addWidget(btnAbout, 6, 1);
  btnAction = new QPushButton("Start", this);
  layout->addWidget(btnAction, 6, 2);
  lblStatus = new QLabel("Status: Waiting to start...", this);
  layout->addWidget(lblStatus, 7, 1, 1, 2);
  initLabels();
  initScreens();
  initResolutions();
  initSensitivity();
  initResilience();
  initDestiny();
  connect(btnAction, &QPushButton::clicked, this, &UserFace::doStartOrStop);
}

void UserFace::initLabels() {
  lblResolution->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
  lblSensitivity->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
  lblResilience->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
  lblStatus->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
}

void UserFace::initScreens() {
  auto screens = QGuiApplication::screens();
  for (auto screen : screens) {
    cmbScreen->addItem(screen->name());
  }
  cmbScreen->setCurrentText(
      settings->value("screen", cmbScreen->itemText(0)).toString());
}

void UserFace::initResolutions() {
  cmbResolution->addItem("640x480");
  cmbResolution->addItem("800x600");
  cmbResolution->addItem("960x720");
  cmbResolution->addItem("1066x600");
  cmbResolution->addItem("1280x720");
  cmbResolution->addItem("1024x768");
  cmbResolution->addItem("1600x900");
  cmbResolution->addItem("1920x1080");
  cmbResolution->setCurrentText(
      settings->value("resolution", cmbResolution->itemText(4)).toString());
}

void UserFace::initSensitivity() {
  edtSensitivity->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
  edtSensitivity->setValidator(new QDoubleValidator(0, 1, 6, this));
  edtSensitivity->setText(settings->value("sensitivity", "0.001").toString());
}

void UserFace::initResilience() {
  edtResilience->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
  edtResilience->setValidator(new QIntValidator(0, 10000, this));
  edtResilience->setText(settings->value("resilience", "27").toString());
}

void UserFace::initDestiny() {
  auto destiny =
      QStandardPaths::writableLocation(QStandardPaths::HomeLocation) +
      "/Records";
  edtDestiny->setText(settings->value("destiny", destiny).toString());
}

void UserFace::doStartOrStop() {
  auto screen = cmbScreen->currentText();
  // auto resolution = cmbResolution->currentText();
  // auto sensitivity = edtSensitivity->text().toInt();
  // auto resilience = edtResilience->text().toInt();
  // auto destiny = edtDestiny->text();
  auto recorder = new Recorder(screen, this);
  recorder->start();
}
