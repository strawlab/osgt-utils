cmake_minimum_required(VERSION 2.8)
project(osgt-utils)

FIND_PACKAGE(osg)
FIND_PACKAGE(osgUtil)
FIND_PACKAGE(osgDB)

SET(OSG_LIBS ${OSG_LIBRARIES} ${OSGUTIL_LIBRARIES} ${OSGDB_LIBRARIES})

ADD_EXECUTABLE(osgtsplit src/osgtsplit.cpp)
TARGET_LINK_LIBRARIES(osgtsplit ${OSG_LIBS})

ADD_EXECUTABLE(osgtmerge src/osgtmerge.cpp)
TARGET_LINK_LIBRARIES(osgtmerge ${OSG_LIBS})
