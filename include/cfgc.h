#pragma once

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>

class ConfigLoader
{
public:
    ConfigLoader(const std::string& filename);
    
    bool load();
    
    std::string getValue(const std::string& key) const;

private:
    std::string filename_;
    std::unordered_map<std::string, std::string> configData_;

    static std::string trim(const std::string& str);
};
