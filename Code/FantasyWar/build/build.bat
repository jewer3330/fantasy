@if "%DEBUG%" == "" @echo off
@rem ##########################################################################
@rem
@rem  zj window shell script for unity build
@rem  2016��7��28��15:22:03
@rem
@rem ##########################################################################

@rem Set local scope for the variables with windows NT shell
if "%OS%"=="Windows_NT" setlocal

@rem ���û�������
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

::��ѡ����(client|hero|quick)
set CHANNEL=%1

::��ѡ����(gen_res|no_gen_res)
set GEN_RES=%2

::��ѡ������������ֶ�����
::����auto �Զ�
::������д�Ѿ����ڰ汾��
::��GEN_RES=gen_resʱ���ò�����Ч
set VERSION=%3

::��ѡ���������������дnoupdate���򲻴�SVN����
::��GEN_RES=gen_resʱ���ò�����Ч�����Զ�����
::��GEN_RES=no_gen_resʱ���ò�����Ч
set NEED_UPDATE=%4

::��ѡ����
::��ֵΪoutʱ�����������汾
set INTER_NETWORK=%5
echo.
@echo ������Ϣ
echo.
@echo PROJECT_PATH	%PROJECT_PATH%
@echo UNITY_LOG_PATH	%UNITY_LOG_PATH%
@echo UNITY_PATH	%UNITY_PATH%
@echo SVN_PATH	%SVN_PATH%
@echo ZIP_PATH	%ZIP_PATH%
@echo KEYSTORE_FILE_PATH	%KEYSTORE_FILE_PATH%
echo.
@echo ������Ϣ
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

@rem �����������
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
echo ��Ŀ·��������,��ǰ����%PROJECT_PATH%
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
set /p VERSION=������汾��:
echo ����İ汾��Ϊ%VERSION%
if "%VERSION%"=="" goto autoVersion
if not "%VERSION%"=="" goto copyVersion
goto fail

:autoVersion
echo.
echo �汾���Զ�
echo.
for /f "tokens=1" %%a in (%VERSION_FILE_PATH%) do ( set BUILD_VERSION=%%a )
set BUILD_VERSION=%BUILD_VERSION: =%
echo.
echo ��ȡ�汾����%BUILD_VERSION%
echo.
set VERSION=%BUILD_VERSION%
if "%GEN_RES%" == "gen_res" goto onSetChannel
if "%GEN_RES%" == "no_gen_res" goto copyVersion
goto fail

:copyVersion
echo.
echo �����汾��
echo.
echo "%PROJECT_PATH%\lastRes\Android\%VERSION%\version.dat"
if not exist "%PROJECT_PATH%\lastRes\Android\%VERSION%\version.dat" goto checkVersionFile
copy %PROJECT_PATH%\lastRes\Android\%VERSION%\version.dat %PROJECT_PATH%\Assets\StreamingAssets\version.dat
goto onSetChannel

:checkVersionFile
echo.
echo ָ���汾������ -----��%PROJECT_PATH%\lastRes\Android\%VERSION%\version.dat
echo.
goto fail

:onSetChannel
echo.
echo ��Ŀ·��%PROJECT_PATH%
echo.
rd /s /q %PROJECT_PATH%\Assets\Plugins\Android
del /f /s /q %PROJECT_PATH%\ProjectSettings\ProjectSettings.asset
echo.
echo ����Android����
echo.
xcopy %DIRNAME%\%CHANNEL%\Android %PROJECT_PATH%\Assets\Plugins\Android\ /s /e /y /q 
echo.
echo ������Ŀ����
echo.
copy %DIRNAME%\%CHANNEL%\ProjectSettings.asset %PROJECT_PATH%\ProjectSettings\ProjectSettings.asset
echo.
echo ����CDN����
echo.
copy %DIRNAME%\%CHANNEL%\url.dat %PROJECT_PATH%\Assets\StreamingAssets\url.dat
echo.
echo ������������
echo.
copy %DIRNAME%\%CHANNEL%\channel.dat %PROJECT_PATH%\Assets\StreamingAssets\channel.dat
echo.
echo ������Դ·������
echo.
copy %DIRNAME%\%CHANNEL%\channel_res.dat %PROJECT_PATH%\Assets\StreamingAssets\channel_res.dat
echo.
echo.
echo ����DEV����
del /f /s /q %PROJECT_PATH%\config\dev.txt
copy %DIRNAME%\%CHANNEL%\dev.txt %PROJECT_PATH%\config\dev.txt
echo.
goto excuteUnity

:checkUpdate
if "%GEN_RES%" == "gen_res" goto needUpdate
if "%NEED_UPDATE%"=="update" goto needUpdate
if not "%NEED_UPDATE%"=="noupdate" goto needUpdate
echo.
echo �����°汾���
echo.
goto checkVersion

