/*
 * Main.cpp
 *
 *  Created on: Jan 7, 2015
 *      Author: mda
 */

#include "util/Logger.h"
#include "controller/controllers/Controller.h"
#include "controller/task/TaskCCR.h"
#include <iostream>
#include <QApplication>

int main(int argc, char** argv) {
<<<<<<< HEAD
    QApplication app(argc, argv);
    Timer* logTimer = new Timer();
	Logger::initialize(true, true, logTimer);
	Logger::trace("Logger initialized.");

	Logger::trace("Began to work on project.");

    Controller *testQueue = new Controller();

    testQueue->initialize();

    while(1){
        testQueue->addTaskToQueue(new TaskCCR());
        std::cout << "I've become so numb!!!!!!~" << std::endl;
    }

    Logger::close();
    return app.exec();
=======
	Logger::initialize(true, false, new Timer());
	Logger::trace("Logger initialized.");
	return 0;
>>>>>>> bfa71d7228bacfb969db89ed7eca1c3741c0d18b
}

