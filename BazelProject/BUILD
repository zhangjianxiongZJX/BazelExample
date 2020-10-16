load("@rules_cc//cc:defs.bzl","cc_test")
load("@rules_cc//cc:defs.bzl", "cc_library")
load("@rules_proto//proto:defs.bzl", "proto_library")
load("@rules_cc//cc:defs.bzl", "cc_proto_library")
load("@rules_cc//cc:defs.bzl","cc_binary")

proto_library(
    name = "thing_proto",
    srcs = ["MyLib/thing.proto"],
)

cc_proto_library(
    name = "cpp_thing_proto",
    deps = [":thing_proto"],
)

cc_library(
    name = "MyLib",
    hdrs = glob(["MyLib/*.h"]),
    srcs = ["MyLib/message.cpp"],
    deps = [
        ":cpp_thing_proto",
        "@bazelTest//:bazelTest",
        "@openssl//:openssl",
        "@hello//:hello"
    ],
    visibility = ["//visibility:public"],
)

cc_binary (
    name = "hello",
    srcs = ["main/test.cpp"],
    deps = [
        ":MyLib"
    ],
)

cc_test(
    name = "MyTest",
    srcs = glob(["test/*.cpp"]),
    deps = [
        ":MyLib",
        "@googletest//:gtest",
        "@googletest//:gtest_main",
    ],
)