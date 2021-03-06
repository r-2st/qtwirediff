// SPDX-License-Identifier: GPL-3.0
#ifndef TRACEVIEW_H
#define TRACEVIEW_H


#include <QFrame>
#include "trace.h"

namespace Ui {
class TraceView;
}

class TraceView : public QFrame
{
    Q_OBJECT

public:
    explicit TraceView(QWidget *parent = 0);
    ~TraceView();
    int getPacketNo();
    Trace::Node* getLastNode() { return lastNode; }
    Trace* getTrace() { return trace_; }

    void moveSelection(int dir);
    void asyncOpen(QString fn, QString filter = "");

signals:
    void packetChanged(TraceView *tv);

private:
    int getRow();


    Ui::TraceView *ui;
    Trace* trace_;
    Trace::Node* lastNode;

    QFutureWatcher<Trace*>* watcherTrace;
    QFuture<Trace*> futureTrace;

    QFutureWatcher<Trace::Node*>* watcherNode;
    QFuture<Trace::Node*> futureNode;

private slots:
    void onSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected);
    void onOpenClick(bool checked);
    void onFilterSubmit();
};

#endif // TRACEVIEW_H
