// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.IO;
using System;


public class NODOLiveLink : ModuleRules
{

    private string ModulePath
    {
        get { return ModuleDirectory; }
    }

    public NODOLiveLink(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
        bEnableUndefinedIdentifierWarnings = false;
        ShadowVariableWarningLevel = WarningLevel.Warning;


        PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"LiveLinkInterface",
				"Messaging",
			});

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"InputCore",
				"Json",
				"JsonUtilities",
				"Networking",
				"Slate",
				"SlateCore",
				"Sockets",
			});


        PublicAdditionalLibraries.Add(Path.Combine(ModulePath, "../ThirdParty/lib/libboost_system-vc141-mt-x64-1_67.lib"));
        PublicAdditionalLibraries.Add(Path.Combine(ModulePath, "../ThirdParty/lib/libboost_date_time-vc141-mt-x64-1_67.lib"));
        PublicAdditionalLibraries.Add(Path.Combine(ModulePath, "../ThirdParty/lib/libboost_regex-vc141-mt-x64-1_67.lib"));
        PublicIncludePaths.Add(Path.Combine(ModulePath, "../ThirdParty"));

        // Not sure if needed
        PublicDefinitions.Add("_CRT_SECURE_NO_WARNINGS=1");
        PublicDefinitions.Add("BOOST_DISABLE_ABI_HEADERS=1");
        //    PublicDefinitions.Add("BOOST_HAS_PRAGMA_DETECT_MISMATCH=0");

        // Needed configurations in order to run Boost
        bUseRTTI = true;
        bEnableExceptions = true;
        bEnableUndefinedIdentifierWarnings = false;


        PublicDefinitions.Add(string.Format("WITH_BOOST_BINDING={0}", 1 ));
        PublicDefinitions.Add(string.Format("_WIN32_WINNT=0x0602"));

        PublicDefinitions.Add(string.Format("ASIO_STANDALONE"));
        PublicDefinitions.Add(string.Format("ASIO_HAS_STD_ADDRESSOF"));
        PublicDefinitions.Add(string.Format("ASIO_HAS_STD_ARRAY"));
        PublicDefinitions.Add(string.Format("ASIO_HAS_CSTDINT"));
        PublicDefinitions.Add(string.Format("ASIO_HAS_STD_SHARED_PTR"));
        PublicDefinitions.Add(string.Format("ASIO_HAS_STD_TYPE_TRAITS"));
        PublicDefinitions.Add(string.Format("BOOST_ERROR_CODE_HEADER_ONLY")); 

    }
}
