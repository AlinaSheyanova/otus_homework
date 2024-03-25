#ifndef BULKPROJECT_WRITER_H
#define BULKPROJECT_WRITER_H

#include <string>

#include "IListener.h"

class Writer : public IListener {
public:
    explicit Writer(std::ostream& output);

    void onNewBlock(const std::vector<std::string>& block) override;

private:
    std::ostream& output;
};

class FileWriter : IListener
{
public:
    explicit FileWriter();

    void onNewBlock(const std::vector<std::string>& block) override;

private:
};

#endif //BULKPROJECT_WRITER_H
