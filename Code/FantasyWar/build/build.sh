#!/bin/sh
#环境变量
DIRNAME="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
cd $DIRNAME
CURRENTDIR=$DIRNAME
cd..
PARENTDIR=$pwd
cd $CURRENTDIR
PROJECT_PATH=$PARENTDIR

UNITY_LOG_PATH="/Users/dmw/Library/Logs/Unity/"
UNITY_PATH=/Applications/Unity/Unity.app/Contents/MacOS/Unity
KEYSTORE_FILE_PATH="$DIRNAME"/keystore.txt
UNITY_BIN="$UNITY_PATH"
VERSION_FILE_PATH="$PROJECT_PATH"/config/buildVersion.txt
TAG=_release
SVN_BIN="svn"
ZIP_BIN="zip"
#必选参数(client|hero|quick)
CHANNEL=$1
#必选参数(gen_res|no_gen_res)
GEN_RES=$2
echo
echo 配置信息
echo DIRNAME $DIRNAME
echo PROJECT_PATH	$PROJECT_PATH
echo UNITY_LOG_PATH	$UNITY_LOG_PATH
echo UNITY_PATH	$UNITY_PATH
#echo SVN_PATH	$SVN_PATH
#echo ZIP_PATH	$ZIP_PATH
echo KEYSTORE_FILE_PATH	$KEYSTORE_FILE_PATH
echo UNITY_BIN	$UNITY_BIN
echo SVN_BIN	$SVN_BIN
echo ZIP_BIN	$ZIP_BIN
echo VERSION_FILE_PATH	$VERSION_FILE_PATH
echo
echo 参数信息
echo
echo CHANNEL 	$CHANNEL
echo GEN_RES 	$GEN_RES
# 检测渠道设置
checkChannel()
{
if 	[ -n "$CHANNEL" -o -d "$CHANNEL"  ]
then
checkKeystoreFilePath;
else
echo "ERROR: CHANNEL is not suport current is $CHANNEL"
echo "Usage: build (client|hero|quick) (gen_res|no_gen_res) "
fail;
fi
return 0;
}
checkKeystoreFilePath()
{
if [ -n "$KEYSTORE_FILE_PATH" -o -d "$KEYSTORE_FILE_PATH" ]
	rm -f $PROJECT_PATH/config/keystore.txt
	cp $KEYSTORE_FILE_PATH $PROJECT_PATH/config/keystore.txt
then
checkResSetting;
else
echo "ERROR: KEYSTORE_FILE_PATH is not not correct $KEYSTORE_FILE_PATH"
fail;
fi
return 0;
}
checkResSetting()
{
if 	[ "$GEN_RES" = "gen_res" -o "$GEN_RES" = "no_gen_res" ]
then
checkProjectPath;
else
echo "ERROR: GEN_RES is not suport var is $GEN_RES"
echo "Usage: build (client|hero|quick) (gen_res|no_gen_res)  "
fail;
fi
return 0;
}
checkProjectPath()
{
if [ -n "$PROJECT_PATH" -o -d  "$PROJECT_PATH" ]
then needUpdate;
else
echo 项目路径不存在,当前配置"$PROJECT_PATH"
fail;
fi
return 0;
}
needUpdate()
{
echo 更新代码和资源中
if [ -n "$SVN_PATH" -o -d "$SVN_PATH" ]
"$SVN_BIN" --version
then
svnUpdate;
else
echo ERROR: SVN_PATH is set to an invalid directory: %SVN_PATH%
echo Please set the SVN_PATH variable in your environment to match the
echo location of your SVN installation.
fail;
fi
return 0;
}
svnUpdate()
{
rm -f log/svnlog.txt
"$SVN_BIN" --accept theirs-full update "$PROJECT_PATH" >>log/svnlog.txt
autoVersion;
return 0;
}
autoVersion()
{
echo 版本号自动
onSetChannel;
return 0;
}
onSetChannel()
{
echo 项目路径"$PROJECT_PATH"
rm -rf "$PROJECT_PATH"/Assets/Plugins/Android
rm -r "$PROJECT_PATH"/ProjectSettings/ProjectSettings.asset
echo 拷贝Android配置
cp -rf "$DIRNAME"/"$CHANNEL"/Android "$PROJECT_PATH"/Assets/Plugins/Android

echo 拷贝项目配置
cp "$DIRNAME"/"$CHANNEL"/ProjectSettings.asset "$PROJECT_PATH"/ProjectSettings/ProjectSettings.asset
echo 拷贝CDN配置
if [ ! -d "$PROJECT_PATH"/Assets/StreamingAssets/ ]; then
mkdir "$PROJECT_PATH"/Assets/StreamingAssets/
fi
cp "$DIRNAME"/"$CHANNEL"/url.dat "$PROJECT_PATH"/Assets/StreamingAssets/url.dat
echo 拷贝渠道配置
cp "$DIRNAME"/"$CHANNEL"/channel.dat "$PROJECT_PATH"/Assets/StreamingAssets/channel.dat
echo 拷贝资源路径配置
cp "$DIRNAME"/"$CHANNEL"/channel_res.dat "$PROJECT_PATH"/Assets/StreamingAssets/channel_res.dat
echo 拷贝DEV配置
rm -r "$PROJECT_PATH"/config/dev.txt
cp "$DIRNAME"/"$CHANNEL"/dev.txt "$PROJECT_PATH"/config/dev.txt
excuteUnity;
return 0;
}
excuteUnity()
{
rm -rf $PROJECT_PATH/Library/ScriptAssemblies
rm -f $PROJECT_PATH/Library/ProjectSettings.asset
rm -f "$UNITY_LOG_PATH"Editor.log
buildInternal;
return 0;
}
buildInternal()
{
if [ $GEN_RES = "gen_res" ]
then buildInternalGenRes; fi
if [ $GEN_RES = "no_gen_res" ]
then buildInternalNoGenRes; fi
return 0;
}
buildInternalGenRes()
{
echo 重新生成资源版本
"$UNITY_BIN"  -projectPath "$PROJECT_PATH" -batchmode -executeMethod AndroidOneKeyTool.StartBuildQuiet -quit
log;
return 0;
}
buildInternalNoGenRes()
{
echo 不重新生成资源版本
"$UNITY_BIN"  -projectPath "$PROJECT_PATH" -batchmode -executeMethod AndroidTool.RefreshAndWaitForCompile -quit
"$UNITY_BIN"  -projectPath "$PROJECT_PATH" -batchmode -executeMethod AndroidTool.BuildApkNoGenResUploadApk -quit
log;
return 0;
}
log()
{
echo 生成日志中...
cp  -f "$PROJECT_PATH"/config/analysis.csv 		log/analysis.csv
cp  -f "$PROJECT_PATH"/config/buildDiff.json 		log/buildDiff.json
cp  -f "$PROJECT_PATH"/config/buildLast.json 		log/buildLast.json
cp  -f "$PROJECT_PATH"/config/buildLog.json		log/buildLog.json
cp  -f "$PROJECT_PATH"/config/record.txt 			log/record.txt
cp  -f "$PROJECT_PATH"/config/record_build.txt 	log/record_build.txt
cp  -f "$PROJECT_PATH"/config/record_del.txt 		log/record_del.txt
cp  -f "$PROJECT_PATH"/config/record_diff.txt 	log/record_diff.txt
cp  -f "$PROJECT_PATH"/config/record_new.txt 		log/record_new.txt
cp  "$UNITY_LOG_PATH"Editor.log 		log/build.log
dozip;
return 0;
}
dozip()
{
if [ -n "$ZIP_PATH"  -o -d "$ZIP_PATH" ]
"$ZIP_BIN" -h;
then
onSetZip;
else
echo ERROR: ZIP_PATH is set to an invalid directory: "$ZIP_PATH"
echo Please set the ZIP_PATH variable in your environment to match the
echo location of your Zip installation.
fail;
fi
return 0;
}
onSetZip()
{
echo 压缩日志中...
rm -f log.7z
#"$ZIP_BIN" a -t7z log.7z log/* -r
"$ZIP_BIN" -r log.7z  log/*
sendmail;
return 0;
}

sendmail()
{
echo 发送邮件中...
rm -f "$DIRNAME"/message.txt
echo "$CHANNEL""$TAG"完成 >> message.txt
echo "这条消息来自尊贵的垃圾桶" >> message.txt
echo 文件路径 \\\\192.168.2.85\\FtpData\\"$CHANNEL""$TAG"\\Android\\>> message.txt
cat message.txt > aa
mail -s "打包完成" 76083509@qq.com < aa
sucess;       
return 0;
}
fail()
{
echo 打包失败
read INP &&
if [ -n $INP  ] ;then
echo
fi
end;
return 0;
}
sucess()
{
svn commit "$PROJECT_PATH"/config/buildVersion.txt -m "黑苹果提交资源版本号"
svn commit "$PROJECT_PATH"/config/versionCode.txt -m "黑苹果提交代码版本号"
echo 打包成功
end;
return 0;
}
end()
{
return 0;
}
if [ -n $CHANNEL  ]
then
checkChannel;
else
echo "ERROR: CHANNEL is not set"
echo "Usage: build (client|hero|quick) (gen_res|no_gen_res) "
fail;
fi