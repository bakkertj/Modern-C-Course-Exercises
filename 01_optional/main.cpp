#include <map>

const char* findErrorMessage(int errorCode) {
    static const std::map<int, const char*> errors = {
        {1, "File not found"},
        {2, "Permission denied"}
    };
    auto it = errors.find(errorCode);
    if (it != errors.end()) {
        return it->second;
    }
    return nullptr; // Ambiguous: is this an error or empty result?
}

int main( int argc, char * argv[] )
{
  
  return 0;
}
