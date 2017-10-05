#ifndef __DIALOGS_H
#define __DIALOGS_H

#include <iostream>
#include <gtkmm.h>

using namespace std;

class Dialogs {
  public:

    static void message(string msg, string title = "Info");

    static int question(string msg, string title = "Question",
                 vector<string> buttons = {"Cancel", "OK"});

    static string input(string msg, string title = "Input", string default_text = "",
                 string cancel_text = "CANCEL");

    static void image(string filename, string title = "Image", string msg = "");
};
#endif
