#include <QApplication>
#include <QFileDialog>
#include <opencv2/imgcodecs/imgcodecs.hpp>

#include <iostream>
#include <sys/stat.h>

#include "opencvglviewer.h"
#include "opencvfacedetect.h"

#define NB_IMAGE 3

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    std::string images[NB_IMAGE] = {"./rsrc/Loic.jpg", "./rsrc/Sylvain.jpg", "./rsrc/Nicolas.jpg"};

    std::string path;

    if (argc > 1)
    {
        int i = 0;
        bool fromFile = false;
        i = atoi(argv[1]);
        if (i == 0) // try to load an image from disk
        {
            struct stat buf;
            if (stat(argv[1], &buf) != -1)
            {
                fromFile = true;
            }
        }
        else if (i > NB_IMAGE - 1) // stay in images bounds
        {
            i = 0;
        }
        path = fromFile ? argv[1] : images[i]; // the path to load the image from
    }
    else // if no argument open a file dialog to select an image
    {
        path = QFileDialog::getOpenFileName().toStdString();
        if (path.empty())
        {
            std::cout << "cancel selected, exiting..." << std::endl;
            return 0;
        }
    }

    OpenCVGLViewer viewer;


    cv::Mat image = cv::imread(path);

    std::cout << "Face detection : " << path << ", please wait ... " << std::flush;
    SFace face;
    try
    {
        face = OpenCVFaceDetect::detectAndDraw(image, false);
    }
    catch (OpenCVFaceDetect::UnableToLoadClassifier &e) {
        std::cerr << e.what() << std::endl;
        return -1;
    }
    std::cout << "done" << std::endl;


    if (viewer.showImage(image, face)) // show only if showImage succeed
    {
        viewer.show();
    }

    return app.exec();

    return 0;
}

