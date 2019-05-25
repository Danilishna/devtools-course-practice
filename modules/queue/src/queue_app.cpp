// Copyright 2019 Utkin Konstantin

#include "include/queue_app.h"

#include <string>

void QueueApplication::Help(const char* appname, const char* message) {
    message_ = std::string(message) +
        "This is a queue application.\n\n" +
        "Please provide arguments in the following format:\n\n" +
        "  $ " + appname + " <actions> " +
        "Where <actions> are operations put/get/top\n" +
        "Format of operations:\n" +
        "put <value : int> - put value in queue\n" +
        "get - extract top element from queue\n" +
        "top - show top element\n";
}

bool QueueApplication::ValidateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        Help(argv[0]);
        return false;
    }
    return true;
}

int QueueApplication::ParseOperation(const char** s) {
    if (std::strcmp(s[0], "put")) {
        int value = std::atoi(s[1]);
        que.Put(value);
        return 2;
    }
    if (std::strcmp(s[0], "get")) {
        que.Get();
        return 1;
    }
    if (std::strcmp(s[0], "top")) {
        message_ = "The top element = " + std::to_string(que.TopElem());
        return 1;
    }
    return 0;
}

std::string QueueApplication::operator()(int argc, const char** argv) {
    if (!ValidateNumberOfArguments(argc, argv)) {
        return message_;
    }
    int i = 1;
    while (i < argc) {
        int inc = ParseOperation(argv + i);
        if (inc == 0) {
            message_ = "Argument error";
            break;
        }
        i += inc + 1;
    }
}
