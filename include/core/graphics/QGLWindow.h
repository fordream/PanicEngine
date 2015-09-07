#ifndef OPENCVGLVIEWER_H
#define OPENCVGLVIEWER_H


#include <QOpenGLWidget>
#include <opencv2/core/core.hpp>

#include "sface.h"

class OpenCVGLViewer : public QOpenGLWidget
{
    Q_OBJECT
private:
    /**
     * @brief m_renderedImage The image to render in the OpenGL context
     */
    QImage m_renderedImage;

    /**
     * @brief m_backgroundColor of the window
     */
    QColor m_backgroundColor;

    int m_imHeight;
    int m_imWidth;
    float m_imRatio;

    /**
     * @brief m_posX the X position where to draw the image
     */
    int m_posX;
    /**
     * @brief m_posY the Y position where to draw the image
     */
    int m_posY;

    /**
     * @brief m_face the detected face in the image to draw
     */
    SFace m_face;

    /**
     * @brief drawEllipse draws the ellipse e with nbSegment
     * @param e
     * @param nbSegment
     */
    void drawEllipse(const SEllipse &e, int nbSegment = 100);

    /**
     * @brief renderImage render the image
     */
    void renderImage();

    /**
     * @brief renderFace draw ellipses on the ROI of the face
     */
    void renderFace();

    /**
     * @brief updateScene called when the scene needs to be updated
     */
    void updateScene();

public:
    explicit OpenCVGLViewer(QWidget *parent = 0);

    /**
     * @brief showImage show the image image with OpenGL and draw the face detected with OpenCV
     * on the image
     * @param image
     * @param face
     * @return true on success, false otherwise
     */
    bool showImage(const cv::Mat &image, const SFace &face);


protected:
    // OpenGL callbacks
    void initializeGL() Q_DECL_OVERRIDE;
    void paintGL() Q_DECL_OVERRIDE;
    void resizeGL(int width, int height) Q_DECL_OVERRIDE;


};

#endif // OPENCVGLVIEWER_H
