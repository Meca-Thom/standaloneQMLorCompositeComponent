#ifndef TESTEMBBEDEDDRIVER_H
#define TESTEMBBEDEDDRIVER_H


/*
    CODE METHODOLODY : BDD, TDD, the 9 Matrix

    A:
        Name the routine

            GenerateSinPeriodically()


        Define the problame it will solve


            It will generate the value of Sin function and return the value.
            Sin(2 PI f t)

        Decide how to test the routine

            I will test that its 0 and 1 are correctly positionned in time


    B:
        Write the detailed PDL
        Research appropriates algorithms

            qSin() function in <QtMath> library


        Check prerequisites

            <QtMath> library
            A timer to run the Sin periodically and get value


    C:
        Think about efficiency
        Think about the data

            Data can be a double, but I want to create a plot in QML

        Review the PDL and the data



*/

struct sPulseGenerator
{
    sPulseGenerator() {
        frequence=0;
    }

    void generatePulseSignal(double frequenceSignal){

    };


    double frequence;
};



#include <QDebug>
#include <QObject>
#include <QtMath>

class TestEmbbededDriver: public QObject
{
    Q_OBJECT
public:
    TestEmbbededDriver();

    /*

    1. To start any simulation for signal, i need a cos generator

    And maybe data variables to hold it



    */










    void GeneratorIQSignals(){

        /*
        template <typename T> auto qCos(T v)

        Returns the cosine of an angle v in radians.
        */

        double x;

        double y;


        y=qCos(x);


    }

    Q_INVOKABLE void testGeneratorIQSignals(){

        bool Result=false;

        qDebug()<<"Hola : "<<Result;
    }
};

#endif // TESTEMBBEDEDDRIVER_H
