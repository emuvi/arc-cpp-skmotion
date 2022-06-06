#ifndef USERFACE_H
#define USERFACE_H

#include <QComboBox>
#include <QDialog>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSettings>
#include <QWidget>
#include <qsettings.h>

class UserFace : public QDialog {
  Q_OBJECT

public:
  explicit UserFace(QWidget *parent = nullptr);

private:
  QSettings *settings;
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
  void initLabels();
  void initScreens();
  void initResolutions();
  void initSensitivity();
  void initResilience();
  void initDestiny();

private slots:
  void doStartOrStop();
};

#endif // USERFACE_H