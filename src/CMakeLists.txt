add_executable(ip_filter main.cpp)

target_link_libraries(ip_filter
 PRIVATE
  ipFilterLib)

install(TARGETS ip_filter RUNTIME DESTINATION ${PROJECT_BINARY_DIR}/bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PATCH_NUMBER_CONSTANT}")

set(CPACK_PACKAGE_CONTACT alina.sheyanova@gmail.com)

include(CPack)
