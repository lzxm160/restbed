# Copyright 2013-2016, Corvusoft Ltd, All Rights Reserved.

if ( BUILD_SSL )
    set( BUILD_ARTIFACTS
        ${SOURCE_DIR}/http.hpp
        ${SOURCE_DIR}/rule.hpp
        ${SOURCE_DIR}/settings.hpp
        ${SOURCE_DIR}/ssl_settings.hpp
        ${SOURCE_DIR}/status_code.hpp
        ${SOURCE_DIR}/resource.hpp
        ${SOURCE_DIR}/request.hpp
        ${SOURCE_DIR}/response.hpp
        ${SOURCE_DIR}/byte.hpp
        ${SOURCE_DIR}/uri.hpp
        ${SOURCE_DIR}/string.hpp
        ${SOURCE_DIR}/logger.hpp
        ${SOURCE_DIR}/service.hpp
        ${SOURCE_DIR}/session.hpp
        ${SOURCE_DIR}/session_manager.hpp
        ${SOURCE_DIR}/context_value.hpp
        ${SOURCE_DIR}/context_placeholder.hpp
        ${SOURCE_DIR}/context_placeholder_base.hpp
    )
else ( )
    set( BUILD_ARTIFACTS
        ${SOURCE_DIR}/http.hpp
        ${SOURCE_DIR}/rule.hpp
        ${SOURCE_DIR}/settings.hpp
        ${SOURCE_DIR}/status_code.hpp
        ${SOURCE_DIR}/resource.hpp
        ${SOURCE_DIR}/request.hpp
        ${SOURCE_DIR}/response.hpp
        ${SOURCE_DIR}/byte.hpp
        ${SOURCE_DIR}/uri.hpp
        ${SOURCE_DIR}/string.hpp
        ${SOURCE_DIR}/logger.hpp
        ${SOURCE_DIR}/service.hpp
        ${SOURCE_DIR}/session.hpp
        ${SOURCE_DIR}/session_manager.hpp
        ${SOURCE_DIR}/context_value.hpp
        ${SOURCE_DIR}/context_placeholder.hpp
        ${SOURCE_DIR}/context_placeholder_base.hpp
    )
endif ( )
