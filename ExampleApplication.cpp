#include "./ExampleApplication.h"
#include "./ExampleAppWindow.h"

ExampleApplication::ExampleApplication()
: Gtk::Application("org.gtkmm.examples.application", Gio::APPLICATION_HANDLES_OPEN) {
}

Glib::RefPtr<ExampleApplication> ExampleApplication::create() {
    return Glib::RefPtr<ExampleApplication>(new ExampleApplication());
}

ExampleAppWindow* ExampleApplication::create_appwindow() {
    auto appwindow = new ExampleAppWindow();

    add_window(*appwindow);

    appwindow->signal_hide().connect(sigc::bind<Gtk::Window*>(sigc::mem_fun(*this,
        &ExampleApplication::on_hide_window), appwindow));

    return appwindow;
}

void ExampleApplication::on_activate() {
    auto appwindow = create_appwindow();
    appwindow->present();
}

void ExampleApplication::on_open(const Gio::Application::type_vec_files& files, const Glib::ustring& /* hint */) {
    ExampleAppWindow* appwindow = nullptr;
    auto windows = get_windows();
    if (windows.size() > 0) {
        appwindow = dynamic_cast<ExampleAppWindow*>(windows[0]);
    }

    if (!appwindow) {
        appwindow = create_appwindow();
    }

    for (const auto& file: files) {
        appwindow->open_file_view(file);
    }

    appwindow->present();
}

void ExampleApplication::on_hide_window(Gtk::Window* window) {
    delete window;
}
