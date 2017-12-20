#ifndef __CLI_REQUEST__
#define __CLI_REQUEST__

#include "common.h"
#include "restclient-cpp/connection.h"
#include "restclient-cpp/restclient.h"

class Request {
public:
  static RestClient::Response authenticate(std::string email, std::string password);
  static RestClient::HeaderFields api_headers();
  static RestClient::Response ping();
  static RestClient::Response tokens();
  static RestClient::Response generate_token();
  static RestClient::Response create_project(std::string name);
  static void download(std::string url, std::string save_path);

private:
  static Request *instance_;
  static Request *instance();
  
  RestClient::Connection *connection;
  Request();
  ~Request();

  RestClient::HeaderFields _default_headers();
  RestClient::HeaderFields _api_headers();
  RestClient::HeaderFields _oauth_headers();
  RestClient::Response _authenticate(std::string email, std::string password);
  RestClient::Response _ping();
  RestClient::Response _tokens();
  RestClient::Response _generate_token();
  RestClient::Response _create_project(std::string name);
  static void _download(std::string url, std::string save_path);
};

#endif
