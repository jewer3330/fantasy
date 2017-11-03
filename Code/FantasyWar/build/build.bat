@if "%DEBUG%" == "" @echo off
@rem ##########################################################################
@rem
@rem  zj window shell script for unity build
@rem  2016年7月28日15:22:03
@rem
@rem ##########################################################################

@rem Set local scope for the variables with windows NT shell
if "%OS%"=="Windows_NT" setlocal

@rem 设置环境变量
set DIRNAME=%~dp0
cd %DIRNAME%
set CURRENTDIR=%DIRNAME%
cd..
set PARENTDIR=%cd%
cd %CURRENTDIR%
set PROJECT_PATH=%PARENTDIR%
set UNITY_LOG_PATH=C:\Users\Administrator\AppData\Local\Unity\Editor\
set UNITY_PATH=C:\Program Files\Unity\Editor\
set SVN_PATH=C:\Program Files\TortoiseSVN\bin\
set ZIP_PATH=C:\Program Files\Easy 7-Zip\
set KEYSTORE_FILE_PATH=%DIRNAME%keystore.txt

set UNITY_BIN="%UNITY_PATH%Unity.exe"
set SVN_BIN="%SVN_PATH%svn.exe"
set ZIP_BIN="%ZIP_PATH%7z.exe"
set VERSION_FILE_PATH=%PROJECT_PATH%\config\versionRes.txt

::必选参数(client|hero|quick)
set CHANNEL=%1

::必选参数(gen_res|no_gen_res)
set GEN_RES=%2

::可选参数，不填，则手动输入
::或者auto 自动
::或者填写已经存在版本号
::当GEN_RES=gen_res时，该参数无效
set VERSION=%3

::可选参数，不填或者填写noupdate，则不打开SVN更新
::当GEN_RES=gen_res时，该参数无效，并自动更新
::当GEN_RES=no_gen_res时，该参数有效
set NEED_UPDATE=%4

::可选参数
::当值为out时，则是外网版本
set INTER_NETWORK=%5
echo.
@echo 配置信息
echo.
@echo PROJECT_PATH	%PROJECT_PATH%
@echo UNITY_LOG_PATH	%UNITY_LOG_PATH%
@echo UNITY_PATH	%UNITY_PATH%
@echo SVN_PATH	%SVN_PATH%
@echo ZIP_PATH	%ZIP_PATH%
@echo KEYSTORE_FILE_PATH	%KEYSTORE_FILE_PATH%
echo.
@echo 参数信息
echo.
@echo CHANNEL 	%CHANNEL%
@echo GEN_RES 	%GEN_RES%
@echo VERSION 	%VERSION%
@echo NEED_UPDATE 	%NEED_UPDATE%
@echo INTER_NETWORK 	%INTER_NETWORK%

if not "%CHANNEL%"=="" goto checkChannel
echo.
echo "ERROR: CHANNEL is not set"
echo "Usage: build (client|hero|quick) (gen_res|no_gen_res) [version] [update] [out] "
goto fail

@rem 检测渠道设置
:checkChannel
if exist "%CHANNEL%" goto checkKeystoreFilePath
echo.
echo "ERROR: CHANNEL is not suport var is %CHANNEL%"
echo "Usage: build (client|hero|quick) (gen_res|no_gen_res) [version] [update] [out] "
goto fail

:checkKeystoreFilePath
if exist "%KEYSTORE_FILE_PATH%" goto checkResSetting
echo.
echo "ERROR: KEYSTORE_FILE_PATH is not not correct %KEYSTORE_FILE_PATH%"
goto fail

:checkResSetting
del /f /s /q %PROJECT_PATH%\config\keystore.txt 
copy %KEYSTORE_FILE_PATH% %PROJECT_PATH%\config\keystore.txt 
if "%GEN_RES%" == "gen_res" 		goto  checkProjectPath
if "%GEN_RES%" == "no_gen_res"  	goto  checkProjectPath
echo.
echo "ERROR: GEN_RES is not suport var is %GEN_RES%"
echo "Usage: build (client|hero|quick) (gen_res|no_gen_res) [version] [update] [out] "
goto fail

:checkProjectPath
if exist "%PROJECT_PATH%" goto checkUpdate
echo.
echo 项目路径不存在,当前配置%PROJECT_PATH%
echo.
goto fail


:checkVersion
if "%GEN_RES%" == "gen_res" goto autoVersion
if "%GEN_RES%" == "no_gen_res" goto setVersion
goto fail

:setVersion
if "%VERSION%"=="auto" goto autoVersion
if "%VERSION%"=="" goto userSetVersion
if not "%VERSION%"=="" goto copyVersion
goto fail

:userSetVersion
set /p VERSION=请输入版本号:
echo 输入的版本号为%VERSION%
if "%VERSION%"=="" goto autoVersion
if not "%VERSION%"=="" goto copyVersion
goto fail

