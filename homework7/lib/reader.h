#ifndef BULKPROJECT_READER_H
#define BULKPROJECT_READER_H

#include "IStringEventSource.h"

class Reader : public IStringEventSource {
public:
    Reader(std::istream& input, int n);

    void registerListener(IListener* listener) override;

    void removeListener(IListener* listener) override;

    void notifyListeners(const std::vector<std::string>& block) override;

    void read();

private:
    int N;
    std::istream& input;
    std::vector<IListener*> listeners;
};


#endif //BULKPROJECT_READER_H
