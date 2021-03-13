#include "./ExampleAppWindow.h"
#include <stdexcept>

ExampleAppWindow::ExampleAppWindow(BaseObjectType* cobject,
	const Glib::RefPtr<Gtk::Builder>& refBuilder)
: Gtk::ApplicationWindow(cobject),
  m_refBuilder(refBuilder) {
}

ExampleAppWindow* ExampleAppWindow::create() {
	auto refBuilder = Gtk::Builder::create_from_resource("/org/gtkmm/exampleapp/window.ui");

	ExampleAppWindow* window = nullptr;
	refBuilder->get_widget_derived("app_window", window);
	if (!window) {
		throw std::runtime_error("No \"app_window\" object in window.ui");
	}

	return window;
}

void ExampleAppWindow::open_file_view(const Glib::RefPtr<Gio::File>& /* file */) {
}
