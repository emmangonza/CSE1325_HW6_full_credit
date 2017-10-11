#include "library.h"
#include "publication.h"
#include "enums.h"
#include "dialogs.h"
#include "main_window.h"

#include <iostream>
#include <vector>
#include <string>
#include <gtkmm.h>

using namespace std;

int main(int argc, char *argv[]) {

  // Gtk::Main kit(argc, argv);
  auto app =
    Gtk::Application::create(argc, argv, "cse1325.hw6.lms");

  Main_window win;

  win.set_title("Library Management System");

  return app->run(win);

  /*Library library;

  string cmd_str = "";
  int cmd_num = -1;
  while (cmd_num != 0) {
    string menu, win_title;
    menu = "<b><span size = 'larger'><span fgcolor='#aa00aa'>CSE1325 Library Management System</span></span></b>\n\n"
           "<b><u>Publications</u></b>\n"
           "(1) Add publication\n"
           "(2) List all publications\n"
           "(3) Check <span font_style = 'italic'>out</span> publication\n"
           "(4) Check <span font_style = 'italic'>in</span> publication\n\n"
           "<b><u>Utility</u></b>\n"
           "(9) <span fgcolor='#00aa00'>Help</span>\n"
           "(0) <span fgcolor='#aa0000'>Exit</span>\n\n";

    win_title = "Main menu";

    cmd_str = Dialogs::input(menu, win_title);
    if (cmd_str == "CANCEL") break;

    cmd_num = atoi(cmd_str.c_str());


    if (cmd_num == 1) {
      string book_title, author, copyright, isbn, temp_str, msg;
      int temp_num;
      Genre genre;
      Media media;
      Age age;

      book_title = Dialogs::input("Title?");
      if (book_title == "CANCEL") break;

      author = Dialogs::input("Author?");
      if (author == "CANCEL") break;

      copyright = Dialogs::input("Copyright date?");
      if (copyright == "CANCEL") break;


      msg = "";
      for (int i = 0; i < genres.size(); ++i)
         msg += "  " + to_string(i) + ") " + genres[i] + "\n";

      temp_str = Dialogs::input(msg, "Select a Genre");
      if (temp_str == "CANCEL") break;

      temp_num = atoi(temp_str.c_str());

      genre = (Genre) temp_num;


      msg = "";
      for (int i = 0; i < medias.size(); ++i)
        msg += "  " + to_string(i) + ") " + medias[i] + "\n";

      temp_str = Dialogs::input(msg, "Select a Media");
      if (temp_str == "CANCEL") break;

      temp_num = atoi(temp_str.c_str());

      media = (Media) temp_num;


      msg = "";
      for (int i = 0; i < ages.size(); ++i)
        msg += "  " + to_string(i) + ") " + ages[i] + "\n";

      temp_str = Dialogs::input(msg, "Select a Target Age");
      if (temp_str == "CANCEL") break;

      temp_num = atoi(temp_str.c_str());

      age = (Age) temp_num;


      isbn = Dialogs::input("ISBN?");
      if (isbn == "CANCEL") break;


      try {
        library.add_publication(Publication(book_title, author, copyright, genre, media, age, isbn));
      } catch (Publication::Invalid_transaction e) {
        Dialogs::message("Unable to add!", "ERROR!");
      }

  }
   if (cmd_num == 2) {
      string msg = "";

      for (int i=0; i<library.number_of_publications(); ++i)
        msg += to_string(i) + ". " + library.publication_to_string(i) + "\n";

      Dialogs::message(msg, "List of Library Publications");

   }
   if (cmd_num == 3) {
      string pub, pat, pat_phone, msg = "";
      int pub_num;

      for (int i=0; i<library.number_of_publications(); ++i)
        msg += to_string(i) + ". " + library.publication_to_string(i) + "\n";

      pub = Dialogs::input(msg, "Publication number?");
      if (pub == "CANCEL") break;

      pub_num = atoi(pub.c_str());

      pat = Dialogs::input("Patron name?");
      if (pat == "CANCEL") break;

      pat_phone = Dialogs::input("Patron number?");
      if (pat_phone == "CANCEL") break;

      try {
        library.check_out(pub_num, pat, pat_phone);
      } catch (Publication::Invalid_transaction e) {
        Dialogs::message("That publication is already checked out!", "ERROR!");
      }

   }
   if (cmd_num == 4) {
      string pub, msg = "";
      int pub_num;

      for (int i=0; i<library.number_of_publications(); ++i)
        msg += to_string(i) + ". " + library.publication_to_string(i) + "\n";

      pub = Dialogs::input(msg, "Publication number?");
      if (pub == "CANCEL") break;

      pub_num = atoi(pub.c_str());

      try {
        library.check_in(pub_num);
      } catch (Publication::Invalid_transaction e) {
        Dialogs::message("That publication is already checked in!", "ERROR!");
      }

   }
   if (cmd_num == 9) {
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
   if (cmd_num == 99) {
     library.easter_egg();
   }
   if (cmd_num < 0 || (4 < cmd_num && cmd_num < 9) || (9 < cmd_num && cmd_num < 99) || (99 < cmd_num)) { // Invalid command
     Dialogs::message("Invalid command - type 9 for help", "ERROR!");
   }
 }
  return EXIT_SUCCESS;*/
}
