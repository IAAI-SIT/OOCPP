cmake_minimum_required(VERSION 3.16)
project(StudentClassroomReview LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(v1 V1_ClassAndObject/main.cpp V1_ClassAndObject/Student.cpp)
target_include_directories(v1 PRIVATE V1_ClassAndObject)

add_executable(v2 V2_Constructor_Const_This/main.cpp V2_Constructor_Const_This/Student.cpp)
target_include_directories(v2 PRIVATE V2_Constructor_Const_This)

add_executable(v3 V3_ObjectArray_Pointer/main.cpp V3_ObjectArray_Pointer/Student.cpp)
target_include_directories(v3 PRIVATE V3_ObjectArray_Pointer)

add_executable(v4 V4_DynamicMemory/main.cpp V4_DynamicMemory/Student.cpp V4_DynamicMemory/Classroom.cpp)
target_include_directories(v4 PRIVATE V4_DynamicMemory)

add_executable(v5 V5_ShallowCopy_Demo/main.cpp V5_ShallowCopy_Demo/Student.cpp V5_ShallowCopy_Demo/ClassroomShallow.cpp)
target_include_directories(v5 PRIVATE V5_ShallowCopy_Demo)

add_executable(v6 V6_Final/main.cpp V6_Final/Student.cpp V6_Final/Classroom.cpp)
target_include_directories(v6 PRIVATE V6_Final)
