#include <map>
#include <optional>
#include <iostream>
#include <string_view>


std::optional<std::string_view> findErrorMessage(int errorCode) {
    static const std::map<int, std::string_view> errors = {
        {1, "File not found"},
        {2, "Permission denied"}
    };
    auto it = errors.find(errorCode);
    if (it != errors.end()) {
        return it->second;
    }
    return std::nullopt; // Clear intent: no message for this code
}

int main( int argc, char * argv[] )
{
  std::optional<std::string_view> error_msg = findErrorMessage( 42 );
  std::cout << "Error: " << error_msg.value_or("Unknown error code") << std::endl;

  error_msg = findErrorMessage( 2 );
  std::cout << "Error: " << error_msg.value_or("Unknown error code") << std::endl;
  return 0;
}
