#include "absl/status/status.h"
#include "absl/status/statusor.h"
#include "status_macros.h"
#include <gtest/gtest.h>

// Returns status1 if it is an error, otherwise status2
absl::Status ReturnIfError(absl::Status status1, absl::Status status2) {
  RETURN_IF_ERROR(status1);
  return status2;
}

absl::StatusOr<int> ReturnValueIfOk(absl::Status status, int value) {
  if (status.ok()) {
    return value;
  }
  return status;
}

absl::StatusOr<int> AssignValueIfOk(absl::Status status, int value) {
  ASSIGN_OR_RETURN(auto result, ReturnValueIfOk(status, value));
  return result;
}

TEST(StatusMacrosTest, ReturnIfErrorReturnsError) {
  absl::Status status1 = absl::InternalError("error");
  absl::Status status2 = absl::OkStatus();

  auto status = ReturnIfError(status1, status2);

  EXPECT_EQ(status, status1);
}

TEST(StatusMacrosTest, ReturnIfErrorDoesNotReturnOk) {
  absl::Status status1 = absl::OkStatus();
  absl::Status status2 = absl::InternalError("error");

  auto status = ReturnIfError(status1, status2);

  EXPECT_EQ(status, status2);
}

TEST(StatusMacroTest, AssignOrReturnAssignsIfOk) {
  auto result = AssignValueIfOk(absl::OkStatus(), 1);

  EXPECT_TRUE(result.status().ok());
  EXPECT_EQ(result.value(), 1);
}

TEST(StatusMacroTest, AssignOrReturnReturnsError) {
  auto error = absl::InternalError("error");

  auto result = AssignValueIfOk(error, 1);

  EXPECT_EQ(result.status(), error);
}
