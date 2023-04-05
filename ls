[33mcommit 41d32ecc32f7500df5eb597da48902ab161d10a8[m[33m ([m[1;36mHEAD -> [m[1;32mmaster[m[33m)[m
Author: aidarchikmaturmalaichik <aidarscharaev@yandex.ru>
Date:   Wed Apr 5 17:40:19 2023 +0300

    calc without dll

[1mdiff --git a/calc.pro b/calc.pro[m
[1mnew file mode 100644[m
[1mindex 0000000..5511af5[m
[1m--- /dev/null[m
[1m+++ b/calc.pro[m
[36m@@ -0,0 +1,32 @@[m
[32m+[m[32mQT       += core gui[m
[32m+[m
[32m+[m[32mgreaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport[m
[32m+[m
[32m+[m[32mCONFIG += c++17[m
[32m+[m
[32m+[m[32m# You can make your code fail to compile if it uses deprecated APIs.[m
[32m+[m[32m# In order to do so, uncomment the following line.[m
[32m+[m[32m#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0[m
[32m+[m
[32m+[m[32mSOURCES += \[m
[32m+[m[32m    graphwindow.cpp \[m
[32m+[m[32m    main.cpp \[m
[32m+[m[32m    mainwindow.cpp \[m
[32m+[m				[32mpolish.cpp \[m
[32m+[m				[32mqcustomplot.cpp[m
[32m+[m
[32m+[m[32mHEADERS += \[m
[32m+[m[32m    graphwindow.h \[m
[32m+[m[32m    mainwindow.h \[m
[32m+[m				[32mpolish.h \[m
[32m+[m				[32mqcustomplot.h[m
[32m+[m
[32m+[m
[32m+[m[32mFORMS += \[m
[32m+[m[32m    graphwindow.ui \[m
[32m+[m[32m    mainwindow.ui[m
[32m+[m
[32m+[m[32m# Default rules for deployment.[m
[32m+[m[32mqnx: target.path = /tmp/$${TARGET}/bin[m
[32m+[m[32melse: unix:!android: target.path = /opt/$${TARGET}/bin[m
[32m+[m[32m!isEmpty(target.path): INSTALLS += target[m
[1mdiff --git a/calc.pro.user b/calc.pro.user[m
[1mnew file mode 100644[m
[1mindex 0000000..752ff49[m
[1m--- /dev/null[m
[1m+++ b/calc.pro.user[m
[36m@@ -0,0 +1,429 @@[m
[32m+[m[32m<?xml version="1.0" encoding="UTF-8"?>[m
[32m+[m[32m<!DOCTYPE QtCreatorProject>[m
[32m+[m[32m<!-- Written by QtCreator 9.0.2, 2023-04-05T17:09:37. -->[m
[32m+[m[32m<qtcreator>[m
[32m+[m[32m <data>[m
[32m+[m[32m  <variable>EnvironmentId</variable>[m
[32m+[m[32m  <value type="QByteArray">{82a5db89-421a-4882-b2f5-37a8738a8774}</value>[m
[32m+[m[32m </data>[m
[32m+[m[32m <data>[m
[32m+[m[32m  <variable>ProjectExplorer.Project.ActiveTarget</variable>[m
[32m+[m[32m  <value type="qlonglong">0</value>[m
[32m+[m[32m </data>[m
[32m+[m[32m <data>[m
[32m+[m[32m  <variable>ProjectExplorer.Project.EditorSettings</variable>[m
[32m+[m[32m  <valuemap type="QVariantMap">[m
[32m+[m[32m   <value type="bool" key="EditorConfiguration.AutoIndent">true</value>[m
[32m+[m[32m   <value type="bool" key="EditorConfiguration.AutoSpacesForTabs">false</value>[m
[32m+[m[32m   <value type="bool" key="EditorConfiguration.CamelCaseNavigation">true</value>[m
[32m+[m[32m   <valuemap type="QVariantMap" key="EditorConfiguration.CodeStyle.0">[m
[32m+[m[32m    <value type="QString" key="language">Cpp</value>[m
[32m+[m[32m    <valuemap type="QVariantMap" key="value">[m
[32m+[m[32m     <value type="QByteArray" key="CurrentPreferences">CppGlobal</value>[m
[32m+[m[32m    </valuemap>[m
[32m+[m[32m   </valuemap>[m
[32m+[m[32m   <valuemap type="QVariantMap" key="EditorConfiguration.CodeStyle.1">[m
[32m+[m[32m    <value type="QString" key="language">QmlJS</value>[m
[32m+[m[32m    <valuemap type="QVariantMap" key="value">[m
[32m+[m[32m     <value type="QByteArray" key="CurrentPreferences">QmlJSGlobal</value>[m
[32m+[m[32m    </valuemap>[m
[32m+[m[32m   </valuemap>[m
[32m+[m[32m   <value type="qlonglong" key="EditorConfiguration.CodeStyle.Count">2</value>[m
[32m+[m[32m   <value type="QByteArray" key="EditorConfiguration.Codec">UTF-8</value>[m
[32m+[m[32m   <value type="bool" key="EditorConfiguration.ConstrainTooltips">false</value>[m
[32m+[m[32m   <value type="int" key="EditorConfiguration.IndentSize">4</value>[m
[32m+[m[32m   <value type="bool" key="EditorConfiguration.KeyboardTooltips">false</value>[m
[32m+[m[32m   <value type="int" key="EditorConfiguration.MarginColumn">80</value>[m
[32m+[m[32m   <value type="bool" key="EditorConfiguration.MouseHiding">true</value>[m
[32m+[m[32m   <value type="bool" key="EditorConfiguration.MouseNavigation">true</value>[m
[32m+[m[32m   <value type="int" key="EditorConfiguration.PaddingMode">1</value>[m
[32m+[m[32m   <value type="bool" key="EditorConfiguration.PreferSingleLineComments">false</value>[m
[32m+[m[32m   <value type="bool" key="EditorConfiguration.ScrollWheelZooming">true</value>[m
[32m+[m[32m   <value type="bool" key="EditorConfiguration.ShowMargin">false</value>[m
[32m+[m[32m   <value type="int" key="EditorConfiguration.SmartBackspaceBehavior">0</value>[m
[32m+[m[32m   <value type="bool" key="EditorConfiguration.SmartSelectionChanging">true</value>[m
[32m+[m[32m   <value type="bool" key="EditorConfiguration.SpacesForTabs">true</value>[m
[32m+[m[32m   <value type="int" key="EditorConfiguration.TabKeyBehavior">0</value>[m
[32m+[m[32m   <value type="int" key="EditorConfiguration.TabSize">8</value>[m
[32m+[m[32m   <value type="bool" key="EditorConfiguration.UseGlobal">true</value>[m
[32m+[m[32m   <value type="bool" key="EditorConfiguration.UseIndenter">false</value>[m
[32m+[m[32m   <value type="int" key="EditorConfiguration.Utf8BomBehavior">1</value>[m
[32m+[m[32m   <value type="bool" key="EditorConfiguration.addFinalNewLine">true</value>[m
[32m+[m[32m   <value type="bool" key="EditorConfiguration.cleanIndentation">true</value>[m
[32m+[m[32m   <value type="bool" key="EditorConfiguration.cleanWhitespace">true</value>[m
[32m+[m[32m   <value type="QString" key="EditorConfiguration.ignoreFileTypes">*.md, *.MD, Makefile</value>[m
[32m+[m[32m   <value type="bool" key="EditorConfiguration.inEntireDocument">false</value>[m
[32m+[m[32m   <value type="bool" key="EditorConfiguration.skipTrailingWhitespace">true</value>[m
[32m+[m[32m   <value type="bool" key="EditorConfiguration.tintMarginArea">true</value>[m
[32m+[m[32m  </valuemap>[m
[32m+[m[32m </data>[m
[32m+[m[32m <data>[m
[32m+[m[32m  <variable>ProjectExplorer.Project.PluginSettings</variable>[m
[32m+[m[32m  <valuemap type="QVariantMap">[m
[32m+[m[32m   <valuemap type="QVariantMap" key="AutoTest.ActiveFrameworks">[m
[32m+[m[32m    <value type="bool" key="AutoTest.Framework.Boost">true</value>[m
[32m+[m[32m    <value type="bool" key="AutoTest.Framework.CTest">false</value>[m
[32m+[m[32m    <value type="bool" key="AutoTest.Framework.Catch">true</value>[m
[32m+[m[32m    <value type="bool" key="AutoTest.Framework.GTest">true</value>[m
[32m+[m[32m    <value type="bool" key="AutoTest.Framework.QtQuickTest">true</value>[m
[32m+[m[32m    <value type="bool" key="AutoTest.Framework.QtTest">true</value>[m
[32m+[m[32m   </valuemap>[m
[32m+[m[32m   <valuemap type="QVariantMap" key="AutoTest.CheckStates"/>[m
[32m+[m[32m   <value type="int" key="AutoTest.RunAfterBuild">0</value>[m
[32m+[m[32m   <value type="bool" key="AutoTest.UseGlobal">true</value>[m
[32m+[m[32m   <valuemap type="QVariantMap" key="ClangTools">[m
[32m+[m[32m    <value type="bool" key="ClangTools.AnalyzeOpenFiles">true</value>[m
[32m+[m[32m    <value type="bool" key="ClangTools.BuildBeforeAnalysis">true</value>[m
[32m+[m[32m    <value type="QString" key="ClangTools.DiagnosticConfig">Builtin.DefaultTidyAndClazy</value>[m
[32m+[m[32m    <value type="int" key="ClangTools.ParallelJobs">4</value>[m
[32m+[m[32m    <valuelist type="QVariantList" key="ClangTools.SelectedDirs"/>[m
[32m+[m[32m    <valuelist type="QVariantList" key="ClangTools.SelectedFiles"/>[m
[32m+[m[32m    <valuelist type="QVariantList" key="ClangTools.SuppressedDiagnostics"/>[m
[32m+[m[32m    <value type="bool" key="ClangTools.UseGlobalSettings">true</value>[m
[32m+[m[32m   </valuemap>[m
[32m+[m[32m   <valuemap type="QVariantMap" key="CppEditor.QuickFix">[m
[32m+[m[32m    <value type="bool" key="UseGlobalSettings">true</value>[m
[32m+[m[32m   </valuemap>[m
[32m+[m[32m  </valuemap>[m
[32m+[m[32m </data>[m
[32m+[m[32m <data>[m
[32m+[m[32m  <variable>ProjectExplorer.Project.Target.0</variable>[m
[32m+[m[32m  <valuemap type="QVariantMap">[m
[32m+[m[32m   <value type="QString" key="DeviceType">Desktop</value>[m
[32m+[m[32m   <value type="QString" key="ProjectExplorer.ProjectConfiguration.DefaultDisplayName">Desktop Qt 6.4.3 MSVC2019 64bit</value>[m
[32m+[m[32m   <value type="QString" key="ProjectExplorer.ProjectConfiguration.DisplayName">Desktop Qt 6.4.3 MSVC2019 64bit</value>[m
[32m+[m[32m   <value type="QString" key="ProjectExplorer.ProjectConfiguration.Id">qt.qt6.643.win64_msvc2019_64_kit</value>[m
[32m+[m[32m   <value type="qlonglong" key="ProjectExplorer.Target.ActiveBuildConfiguration">0</value>[m
[32m+[m[32m   <value type="qlonglong" key="ProjectExplorer.Target.ActiveDeployConfiguration">0</value>[m
[32m+[m[32m   <value type="qlonglong" key="ProjectExplorer.Target.ActiveRunConfiguration">0</value>[m
[32m+[m[32m   <valuemap type="QVariantMap" key="ProjectExplorer.Target.BuildConfiguration.0">[m
[32m+[m[32m    <value type="int" key="EnableQmlDebugging">0</value>[m
[32m+[m[32m    <value type="QString" key="ProjectExplorer.BuildConfiguration.BuildDirectory">D:\Qt\projects\calc\..\build-calc-Desktop_Qt_6_4_3_MSVC2019_64bit-Debug</value>[m
[32m+[m[32m    <value type="QString" key="ProjectExplorer.BuildConfiguration.BuildDirectory.shadowDir">D:/Qt/projects/build-calc-Desktop_Qt_6_4_3_MSVC2019_64bit-Debug</value>[m
[32m+[m[32m    <valuemap type="QVariantMap" key="ProjectExplorer.BuildConfiguration.BuildStepList.0">[m
[32m+[m[32m     <valuemap type="QVariantMap" key="ProjectExplorer.BuildStepList.Step.0">[m
[32m+[m[32m      <value type="bool" key="ProjectExplorer.BuildStep.Enabled">true</value>[m
[32m+[m[32m      <value type="QString" key="ProjectExplorer.ProjectConfiguration.Id">QtProjectManager.QMakeBuildStep</value>[m
[32m+[m[32m      <value type="bool" key="QtProjectManager.QMakeBuildStep.QMakeForced">false</value>[m
[32m+[m[32m      <valuelist type="QVariantList" key="QtProjectManager.QMakeBuildStep.SelectedAbis"/>[m
[32m+[m[32m     </valuemap>[m
[32m+[m[32m     <valuemap type="QVariantMap" key="ProjectExplorer.BuildStepList.Step.1">[m
[32m+[m[32m      <value type="bool" key="ProjectExplorer.BuildStep.Enabled">true</value>[m
[32m+[m[32m      <value type="QString" key="ProjectExplorer.ProjectConfiguration.Id">Qt4ProjectManager.MakeStep</value>[m
[32m+[m[32m     </valuemap>[m
[32m+[m[32m     <value type="qlonglong" key="ProjectExplorer.BuildStepList.StepsCount">2</value>[m
[32m+[m[32m     <value type="QString" key="ProjectExplorer.ProjectConfiguration.DefaultDisplayName">Сборка</value>[m
[32m+[m[32m     <value type="QString" key="ProjectExplorer.ProjectConfiguration.DisplayName">Сборка</value>[m
[32m+[m[32m     <value type="QString" key="ProjectExplorer.ProjectConfiguration.Id">ProjectExplorer.BuildSteps.Build</value>[m
[32m+[m[32m    </valuemap>[m
[32m+[m[32m    <valuemap type="QVariantMap" key="ProjectExplorer.BuildConfiguration.BuildStepList.1">[m
[32m+[m[32m     <valuemap type="QVariantMap" key="ProjectExplorer.BuildStepList.Step.0">[m
[32m+[m[32m      <value type="bool" key="ProjectExplorer.BuildStep.Enabled">true</value>[m
[32m+[m[32m      <value type="QString" key="ProjectExplorer.ProjectConfiguration.Id">Qt4ProjectManager.MakeStep</value>[m
[32m+[m[32m      <value type="QString" key="Qt4ProjectManager.MakeStep.MakeArguments">clean</value>[m
[32m+[m[32m     </valuemap>[m
[32m+[m[32m     <value type="qlonglong" key="ProjectExplorer.BuildStepList.StepsCount">1</value>[m
[32m+[m[32m     <value type="QString" key="ProjectExplorer.ProjectConfiguration.DefaultDisplayName">Очистка</value>[m
[32m+[m[32m     <value type="QString" key="ProjectExplorer.ProjectConfiguration.DisplayName">Очистка</value>[m
[32m+[m[32m     <value type="QString" key="ProjectExplorer.ProjectConfiguration.Id">ProjectExplorer.BuildSteps.Clean</value>[m
[32m+[m[32m    </valuemap>[m
[32m+[m[32m    <value type="int" key="ProjectExplorer.BuildConfiguration.BuildStepListCount">2</value>[m
[32m+[m[32m    <value type="bool" key="ProjectExplorer.BuildConfiguration.ClearSystemEnvironment">false</value>[m
[32m+[m[32m    <valuelist type="QVariantList" key="ProjectExplorer.BuildConfiguration.CustomParsers"/>[m
[32m+[m[32m    <value type="bool" key="ProjectExplorer.BuildConfiguration.ParseStandardOutput">false</value>[m
[32m+[m[32m    <valuelist type="QVariantList" key="ProjectExplorer.BuildConfiguration.UserEnvironmentChanges"/>[m
[32m+[m[32m    <value type="QString" key="ProjectExplorer.ProjectConfiguration.DisplayName">Debug</value>[m
[32m+[m[32m    <value type="QString" key="ProjectExplorer.ProjectConfiguration.Id">Qt4ProjectManager.Qt4BuildConfiguration</value>[m
[32m+[m[32m    <value type="int" key="Qt4ProjectManager.Qt4BuildConfiguration.BuildConfiguration">2</value>[m
[32m+[m[32m   </valuemap>[m
[32m+[m[32m   <valuemap type="QVariantMap" key="ProjectExplorer.Target.BuildConfiguration.1">[m
[32m+[m[32m    <value type="QString" key="ProjectExplorer.BuildConfiguration.BuildDirectory">D:\Qt\projects\calc\..\build-calc-Desktop_Qt_6_4_3_MSVC2019_64bit-Release</value>[m
[32m+[m[32m    <value type="QString" key="ProjectExplorer.BuildConfiguration.BuildDirectory.shadowDir">D:/Qt/projects/build-calc-Desktop_Qt_6_4_3_MSVC2019_64bit-Release</value>[m
[32m+[m[32m    <valuemap type="QVariantMap" key="ProjectExplorer.BuildConfiguration.BuildStepList.0">[m
[32m+[m[32m     <valuemap type="QVariantMap" key="ProjectExplorer.BuildStepList.Step.0">[m
[32m+[m[32m      <value type="bool" key="ProjectExplorer.BuildStep.Enabled">true</value>[m
[32m+[m[32m      <value type="QString" key="ProjectExplorer.ProjectConfiguration.Id">QtProjectManager.QMakeBuildStep</value>[m
[32m+[m[32m      <value type="bool" key="QtProjectManager.QMakeBuildStep.QMakeForced">false</value>[m
[32m+[m[32m      <valuelist type="QVariantList" key="QtProjectManager.QMakeBuildStep.SelectedAbis"/>[m
[32m+[m[32m     </valuemap>[m
[32m+[m[32m     <valuemap type="QVariantMap" key="ProjectExplorer.BuildStepList.Step.1">[m
[32m+[m[32m      <value type="bool" key="ProjectExplorer.BuildStep.Enabled">true</value>[m
[32m+[m[32m      <value type="QString" key="ProjectExplorer.ProjectConfiguration.Id">Qt4ProjectManager.MakeStep</value>[m
[32m+[m[32m     </valuemap>[m
[32m+[m[32m     <value type="qlonglong" key="ProjectExplorer.BuildStepList.StepsCount">2</value>[m
[32m+[m[32m     <value type="QString" key="ProjectExplorer.ProjectConfiguration.DefaultDisplayName">Сборка</value>[m
[32m+[m[32m     <value type="QString" key="ProjectExplorer.ProjectConfiguration.DisplayName">Сборка</value>[m
[32m+[m[32m     <value type="QString" key="ProjectExplorer.ProjectConfiguration.Id">ProjectExplorer.BuildSteps.Build</value>[m
[32m+[m[32m    </valuemap>[m
[32m+[m[32m    <valuemap type="QVariantMap" key="ProjectExplorer.BuildConfiguration.BuildStepList.1">[m
[32m+[m[32m     <valuemap type="QVariantMap" key="ProjectExplorer.BuildStepList.Step.0">[m
[32m+[m[32m      <value type="bool" key="ProjectExplorer.BuildStep.Enabled">true</value>[m
[32m+[m[32m      <value type="QString" key="ProjectExplorer.ProjectConfiguration.Id">Qt4ProjectManager.MakeStep</value>[m
[32m+[m[32m      <value type="QString" key="Qt4ProjectManager.MakeStep.MakeArguments">clean</value>[m
[32m+[m[32m     </valuemap>[m
[32m+[m[32m     <value type="qlonglong" key="ProjectExplorer.BuildStepList.StepsCount">1</value>[m
[32m+[m[32m     <value type="QString" key="ProjectExplorer.ProjectConfiguration.DefaultDisplayName">Очистка</value>[m
[32m+[m[32m     <value type="QString" key="ProjectExplorer.ProjectConfiguration.DisplayName">Очистка</value>[m
[32m+[m[32m     <value type="QString" key="ProjectExplorer.ProjectConfiguration.Id">ProjectExplorer.BuildSteps.Clean</value>[m
[32m+[m[32m    </valuemap>[m
[32m+[m[32m    <value type="int" key="ProjectExplorer.BuildConfiguration.BuildStepListCount">2</value>[m
[32m+[m[32m    <value type="bool" key="ProjectExplorer.BuildConfiguration.ClearSystemEnvironment">false</value>[m
[32m+[m[32m    <valuelist type="QVariantList" key="ProjectExplorer.BuildConfiguration.CustomParsers"/>[m
[32m+[m[32m    <value type="bool" key="ProjectExplorer.BuildConfiguration.ParseStandardOutput">false</value>[m
[32m+[m[32m    <valuelist type="QVariantList" key="ProjectExplorer.BuildConfiguration.UserEnvironmentChanges"/>[m
[32m+[m[32m    <value type="QString" key="ProjectExplorer.ProjectConfiguration.DisplayName">Release</value>[m
[32m+[m[32m    <value type="QString" key="ProjectExplorer.ProjectConfiguration.Id">Qt4ProjectManager.Qt4BuildConfiguration</value>[m
[32m+[m[32m    <value type="int" key="Qt4ProjectManager.Qt4BuildConfiguration.BuildConfiguration">0</value>[m
[32m+[m[32m    <value type="int" key="QtQuickCompiler">0</value>[m
[32m+[m[32m   </valuemap>[m
[32m+[m[32m   <valuemap type="QVariantMap" key="ProjectExplorer.Target.BuildConfiguration.2">[m
[32m+[m[32m    <value type="int" key="EnableQmlDebugging">0</value>[m
[32m+[m[32m    <value type="QString" key="ProjectExplorer.BuildConfiguration.BuildDirectory">D:\Qt\projects\calc\..\build-calc-Desktop_Qt_6_4_3_MSVC2019_64bit-Profile</value>[m
[32m+[m[32m    <value type="QString" key="ProjectExplorer.BuildConfiguration.BuildDirectory.shadowDir">D:/Qt/projects/build-calc-Desktop_Qt_6_4_3_MSVC2019_64bit-Profile</value>[m
[32m+[m[32m    <valuemap type="QVariantMap" key="ProjectExplorer.BuildConfiguration.BuildStepList.0">[m
[32m+[m[32m     <valuemap type="QVariantMap" key="ProjectExplorer.BuildStepList.Step.0">[m
[32m+[m[32m      <value type="bool" key="ProjectExplorer.BuildStep.Enabled">true</value>[m
[32m+[m[32m      <value type="QString" key="ProjectExplorer.ProjectConfiguration.Id">QtProjectManager.QMakeBuildStep</value>[m
[32m+[m[32m      <value type="bool" key="QtProjectManager.QMakeBuildStep.QMakeForced">false</value>[m
[32m+[m[32m      <valuelist type="QVariantList" key="QtProjectManager.QMakeBuildStep.SelectedAbis"/>[m
[32m+[m[32m     </valuemap>[m
[32m+[m[32m     <valuemap type="QVariantMap" key="ProjectExplorer.BuildStepList.Step.1">[m
[32m+[m[32m      <value type="bool" key="ProjectExplorer.BuildStep.Enabled">true</value>[m
[32m+[m[32m      <value type="QString" key="ProjectExplorer.ProjectConfiguration.Id">Qt4ProjectManager.MakeStep</value>[m
[32m+[m[32m     </valuemap>[m
[32m+[m[32m     <value type="qlonglong" key="ProjectExplorer.BuildStepList.StepsCount">2</value>[m
[32m+[m[32m     <value type="QString" key="ProjectExplorer.ProjectConfiguration.DefaultDisplayName">Сборка</value>[m
[32m+[m[32m     <value type="QString" key="ProjectExplorer.ProjectConfiguration.DisplayName">Сборка</value>[m
[32m+[m[32m     <value type="QString" key="ProjectExplorer.ProjectConfiguration.Id">ProjectExplorer.BuildSteps.Build</value>[m
[32m+[m[32m    </valuemap>[m
[32m+[m[32m    <valuemap type="QVariantMap" key="ProjectExplorer.BuildConfiguration.BuildStepList.1">[m
[32m+[m[32m     <valuemap type="QVariantMap" key="ProjectExplorer.BuildStepList.Step.0">[m
[32m+[m[32m      <value type="bool" key="ProjectExplorer.BuildStep.Enabled">true</value>[m
[32m+[m[32m      <value type="QString" key="ProjectExplorer.ProjectConfiguration.Id">Qt4ProjectManager.MakeStep</value>[m
[32m+[m[32m      <value type="QString" key="Qt4ProjectManager.MakeStep.MakeArguments">clean</value>[m
[32m+[m[32m     </valuemap>[m
[32m+[m[32m     <value type="qlonglong" key="ProjectExplorer.BuildStepList.StepsCount">1</value>[m
[32m+[m[32m     <value type="QString" key="ProjectExplorer.ProjectConfiguration.DefaultDisplayName">Очистка</value>[m
[32m+[m[32m     <value type="QString" key="ProjectExplorer.ProjectConfiguration.DisplayName">Очистка</value>[m
[32m+[m[32m     <value type="QString" key="ProjectExpl