:autoVersion
echo.
echo 版本号自动
echo.
for /f "tokens=1" %%a in (%VERSION_FILE_PATH%) do ( set BUILD_VERSION=%%a )
set BUILD_VERSION=%BUILD_VERSION: =%
echo.
echo 读取版本号是%BUILD_VERSION%
echo.
set VERSION=%BUILD_VERSION%
if "%GEN_RES%" == "gen_res" goto onSetChannel
if "%GEN_RES%" == "no_gen_res" goto copyVersion
goto fail

:copyVersion
echo.
echo 拷贝版本号
echo.
echo "%PROJECT_PATH%\lastRes\Android\%VERSION%\version.dat"
if not exist "%PROJECT_PATH%\lastRes\Android\%VERSION%\version.dat" goto checkVersionFile
copy %PROJECT_PATH%\lastRes\Android\%VERSION%\version.dat %PROJECT_PATH%\Assets\StreamingAssets\version.dat
goto onSetChannel

:checkVersionFile
echo.
echo 指定版本不存在 -----》%PROJECT_PATH%\lastRes\Android\%VERSION%\version.dat
echo.
goto fail

:onSetChannel
echo.
echo 项目路径%PROJECT_PATH%
echo.
rd /s /q %PROJECT_PATH%\Assets\Plugins\Android
del /f /s /q %PROJECT_PATH%\ProjectSettings\ProjectSettings.asset
echo.
echo 拷贝Android配置
echo.
xcopy %DIRNAME%\%CHANNEL%\Android %PROJECT_PATH%\Assets\Plugins\Android\ /s /e /y /q 
echo.
echo 拷贝项目配置
echo.
copy %DIRNAME%\%CHANNEL%\ProjectSettings.asset %PROJECT_PATH%\ProjectSettings\ProjectSettings.asset
echo.
echo 拷贝CDN配置
echo.
copy %DIRNAME%\%CHANNEL%\url.dat %PROJECT_PATH%\Assets\StreamingAssets\url.dat
echo.
echo 拷贝渠道配置
echo.
copy %DIRNAME%\%CHANNEL%\channel.dat %PROJECT_PATH%\Assets\StreamingAssets\channel.dat
echo.
echo 拷贝资源路径配置
echo.
copy %DIRNAME%\%CHANNEL%\channel_res.dat %PROJECT_PATH%\Assets\StreamingAssets\channel_res.dat
echo.
echo.
echo 拷贝DEV配置
del /f /s /q %PROJECT_PATH%\config\dev.txt
copy %DIRNAME%\%CHANNEL%\dev.txt %PROJECT_PATH%\config\dev.txt
echo.
goto excuteUnity

:checkUpdate
if "%GEN_RES%" == "gen_res" goto needUpdate
if "%NEED_UPDATE%"=="update" goto needUpdate
if not "%NEED_UPDATE%"=="noupdate" goto needUpdate
echo.
echo 不更新版本打包
echo.
goto checkVersion

:needUpdate
echo.
echo 更新代码和资源中
echo.
if exist "%SVN_PATH%" goto svnUpdate
echo.
echo ERROR: SVN_PATH is set to an invalid directory: %SVN_PATH%
echo.
echo Please set the SVN_PATH variable in your environment to match the
echo location of your SVN installation.

goto fail

:svnUpdate
del /f /q log\svnlog.txt
call %SVN_BIN% --accept theirs-full update %PROJECT_PATH% >>log\svnlog.txt
goto checkVersion

:excuteUnity

rd /s /q %PROJECT_PATH%\Library\ScriptAssemblies
del /f /s /q %PROJECT_PATH%\Library\ProjectSettings.asset
del /f /q %UNITY_LOG_PATH%Editor.log 

if "%INTER_NETWORK%" == "" 		goto buildInternal
if "%INTER_NETWORK%" == "out" 	goto buildOuternal 
echo.
echo 内网版还是外网版？"%INTER_NETWORK%"
echo.
goto fail

:buildInternal
if "%GEN_RES%" == "gen_res" goto buildInternalGenRes
if "%GEN_RES%" == "no_gen_res" goto buildInternalNoGenRes
goto fail

:buildOuternal
if "%GEN_RES%" == "gen_res" goto buildOuternalGenRes
if "%GEN_RES%" == "no_gen_res" goto buildOuternalNoGenRes
goto fail

:buildInternalGenRes
echo.
echo 重新生成资源版本
echo.
call %UNITY_BIN%  -projectPath %PROJECT_PATH% -batchmode -executeMethod AndroidOneKeyTool.StartBuildQuiet -quit 
goto log

:buildInternalNoGenRes
echo.
echo 不重新生成资源版本
echo.
call %UNITY_BIN%  -projectPath %PROJECT_PATH% -batchmode -executeMethod AndroidTool.RefreshAndWaitForCompile -quit 
call %UNITY_BIN%  -projectPath %PROJECT_PATH% -batchmode -executeMethod AndroidTool.BuildApkNoGenResUploadApk -quit 
goto log

