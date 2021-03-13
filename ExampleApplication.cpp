#include "./ExampleApplication.h"
#include "./ExampleAppWindow.h"

#include <iostream>
#include <exception>

ExampleApplication::ExampleApplication()
: Gtk::Application("org.gtkmm.examples.application", Gio::APPLICATION_HANDLES_OPEN) {
}

Glib::RefPtr<ExampleApplication> ExampleApplication::create() {
	return Glib::RefPtr<ExampleApplication>(new ExampleApplication());
}

ExampleAppWindow* ExampleApplication::create_appwindow() {
	auto appwindow = ExampleAppWindow::create();

	// Make sure that the application runs for as long this window is still open.
	add_window(*appwindow);

	// Gtk::Application::add_window() connects a signal handler to the window's
	// signal_hide(). That handler removes the window from the application.
	// If it's the last window to be removed, the application stops running.
	// Gtk::Window::set_application() does not connect a signal handler, but is
	// otherwise equivalent to Gtk::Application::add_window().

	// Delete the window when it is hidden.
	appwindow->signal_hide().connect(sigc::bind<Gtk::Window*>(sigc::mem_fun(*this,
		&ExampleApplication::on_hide_window), appwindow));

	return appwindow;
}

void ExampleApplication::on_activate() {
	try {
		// The application has been started, so let's show a window.
		auto appwindow = create_appwindow();
		appwindow->present();
	}

	// If create_appwindow() throws an exception (perhaps from Gtk::Builder),
	// no window has been created, no window has been added to the application,
	// and therefore the application will stop running.
	catch (const Glib::Error& ex) {
		std::cerr << "ExampleApplication::on_activate(): " << ex.what() << "\n";
	}
	catch (const std::exception& ex) {
		std::cerr << "ExampleApplication:on_activate(): " << ex.what() << "\n";
	}
}

void ExampleApplication::on_open(const Gio::Application::type_vec_files& files, const Glib::ustring& /* hint */) {
	// The application has been asked to open some files,
	// so let's open a new view for each one.
	ExampleAppWindow* appwindow = nullptr;
	auto windows = get_windows();
	if (windows.size() > 0) {
		appwindow = dynamic_cast<ExampleAppWindow*>(windows[0]);
	}

	try {
		if (!appwindow) {
			appwindow = create_appwindow();
		}

		for (const auto& file: files) {
			appwindow->open_file_view(file);
		}

		appwindow->present();
	}
	catch (const Glib::Error& ex) {
		std::cerr << "ExampleApplication::on_open(): " << ex.what() << "\n";
	}
	catch (const std::exception& ex) {
		std::cerr << "ExampleApplication::on_open(): " << ex.what() << "\n";
	}
}

void ExampleApplication::on_hide_window(Gtk::Window* window) {
	delete window;
}
