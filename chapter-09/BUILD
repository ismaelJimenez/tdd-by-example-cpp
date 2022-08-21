cc_test(
  name = "test",
  size = "small",
      srcs = glob(
        include = [
            "*.cpp",
            "*.hpp",
        ],
    ),
  deps = ["@com_google_googletest//:gtest_main"],
  copts = ["--std=c++17"],
)