:buildOuternalGenRes
echo.
echo 重新生成资源外网版本
echo 废弃的配置，请不要加最后一个参数
goto fail
echo.
goto log

:buildOuternalNoGenRes
REM echo.
REM echo 不重新生成资源外网版本
REM echo.
REM call %UNITY_BIN%  -projectPath %PROJECT_PATH% -batchmode -executeMethod AndroidTool.RefreshAndWaitForCompile -quit
REM call %UNITY_BIN%  -projectPath %PROJECT_PATH% -batchmode -executeMethod AndroidTool.BuildReleaseAPKMiniAndAPKALL -quit
REM goto log
echo.
echo 重新生成资源外网版本
echo 废弃的配置，请不要加最后一个参数
goto fail
echo.
goto log

:log
echo.
echo 生成日志中...
echo.
copy  %PROJECT_PATH%\config\analysis.csv 		log\analysis.csv
copy  %PROJECT_PATH%\config\buildDiff.json 	log\buildDiff.json
copy  %PROJECT_PATH%\config\buildLast.json 	log\buildLast.json
copy  %PROJECT_PATH%\config\buildLog.json		log\buildLog.json
copy  %PROJECT_PATH%\config\record.txt 		log\record.txt
copy  %PROJECT_PATH%\config\record_build.txt 	log\record_build.txt
copy  %PROJECT_PATH%\config\record_del.txt 	log\record_del.txt
copy  %PROJECT_PATH%\config\record_diff.txt 	log\record_diff.txt
copy  %PROJECT_PATH%\config\record_new.txt 	log\record_new.txt
copy  %UNITY_LOG_PATH%Editor.log 		log\build.log

goto zip

:zip
if exist "%ZIP_PATH%" goto onSetZip
echo.
echo ERROR: ZIP_PATH is set to an invalid directory: %ZIP_PATH%
echo.
echo Please set the ZIP_PATH variable in your environment to match the
echo location of your 7-Zip installation.
goto fail

:onSetZip
echo.
echo 压缩日志中...
echo.
del /f /q log.7z
%ZIP_BIN% a -t7z log.7z log\* -r 
goto readVersion

:readVersion
for /f "tokens=1" %%a in (%VERSION_FILE_PATH%) do ( set BUILD_VERSION=%%a )
set BUILD_VERSION=%BUILD_VERSION: =%
echo.
echo 完成版本号是%BUILD_VERSION%
echo.
if "%INTER_NETWORK%" == ""  set TAG=_release
if "%INTER_NETWORK%" == "out" set TAG=_release
goto mail

:mail
echo.
echo 发送邮件中...
echo.
del /f /q %DIRNAME%\message.txt
echo 打%CHANNEL%%TAG%包完成,版本号%BUILD_VERSION% >> %DIRNAME%\message.txt
echo 计算机名称%COMPUTERNAME% >> %DIRNAME%\message.txt
echo 资源目录 file:\\192.168.2.85\FtpData\%CHANNEL%%TAG%\Android\%BUILD_VERSION% >> %DIRNAME%\message.txt
echo 完整APK路径 http://116.236.180.14/%CHANNEL%%TAG%/Android/TankGirl_%CHANNEL%%TAG%_%BUILD_VERSION%_full.apk >> %DIRNAME%\message.txt
REM echo 小包APK路径 http://116.236.180.14/%CHANNEL%%TAG%/Android/%BUILD_VERSION%/TankGirl.apk >> %DIRNAME%\message.txt
echo.>> %DIRNAME%\message.txt
echo.>> %DIRNAME%\message.txt
echo.>> %DIRNAME%\message.txt
echo 岂曰无衣？>> %DIRNAME%\message.txt
echo 与子同袍。>> %DIRNAME%\message.txt
echo 王于兴师，修我戈矛，与子同仇！>> %DIRNAME%\message.txt
echo 岂曰无衣？>> %DIRNAME%\message.txt
echo 与子同泽。>> %DIRNAME%\message.txt
echo 王于兴师，修我矛戟，与子偕作！>> %DIRNAME%\message.txt
echo 岂曰无衣？>> %DIRNAME%\message.txt
echo 与子同裳。>> %DIRNAME%\message.txt
echo 王于兴师，修我甲兵，与子偕行！>> %DIRNAME%\message.txt
REM %DIRNAME%\blat.exe %DIRNAME%\message.txt -to 76083509@qq.com -subject 打包完成 -server smtp.126.com -f ****@***.com 换成自己邮箱 -u wujiezhaojun -pw ******* 换成自己得密码 -charset Gb2312 -attach log.7z -cc 601954289@qq.com,2776133@qq.com,316259872@qq.com,zhiqiang.xie@yingxiong.com,yong.zhang@yingxiong.com,178478909@qq.com
goto sucess

:fail
echo.
@echo 打包失败
echo.
pause
goto end

:sucess
echo.
@echo 打包成功
echo.
goto end

:end
if "%OS%"=="Windows_NT" endlocal
