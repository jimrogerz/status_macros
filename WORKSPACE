workspace(name = "root")
 
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
  name = "com_google_absl",
  urls = ["https://github.com/abseil/abseil-cpp/archive/c2435f8342c2d0ed8101cb43adfd605fdc52dca2.zip"],
  strip_prefix = "abseil-cpp-c2435f8342c2d0ed8101cb43adfd605fdc52dca2",
)

http_archive(
  name = "bazel_skylib",
  urls = ["https://github.com/bazelbuild/bazel-skylib/releases/download/1.2.1/bazel-skylib-1.2.1.tar.gz"],
  sha256 = "f7be3474d42aae265405a592bb7da8e171919d74c16f082a5457840f06054728",
)

http_archive(
  name = "com_google_googletest",
  urls = ["https://github.com/google/googletest/archive/58d77fa8070e8cec2dc1ed015d66b454c8d78850.zip"],
  strip_prefix = "googletest-58d77fa8070e8cec2dc1ed015d66b454c8d78850",
)
