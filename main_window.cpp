#include "main_window.h"

Main_window::Main_window() {
  set_default_size(400, 150);

  Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
  add(*vbox);

  Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar());
  vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);

  Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
  menubar->append(*menuitem_file);
  Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
  menuitem_file->set_submenu(*filemenu);

  Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
  menuitem_quit->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_quit_click));
  filemenu->append(*menuitem_quit);

  Gtk::MenuItem *menuitem_pub = Gtk::manage(new Gtk::MenuItem("_Publication", true));
  menubar->append(*menuitem_pub);
  Gtk::Menu *pubmenu = Gtk::manage(new Gtk::Menu());
  menuitem_pub->set_submenu(*pubmenu);

  Gtk::MenuItem *menuitem_add = Gtk::manage(new Gtk::MenuItem("Add", true));
  menuitem_add->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_add_click));
  pubmenu->append(*menuitem_add);

  Gtk::MenuItem *menuitem_list = Gtk::manage(new Gtk::MenuItem("List", true));
  menuitem_list->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_list_click));
  pubmenu->append(*menuitem_list);

  Gtk::MenuItem *menuitem_check_out = Gtk::manage(new Gtk::MenuItem("Check out", true));
  menuitem_check_out->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_check_out_click));
  pubmenu->append(*menuitem_check_out);

  Gtk::MenuItem *menuitem_check_in = Gtk::manage(new Gtk::MenuItem("Check in", true));
  menuitem_check_in->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_check_in_click));
  pubmenu->append(*menuitem_check_in);

  Gtk::MenuItem *menuitem_help = Gtk::manage(new Gtk::MenuItem("_Help", true));
  menubar->append(*menuitem_help);
  Gtk::Menu *helpmenu = Gtk::manage(new Gtk::Menu());
  menuitem_help->set_submenu(*helpmenu);

  Gtk::MenuItem *menuitem_about = Gtk::manage(new Gtk::MenuItem("About", true));
  menuitem_about->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_about_click));
  helpmenu->append(*menuitem_about);
}
