#include "../include/Parser.hpp"
#include "../include/Output.hpp"
#include <fstream>
#include <exception>
#include <sstream>
#include <algorithm>
#include <regex>

Parser::Parser(char *path, Circuit &toFill)
{
    std::string stringPath (path);
    std::ifstream file(stringPath, std::ios::in);
    std::stringstream noComments;
    std::string line;
    std::string emp;

    if (!file)
        throw std::runtime_error("file : '" + stringPath + "' not found.");
    if (stringPath.length() < 4 || stringPath.substr(stringPath.length() - 4) != ".nts")
        throw std::runtime_error("file : '" + stringPath + "' is no nts file.");
    while (getline(file, line))
    {
        std::string noCommentLine = line.substr(0, line.find('#'));
        if ((size_t) std::count(noCommentLine.begin(), noCommentLine.end(), ' ') != noCommentLine
        .length())
            noComments << noCommentLine << std::endl;
    }
    if (!getline(noComments, line))
        throw std::runtime_error(".chipset command is missing");
    std::stringstream ss(line);
    ss >> line >> emp;
    if (line !=".chipsets:")
        throw std::runtime_error(".chipset command is missing");
    if (!emp.empty())
        throw std::runtime_error("no valid syntax: " + emp);
    createChipsets(toFill, noComments);
    createLinks(toFill, noComments);
}

void Parser::createChipsets(Circuit &toFill, std::stringstream &noComments)
{
    Factory fac;
    std::string line;
    std::stringstream lineStream;
    std::string firstArg;
    std::string secondArg;
    std::string emptyArg;

    while (getline(noComments, line))
    {
        std::stringstream ss(line);
        std::string links;
        std::string emp;
        ss >> links >> emp;
        if (links ==".links:")
        {
            if (!emp.empty())
                throw std::runtime_error("no valid syntax: " + emp);
            break;
        }
        lineStream = std::stringstream (line);
        lineStream >> firstArg >> secondArg >> emptyArg;
        if (!emptyArg.empty() || firstArg.empty() || secondArg.empty())
            throw std::runtime_error("invalid component syntax");
        fflush(stdout);
        std::unique_ptr<nts::IComponent> k = fac.createComponent(firstArg, secondArg);
        toFill.addComponent(std::move(k), secondArg, firstArg);
    }
}


void Parser::createLinks(Circuit &circuit, std::stringstream &noComments)
{
    std::string pinOneString;
    std::string pinTwoString;
    std::string line;
    std::pair<std::string, size_t>pairOne;
    std::pair<std::string, size_t>pairTwo;
    while (getline(noComments, line))
    {
        try
        {
            std::stringstream ss(line);
            ss >> pinOneString >> pinTwoString;
            std::string namePinOne = pinOneString.substr(0, pinOneString.find(':'));
            std::string numberPinOne = pinOneString.substr(pinOneString.find(':') + 1);

            std::string namePinTwo = pinTwoString.substr(0, pinTwoString.find(':'));
            std::string numberPinTwo = pinTwoString.substr(pinTwoString.find(':') + 1);

            size_t numberOne = std::stoi(numberPinOne);
            size_t numberTwo = std::stoi(numberPinTwo);

            pairOne = std::make_pair(namePinOne, numberOne);
            pairTwo = std::make_pair(namePinTwo, numberTwo);
//            circuit.setLink(pairOne, pairTwo);
            circuit.setLink(namePinOne, numberOne, namePinTwo, numberTwo);
        } catch (std::exception const &ex)
        {
            throw std::runtime_error("invalid setLink syntax");
        }
//        if (!std::regex_search(line, regexResult, regex))
//        pairOne = std::make_pair(regexResult.str(1), stoi(regexResult.str(2)));
//        pairTwo = std::make_pair(regexResult.str(3), stoi(regexResult.str(4)));
//        circuit.setLink(pairOne, pairTwo);
    }
}
