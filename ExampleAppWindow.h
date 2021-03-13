#ifndef EXAMPLEAPPWINDOW_H_
#define EXAMPLEAPPWINDOW_H_

#include <gtkmm.h>

class ExampleAppWindow : public Gtk::ApplicationWindow {
 public:
	ExampleAppWindow(BaseObjectType* cobject,
		const Glib::RefPtr<Gtk::Builder>& refBuilder);

	static ExampleAppWindow* create();

	void open_file_view(const Glib::RefPtr<Gio::File>& file);
 protected:
	Glib::RefPtr<Gtk::Builder> m_refBuilder;
};

#endif // EXAMPLEAPPWINDOW_H_
