#include "main_window.h"

Main_window::Main_window() {
  set_default_size(400, 200);

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

  Gtk::MenuItem *menuitem_preload = Gtk::manage(new Gtk::MenuItem("Preload", true));
  menuitem_preload->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_preload_click));
  pubmenu->append(*menuitem_preload);

  /*Gtk::MenuItem *menuitem_check_out = Gtk::manage(new Gtk::MenuItem("Check out", true));
  menuitem_checifk_out->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_check_out_click));
  pubmenu->append(*menuitem_check_out);

  Gtk::MenuItem *menuitem_check_in = Gtk::manage(new Gtk::MenuItem("Check in", true));
  menuitem_check_in->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_check_in_click));
  pubmenu->append(*menuitem_check_in);*/

  Gtk::MenuItem *menuitem_help = Gtk::manage(new Gtk::MenuItem("_Help", true));
  menubar->append(*menuitem_help);
  Gtk::Menu *helpmenu = Gtk::manage(new Gtk::Menu());
  menuitem_help->set_submenu(*helpmenu);

  Gtk::MenuItem *menuitem_about = Gtk::manage(new Gtk::MenuItem("About", true));
  menuitem_about->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_about_click));
  helpmenu->append(*menuitem_about);

  vbox->show_all();

  library = new Library();
}

Main_window::~Main_window() { }

void Main_window::on_add_click() {
  Glib::ustring book_title, author, copyright, isbn, temp_str, msg;
  int temp_num;
  Genre genre;
  Media media;
  Age age;

  book_title = Dialogs::input("Title?");
  // if (book_title == "CANCEL") close();

  author = Dialogs::input("Author?");
  // if (author == "CANCEL") on_quit_click();

  copyright = Dialogs::input("Copyright date?");
  // if (copyright == "CANCEL") on_quit_click();


  msg = "";
  for (int i = 0; i < genres.size(); ++i)
     msg += "  " + to_string(i) + ") " + genres[i] + "\n";

  temp_str = Dialogs::input(msg, "Select a Genre");
  // if (temp_str == "CANCEL") on_quit_click();

  temp_num = atoi(temp_str.c_str());

  genre = (Genre) temp_num;


  msg = "";
  for (int i = 0; i < medias.size(); ++i)
    msg += "  " + to_string(i) + ") " + medias[i] + "\n";

  temp_str = Dialogs::input(msg, "Select a Media");
  // if (temp_str == "CANCEL") on_quit_click();

  temp_num = atoi(temp_str.c_str());

  media = (Media) temp_num;


  msg = "";
  for (int i = 0; i < ages.size(); ++i)
    msg += "  " + to_string(i) + ") " + ages[i] + "\n";

  temp_str = Dialogs::input(msg, "Select a Target Age");
  // if (temp_str == "CANCEL") on_quit_click();

  temp_num = atoi(temp_str.c_str());

  age = (Age) temp_num;


  isbn = Dialogs::input("ISBN?");
  // if (isbn == "CANCEL") on_quit_click();


  try {
    library->add_publication(Publication(book_title, author, copyright, genre, media, age, isbn));
  } catch (Publication::Invalid_transaction e) {
    Dialogs::message("Unable to add!", "ERROR!");
  }
}

void Main_window::on_list_click() {
  string msg = "";

  for (int i=0; i<library->number_of_publications(); ++i)
    msg += to_string(i) + ". " + library->publication_to_string(i) + "\n";

  Dialogs::message(msg, "List of Library Publications");
}

void Main_window::on_about_click() {
  string msg = R"(
The LMS tracks publication assets for a library, including those who
check out and return those publications.

(1) <b>Add publication</b> - This allows the librarian to enter data
associated with a new publication.
(2) <b>List all publications</b> - All data known about each publication
in the library is listed.
(3) <b>Check <span font_style = 'italic'>out</span> publication</b> - Enter the data for patrons who check out
a publication, and mark that publication as checked out.
(4) <b>Check <span font_style = 'italic'>in</span> publication</b> - Select a publication and mark it as checked in.
(9) <span fgcolor='#00aa00'>Help</span> - Print this text.
(0) <span fgcolor='#aa0000'>Exit</span> - Exit the program. WARNING: The current version does NOT
save any entered data. This feature will be added in the "next version".

Use the '99' command to pre-populate test data.
)";

  Dialogs::message(msg, "Help Menu");
}

void Main_window::on_preload_click() {
  library->easter_egg();
}

void Main_window::on_quit_click() {
  close();
}
