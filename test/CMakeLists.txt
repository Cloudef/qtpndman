cmake_minimum_required(VERSION 2.6)

include_directories(../include)

add_executable(repositorytest src/repositorytest.cpp)
target_link_libraries(repositorytest qtpndman)

add_executable(devicetest src/devicetest.cpp)
target_link_libraries(devicetest qtpndman)

add_executable(packageinfotest src/packageinfotest.cpp)
target_link_libraries(packageinfotest qtpndman)

add_executable(downloadtest src/downloadtest.cpp)
target_link_libraries(downloadtest qtpndman)

add_executable(upgradetest src/upgradetest.cpp)
target_link_libraries(upgradetest qtpndman)

add_executable(removetest src/removetest.cpp)
target_link_libraries(removetest qtpndman)

add_executable(threadingtest src/threadingtest.cpp)
target_link_libraries(threadingtest qtpndman)

add_executable(iconextractiontest src/iconextractiontest.cpp)
target_link_libraries(iconextractiontest qtpndman)

add_executable(commentpulltest src/commentpulltest.cpp)
target_link_libraries(commentpulltest qtpndman)

add_executable(commentaddtest src/commentaddtest.cpp)
target_link_libraries(commentaddtest qtpndman)

add_executable(ratingtest src/ratingtest.cpp)
target_link_libraries(ratingtest qtpndman)

add_executable(downloadhistorytest src/downloadhistorytest.cpp)
target_link_libraries(downloadhistorytest qtpndman)

add_executable(archivedtest src/archivedtest.cpp)
target_link_libraries(archivedtest qtpndman)
