
file(GLOB mule_srcs
     "*.hpp"
     "*.cpp"
)

picosystem_executable(
    mule_main
    ${mule_srcs}
)


#pixel_double(mule_main)
disable_startup_logo(mule_main)
