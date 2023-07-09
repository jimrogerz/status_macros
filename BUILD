load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "status_macros",
    srcs = [
        "status.cc",
        "status_builder.cc",
    ],
    hdrs = [
        "canonical_errors.h",
        "source_location.h",
        "status.h",
        "status_builder.h",
        "status_macros.h",
    ],
    deps = [
        "@com_google_absl//absl/base:core_headers",
        "@com_google_absl//absl/memory",
        "@com_google_absl//absl/status",
        "@com_google_absl//absl/strings",
    ],
    copts = ["-std=c++14"],
)