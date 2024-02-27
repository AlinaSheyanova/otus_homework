#include <cstdlib>

#include "VectorEditorController.h"

int main(int argc, char** argv)
{
    VectorEditorController controller;
    controller.openDocument("path/to.file");
    controller.addLine();
    controller.addLine();
    controller.undo();
    controller.addRectangle();
    controller.saveDocument("new/path/to.file");
    controller.closeDocument();
    return EXIT_SUCCESS;
}