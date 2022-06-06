#ifndef USERFACE_H
#define USERFACE_H

#include <QComboBox>
#include <QDialog>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>

class UserFace : public QDialog {
  Q_OBJECT

public:
  explicit UserFace(QWidget *parent = nullptr);

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
  void initScreens();

private slots:
  void start();
};

#endif // USERFACE_H