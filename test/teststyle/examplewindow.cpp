#include "examplewindow.hpp"

#include <gtkmm/messagedialog.h>
#include <iostream>

ExampleWindow::ExampleWindow() :
	m_button_box(Gtk::ORIENTATION_VERTICAL),
	m_button_info("Show Info MessageDialog"),
	m_button_question("Show Question MessageDialog")
{
	set_title("Gtk::MessageDialog example");
	resize(500, 430);

	add(m_button_box);

	m_button_box.pack_start(m_button_info);
	m_button_info.signal_clicked().connect(sigc::mem_fun(*this, &ExampleWindow::on_button_info_clicked));

	m_button_box.pack_start(m_button_question);
	m_button_question.signal_clicked().connect(sigc::mem_fun(*this, &ExampleWindow::on_button_question_clicked));

	show_all_children();
}

ExampleWindow::~ExampleWindow()
{
}

void ExampleWindow::on_button_info_clicked()
{
	Gtk::MessageDialog dialog(*this, "This is an INFO MessageDialog");
	dialog.set_secondary_text("And this is the secondary test that explains things.");

	dialog.run();
}

void ExampleWindow::on_button_question_clicked()
{
	Gtk::MessageDialog dialog(*this, "This is a QUESTION MessageDialog", false, Gtk::MESSAGE_QUESTION, Gtk::BUTTONS_OK_CANCEL);
	dialog.set_secondary_text("And this is the secondary text that explains things.");

	int result = dialog.run();

	//Handle the response:
	switch(result)
	{
		case(Gtk::RESPONSE_OK):
		{
			std::cout << "OK clicked." << std::endl;
			break;
		}
		case(Gtk::RESPONSE_CANCEL):
		{
			std::cout << "Cancel clicked." << std::endl;
			break;
		}
		default:
		{
			std::cout << "Unexpected button clicked." << std::endl;
			break;
		}
	}
}
