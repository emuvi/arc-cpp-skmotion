#ifndef INTERFACE_H
#define INTERFACE_H

#include <QComboBox>
#include <QDialog>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class UserFace : public QDialog {
  Q_OBJECT

public:
  UserFace();

private:
  QGridLayout *layout;
  QPushButton *btnScreen;
  QComboBox *cmbScreen;
  QLabel *lblResolution;
  QComboBox *cmbResolution;
  QLabel *lblSensitivity;
  QLineEdit *edtSensitivity;
  QLabel *lblResilience;
  QLineEdit *edtResilience;
  QPushButton *btnDestiny;
  QLineEdit *edtDestiny;
  QLabel *lblStatus;
  QPushButton *btnAbout;
  QPushButton *btnAction;

private slots:
  void start();
};

#endif // INTERFACE_H