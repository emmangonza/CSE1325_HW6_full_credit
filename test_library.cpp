#include "publication.h"
#include "library.h"

int main() {
  Library library;

  bool passed = true;

  //
  // Test adding publications
  //

  Publication foundation("Foundation", "Isaac Asimov", "1942",
      Genre::fiction, Media::book, Age::adult, "0385177259");
  Publication foundation_empire("Foundation and Empire", "Isaac Asimov", "1943",
      Genre::fiction, Media::book, Age::adult, "0385177259");
  Publication foundation2("Second Foundation", "Isaac Asimov", "1944",
      Genre::fiction, Media::book, Age::adult, "0385177259");
  Publication war("War of the Worlds", "Jeff Wayne", "1977",
      Genre::performance, Media::audio, Age::teen, "9780711969148");
  Publication wonka("Willy Wonka and the Chocolate Factory", "Roald Dahl", "1971",
      Genre::performance, Media::video, Age::children, "0142410314");

  if (library.number_of_publications() != 0) {
    passed = false;
    cerr << "Started with " << library.number_of_publications() << " publications" << endl;
  }

  library.add_publication(foundation);
  library.add_publication(foundation_empire);
  library.add_publication(foundation2);
  library.add_publication(war);
  library.add_publication(wonka);

  if (library.number_of_publications() != 5) {
    passed = false;
    cerr << "Ended with " << library.number_of_publications() << " publications (expected 5)" << endl;
  }

  string expected = "\"Foundation\" by Isaac Asimov, 1942 (adult fiction book) ISBN: 0385177259";
  string actual = library.publication_to_string(0);
  if (actual != expected) {
    passed = false;
    cerr << "String from publication_to_string doesn't match" << endl;
    cerr << "  Expected: " << expected << endl;
    cerr << "  Actual:   " << actual << endl;
  }

  //
  // Test check out and check in
  //

  library.check_out(1, "Curly", "817-555-1212");

  expected = "\"Foundation and Empire\" by Isaac Asimov, 1943 (adult fiction book) ISBN: 0385177259\nChecked out to Curly (817-555-1212)";
  actual = library.publication_to_string(1);
  if (actual != expected) {
    passed = false;
    cerr << "String from publication_to_string doesn't match after check out" << endl;
    cerr << "  Expected: " << expected << endl;
    cerr << "  Actual:   " << actual << endl;
  }

  library.check_in(1);

  expected = "\"Foundation and Empire\" by Isaac Asimov, 1943 (adult fiction book) ISBN: 0385177259";
  actual = library.publication_to_string(1);
  if (actual != expected) {
    passed = false;
    cerr << "String from publication_to_string doesn't match after check in" << endl;
    cerr << "  Expected: " << expected << endl;
    cerr << "  Actual:   " << actual << endl;
  }
  //
  // Show results if failed
  //
  if (!passed) cerr << "fail" << endl;
}
