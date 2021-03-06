/*
 * Copyright 2013-2016, Corvusoft Ltd, All Rights Reserved.
 */

#ifndef _RESTBED_DETAIL_SERVICE_IMPL_H
#define _RESTBED_DETAIL_SERVICE_IMPL_H 1

//System Includes
#include <set>
#include <map>
#include <thread>
#include <memory>
#include <string>
#include <vector>
#include <stdexcept>
#include <functional>
#include <boost/date_time/posix_time/posix_time.hpp>
//Project Includes

//External Includes
#include <boost/asio.hpp>
#ifdef BUILD_SSL
    #include <boost/asio/ssl.hpp>
#endif

//System Namespaces

//Project Namespaces

//External Namespaces

namespace restbed
{
    //Forward Declarations
    class Rule;
    class Logger;
    class Session;
    class Service;
    class Resource;
    class Settings;
    class SessionManager;
    class SSLSettings;
    
    namespace detail
    {
        //Forward Declarations
        
        class ServiceImpl
        {
            public:
                //Friends
                
                //Definitions
                
                //Constructors
                ServiceImpl( void );
                
                virtual ~ServiceImpl( void );
                
                //Functionality
                void http_start( void );
                
                void http_listen( void ) const;
#ifdef BUILD_SSL
                void https_start( void );
                
                void https_listen( void ) const;
                
                void create_ssl_session( const std::shared_ptr< boost::asio::ssl::stream< boost::asio::ip::tcp::socket > >& socket, const boost::system::error_code& error ) const;
#endif
                std::string sanitise_path( const std::string& path ) const;
                
                void not_found( const std::shared_ptr< Session > session ) const;
                
                bool has_unique_paths( const std::set< std::string >& paths ) const;
                
                void log( const Logger::Level level, const std::string& message ) const;
                
                void method_not_allowed( const std::shared_ptr< Session > session ) const;
                
                void method_not_implemented( const std::shared_ptr< Session > session ) const;
                
                void failed_filter_validation( const std::shared_ptr< Session > session ) const;
                
                void router( const std::shared_ptr< Session > session ) const;
                
                void create_session( const std::shared_ptr< boost::asio::ip::tcp::socket >& socket, const boost::system::error_code& error ) const;
                
                void extract_path_parameters( const std::string& sanitised_path, const std::shared_ptr< const Request >& request ) const;
                
                std::function< void ( const std::shared_ptr< Session > ) > find_method_handler( const std::shared_ptr< Session > session ) const;
                
                void authenticate( const std::shared_ptr< Session > session ) const;
                
                bool resource_router( const std::shared_ptr< Session > session, const std::pair< std::string, std::shared_ptr< const Resource > >& route ) const;
                
                //Getters
                
                //Setters
                
                //Operators
                
                //Properties
                bool m_is_running;
                
                std::shared_ptr< Logger > m_logger;
                
                std::set< std::string > m_supported_methods;
                
                std::shared_ptr< const Settings > m_settings;
                
                std::shared_ptr< boost::asio::io_service > m_io_service;
                
                std::shared_ptr< SessionManager > m_session_manager;
                
                std::vector< std::shared_ptr< Rule > > m_rules;
                
                std::vector< std::shared_ptr< std::thread > > m_workers;
#ifdef BUILD_SSL
                std::shared_ptr< const SSLSettings > m_ssl_settings;
                
                std::shared_ptr< boost::asio::ssl::context > m_ssl_context;
                
                std::shared_ptr< boost::asio::ip::tcp::acceptor > m_ssl_acceptor;
#endif
                std::shared_ptr< boost::asio::ip::tcp::acceptor > m_acceptor;
                
                std::map< std::string, std::string > m_resource_paths;
                
                std::map< std::string, std::shared_ptr< const Resource > > m_resource_routes;
                
                std::function< void ( void ) > m_ready_handler;
                
                std::function< void ( const std::shared_ptr< Session > ) > m_not_found_handler;
                
                std::function< void ( const std::shared_ptr< Session > ) > m_method_not_allowed_handler;
                
                std::function< void ( const std::shared_ptr< Session > ) > m_method_not_implemented_handler;
                
                std::function< void ( const std::shared_ptr< Session > ) > m_failed_filter_validation_handler;
                
                std::function< void ( const int, const std::exception&, const std::shared_ptr< Session > ) > m_error_handler;
                
                std::function< void ( const std::shared_ptr< Session >, const std::function< void ( const std::shared_ptr< Session > ) >& ) > m_authentication_handler;
                
            protected:
                //Friends
                
                //Definitions
                
                //Constructors
                
                //Functionality
                
                //Getters
                
                //Setters
                
                //Operators
                
                //Properties
                
            private:
                //Friends
                
                //Definitions
                
                //Constructors
                ServiceImpl( const ServiceImpl& original ) = delete;
                
                //Functionality
                
                //Getters
                
                //Setters
                
                //Operators
                ServiceImpl& operator =( const ServiceImpl& value ) = delete;
                
                //Properties
        };
    }
}

#endif  /* _RESTBED_DETAIL_SERVICE_IMPL_H */
