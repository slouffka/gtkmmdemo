#ifndef EXAMPLEAPPWINDOW_H_
#define EXAMPLEAPPWINDOW_H_

#include <gtkmm.h>

class ExampleAppWindow : public Gtk::ApplicationWindow {
 public:
	ExampleAppWindow();

	void open_file_view(const Glib::RefPtr<Gio::File>& file);
};

#endif // EXAMPLEAPPWINDOW_H_
