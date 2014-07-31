
FIND_PACKAGE(CMakeHelper)

SET(components std log console network)
SET(pkg_name Galaxy)

cmh_finder(${pkg_name} "${components}")


