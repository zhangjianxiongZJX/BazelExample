# BazelExample

本项目是一个Bazel工具的示例项目。Bazel是一款类似于Maven的优秀的项目构建与管理工具。作为C++开发工程师经常在项目的管理上因为三方依赖、单元测试覆盖、协同开发、远程开发、跨平台等问题耗费大量时间，影响开发效率。使用Bazel可以很好地解决这些问题。

**1、跨平台**

Bazel通过自身制定的规则对项目进行管理和构建。只要在不同平台（Windows，Linux，MacOS）正确安装Bazel，然后就可以对项目进行构建，在项目中无需设置任何和平台相关的配置

**2、三方依赖**

Bazel对于三方库依赖管理上也非常便捷，尤其是当下分布式开发，远程依赖环境下优势更为明显，能给C++开发人员一种和Java开发中使用Maven进行依赖管理类似的感觉，十分便捷。

它支持多种依赖方式：

a、本地Bazel项目依赖

b、本地非Bazel项目依赖

c、远程git仓库Bazel项目依赖

d、远程git仓库非Bazel项目依赖

e、远程Bazel归档项目依赖

f、远程非Bazel归档项目依赖

后面四种三方依赖方式非常适合分布式开发场景。开发人员在完成项目开发后，发送到远程机进行编译时，或者团队其他人员拉去代码进行编译时，不需要每次都重新在本地安装三方依赖，Bazel会自动根据构建文件下载并重新构建依赖。

## Bazel安装

### Linux安装：

**Ubuntu:**

https://docs.bazel.build/versions/master/install-ubuntu.html

**CentOS:**

https://docs.bazel.build/versions/master/install-redhat.html

### Windows安装

https://docs.bazel.build/versions/master/install-windows.html

### MacOS安装

https://docs.bazel.build/versions/master/install-os-x.html



## 非Bazel项目依赖

**本地非Bazel项目**

```
new_local_repository(
    name = "openssl",
    path = "../localProj",
    build_file = "BUILD.openssl",
)
```

其中path为外部依赖项目的路径（可以是绝对路径，也可以是相对于workspace的路径）。BUILD.openssl是构建文件，位于workspace的根路径下，即WORKSPACE文件所在路径中。

**远程git仓库非Bazel项目**

```
load("@bazel_tools//tools/build_defs/repo:git.bzl", "new_git_repository")
new_git_repository(
    name = "bazelTest",
    remote = "https://github.com/zhangjianxiongZJX/test.git",
    commit = "f675ab36437eec682d72996ee376fa2758e5d32b",
    build_file = "BUILD.test",
)
```

为了构建这样的外部依赖，同样需要自己编写build_file（当然也可以调用外部工具链，比如cmake）。new_git_repository中的build_file不能放在workspace根路径下，必须创建一个子目录external，然后将BUILD.test放在里面。否则构建时会报错：No regular file in xx/xx/external/BUILD.test（有点坑，官方文档没提这一点）

## 外部工具使用

protobuf、gtest等工具的使用在示例项目中具有提及，只需和示例项目一样建立依赖即可使用，非常方便