// maingui.h

// Copyright (C) 2012 by Werner Lemberg.
//
// This file is part of the ttfautohint library, and may only be used,
// modified, and distributed under the terms given in `COPYING'.  By
// continuing to use, modify, or distribute this file you indicate that you
// have read `COPYING' and understand and accept it fully.
//
// The file `COPYING' mentioned in the previous paragraph is distributed
// with the ttfautohint library.


#ifndef __MAINGUI_H__
#define __MAINGUI_H__

#include <QMainWindow>

class QAction;
class QLabel;
class QMenu;
class QLineEdit;
class QPushButton;
class QSpinBox;
class QComboBox;
class QCheckBox;
class QLocale;
class QFile;

class Main_GUI
: public QMainWindow
{
  Q_OBJECT

public:
  Main_GUI(int, int, bool, bool, int);

protected:
  void closeEvent(QCloseEvent*);

private slots:
  void about();
  void browse_input();
  void browse_output();
  void check_min();
  void check_max();
  void absolute_input();
  void absolute_output();
  void check_run();
  void run();

private:
  int hinting_range_min;
  int hinting_range_max;
  int ignore_permissions;
  int pre_hinting;
  int latin_fallback;

  void create_layout();
  void create_connections();
  void create_actions();
  void create_menus();
  void create_status_bar();
  void read_settings();
  void write_settings();

  int check_filenames(const QString&, const QString&);
  int open_files(const QString&, FILE**, const QString&, FILE**);

  QMenu* file_menu;
  QMenu* help_menu;

  QLineEdit* input_line;
  QPushButton* input_button;

  QLineEdit* output_line;
  QPushButton* output_button;

  QSpinBox* min_box;
  QSpinBox* max_box;

  QComboBox* fallback_box;

  QCheckBox* pre_box;
  QCheckBox* ignore_box;

  QPushButton* run_button;

  QAction* exit_act;
  QAction* about_act;
  QAction* about_Qt_act;

  QLocale* locale;
};

#endif /* __MAINGUI_H__ */

// end of maingui.h
