# PHP shutdown扩展
windows下关机扩展，支持关机、注销、重启、休眠
## 使用方法
参见[shutdown.stub.php](shutdown.stub.php)

## 已测试环境
```
Microsoft Windows [版本 10.0.19045.3393]
```
```
PHP 8.2.10 (cli) (built: Aug 29 2023 21:51:44) (ZTS Visual C++ 2019 x64)
Copyright (c) The PHP Group
Zend Engine v4.2.10, Copyright (c) Zend Technologies
    with Xdebug v3.2.2, Copyright (c) 2002-2023, by Derick Rethans
```
```
Microsoft Visual Studio Community 2022 (64 位) - Current
版本 17.7.3
```
## 编译
### 环境变量
以下环境变量代指：
```
PHP_ROOT php安装目录
PHP_SRC_ROOT php源码目录
PHP_DEVEL_ROOT php devel目录
PHP_SDK_ROOT php sdk目录
```
** 生成shutdown_arginfo.h
```
%PHP_ROOT%\php.exe %PHP_SRC_ROOT%\build\gen_stub.php shutdown.stub.php
```
** 生成configure
```
%PHP_DEVEL_ROOT%\phpize.bat
```
** 进入编译shell
如果是vs 2019，执行
```
%PHP_SDK_ROOT%\phpsdk-vs16-x64.bat
```
如果是vs 2022，需要添加`MSVC v142 - VS 2019 C++ x64/x86 生成工具 (v14.29)`
先执行
```
%PHP_SDK_ROOT%\phpsdk-starter.bat -c vs17 -a x64
```
再执行，切换为vs2019环境,`-vcvars_ver`值根据`C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\Microsoft.VCToolsVersion.v142.default.txt`内容设置
```
call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvarsall.bat" x64 -vcvars_ver=14.29
```

** 生成Makefile
```
configure.bat --enable-shutdown --with-prefix=%PHP_ROOT%
```
** 编译
```
nmake
```
** 测试
```
nmake test
```
## 安装
```
nmake install
```
或手动安装，将x64\Release_TS下的php_shutdown.dll复制到%PHP_ROOT%\ext目录下
修改php.in添加内容
```
extension=shutdown
```