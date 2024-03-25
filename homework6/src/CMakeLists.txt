add_executable(sparsematrix_cli main.cpp)

target_link_libraries(sparsematrix_cli
 PRIVATE
  SparseMatrixLib)

install(TARGETS sparsematrix_cli RUNTIME DESTINATION ${PROJECT_BINARY_DIR}/bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PATCH_NUMBER_CONSTANT}")

set(CPACK_PACKAGE_CONTACT alina.sheyanova@gmail.com)

include(CPack)
