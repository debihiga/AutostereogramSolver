#include "wbase.h"
#include <QTimer>
#include <QEventLoop>
#include <QThread>


/*
 * Constructor.
 * _acquiring = false -> not doing work.
 * _abort = false -> not aborted.
 */
WBase::WBase(QObject *parent) :
	QObject(parent)
{
	_working = false;
	_finish = false;
}

/*
 * requestWork
 * Requests the process to start.
 * It is thread safe as it uses #mutex to protect access to #_working variable.
 */
void WBase::requestWork()
{
	 mutex_finish.lock();
	 _working = true;
	 _finish = false;
	 mutex_finish.unlock();

	 emit workRequested();
}

/*
 * abort
 * Requests the process to abort
 * It is thread safe as it uses #mutex to protect access to #_abort variable.
 */
void WBase::requestFinish()
{
	 mutex_finish.lock();
	 if (_working) {
		  _finish = true;
          //qDebug()<<"Request worker finishing in Thread "<<thread()->currentThreadId();
	 }
	 mutex_finish.unlock();
}
