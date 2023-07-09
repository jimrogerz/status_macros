# Google C++ Status Macros

This repository contains a [bazel](https://bazel.build) build target for Google C++ status macros, redistributed from [mediapipe](https://github.com/google/mediapipe).


## Setup

Add the following to your WORKSPACE file:


```
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

git_repository(
    name = "status_macros",
    commit = "169fa76f8f2a83308c91b0a421c20aac6e42d1fe",
    remote = "https://github.com/jimrogerz/status_macros.git",
)
```

Add `"@status_macros//:status_macros"` to your BUILD deps, then `#include "status_macros.h"` to your source.

## Usage

See [RETURN_IF_ERROR](https://github.com/jimrogerz/status_macros/blob/main/status_macros.h#L29) and [ASSIGN_OR_RETURN](https://github.com/jimrogerz/status_macros/blob/main/status_macros.h#L91).
