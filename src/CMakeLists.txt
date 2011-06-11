SET(LIB_NAME ES)

INCLUDE_DIRECTORIES(
  ${CMAKE_CURRENT_SOURCE_DIR}/../include/
)

SET(HEADER_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../include})
SET(SOURCE_PATH ${CMAKE_CURRENT_SOURCE_DIR})

SET(LIB_PUBLIC_HEADERS
  ${HEADER_PATH}/Component.h
  ${HEADER_PATH}/ComponentManager.h
  ${HEADER_PATH}/EntityManager.h
  ${HEADER_PATH}/EntityProcessingSystem.h
  ${HEADER_PATH}/EntitySystem.h
  ${HEADER_PATH}/IntervalEntitySystem.h
  ${HEADER_PATH}/SystemManager.h
  ${HEADER_PATH}/TagManager.h
  ${HEADER_PATH}/World.h

)

SET(LIB_SOURCES
  ${SOURCE_PATH}/ComponentManager.cpp
  ${SOURCE_PATH}/EntityManager.cpp
  ${SOURCE_PATH}/EntityProcessingSystem.cpp
  ${SOURCE_PATH}/EntitySystem.cpp
  ${SOURCE_PATH}/SystemManager.cpp
  ${SOURCE_PATH}/TagManager.cpp
  ${SOURCE_PATH}/World.cpp
)

ADD_LIBRARY(${LIB_NAME} SHARED
    ${LIB_PUBLIC_HEADERS}
    ${LIB_SOURCES}
)
