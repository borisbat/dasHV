
IF ((NOT DAS_HV_INCLUDED) AND ((NOT ${DAS_HV_DISABLED}) OR (NOT DEFINED DAS_HV_DISABLED)))
    SET(DAS_HV_INCLUDED TRUE)
    MESSAGE(STATUS "dasHV module included.")

	SET(DAS_HV_DIR ${PROJECT_SOURCE_DIR}/modules/dasHV)

	include(ExternalProject)

	IF(WIN32)
		find_package(OpenSSL REQUIRED)
		IF(NOT OpenSSL_FOUND)
			# Install and build it from sources. Do we need it?
			if(${CMAKE_SIZEOF_VOID_P} EQUAL 8)
				set(OPENSSL_ARCH "VC-WIN64A")
			else()
				set(OPENSSL_ARCH "VC-WIN32")
			endif()
			set(OPENSSL_ROOT_DIR "${CMAKE_BINARY_DIR}/openssl")
			set(OPENSSL_INCLUDE_DIR ${OPENSSL_ROOT_DIR}/include)
			set(OPENSSL_LIBRARIES ${OPENSSL_ROOT_DIR}/lib)

			ExternalProject_Add(openssl_build
				URL "https://www.openssl.org/source/openssl-1.1.1l.tar.gz"
				URL_HASH SHA256=0b7a3e5e59c34827fe0c3a74b7ec8baef302b98fa80088d7f9153aa16fa76bd1
				PREFIX ${OPENSSL_ROOT_DIR}
				CONFIGURE_COMMAND perl Configure ${OPENSSL_ARCH} no-shared --prefix=${OPENSSL_ROOT_DIR} --openssldir=${OPENSSL_ROOT_DIR}
				BUILD_COMMAND nmake
				INSTALL_COMMAND nmake install_sw
				BUILD_IN_SOURCE 1
			)
			SET(OPENSSL_FROM_SOURCES TRUE)
		ENDIF()
		SET(HV_LIBRARIES ${DAS_HV_DIR}/hv/lib/hv_static.lib)
	ELSE()
		find_package(OpenSSL REQUIRED)
		SET(HV_LIBRARIES ${DAS_HV_DIR}/hv/lib/libhv_static.a)
	ENDIF()


	SET(HV_CMAKE_FLAGS
		-DCMAKE_OSX_ARCHITECTURES="${CMAKE_OSX_ARCHITECTURES}"
		-DCMAKE_INSTALL_PREFIX=${DAS_HV_DIR}/hv
		-DCMAKE_BUILD_TYPE=Release
		-DBUILD_SHARED=OFF
		-DBUILD_EXAMPLES=OFF
		-DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER}
		-DCMAKE_C_COMPILER=${CMAKE_C_COMPILER}
		-DCMAKE_LINKER=${CMAKE_LINKER}
		-DWITH_OPENSSL=ON
		-DOPENSSL_INCLUDE_DIR=${OPENSSL_INCLUDE_DIR}
		-DOPENSSL_LIBRARIES="${OPENSSL_CRYPTO_LIBRARY};${OPENSSL_SSL_LIBRARY}"
	)
	IF("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang" AND (NOT CMAKE_CXX_COMPILER_FRONTEND_VARIANT STREQUAL "MSVC"))
		# todo: remove. For some reasons clang-cl doesn't work well without this flag.
		list(APPEND HV_CMAKE_FLAGS
			-DCMAKE_TRY_COMPILE_TARGET_TYPE=STATIC_LIBRARY
		)
	ENDIF()

	ExternalProject_Add(
		LIBHV
		SOURCE_DIR ${DAS_HV_DIR}/libhv
		CMAKE_ARGS ${HV_CMAKE_FLAGS}
		BINARY_DIR ${DAS_HV_DIR}/libhv/build
		BUILD_BYPRODUCTS ${HV_LIBRARIES}
	)
	IF(OPENSSL_FROM_SOURCES)
		add_dependencies(LIBHV openssl_build)
	ENDIF()

	IF(APPLE)
		list(APPEND HV_LIBRARIES
			"-framework CoreFoundation"
			"-framework Security"
		)
	ENDIF()

    LIST(APPEND CMAKE_MODULE_PATH ${DAS_HV_DIR})

	# libDasModuleHV
	SET(DAS_HV_MODULE_SRC
		${DAS_HV_DIR}/src/dasHV.h
		${DAS_HV_DIR}/src/dasHV.cpp
	)

	ADD_MODULE_LIB(libDasModuleHV)
	ADD_MODULE_CPP(HV)
	ADD_LIBRARY(libDasModuleHV ${DAS_HV_MODULE_SRC} ${DAS_HV_MODULE_PLATFORM_SRC})
	ADD_DEPENDENCIES(libDasModuleHV LIBHV)
	TARGET_INCLUDE_DIRECTORIES(libDasModuleHV PUBLIC "${DAS_HV_DIR}/hv/include")
	TARGET_LINK_LIBRARIES(libDasModuleHV ${HV_LIBRARIES})
	target_link_libraries(libDasModuleHV OpenSSL::Crypto OpenSSL::SSL)
	SETUP_CPP11(libDasModuleHV)

	ADD_MODULE_DAS(dashv dashv dashv_boost)

    install(DIRECTORY ${PROJECT_SOURCE_DIR}/modules/dasHV/dashv
        DESTINATION ${DAS_INSTALL_MODULESDIR}/dasHV
        FILES_MATCHING
        PATTERN "*.das"
    )

	install(DIRECTORY ${PROJECT_SOURCE_DIR}/modules/dasHV/libhv/cert
        DESTINATION ${DAS_INSTALL_MODULESDIR}/dasHV
        FILES_MATCHING
        PATTERN "*.crt"
    )

	install(DIRECTORY ${PROJECT_SOURCE_DIR}/modules/dasHV/libhv/cert
        DESTINATION ${DAS_INSTALL_MODULESDIR}/dasHV
        FILES_MATCHING
        PATTERN "*.key"
    )

    file(GLOB DAS_HV_EXAMPLES
        ${PROJECT_SOURCE_DIR}/modules/dasHV/example/*.*
    )

    install(FILES ${DAS_HV_EXAMPLES}
        DESTINATION ${DAS_INSTALL_EXAMPLESDIR}/hv
    )

	install(FILES ${PROJECT_SOURCE_DIR}/modules/dasHV/libhv/LICENSE DESTINATION ${DAS_INSTALL_DOCDIR} RENAME HV.LICENSE)

ENDIF()
