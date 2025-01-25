# Google C++ Status Macros

This repository contains a [bazel](https://bazel.build) build target for Google C++ status macros,
redistributed from [mediapipe](https://github.com/google/mediapipe).

## Setup

### MODULE.bzl

```
# Add the http_archive rule if you don't have it already
http_archive = use_repo_rule("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

# Pick the latest commit from https://github.com/jimrogerz/status_macros/commits/main/
STATUS_MACROS_COMMIT = "cd57b990ffe8f6382f6680c2d16bbd3b98bdf125"
http_archive(
    name = "status_macros",
    strip_prefix = "status_macros-" + STATUS_MACROS_COMMIT,
    url = "https://github.com/jimrogerz/status_macros/archive/%s.zip" % STATUS_MACROS_COMMIT,
)
```

### BUILD

Add `"@status_macros//:status_macros"` to BUILD deps for targets that use this.

## Usage

Add `#include "status_macros.h"` to your source.

See [RETURN_IF_ERROR](https://github.com/jimrogerz/status_macros/blob/main/status_macros.h#L29) and [ASSIGN_OR_RETURN](https://github.com/jimrogerz/status_macros/blob/main/status_macros.h#L91).
