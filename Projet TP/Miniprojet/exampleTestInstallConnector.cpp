#include <iostream>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <mysql_connection.h>

auto main() -> int {
   sql::Driver *driver = get_driver_instance();
   try {
     std::unique_ptr<sql::Connection> con(
         driver->connect("localhost", "admin", "admin")); // FILL IN HERE
     if (con != NULL) {
       std::cout << "MySQL Connected successfully!\n";
     }
   } catch (sql::SQLException &e) {
     std::cerr << "MySQL was NOT started or Incorrect credentials.\n";
     return 1;
   }
}
 