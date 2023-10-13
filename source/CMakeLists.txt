############################################################
# Create the QPixRTD library
############################################################

file(GLOB SOURCES "*.cpp")

# # generate ROOT dictionary
ROOT_GENERATE_DICTIONARY(QPixRTDDict ROOTFileManager.h LINKDEF LinkDef.h)

##Generate the static library from the library sources
add_library(QPixRTD SHARED ${SOURCES} QPixRTDDict.cxx)

find_package(nlohmann_json 3.2.0 REQUIRED)

target_compile_options(QPixRTD PRIVATE -DBOOST_NO_CXX11_SCOPED_ENUMS)

target_link_libraries(QPixRTD ${ROOT_LIBRARIES})
target_link_libraries(QPixRTD ${Boost_LIBRARIES})
