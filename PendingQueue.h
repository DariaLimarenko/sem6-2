#ifndef PENDINGQUEUE_H
#define PENDINGQUEUE_H

#include <queue>
#include <memory>
#include <tuple>
#include <utility>
#include <iostream>

class IPending {
public:
    virtual void run() = 0;
    virtual ~IPending() = default;
};

template<typename Callable, typename... Args>
class Pending : public IPending {
private:
    Callable callable;
    std::tuple<Args...> args;

public:
    Pending(Callable c, Args... a)
        : callable(c), args(std::make_tuple(a...)) {}

    void run() override {
        std::apply(callable, args);
    }
};

class PendingQueue : private std::queue<std::unique_ptr<IPending>> {
public:
    ~PendingQueue() {
        std::cout << size() << " pending items dropped" << std::endl;
    }

    template<typename Callable, typename... Args>
    void enqueue(Callable callable, Args... args) {
        using PendingType = Pending<Callable, Args...>;
        this->emplace(std::make_unique<PendingType>(callable, args...));
    }

    void run() {
        if (this->empty()) {
            return;
        }

        this->front()->run();
        this->pop();
    }

    void run_one() {
        run();
    }

    void run_all() {
        while (!this->empty()) {
            run();
        }
    }
};

#endif
