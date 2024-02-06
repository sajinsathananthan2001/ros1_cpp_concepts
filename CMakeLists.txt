cmake_minimum_required(VERSION 3.0.2)
project(ros1_cpp_concepts)


find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  geometry_msgs
  actionlib
  actionlib_msgs
  message_generation
  message_runtime
)


add_message_files( 
   FILES 
   demo_msg.msg 
) 

## Generate services in the 'srv' folder 
add_service_files( 
   FILES 
   demo_srv.srv
   my_srv.srv
 ) 
 
 ## Generate actions in the 'action' folder
add_action_files(
   FILES
   Demo_action.action
)

## Generate added messages and services with any dependencies listed here 
generate_messages( 
   DEPENDENCIES 
   std_msgs 
   actionlib_msgs
) 


catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES ros1_cpp_concepts
#  CATKIN_DEPENDS roscpp rospy std_msgs
#  DEPENDS system_lib
)




include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(print_msg_node src/print_msg_node.cpp)
add_executable(cpp_publisher src/cpp_publisher.cpp)
add_executable(cpp_subscriber src/cpp_subscriber.cpp)
add_executable(move_turtle src/move_turtle.cpp)
add_executable(set_get_param src/parameter/set_get_param.cpp)
add_executable(reset_client src/service/reset_client.cpp)
add_executable(change_color src/parameter/change_color.cpp)
add_executable(my_server src/service/my_server.cpp)
add_executable(my_client src/service/my_client.cpp)


add_dependencies(print_msg_node ${print_msg_node_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
add_dependencies(cpp_publisher ${cpp_publisher_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
add_dependencies(cpp_subscriber ${cpp_subscriber_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
add_dependencies(move_turtle ${move_turtle_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
add_dependencies(set_get_param ${set_get_param_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
add_dependencies(reset_client ${reset_client_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
add_dependencies(change_color ${change_color_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
add_dependencies(my_server ${my_server_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
add_dependencies(my_client ${my_client_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

target_link_libraries(print_msg_node      
  ${catkin_LIBRARIES}
)
target_link_libraries(cpp_publisher      
  ${catkin_LIBRARIES}
)
target_link_libraries(cpp_subscriber      
  ${catkin_LIBRARIES}
)
target_link_libraries(move_turtle      
  ${catkin_LIBRARIES}
)
target_link_libraries(set_get_param      
  ${catkin_LIBRARIES}
)
target_link_libraries(reset_client      
  ${catkin_LIBRARIES}
)
target_link_libraries(change_color      
  ${catkin_LIBRARIES}
)
target_link_libraries(my_server      
  ${catkin_LIBRARIES}
)
target_link_libraries(my_client      
  ${catkin_LIBRARIES}
)


add_executable(demo_msg_publisher src/demo_msg_publisher.cpp)
add_executable(demo_msg_subscriber src/demo_msg_subscriber.cpp)
add_executable(demo_service_server src/service/demo_service_server.cpp)
add_executable(demo_service_client src/service/demo_service_client.cpp) 
add_executable(demo_action_server src/demo_action_server.cpp) 
add_executable(demo_action_client src/demo_action_client.cpp)

add_dependencies(demo_msg_publisher ${demo_msg_publisher_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
add_dependencies(demo_msg_subscriber ${demo_msg_subscriber_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
add_dependencies(demo_service_server ${demo_service_server_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
add_dependencies(demo_service_client ${demo_service_client_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
add_dependencies(demo_action_server ${demo_action_server_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
add_dependencies(demo_action_client ${demo_action_client_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})


target_link_libraries(demo_msg_publisher ${catkin_LIBRARIES})
target_link_libraries(demo_msg_subscriber ${catkin_LIBRARIES})
target_link_libraries(demo_service_server ${catkin_LIBRARIES}) 
target_link_libraries(demo_service_client ${catkin_LIBRARIES}) 
target_link_libraries(demo_action_server ${catkin_LIBRARIES} )
target_link_libraries(demo_action_client ${catkin_LIBRARIES})












