load("@rules_cc//cc:defs.bzl","cc_test")
load("@rules_cc//cc:defs.bzl", "cc_library")
load("@rules_proto//proto:defs.bzl", "proto_library")
load("@rules_cc//cc:defs.bzl", "cc_proto_library")
load("@rules_cc//cc:defs.bzl","cc_binary")

proto_library(
    name = "thing_proto",
    srcs = ["lib/thing.proto"],
)

cc_proto_library(
    name = "cpp_thing_proto",
    deps = [":thing_proto"],
)

cc_library(
    name = "lib",
    hdrs = glob(["lib/*.h"]),
    srcs = ["lib/message.cpp"],
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
        ":lib"
    ],
)

cc_test(
    name = "test",
    srcs = glob(["test/*.cpp"]),
    deps = [
        ":lib",
        "@googletest//:gtest",
        "@googletest//:gtest_main",
    ],
)