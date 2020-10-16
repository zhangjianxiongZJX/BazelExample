#include <iostream>
#include "message.h"
#include "ssl/ssl.h"
#include "lib/thing.pb.h"
std::string get_message() {
    example::Thing thing;
    thing.set_name("zjx");
    thing.set_payload("123");
    return thing.name() + thing.payload();   
}