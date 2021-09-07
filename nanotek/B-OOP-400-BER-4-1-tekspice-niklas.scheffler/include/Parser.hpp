#include "MyShell.hpp"
#include <unordered_map>
#include <memory>
#include "Factory.hpp"

class Parser
{
public:
	Parser(char *path, Circuit &toFill);

    void createChipsets(Circuit &toFill, std::stringstream &noComments);
    void createLinks(Circuit &circuit, std::stringstream &stringstream);
};