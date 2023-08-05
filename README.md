# Google C++ Status Macros

This repository contains a minimal [bazel](https://bazel.build) build target for Google C++ status macros, redistributed from [mediapipe](https://github.com/google/mediapipe).

## Setup

### Bzlmod

This repo supports integration with [Bzlmod](https://docs.bazel.build/versions/5.0.0/bzlmod.html).

I'll see if I can [get this in the central repository](https://github.com/bazelbuild/bazel-central-registry/pull/815), but for now looks like you'll have to set it up
with a [local registry](https://bazel.build/external/registry).

### WORKSPACE

If you're not using Bzlmod, add the following to your WORKSPACE file:


```
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

git_repository(
    name = "status_macros",
    commit = "1592ab2d4b4f92976fc3f4a6cb3a1323a4b549c3",
    remote = "https://github.com/jimrogerz/status_macros.git",
)
```

Also make sure you have transitive dependencies from this repo's [WORKSPACE](https://github.com/jimrogerz/status_macros/blob/main/WORKSPACE).

### BUILD

Add `"@status_macros//:status_macros"` to BUILD deps for targets that use this.


## Usage

Add `#include "status_macros.h"` to your source.

See [RETURN_IF_ERROR](https://github.com/jimrogerz/status_macros/blob/main/status_macros.h#L29) and [ASSIGN_OR_RETURN](https://github.com/jimrogerz/status_macros/blob/main/status_macros.h#L91).
