////////////////////////////////////////////////////////
// ECE 3574 - Exercise 9: Qt widgets
//
#include "complex_widget.hpp"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <cmath>

ComplexWidget::ComplexWidget(QWidget *parent)
    : QWidget(parent), magnitude(0.0), phase(0.0)
{
    // text boxes for entering the real and imaginary parts
    realEdit = new QLineEdit(this);
    imagEdit = new QLineEdit(this);

    // labels that display the computed magnitude and phase, initialized to 0
    magnitudeLabel = new QLabel("0.0", this);
    phaseLabel = new QLabel("0.0", this);

    // button that triggers the calculation
    updateButton = new QPushButton("Update", this);

    // row containing the real part label and its entry box
    QHBoxLayout *realLayout = new QHBoxLayout;
    realLayout->addWidget(new QLabel("Real:", this));
    realLayout->addWidget(realEdit);

    // row containing the imaginary part label and its entry box
    QHBoxLayout *imagLayout = new QHBoxLayout;
    imagLayout->addWidget(new QLabel("Imaginary:", this));
    imagLayout->addWidget(imagEdit);

    // row containing the magnitude result
    QHBoxLayout *magLayout = new QHBoxLayout;
    magLayout->addWidget(new QLabel("Magnitude:", this));
    magLayout->addWidget(magnitudeLabel);

    // row containing the phase result
    QHBoxLayout *phaseLayout = new QHBoxLayout;
    phaseLayout->addWidget(new QLabel("Phase:", this));
    phaseLayout->addWidget(phaseLabel);

    // stacks all rows plus the button into one column
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(realLayout);
    mainLayout->addLayout(imagLayout);
    mainLayout->addLayout(magLayout);
    mainLayout->addLayout(phaseLayout);
    mainLayout->addWidget(updateButton);

    // connects the button click to the update slot
    connect(updateButton, &QPushButton::clicked, this, &ComplexWidget::updateDisplay);
}

double ComplexWidget::getRealPart() const
{
    // converts the current text in the real box to a double
    return realEdit->text().toDouble();
}

double ComplexWidget::getImaginaryPart() const
{
    // converts the current text in the imaginary box to a double
    return imagEdit->text().toDouble();
}

double ComplexWidget::getMagnitude() const
{
    // returns the last computed magnitude
    return magnitude;
}

double ComplexWidget::getPhase() const
{
    // returns the last computed phase
    return phase;
}

void ComplexWidget::updateDisplay()
{
    // reads the current values from the text boxes
    double real = getRealPart();
    double imag = getImaginaryPart();

    // computes magnitude as the square root of real squared plus imaginary squared
    magnitude = std::sqrt(real * real + imag * imag);

    // computes phase with atan2 so the correct quadrant is used
    phase = std::atan2(imag, real);

    // updates the labels with the newly computed values
    magnitudeLabel->setText(QString::number(magnitude));
    phaseLabel->setText(QString::number(phase));
}