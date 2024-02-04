#include "../include/cfgc.h"

ConfigLoader::ConfigLoader(const std::string& filename) : filename_(filename) {}

bool ConfigLoader::load()
{
    std::ifstream file(filename_);
    
    if (!file.is_open())
    {
        std::cerr << "Error: Unable to open file " << filename_ << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(file, line))
    {
        if (line.empty() || line[0] == '#') {
            continue;
        }

        size_t delimiterPos = line.find('=');
        if (delimiterPos != std::string::npos)
        {
            std::string key = trim(line.substr(0, delimiterPos));
            std::string value = trim(line.substr(delimiterPos + 1));

            configData_[key] = value;
        }
    }

    file.close();
    return true;
}

std::string ConfigLoader::getValue(const std::string& key) const
{
    auto it = configData_.find(key);
    return (it != configData_.end()) ? it->second : "";
}

std::string ConfigLoader::trim(const std::string& str)
{
    size_t first = str.find_first_not_of(" \t");
    size_t last = str.find_last_not_of(" \t");

    if (first == std::string::npos || last == std::string::npos)
    {
        return "";
    }

    return str.substr(first, last - first + 1);
}
