#ifndef WBASE_H
#define WBASE_H

/* Worker Base
 * (father of other workers)
 *
 * Start
 * =====
 * 1) MainWindow asks requestWork() when "Start" button is clicked.
 * 2) requestWork() emits workRequested() signal which starts thread.
 * 3) When thread starts, worker starts working.
 *
 * Stop
 * ====
 * 1) MainWindow asks requestFinish() when "Stop" button is clicked.
 * 2) Worker stops working and emits finished.
 * 3) Thread quits.
*/

#include <iostream>
#include <QObject>
#include <QMutex>
#include <QDebug>

// https://fabienpn.wordpress.com/2013/05/01/qt-thread-simple-and-stable-with-sources/
// http://doc.qt.io/qt-4.8/thread-basics.html

class WBase : public QObject
{
	Q_OBJECT

public:
	explicit WBase(QObject *parent = 0);
	void requestWork();
	void requestFinish();

protected:
	bool _working;					// true when Worker is doing work.
	bool _finish;					// Process is aborted when @em true.
	QMutex mutex_finish;			// Protects access to #_finish.

signals:
	void workRequested();
		// This signal is emitted when the Worker request to Work requestWork()
	void finished();
		// This signal is emitted when process is finished.
};

#endif // WBASE_H
