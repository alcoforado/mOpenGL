#include "MainWindow.h"
#include <QGuiApplication>
#include <QApplication>
#include <QWindow>
#include "WindowGL.h"
#include <GL.h>
#include <QDebug>
#include <QTime>
#include <QMessageBox>






int main(int argc, char *argv[])
{
    QGuiApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    QSurfaceFormat format;
    format.setSamples(1);
    format.setVersion(4,1);
    format.setProfile( QSurfaceFormat::CoreProfile );
    WindowGL win(nullptr,format);
    win.resize(640,480);
    win.show();
    qDebug() << win.engine.getOpenGLInfo();

#if 0
    a.exec();
#else

    QTime timer;
    timer.start();
    long unsigned icnt=0;
    long unsigned limit=200;

    while (win.isVisible())
      {

        a.processEvents();
        win.render();
        if (++icnt > limit)
          {
            icnt=0;
            int time=timer.restart();
            double fps=1000.0*limit/(double) time;
            if (time == 0)
              win.setTitle(QString("Infinity"));
            else
              {
                limit=fps;
                win.setTitle(QString("%1 FPS").arg(fps));
              }

          }

      }
#endif


  return 0;

}
