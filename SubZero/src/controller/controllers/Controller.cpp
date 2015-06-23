/*
 * Controller.cpp
 *
 *  Created on: Jan 7, 2015
 *      Author: mda
 */

#include "Controller.h"

<<<<<<< HEAD
#include <iostream>

Controller::Controller(void){
    taskList = *new QQueue <class Task* >;
}

void Controller::initialize(void) {
    ControllerThread *cT = new ControllerThread(&taskList, &mutex);
    cT->moveToThread(&queueThread);
    connect(&queueThread, &QThread::finished, cT, &QObject::deleteLater);
    connect(this, &Controller::beginCT, cT, &ControllerThread::executeTasks);
    connect(cT, &ControllerThread::resultReady, this, &Controller::cTHandleResults);
    queueThread.start();
    emit beginCT("Begin handling Commands");
}

    //Destructor to free pointers
Controller::~Controller(){
    queueThread.quit();
    queueThread.wait();
}

void Controller::cTHandleResults(const QString &s){
    std::cout << "Bye Bye Beautiful!!" << std::endl;
}

void Controller::addTaskToQueue(Task *newTask)
{
    mutex.lock();
    taskList.enqueue(newTask);
    mutex.unlock();
=======
Controller::Controller() {
	// TODO Auto-generated constructor stub

}

Controller::~Controller() {
	// TODO Auto-generated destructor stub
>>>>>>> bfa71d7228bacfb969db89ed7eca1c3741c0d18b
}

