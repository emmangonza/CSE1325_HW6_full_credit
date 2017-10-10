#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include "publication.h"

#include <gtkmm.h>

class Main_window : public Gtk::Window {
  public:
    Main_window();
    virtual ~Main_window();
  protected:
    void on_add_click();
    void on_list_click();
    void on_check_out_click();
    void on_check_in_click();
    void on_about_click();
    void on_quit_click();
};
#endif
