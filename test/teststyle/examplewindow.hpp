#ifndef EXAMPLEWINDOW_H
#define EXAMPLEWINDOW_H

#include <gtkmm/window.h>
#include <gtkmm/buttonbox.h>
#include <gtkmm/button.h>

class ExampleWindow : public Gtk::Window
{
public:
	ExampleWindow();
	virtual ~ExampleWindow();
protected:
	void on_button_info_clicked();
	void on_button_question_clicked();

	Gtk::ButtonBox m_button_box;
	Gtk::Button m_button_info, m_button_question;
};

#endif
