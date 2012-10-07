CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT(GraphDatabase)

ADD_SUBDIRECTORY(./src/DataStore)
ADD_SUBDIRECTORY(./src/DataStructure)
ADD_SUBDIRECTORY(./src/GraphAlgorithms)

ADD_EXECUTABLE(graphDb ./src/main.cpp)

TARGET_LINK_LIBRARIES(graphDb Graph Prim)