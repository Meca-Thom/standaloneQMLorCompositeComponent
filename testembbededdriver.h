#ifndef TESTEMBBEDEDDRIVER_H
#define TESTEMBBEDEDDRIVER_H

#include <QTimer>
#include <QDebug>


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

class sPulseGenerator: public QObject
{
    Q_OBJECT
public:
    sPulseGenerator() {
        frequenceDuSignal=0;



        //QMetaObject::Connection connection = timerGenerator.callOnTimeout(&sPulseGenerator::generatePulseSignal);
        QObject::connect(&timerGenerator, &QTimer::timeout, this, &sPulseGenerator::generatePulseSignal);

        //timerGenerator.start(1000);
    }

    ~sPulseGenerator(){
        timerGenerator.stop();
    }

    void setPulseSignal(double frequenceSignal){
        qDebug()<<"SET FREQUENCY :: "<<frequenceSignal<<"Hz";
        double periodeDuSignal = 1/frequenceSignal;

        timerGenerator.setInterval(periodeDuSignal/*/2*/);//msec
        timerGenerator.start();

    };

    void stopSignal(){
        timerGenerator.stop();
    }

public slots:
    bool generatePulseSignal(){

        static int SignalValue=0;
        static bool validValue=false;
        static int cptValue=0;
        qDebug()<<"generatePulseSignal   SignalValue   validValue   cptValue"<<SignalValue<<"  "<<validValue<<"  "<<cptValue;


        if(validValue==false){
            cptValue++;
            if(cptValue==10){
                validValue=true;
            }
            return false;
        }
        else{
            validValue=false;
            if(SignalValue==0){
                SignalValue=1;

            }
            else{
                SignalValue=0;
            }

            qDebug()<<SignalValue;
            return true;
        }


    };



public:
    QTimer timerGenerator;

    double frequenceDuSignal;
};



#include <QDebug>
#include <QObject>
#include <QtMath>

class TestEmbbededDriver: public QObject
{
    Q_OBJECT
public:
    TestEmbbededDriver(){
        gen_PULSE = new sPulseGenerator;
    };


    ~TestEmbbededDriver(){
        delete gen_PULSE;
    }

    /*

    1. To start any simulation for signal, i need a cos generator

    And maybe data variables to hold it



    */

    sPulseGenerator * gen_PULSE;








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

        static bool INITVAL=false;

        if(INITVAL==false){
            //gen_PULSE->setPulseSignal(0.5);
            gen_PULSE->setPulseSignal(10);
            //gen_PULSE->generatePulseSignal();
            INITVAL=true;
        }
        else{
            gen_PULSE->stopSignal();
            INITVAL=false;
        }


        gen_PULSE->generatePulseSignal();

        qDebug()<<"Hola : "<<INITVAL;
    }
};

#endif // TESTEMBBEDEDDRIVER_H
