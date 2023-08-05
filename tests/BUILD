load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

cc_test(
  name = "status_macros_test",
  srcs = ["status_macros_test.cc"],
  deps = [
    "@status_macros//:status_macros",
    "@com_google_absl//absl/status",
    "@com_google_absl//absl/status:statusor",
    "@com_google_googletest//:gtest_main"
  ],
)

