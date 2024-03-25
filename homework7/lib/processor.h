#ifndef BULKPROJECT_PROCESSOR_H
#define BULKPROJECT_PROCESSOR_H

#include "IListener.h"
#include "IStringEventSource.h"

class Processor : public IListener, public IStringEventSource {
public:
    explicit Processor();

    void onNewBlock(const std::vector<std::string>& block) override;

    void registerListener(IListener* listener) override;

    void removeListener(IListener* listener) override;

    void notifyListeners(const std::vector<std::string>& block) override;

private:
    std::vector<std::string> commands;
    std::vector<IListener*> listeners;
};

#endif //BULKPROJECT_PROCESSOR_H
