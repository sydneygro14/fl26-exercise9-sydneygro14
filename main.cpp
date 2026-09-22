////////////////////////////////////////////////////////
// ECE 3574 - Exercise 9: Qt widgets
//
#include <QApplication>
#include "complex_widget.hpp"

int main(int argc, char *argv[])
{
    // sets up the qt application and event loop management
    QApplication app(argc, argv);

    // creates the widget and displays it on screen
    ComplexWidget widget;
    widget.show();

    // enters the event loop, waiting for user interaction
    return app.exec();
}