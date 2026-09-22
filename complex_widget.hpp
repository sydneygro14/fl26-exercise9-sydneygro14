////////////////////////////////////////////////////////
// ECE 3574 - Exercise 9: Qt widgets
//
#ifndef COMPLEX_WIDGET_H
#define COMPLEX_WIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>

class ComplexWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ComplexWidget(QWidget *parent = nullptr);

    // returns the current real part entered in the text box
    double getRealPart() const;

    // returns the current imaginary part entered in the text box
    double getImaginaryPart() const;

    // returns the most recently computed magnitude
    double getMagnitude() const;

    // returns the most recently computed phase
    double getPhase() const;

private slots:
    // recomputes magnitude and phase and refreshes the display labels
    void updateDisplay();

private:
    // entry boxes for the real and imaginary parts
    QLineEdit *realEdit;
    QLineEdit *imagEdit;

    // display boxes for the computed magnitude and phase
    QLabel *magnitudeLabel;
    QLabel *phaseLabel;

    // button that triggers recalculation when clicked
    QPushButton *updateButton;

    // stored results so the getters have something to return
    double magnitude;
    double phase;
};

#endif