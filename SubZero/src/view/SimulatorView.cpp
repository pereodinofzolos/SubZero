#include "SimulatorView.h"

SimulatorView::SimulatorView() {

}

SimulatorView::SimulatorView(Stage *stage, Controller *controller, std::vector<State *> states)
    : View(stage, controller, states) {

}

SimulatorView::~SimulatorView() {
    delete logger;
}

void SimulatorView::update(int id) {

}

void SimulatorView::initialize() {
    // Window sizing
    QSize minSize = QSize(100, 100);
    QSize maxSize = QSize(1920, 1080);

    // Obscurity and depth perception modifiers
    int depthBufferSize = 16;   // 8,16,24 and 32 bit  but fixing at 16 bit b/c expecting obscure environment
    int multiSampleAntiAliasingSamples = 4; // Number of samples to take of each pixel if multi-sample anti-aliasing is used

    // Setup the window
    format = new QSurfaceFormat();
    format->setProfile(QSurfaceFormat::NoProfile);  // In case OpenGl version less than 3.2
    format->setDepthBufferSize(depthBufferSize);    // In water don't see too far ahead so reducing depth perception from standard 24
    format->setSamples(multiSampleAntiAliasingSamples); // For multisample based anti-aliasing

    window = new QWindow();
    window->setSurfaceType(QSurface::OpenGLSurface);    // Set to use OpenGl for rendering & painting
    window->setFormat(*format);
    window->create();

    container = new QWidget();
    container = createWindowContainer(window);
    container->setParent(this); // Allows containter to be shown when this is
    container->setMinimumSize(minSize); // Can be as small as 100 pixels by 100 pixels
    container->setMaximumSize(maxSize); // Can be as large as

    // Initialize the Simulator 3D Engine
    //TODO: Use dependency injection here instead
    Qt3D::QEntity* rootEntity = new Qt3D::QEntity();
    engine = new SimulatorEngine(window, new SimulatedSub(rootEntity), new SimulatedEnvironment(rootEntity), rootEntity);
    engine->initialize();
}

QSize SimulatorView::sizeHint() const {

}

QSize SimulatorView::minimumSizeHint() const {

}

QWindow *SimulatorView::getWindow() {
    return window;
}

void SimulatorView::keyPressEvent(QKeyEvent *event) {
    QWidget::keyPressEvent(event);
}

void SimulatorView::makeQImage(cv::Mat imgData, QImage &imgHolder) {

}