:needUpdate
echo.
echo ���´������Դ��
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
echo �����滹�������棿"%INTER_NETWORK%"
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
echo ����������Դ�汾
echo.
call %UNITY_BIN%  -projectPath %PROJECT_PATH% -batchmode -executeMethod AndroidOneKeyTool.StartBuildQuiet -quit 
goto log

:buildInternalNoGenRes
echo.
echo ������������Դ�汾
echo.
call %UNITY_BIN%  -projectPath %PROJECT_PATH% -batchmode -executeMethod AndroidTool.RefreshAndWaitForCompile -quit 
call %UNITY_BIN%  -projectPath %PROJECT_PATH% -batchmode -executeMethod AndroidTool.BuildApkNoGenResUploadApk -quit 
goto log

:buildOuternalGenRes
echo.
echo ����������Դ�����汾
echo ���������ã��벻Ҫ�����һ������
goto fail
echo.
goto log

:buildOuternalNoGenRes
REM echo.
REM echo ������������Դ�����汾
REM echo.
REM call %UNITY_BIN%  -projectPath %PROJECT_PATH% -batchmode -executeMethod AndroidTool.RefreshAndWaitForCompile -quit
REM call %UNITY_BIN%  -projectPath %PROJECT_PATH% -batchmode -executeMethod AndroidTool.BuildReleaseAPKMiniAndAPKALL -quit
REM goto log
echo.
echo ����������Դ�����汾
echo ���������ã��벻Ҫ�����һ������
goto fail
echo.
goto log

:log
echo.
echo ������־��...
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
echo ѹ����־��...
echo.
del /f /q log.7z
%ZIP_BIN% a -t7z log.7z log\* -r 
goto readVersion

:readVersion
for /f "tokens=1" %%a in (%VERSION_FILE_PATH%) do ( set BUILD_VERSION=%%a )
set BUILD_VERSION=%BUILD_VERSION: =%
echo.
echo ��ɰ汾����%BUILD_VERSION%
echo.
if "%INTER_NETWORK%" == ""  set TAG=_release
if "%INTER_NETWORK%" == "out" set TAG=_release
goto mail

:mail
echo.
echo �����ʼ���...
echo.
del /f /q %DIRNAME%\message.txt
echo ��%CHANNEL%%TAG%�����,�汾��%BUILD_VERSION% >> %DIRNAME%\message.txt
echo ���������%COMPUTERNAME% >> %DIRNAME%\message.txt
echo ��ԴĿ¼ file:\\192.168.2.85\FtpData\%CHANNEL%%TAG%\Android\%BUILD_VERSION% >> %DIRNAME%\message.txt
echo ����APK·�� http://116.236.180.14/%CHANNEL%%TAG%/Android/TankGirl_%CHANNEL%%TAG%_%BUILD_VERSION%_full.apk >> %DIRNAME%\message.txt
REM echo С��APK·�� http://116.236.180.14/%CHANNEL%%TAG%/Android/%BUILD_VERSION%/TankGirl.apk >> %DIRNAME%\message.txt
echo.>> %DIRNAME%\message.txt
echo.>> %DIRNAME%\message.txt
echo.>> %DIRNAME%\message.txt
echo ��Ի���£�>> %DIRNAME%\message.txt
echo ����ͬ�ۡ�>> %DIRNAME%\message.txt
echo ������ʦ�����Ҹ�ì������ͬ��>> %DIRNAME%\message.txt
echo ��Ի���£�>> %DIRNAME%\message.txt
echo ����ͬ��>> %DIRNAME%\message.txt
echo ������ʦ������ìꪣ�����������>> %DIRNAME%\message.txt
echo ��Ի���£�>> %DIRNAME%\message.txt
echo ����ͬ�ѡ�>> %DIRNAME%\message.txt
echo ������ʦ�����Ҽױ����������У�>> %DIRNAME%\message.txt
REM %DIRNAME%\blat.exe %DIRNAME%\message.txt -to 76083509@qq.com -subject ������ -server smtp.126.com -f ****@***.com �����Լ����� -u wujiezhaojun -pw ******* �����Լ������� -charset Gb2312 -attach log.7z -cc 601954289@qq.com,2776133@qq.com,316259872@qq.com,zhiqiang.xie@yingxiong.com,yong.zhang@yingxiong.com,178478909@qq.com
goto sucess

:fail
echo.
@echo ���ʧ��
echo.
pause
goto end

:sucess
echo.
@echo ����ɹ�
echo.
goto end

:end
if "%OS%"=="Windows_NT" endlocal
