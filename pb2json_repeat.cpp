//pb2json_repeat.cpp
//
// Created by hyj on 2020-05-06.
//

#include <iostream>
#include <string>
#include <pb2json.h>
#include "config.pb.h"

using namespace std;

#define LVAR(var)   " " << #var << "="<< var

int main() {
    Pb2Json::Json json1;
    json1 = Pb2Json::Json::parse("{\n"
            "  \"host\": [\n"
            "    {\n"
            "      \"hash_id\": 0,\n"
            "      \"host\": \"127.0.0.1\",\n"
            "      \"port\": 9800\n"
            "    },\n"
            "    {\n"
            "      \"hash_id\": 1,\n"
            "      \"host\": \"127.0.0.1\",\n"
            "      \"port\": 9801\n"
            "    },\n"
            "    {\n"
            "      \"hash_id\": 2,\n"
            "      \"host\": \"127.0.0.1\",\n"
            "      \"port\": 9802\n"
            "    }\n"
            "\n"
            "  ],\n"
            "  \"self_hash_id\": 1\n"
            "}");
    cout << LVAR(json1) << endl;
    tpc::Config::Config config1;
    bool ret = Pb2Json::Json2Message(json1, config1, true);
    assert(ret);
    cout << LVAR(config1.host_size()) << endl;
}

