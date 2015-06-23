/*
<<<<<<< HEAD
 * BaseTask.h
=======
 * Task.h
>>>>>>> bfa71d7228bacfb969db89ed7eca1c3741c0d18b
 *
 *  Created on: Jan 7, 2015
 *      Author: mda
 */

#ifndef TASK_H_
#define TASK_H_

<<<<<<< HEAD
#include <QMutex>
#include <vector>

#define TASKLISTLENGTH 10

class Task {
    public:
        //The Task class is purely virtual (abstract)
        virtual ~Task();

        virtual void execute() = 0;

    protected:
       std::vector <Task*> taskList;
};

#endif /* BASETASK_H_ */
=======
class Task {
public:
	Task();
	virtual ~Task();
};

#endif /* TASK_H_ */
>>>>>>> bfa71d7228bacfb969db89ed7eca1c3741c0d18b
