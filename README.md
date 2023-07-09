# Google C++ Status Macros

This repository contains a [bazel](https://bazel.build) build target for Google C++ status macros, redistributed from [mediapipe](https://github.com/google/mediapipe).


## Setup

Add the following to your WORKSPACE file:


```
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository", "new_git_repository")

git_repository(
    name = "status_macros",
    commit = "edc9a19d526220c4db4086df1e3a74717629d169",
    remote = "https://github.com/jimrogerz/status_macros.git",
)
```

Add `"@status_macros//:status_macros"` to your BUILD deps, then `#include "status_macros.h"` to your source.

## Usage

See [ASSIGN_OR_RETURN](https://github.com/jimrogerz/status_macros/blob/main/status_macros.h#L100) and [RETURN_IF_ERROR](https://github.com/jimrogerz/status_macros/blob/main/status_macros.h#L61).
