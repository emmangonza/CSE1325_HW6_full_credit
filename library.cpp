#include "library.h"

void Library::add_publication(Publication pub) {
  publications.push_back(pub);
}

void Library::check_out(int publication_index, string patron_name, string patron_phone) {
  publications[publication_index].check_out(patron_name, patron_phone);
}

void Library::check_in(int publication_index) {
  publications[publication_index].check_in();
}

string Library::publication_to_string(int publication_index) {
  return publications[publication_index].to_string();
}

int Library::number_of_publications() {
  return publications.size();
}

void Library::easter_egg() {
 add_publication(Publication("The Firm", "John Grisham", "1991",
       Genre::fiction, Media::book, Age::adult, "0440245923"));
 add_publication(Publication("Foundation", "Isaac Asimov", "1942",
        Genre::fiction, Media::book, Age::adult, "0385177259"));
 add_publication(Publication("Foundation and Empire", "Isaac Asimov", "1943",
        Genre::fiction, Media::book, Age::adult, "0385177259"));
 add_publication(Publication("Second Foundation", "Isaac Asimov", "1944",
        Genre::fiction, Media::book, Age::adult, "0385177259"));
 add_publication(Publication("War of the Worlds", "Jeff Wayne", "1977",
        Genre::performance, Media::audio, Age::teen, "9780711969148"));
 add_publication(Publication("Willy Wonka and the Chocolate Factory", "Roald Dahl", "1971",
        Genre::performance, Media::video, Age::children, "0142410314"));
}
