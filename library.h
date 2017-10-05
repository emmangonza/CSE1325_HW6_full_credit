#ifndef __LIBRARY_H
#define __LIBRARY_H

#include "publication.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Library {
  public:
    void add_publication(Publication pub);
    void check_out(int publication_index, string patron_name,
                    string patron_phone);
    void check_in(int publication_index);
    string publication_to_string(int publication_index);
    int number_of_publications();
    void easter_egg();

  private:
    vector<Publication> publications;
};
#endif
