#ifndef EXAMPLEAPPLICATION_H_
#define EXAMPLEAPPLICATION_H_

#include <gtkmm.h>

class ExampleAppWindow;

class ExampleApplication: public Gtk::Application {
 protected:
    ExampleApplication();

 public:
    static Glib::RefPtr<ExampleApplication> create();

 protected:
    void on_activate() override;
    void on_open(const Gio::Application::type_vec_files& files, const Glib::ustring& hint) override;
 private:
    ExampleAppWindow* create_appwindow();
    void on_hide_window(Gtk::Window* window);
};

#endif // EXAMPLEAPPLICATION_H_
