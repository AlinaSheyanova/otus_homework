include_directories(. Models Models/GraphPrimitives
        Actions Actions/DocumentActions Actions/PrimitivesActions)

add_executable(vector_editor
        main.cpp
        VectorEditorController.cpp
        VectorEditorView.cpp
        Models/GraphPrimitives/Line.cpp
        Models/GraphPrimitives/Rectangle.cpp
        Models/Point.cpp
        Models/VectorDocument.cpp
        Models/VectorEditorModel.cpp
        Actions/ActionComposition.cpp
        Actions/PrimitivesActions/DeletePrimitiveAction.cpp
        Actions/PrimitivesActions/SelectPrimitiveAction.cpp
        Actions/DocumentActions/CloseDocumentAction.cpp
        Actions/DocumentActions/CreateDocumentAction.cpp
        Actions/DocumentActions/OpenDocumentAction.cpp
        Actions/DocumentActions/SaveDocumentToFile.cpp)

install(TARGETS vector_editor RUNTIME DESTINATION ${PROJECT_BINARY_DIR}/bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PATCH_NUMBER_CONSTANT}")

set(CPACK_PACKAGE_CONTACT alina.sheyanova@gmail.com)

include(CPack)
