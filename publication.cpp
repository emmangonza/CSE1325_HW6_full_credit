#include "publication.h"

#include <iostream>
#include <string>

using namespace std;

Publication::Publication(string title, string author, string copyright,
  Genre genre, Media media, Age target_age, string isbn) : _title{title},
  _author{author}, _copyright{copyright}, _genre{genre}, _media{media},
  _target_age{target_age}, _isbn{isbn} {}

void Publication::check_out(string patron_name, string patron_phone) {
  if(checked_out == true) {
    throw Invalid_transaction();
  }
  else {
    checked_out = true;
    _patron_name = patron_name;
    _patron_phone = patron_phone;
  }
}

void Publication::check_in() {
  if(checked_out == true) {
    checked_out = false;
  }
  else {
    throw Invalid_transaction();
  }
}

bool Publication::is_checked_out() {
  return checked_out;
}

string Publication::to_string() {
  string pub =  "\"" + _title + "\" by " + _author + ", \n    " + _copyright + " (" +
          ages[_target_age] + " " + genres[_genre] + " " + medias[_media] +
          ")\n    ISBN: " + _isbn;

  if(checked_out == true) {
    pub += "\n    Checked out to " +_patron_name + " (" + _patron_phone + ")";
  }

  return pub;
}
