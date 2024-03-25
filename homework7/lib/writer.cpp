#include "writer.h"

#include <iostream>
#include <fstream>

Writer::Writer(std::ostream& output) : output(output) {}

void Writer::onNewBlock(const std::vector<std::string>& block) {
    output << "bulk:";
    for (const auto &command: block) {
        output << command << ",";
    }
    output << std::endl;
}

FileWriter::FileWriter()  {}

void FileWriter::onNewBlock(const std::vector<std::string>& block) {

}

